//
// Created by Alexandru Mihalache on 05.05.2024.
//

#include "Lan_Party_header.h"

typedef struct BST {
    Team *theTeams;
    struct BST *left;
    struct BST *right;
} BST;

// task 4
bool verifyCond(float score1, float score2, char *name1, char *name2);

BST *newNode(Team *theTeam);

BST *Insert(BST *node, Team *theTeam);

BST *CreateTheTree(Team *theEight);

void ShowTheStandings(BST *root, FILE *myfile);

void deleteTheTree(BST *root);

//task 5
void InorderList(BST *root, Team **theTeam);

void addToList(Team **theTeam, Team *data);

BST *buildAVL(Team **theTeam, int start, int finish);

void printLevel(BST *root, int level, FILE *myfile);

#ifndef TEMA_LAN_PARTY_LAN_PARTY_TREES_H
#define TEMA_LAN_PARTY_LAN_PARTY_TREES_H

#endif //TEMA_LAN_PARTY_LAN_PARTY_TREES_H
