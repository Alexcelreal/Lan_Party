//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

void TeamsPoints(Team *head) {
    Team *currentTeam = head;
    while (currentTeam != NULL) {
        float total = 0;
        Player *currentPlayer = currentTeam->players;
        while (currentPlayer != NULL) {
            total += currentPlayer->points;
            currentPlayer = currentPlayer->next;
        }
        currentTeam->teamPoints = total / (float) currentTeam->membersNr;
        currentTeam = currentTeam->next;
    }
}

Team *minScoreTeam(Team *head){
    float min_score=head->teamPoints;
    Team *min_score_team=head;
    head=head->next;
    while(head!=NULL){
        if(head->teamPoints<min_score){
            min_score=head->teamPoints;
            min_score_team=head;
        }
        head=head->next;
    }
    return min_score_team;
}

bool powerOfTwo(int number){
    if(number==0)
        return false;
    if(ceil(log2(number))!=floor(log2(number)))
        return false;
    return true;
}

void theNewList(Team **head, int *teamsNumber){
    Team *findTeam=NULL;
    while(powerOfTwo(*teamsNumber)==false){
        findTeam= minScoreTeam(*head);
        deleteTeam(head,findTeam);
        (*teamsNumber)--;
    }
}
