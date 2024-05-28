//
// Created by Alexandru Mihalache on 02.05.2024.
//

#include "Lan_Party_header.h"

char *strtrim(char *string) {
    while (isspace(*string)) { //stergere spatii goale inceput
        string++;
    }
    if (*string == '\0') {
        return string;
    }
    char *end;
    end = string + strlen(string) - 1; //pozitionare ultim caracter ce nu este spatiu
    while (end > string && isspace(*end)) { //stergere spatii goale final
        end--;
    }
    *(end + 1) = '\0';
    return string;
}

Team *createTeamList(char *input_2, int *TeamsNumber) {
    Team *theTeam = NULL;

    FILE *readFile = fopen(input_2, "rt");
    if (readFile == NULL) {
        perror("Can't open this file");
        exit(1);
    }

    int teamsNumber = 0;
    fscanf(readFile, "%d", &teamsNumber); //citire numar echipe
    *TeamsNumber = teamsNumber;
    char *teamName = (char *) malloc(DIM * sizeof(char));
    int membersNr = 0;
    while (teamsNumber != 0) {
        Player *thePlayer = NULL;
        membersNr = 0;
        fscanf(readFile, "%d", &membersNr); //citire nr membrii
        fscanf(readFile, " ");
        fscanf(readFile, "%[^\n]", teamName); //citire nume echipa (citire pana la \n)
        strtrim(teamName);
        addAtBeginningTeam(&theTeam, teamName, membersNr);
        float points;
        char *name = (char *) malloc(DIM * sizeof(char));
        char *secondName = (char *) malloc(DIM * sizeof(char));
        while (membersNr != 0) {
            fscanf(readFile, "%s%s%f", name, secondName, &points); //citire nume/prenume/puncte
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