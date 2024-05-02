//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

Team *createTeamList(char *input_2, int *TeamsNumber){
    Team *theTeam=NULL;
    Player *thePlayer=NULL;

    FILE *readFile= fopen(input_2,"rt");
    if(readFile==NULL){
        perror("Can't open this file");
        exit(1);
    }

    int teamsNumber=0;
    fscanf(readFile,"%d",&teamsNumber);
    *TeamsNumber=teamsNumber;
    char *teamName=(char*)malloc(DIM*sizeof(char));
    int membersNr=0;
    while(teamsNumber!=0){
        membersNr=0;
        fscanf(readFile,"%d",&membersNr); //citire nr membrii
        fscanf(readFile," ");
        fscanf(readFile,"%[^\n]",teamName); //citire nume echipa
        addAtBeginningTeam(&theTeam,teamName,membersNr);
        char *name=(char*)malloc(DIM*sizeof(char));
        char *secondName=(char*)malloc(DIM*sizeof(char));
        int points;
        int total=0;
        while(membersNr!=0){
            fscanf(readFile,"%s%s%d",name,secondName,&points); //citire nume/prenume/puncte
            addAtBeginningPlayer(&thePlayer,name,secondName,points);
            membersNr--;
            total+=points;
        }
        teamsNumber--;
        theTeam->players=thePlayer; //adaugare adresa de inceput a listei thePlayer
        theTeam->teamPoints=(float)total/(float)theTeam->membersNr;
        free(name);
        free(secondName);
    }
    free(teamName);
    fclose(readFile);
    return theTeam;
}

void showTeamsList(Team *theTeam, char *output_3){
    FILE *printFile=fopen(output_3,"wt");
    if(printFile==NULL){
        perror("Can't open this file");
        exit(1);
    }
    Team *ptr_team=theTeam;
    while(ptr_team!=NULL){
        fprintf(printFile,"%s\n",ptr_team->teamName);
        //fprintf(printFile,"%s %f",ptr_team->teamName,ptr_team->teamPoints);
        ptr_team=ptr_team->next;
    }
    fclose(printFile);
}