//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

char *strtrim(char *str) {
    char *end;
    while (isspace((unsigned char) *str)) { //stergere spatii inceput
        str++;
    }
    if (*str == '\0') {
        return str;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) { //stergere spatii final
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

Team *createTeamList(char *input_2, int *TeamsNumber) {
    Team *theTeam = NULL;

    FILE *readFile = fopen(input_2, "rt");
    if (readFile == NULL) {
        perror("Can't open this file");
        exit(1);
    }

    int teamsNumber = 0;
    fscanf(readFile, "%d", &teamsNumber);
    *TeamsNumber = teamsNumber;
    char *teamName = (char *) malloc(DIM * sizeof(char));
    int membersNr = 0;
    while (teamsNumber != 0) {
        Player *thePlayer = NULL;
        membersNr = 0;
        fscanf(readFile, "%d", &membersNr); //citire nr membrii
        fscanf(readFile, " ");
        fscanf(readFile, "%[^\n]", teamName); //citire nume echipa
        strtrim(teamName);
        addAtBeginningTeam(&theTeam, teamName, membersNr);
        int points;
        char *name = (char *) malloc(DIM * sizeof(char));
        char *secondName = (char *) malloc(DIM * sizeof(char));
        while (membersNr != 0) {
            fscanf(readFile, "%s%s%d", name, secondName, &points); //citire nume/prenume/puncte
            addAtBeginningPlayer(&thePlayer, name, secondName, points);
            membersNr--;
        }
        teamsNumber--;
        theTeam->players = thePlayer; //adaugare adresa de inceput a listei thePlayer
        free(name);
        free(secondName);
    }
    free(teamName);
    fclose(readFile);
    return theTeam;
}

void showTeamsList(Team *theTeam, char *output_3) {
    FILE *printFile = fopen(output_3, "wt");
    if (printFile == NULL) {
        perror("Can't open this file");
        exit(1);
    }
    Team *ptr_team = theTeam;
    while (ptr_team != NULL) {
        fprintf(printFile, "%s\n", ptr_team->teamName);
        ptr_team = ptr_team->next;
    }
    fclose(printFile);
}