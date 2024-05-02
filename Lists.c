//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

void addAtBeginningPlayer(Player **head, char *firstNmame, char *secondName, int points){
    Player *newPlayer=(Player*)malloc(sizeof(Player));
    if(newPlayer==NULL){
        printf("Not enough memory");
        exit(1);
    }
    newPlayer->firstName= strdup(firstNmame);
    newPlayer->secondName= strdup(secondName);
    newPlayer->points=points;
    newPlayer->next=*head;
    *head=newPlayer;
}

void addAtBeginningTeam(Team **head, char *teamName, int membersNr){
    Team *newTeam=(Team*)malloc(sizeof(Team));
    if(newTeam==NULL){
        printf("Not enough memory");
        exit(1);
    }
    newTeam->teamName= strdup(teamName);
    newTeam->membersNr=membersNr;
    newTeam->next=*head;
    *head=newTeam;
}