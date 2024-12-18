//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

QueueMatch *CreateQueue() {
    QueueMatch *Matchs = NULL;
    Matchs = (QueueMatch *) malloc(sizeof(QueueMatch));
    if (Matchs == NULL) return NULL;
    Matchs->Front = Matchs->Rear = NULL;
    return Matchs;
}

void enQueue(QueueMatch *Matchs, Team *theTeam) {
    QueueNode *newNode = (QueueNode *) malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Not enough memory");
        exit(1);
    }
    newNode->data = theTeam;
    newNode->next = NULL;
    if (isEmpty(Matchs)) {
        Matchs->Front = Matchs->Rear = newNode;
    } else {
        Matchs->Rear->next = newNode;
        Matchs->Rear = newNode;
    }
}

int isEmpty(QueueMatch *Matches) {
    return (Matches->Front == NULL);
}

Team *deQueue(QueueMatch *Matchs) {
    if (isEmpty(Matchs)) return NULL;
    QueueNode *aux = Matchs->Front;
    Team *dequeueTeam = aux->data;
    Matchs->Front = Matchs->Front->next;
    free(aux);
    return dequeueTeam;
}

void deleteQueue(QueueMatch *Match) {
    QueueNode *aux;
    while (!isEmpty(Match)) {
        aux = Match->Front;
        Match->Front = Match->Front->next;
        free(aux->data->teamName);
        deletePlayers(&aux->data->players);
        free(aux);
    }
    Match = NULL;
}
