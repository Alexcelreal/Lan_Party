//
// Created by Alexandru Mihalache on 05.05.2024.
//

#include "Lan_Party_trees.h"

void addToList(Team **theTeam, Team *data) {
    data->next = (*theTeam);
    (*theTeam) = data;
}

void InorderList(BST *root, Team **theTeam) {
    if (root == NULL) {
        return;
    }
    InorderList(root->left, theTeam);
    addToList(theTeam, root->theTeams);
    InorderList(root->right, theTeam);
}

BST *buildAVL(Team **theTeam, int start, int finish) {
    if (start > finish || (*theTeam) == NULL)
        return NULL;
    int middle = (start + finish) / 2;
    Team *theTeamcpy = (*theTeam);
    for (int i = 0; i < middle && theTeamcpy != NULL; i++) {
        theTeamcpy = theTeamcpy->next;
    }
    if (theTeamcpy != NULL) {
        BST *newNode = (BST *) malloc(sizeof(BST));
        if (newNode == NULL) {
            printf("Not enough memory");
            exit(1);
        }
        newNode->theTeams = theTeamcpy;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->left = buildAVL(theTeam, start, middle - 1);
        newNode->right = buildAVL(theTeam, middle + 1, finish);
        return newNode;
    } else
        return NULL;
}

void printLevel(BST *root, int level, FILE *myfile) {
    if (root == NULL) return;
    if (level == 1) fprintf(myfile, "%s\n", root->theTeams->teamName);
    else {
        if (level > 1) {
            printLevel(root->left, level - 1, myfile);
            printLevel(root->right, level - 1, myfile);
        }
    }
}