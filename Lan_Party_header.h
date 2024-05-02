//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define DIM 25

typedef struct Player{
    char *firstName;
    char *secondName;
    int points;
    struct Player *next;
}Player;

typedef struct Team{
    char *teamName;
    int membersNr;
    float teamPoints;
    Player *players;
    struct Team *next;
}Team;

//for first task
void addAtBeginningPlayer(Player **head, char *firstNmame, char *secondName, int points);
void addAtBeginningTeam(Team **head, char *teamName, int membersNr);
Team *createTeamList(char *input_2, int *teamsNumber);
void showTeamsList(Team *theTeam, char *output_3);

//for second task
void deletePlayers(Player **head);
void deleteTeam(Team **head, Team *findTeam);
void TeamsPoints(Team *head);
Team *minScoreTeam(Team *head);
bool powerOfTwo(int number);
void theNewList(Team **head, int *teamsNumber);



#ifndef TEMA_LAN_PARTY_LAN_PARTY_HEADER_H
#define TEMA_LAN_PARTY_LAN_PARTY_HEADER_H

#endif //TEMA_LAN_PARTY_LAN_PARTY_HEADER_H
