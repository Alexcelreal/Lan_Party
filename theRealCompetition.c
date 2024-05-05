//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

#define TABLE_DESIGN 32
#define THELAST 8

char *strtrim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) { //stergere spatii inceput
        str++;
    }
    if (*str == '\0') {
        return str;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) { //stergere spatii final
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

char *addSpaceBack(char *str){
    int strDim=strlen(str);
    str=(char*)realloc(str,(TABLE_DESIGN+1)*sizeof(char));
    if(str==NULL){
        printf("Not enough memory");
        exit(1);
    }
    for(int i=strDim;i<=TABLE_DESIGN;i++){
        str[i]=' ';
    }
    str[TABLE_DESIGN+1]='\0';
    return str;
}

char *addSpaceFront(char *str){
    int strDim= strlen(str);
    int strAdd=TABLE_DESIGN-strDim;
    char *strNew=(char*)malloc((TABLE_DESIGN+1)*sizeof(char));
    if(strNew==NULL){
        printf("Not enough memory");
        exit(1);
    }
    for(int i=0;i<=strAdd;i++){
        strNew[i]=' ';
    }
    strNew[strAdd+1]='\0';
    strcat(strNew,str);
    return strNew;
}


QueueMatch *CreateTheQueue(Team *theTeam){
    QueueMatch *theQueue=CreateQueue();
    while(theTeam!=NULL){
        //theTeam->next=NULL
        enQueue(theQueue,theTeam);
        theTeam=theTeam->next;
    }
    deleteTeamList(&theTeam);
    return theQueue;
}

void showtheTable(QueueMatch *Match, Team **win, Team **lost,FILE *myfile){
    Team *T1=NULL;
    Team *T2=NULL;
    while(!isEmpty(Match)) {
        T1 = deQueue(Match);
        T2 = deQueue(Match);
        char *c1= strdup(strtrim(T1->teamName));
        c1= addSpaceBack(c1);
        char *c2= strdup(strtrim(T2->teamName));
        c2= addSpaceFront(c2);
        fprintf(myfile,"%s-%s\n",c1,c2);
        free(c1);
        free(c2);
        //printf("%s - %s\n", strtrim(T1->teamName), strtrim(T2->teamName));
        if(T1->teamPoints>T2->teamPoints){
            T1->teamPoints+=1;
            StackPush(win,T1);
            StackPush(lost,T2);
        }else if(T1->teamPoints<T2->teamPoints){
            T2->teamPoints+=1;
            StackPush(win,T2);
            StackPush(lost,T1);
        }else{
            T2->teamPoints+=1;
            StackPush(win,T2);
        }
    }
    /*free(T1->teamName);
    free(T1);
    free(T2->teamName);
    free(T2);*/
}

void RestoreDate(Team **win, Team **lose, QueueMatch **Match, FILE *myfile){
    deleteStack(lose);
    Team *newTeam = NULL;
    QueueMatch *tempMatch = CreateQueue();  // coadă temporară
    while ((*win) != NULL) {
        newTeam = StackPop(win);
        char *c3= strdup(strtrim(newTeam->teamName));
        c3= addSpaceBack(c3);
        fprintf(myfile,"%s -  %.2f\n",c3,newTeam->teamPoints);
        enQueue(tempMatch, newTeam);  // adaugare in coada temporara
    }
    while (!isEmpty(tempMatch)) { //copiere in coada principala
        newTeam = deQueue(tempMatch);
        enQueue(*Match, newTeam);
    }
    deleteQueue(tempMatch);
}

Team *TheLastEight(QueueMatch **Match){
    QueueMatch *Matchcopy=CreateQueue();//creare coda temporara
    Team *TheEight=NULL;
    Team *Copy=NULL;
    while(!isEmpty(*Match)){
        Copy= deQueue(*Match);
        addAtBeginningTeam(&TheEight,Copy->teamName,Copy->membersNr);
        TheEight->teamPoints=Copy->teamPoints;
        Player *CopyPlayer=Copy->players;
        Player *TheEightPly=NULL;
        while(CopyPlayer!=NULL){
            addAtBeginningPlayer(&TheEightPly,CopyPlayer->firstName,CopyPlayer->secondName,CopyPlayer->points);
            CopyPlayer=CopyPlayer->next;
        }
        TheEight->players=TheEightPly;
        enQueue(Matchcopy,Copy);
    }
    (*Match)=Matchcopy;
    return TheEight;
}


void TheFinalScore(QueueMatch *Match, int TeamsNumber, char *output_3, Team **TheEight){
    FILE *myfile= fopen(output_3,"at");
    if(myfile==NULL){
        perror("Can't open this file");
        exit(1);
    }
    Team *win=NULL;
    Team *lose=NULL;
    int nrRounds=floor(log2(TeamsNumber));
    int cnt=1;
    while(cnt<=nrRounds) {
        fprintf(myfile,"\n");
        fprintf(myfile,"--- ROUND NO:%d\n",cnt);
        showtheTable(Match, &win, &lose,myfile);
        fprintf(myfile,"\n");
        fprintf(myfile,"WINNERS OF ROUND NO:%d\n",cnt);
        RestoreDate(&win, &lose, &Match,myfile);
        if(pow(2,nrRounds-cnt)==THELAST){
            (*TheEight)= TheLastEight(&Match);
        }
        cnt++;
    }
    deleteQueue(Match);
    fclose(myfile);
}



