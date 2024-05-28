//
// Created by Alexandru Mihalache on 05.05.2024.
//

#include "Lan_Party_trees.h"

void addToList(Team **theTeam, Team *data) {
    data->next = (*theTeam);
    (*theTeam) = data;
}

void InorderList(BST *root, Team **theTeam) { //adaugare BST intr-o lista in inordine (SRD)
    if (root == NULL) {
        return;
    }
    InorderList(root->left, theTeam);
    addToList(theTeam, root->theTeams);
    InorderList(root->right, theTeam);
}

BST *buildAVL(Team **theTeam, int start, int finish) { //utilizare divide et impera
    if (start > finish || (*theTeam) == NULL)
        return NULL;
    int middle = (start + finish) / 2;
    Team *theTeamcpy = (*theTeam);
    for (int i = 0; i < middle && theTeamcpy != NULL; i++) { //ma deplasez spre mijloc
        theTeamcpy = theTeamcpy->next;
    }
    if (theTeamcpy != NULL) { //verificare daca exista element
        BST *newNode = (BST *) malloc(sizeof(BST)); //creare nod AVL
        if (newNode == NULL) {
            printf("Not enough memory");
            exit(1);
        }
        newNode->theTeams = theTeamcpy;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->left = buildAVL(theTeam, start, middle - 1); //generare subarbore stang
        newNode->right = buildAVL(theTeam, middle + 1, finish); //generare subarbore drept
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