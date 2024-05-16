//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

void addAtBeginningPlayer(Player **head, char *firstName, char *secondName, float points) {
    Player *newPlayer = (Player *) malloc(sizeof(Player));
    if (newPlayer == NULL) {
        printf("Not enough memory");
        exit(1);
    }
    newPlayer->firstName = strdup(firstName);
    newPlayer->secondName = strdup(secondName);
    newPlayer->points = points;
    newPlayer->next = *head;
    *head = newPlayer;
}

void addAtBeginningTeam(Team **head, char *teamName, int membersNr) {
    Team *newTeam = (Team *) malloc(sizeof(Team));
    if (newTeam == NULL) {
        printf("Not enough memory");
        exit(1);
    }
    newTeam->teamName = strdup(teamName);
    newTeam->membersNr = membersNr;
    newTeam->next = *head;
    *head = newTeam;
}

void deletePlayers(Player **head) {
    Player *current = (*head);
    Player *headCopy;
    while (current != NULL) {
        headCopy = current->next;
        free(current->firstName);
        free(current->secondName);
        free(current);
        current = headCopy;
    }
    *head = NULL;
}

void deleteTeam(Team **head, Team *findTeam) {
    if (*head == NULL) return;
    Team *headCopy = *head;
    if (headCopy == findTeam) {
        *head = (*head)->next;
        deletePlayers(&findTeam->players);
        free(findTeam->teamName);
        free(findTeam);
        return;
    }
    Team *prev = *head;
    while (headCopy != NULL) {
        if (headCopy != findTeam) {
            prev = headCopy;
            headCopy = headCopy->next;
        } else {
            prev->next = headCopy->next;
            deletePlayers(&findTeam->players);
            free(findTeam->teamName);
            free(findTeam);
            return;
        }
    }
}

void deleteTeamList(Team **head) {
    Team *headcopy;
    while (*head != NULL) {
        headcopy = (*head)->next;
        deletePlayers(&(*head)->players);
        free((*head)->teamName);
        free(*head);
        *head = headcopy;
    }
    (*head) = NULL;
}