//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define DIM 25

typedef struct Player {
    char *firstName;
    char *secondName;
    float points;
    struct Player *next;
} Player;

typedef struct Team {
    char *teamName;
    int membersNr;
    float teamPoints;
    Player *players;
    struct Team *next;
} Team;

typedef struct QueueNode {
    Team *data;
    struct QueueNode *next;
} QueueNode;

typedef struct QueueMatch {
    QueueNode *Front;
    QueueNode *Rear;
} QueueMatch;

//task 1
void addAtBeginningPlayer(Player **head, char *firstNmame, char *secondName, float points);

void addAtBeginningTeam(Team **head, char *teamName, int membersNr);

Team *createTeamList(char *input_2, int *teamsNumber);

void showTeamsList(Team *theTeam, char *output_3);

//task 2
void deletePlayers(Player **head);

void deleteTeam(Team **head, Team *findTeam);

void TeamsPoints(Team *head);

Team *minScoreTeam(Team *head);

bool powerOfTwo(int number);

void theNewList(Team **head, int *teamsNumber);

//task 3
QueueMatch *CreateQueue();

QueueMatch *CreateTheQueue(Team *theTeam);

void enQueue(QueueMatch *Matchs, Team *theTeam);

Team *deQueue(QueueMatch *Matchs);

int isEmpty(QueueMatch *Matches);

void deleteTeamList(Team **head);

void showtheTable(QueueMatch *Match, Team **win, Team **lost, FILE *myfile);

void StackPush(Team **Top, Team *theTeam);

int isEmptyStack(Team *Top);

Team *StackPop(Team **Top);

void deleteStack(Team **Top);

void RestoreData(Team **win, Team **lose, QueueMatch **Match, FILE *myfile);

void TheFinalScore(QueueMatch *Match, int TeamsNumber, char *output_3, Team **TheEight);

void deleteQueue(QueueMatch *Match);

char *strtrim(char *string);

Team *TheLastEight(QueueMatch **Match);

void modifyPlyPoint(Player *thePlayer, int teamMembers);

void addSpace(char *str, FILE *myfile);

#ifndef TEMA_LAN_PARTY_LAN_PARTY_HEADER_H
#define TEMA_LAN_PARTY_LAN_PARTY_HEADER_H

#endif //TEMA_LAN_PARTY_LAN_PARTY_HEADER_H