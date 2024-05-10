//
// Created by Alexandru Mihalache on 03.05.2024.
//

#include "Lan_Party_header.h"

int isEmptyStack(Team *Top){
    return Top==NULL;
}

void StackPush(Team **Top, Team *theTeam){
    theTeam->next=*Top;
    *Top=theTeam;
}

Team *StackPop(Team **Top){
    if(isEmptyStack(*Top)) return NULL;
    Team *temp=(*Top);
    (*Top)=(*Top)->next;
    temp->next=NULL;
    return temp;
}

void deleteStack(Team **Top){
    Team *temp;
    while((*Top)!=NULL){
        temp=*Top;
        *Top=(*Top)->next;
        free(temp->teamName);
        deletePlayers(&temp->players);
        free(temp);
    }
    *Top=NULL;
}



