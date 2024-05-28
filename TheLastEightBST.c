//
// Created by Alexandru Mihalache on 05.05.2024.
//

#include "Lan_Party_trees.h"

bool verifyCond(float score1, float score2, char *name1, char *name2) {
    if (score2 < score1)
        return true;
    else {
        if (score2 == score1 && strcmp(name2, name1) < 0)
            return true;
    }
    return false;
}

BST *newNode(Team *theTeam) {
    BST *node = (BST *) malloc(sizeof(BST));
    node->theTeams = theTeam;
    node->right = node->left = NULL;
    return node;
}

BST *Insert(BST *node, Team *theTeam) {
    if (node == NULL) return newNode(theTeam);
    if (verifyCond(node->theTeams->teamPoints, theTeam->teamPoints, node->theTeams->teamName, theTeam->teamName)) {
        node->left = Insert(node->left, theTeam); //inserare subarbore stang
    } else {
        node->right = Insert(node->right, theTeam); //inserare subarbore drept
    }
    return node;
}

BST *CreateTheTree(Team *theEight) { //creare arbore BST
    BST *root = NULL;
    while (theEight != NULL) {
        root = Insert(root, theEight);
        theEight = theEight->next;
    }
    return root;
}

void deleteTheTree(BST *root) {
    if (root == NULL) return;
    deleteTheTree(root->left);
    deleteTheTree(root->right);
    free(root->theTeams->teamName);
    deletePlayers(&root->theTeams->players);
    free(root);
}

void ShowTheStandings(BST *root, FILE *myfile) { //parcurgere inordine in sens invers (DRS) + afisare echipe si punctaj
    if (root == NULL) return;
    ShowTheStandings(root->right, myfile);
    fprintf(myfile, "%s ", root->theTeams->teamName);
    addSpace(root->theTeams->teamName, myfile);
    fprintf(myfile, "-  %.2f\n", root->theTeams->teamPoints);
    ShowTheStandings(root->left, myfile);
}