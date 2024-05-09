//
// Created by Alexandru Mihalache on 05.05.2024.
//

#include "Lan_Party_trees.h"

bool verifyCond(float score1, float score2, char *name1, char *name2){
    if(score2<score1)
        return true;
    else{
        if(score2==score1&&strcmp(name2,name1)<0)
            return true;
    }
    return false;
}

BST *newNode(Team *theTeam){
    BST *node=(BST*)malloc(sizeof(BST));
    node->theTeams=theTeam;
    node->right=node->left=NULL;
    return node;
}

BST *Insert(BST *node, Team *theTeam){
    if(node==NULL) return newNode(theTeam);
    if(verifyCond(node->theTeams->teamPoints,theTeam->teamPoints,node->theTeams->teamName,theTeam->teamName)){
        node->left= Insert(node->left,theTeam);
    }else{
        node->right= Insert(node->right,theTeam);
    }
    return node;
}

BST *CreateTheTree(Team *theEight){
    BST *root=NULL;
    while(theEight!=NULL){
        root= Insert(root,theEight);
        theEight=theEight->next;
    }
    return root;
}

/*void ShowTheStandings(BST *root){ //parcurgere preordine
    if(root){
        printf("%s %f\n", strtrim(root->theTeams->teamName),root->theTeams->teamPoints);
        ShowTheStandings(root->left);
        ShowTheStandings(root->right);
    }
}*/

void ShowTheStandings(BST *root, FILE *myfile){ //parcurgere inordine in sens invers
    if(root==NULL) return;
    ShowTheStandings(root->right, myfile);
    char *c1=NULL;
    c1= strdup(strtrim(root->theTeams->teamName));
    c1= addSpaceBack(c1);
    fprintf(myfile,"%s -  %.2f\n",c1,root->theTeams->teamPoints);
    free(c1);
    ShowTheStandings(root->left,myfile);
    }


