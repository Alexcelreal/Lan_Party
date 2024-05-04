//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

QueueMatch *CreateQueue(){
    QueueMatch *Matchs=NULL;
    Matchs=(QueueMatch*)malloc(sizeof(QueueMatch));
    if(Matchs==NULL) return NULL;
    Matchs->Front=Matchs->Rear=NULL;
    return Matchs;
}

void enQueue(QueueMatch *Matchs, Team *theTeam){
    QueueNode *newNode=(QueueNode*)malloc(sizeof(QueueNode));
    if(newNode==NULL){
        printf("Not enough memory");
        exit(1);
    }
    newNode->data=theTeam;
    newNode->next=NULL;
    if(isEmpty(Matchs)){
        Matchs->Front = Matchs->Rear=newNode;
    }else{
        Matchs->Rear->next=newNode;
        Matchs->Rear=newNode;
    }
}

int isEmpty(QueueMatch *Matches){
    return (Matches->Front==NULL);
}

Team *deQueue(QueueMatch *Matchs){
    if(isEmpty(Matchs)) return NULL;
    QueueNode *aux=Matchs->Front;
    Team *dequeueTeam=aux->data;
    //dequeueTeam->teamName= strdup(aux->data->teamName);
    Matchs->Front=Matchs->Front->next;
    free(aux);
    return dequeueTeam;
}

void printQueue(QueueMatch *Matchs) {
    if (isEmpty(Matchs)) {
        printf("Coadă goală.\n");
        return;
    }
    QueueNode *currentNode = Matchs->Front;
    printf("Conținutul cozii:\n");
    while (currentNode != NULL) {
        Team *team = currentNode->data;
        printf("Nume echipă: %s\n", team->teamName);
        currentNode = currentNode->next->next;
    }
}

void deleteQueue(QueueMatch *Match){
    while(!isEmpty(Match)){
        deQueue(Match);
    }
    free(Match);
}
