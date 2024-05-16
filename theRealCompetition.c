//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

#define TABLE_DESIGN 32
#define THELAST 8

void addSpace(char *str, FILE *myfile) {
    int strDim = strlen(str) - 1;
    int strSpace = TABLE_DESIGN - strDim;
    while (strSpace != 0) {
        fprintf(myfile, "%c", ' ');
        strSpace--;
    }
}

QueueMatch *CreateTheQueue(Team *theTeam) {
    QueueMatch *theQueue = CreateQueue();
    while (theTeam != NULL) {
        enQueue(theQueue, theTeam);
        theTeam = theTeam->next;
    }
    deleteTeamList(&theTeam);
    return theQueue;
}

void modifyPlyPoint(Player *thePlayer, int teamMembers) {
    Player *PlayerCpy = thePlayer;
    float ratio = (float) 1 / (float) teamMembers;
    while (PlayerCpy != NULL) {
        PlayerCpy->points += ratio;
        PlayerCpy = PlayerCpy->next;
    }
}

void showtheTable(QueueMatch *Match, Team **win, Team **lost, FILE *myfile) {
    Team *T1 = NULL;
    Team *T2 = NULL;
    while (!isEmpty(Match)) {
        T1 = deQueue(Match);
        T2 = deQueue(Match);
        fprintf(myfile, "%s", T1->teamName);
        addSpace(T1->teamName, myfile);
        fprintf(myfile, "%c", '-');
        addSpace(T2->teamName, myfile);
        fprintf(myfile, "%s", T2->teamName);
        fprintf(myfile, "\n");
        if (T1->teamPoints > T2->teamPoints) {
            T1->teamPoints += 1;
            modifyPlyPoint(T1->players, T1->membersNr);
            StackPush(win, T1);
            StackPush(lost, T2);
        } else if (T1->teamPoints < T2->teamPoints) {
            T2->teamPoints += 1;
            modifyPlyPoint(T2->players, T2->membersNr);
            StackPush(win, T2);
            StackPush(lost, T1);
        } else {
            T2->teamPoints += 1;
            modifyPlyPoint(T2->players, T2->membersNr);
            StackPush(win, T2);
        }
    }
    T1 = NULL;
    T2 = NULL;
    deleteQueue(Match);
}

void RestoreDate(Team **win, Team **lose, QueueMatch **Match, FILE *myfile) {
    deleteStack(lose);
    Team *newTeam = NULL;
    QueueMatch *tempMatch = CreateQueue();  // coadă temporară
    while ((*win) != NULL) {
        newTeam = StackPop(win);
        fprintf(myfile, "%s", newTeam->teamName);
        addSpace(newTeam->teamName, myfile);
        fprintf(myfile, " -  %.2f\n", newTeam->teamPoints);
        enQueue(tempMatch, newTeam);  // adaugare in coada temporara
    }
    while (!isEmpty(tempMatch)) { //copiere in coada principala
        newTeam = deQueue(tempMatch);
        enQueue(*Match, newTeam);
    }
    deleteQueue(tempMatch);
}

Team *TheLastEight(QueueMatch **Match) {
    QueueMatch *Matchcopy = CreateQueue();//creare coda temporara
    Team *TheEight = NULL;
    Team *Copy = NULL;
    while (!isEmpty(*Match)) {
        Copy = deQueue(*Match);
        addAtBeginningTeam(&TheEight, Copy->teamName, Copy->membersNr);
        TheEight->teamPoints = Copy->teamPoints;
        Player *CopyPlayer = Copy->players;
        Player *TheEightPly = NULL;
        while (CopyPlayer != NULL) {
            addAtBeginningPlayer(&TheEightPly, CopyPlayer->firstName, CopyPlayer->secondName, CopyPlayer->points);
            CopyPlayer = CopyPlayer->next;
        }
        TheEight->players = TheEightPly;
        enQueue(Matchcopy, Copy);
    }
    (*Match) = Matchcopy;
    return TheEight;
}


void TheFinalScore(QueueMatch *Match, int TeamsNumber, char *output_3, Team **TheEight) {
    FILE *myfile = fopen(output_3, "at");
    if (myfile == NULL) {
        perror("Can't open this file");
        exit(1);
    }
    Team *win = NULL;
    Team *lose = NULL;
    int nrRounds = floor(log2(TeamsNumber));
    int cnt = 1;
    while (cnt <= nrRounds) {
        fprintf(myfile, "\n");
        fprintf(myfile, "--- ROUND NO:%d\n", cnt);
        showtheTable(Match, &win, &lose, myfile);
        fprintf(myfile, "\n");
        fprintf(myfile, "WINNERS OF ROUND NO:%d\n", cnt);
        RestoreDate(&win, &lose, &Match, myfile);
        if (pow(2, nrRounds - cnt) == THELAST) {
            (*TheEight) = TheLastEight(&Match);
        }
        cnt++;
    }
    deleteStack(&win);
    deleteQueue(Match);
    fclose(myfile);
}