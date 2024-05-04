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

void deletePlayers(Player **head){
    Player *headCopy;
    while(*head!=NULL){
        headCopy=(*head)->next;
        free(*head);
        *head=headCopy;
    }
    *head=NULL;
}

void deleteTeam(Team **head, Team *findTeam){
    if(*head==NULL) return;
    Team *headCopy=*head;
    if(headCopy==findTeam){
        *head=(*head)->next;
        //deletePlayers(&findTeam->players);
        free(findTeam);
        return;
    }
    Team *prev=*head;
    while(headCopy!=NULL){
        if(headCopy!=findTeam){
            prev=headCopy;
            headCopy=headCopy->next;
        }else{
            prev->next=headCopy->next;
            //deletePlayers(&findTeam->players);
            free(findTeam);
            return;
        }
    }
}

void deleteTeamList(Team **head){
    Team *headcopy;
    while(*head!=NULL){
        headcopy=(*head)->next;
        free((*head)->teamName);
        (*head)->next=NULL;
        Player *currentPlayer=(*head)->players;
        while(currentPlayer!=NULL){
            Player *nextPlayer=currentPlayer->next;
            free(currentPlayer->firstName);
            free(currentPlayer->secondName);
            free(currentPlayer);
            currentPlayer=nextPlayer;
        }
        free(*head);
        *head=headcopy;
    }
}