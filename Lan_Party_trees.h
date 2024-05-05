//
// Created by Alexandru Mihalache on 05.05.2024.
//

#include "Lan_Party_header.h"

typedef struct BST{
    Team *theTeams;
    struct BST *left;
    struct BST *right;
}BST;

bool verifyCond(float score1, float score2, char *name1, char *name2);
BST *newNode(Team *theTeam);
BST *Insert(BST *node, Team *theTeam);
BST *CreateTheTree(Team *theEight);
void ShowTheStandings(BST *root, FILE *myfile);

#ifndef TEMA_LAN_PARTY_LAN_PARTY_TREES_H
#define TEMA_LAN_PARTY_LAN_PARTY_TREES_H

#endif //TEMA_LAN_PARTY_LAN_PARTY_TREES_H


