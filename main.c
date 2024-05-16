#include "Lan_Party_trees.h"

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Invalid data");
        exit(1);
    }

    char *input_1 = argv[1];
    char *input_2 = argv[2];
    char *output_3 = argv[3];

    printf("Input file 1: %s\n", input_1);
    printf("Input file 2: %s\n", input_2);
    printf("Output file: %s\n", output_3);

    FILE *readFile1 = fopen(input_1, "rt");
    if (readFile1 == NULL) {
        perror("Can't open this file");
        exit(1);
    }
    int var1 = 0, var2 = 0, var3 = 0, var4 = 0, var5 = 0;
    fscanf(readFile1, "%d%d%d%d%d", &var1, &var2, &var3, &var4, &var5);
    fclose(readFile1);
    Team *theTeam = NULL;
    int TeamsNumber = 0;

    if (var1 == 1 && var2 == 0) {
        theTeam = createTeamList(input_2, &TeamsNumber);
        TeamsPoints(theTeam);
        showTeamsList(theTeam, output_3);
        deleteTeamList(&theTeam);
    }
    if (var1 == 1 && var2 == 1 && var3 == 0) {
        theTeam = createTeamList(input_2, &TeamsNumber);
        TeamsPoints(theTeam);
        theNewList(&theTeam, &TeamsNumber);
        showTeamsList(theTeam, output_3);
        deleteTeamList(&theTeam);
    }
    if (var1 == 1 && var2 == 1 && var3 == 1 && var4 == 0) {
        theTeam = createTeamList(input_2, &TeamsNumber);
        TeamsPoints(theTeam);
        theNewList(&theTeam, &TeamsNumber);
        showTeamsList(theTeam, output_3);
        QueueMatch *theQueue;
        Team *TheEight = NULL;
        theQueue = CreateTheQueue(theTeam);
        TheFinalScore(theQueue, TeamsNumber, output_3, &TheEight);
        deleteTeamList(&TheEight);
    }
    if (var1 == 1 && var2 == 1 && var3 == 1 && var4 == 1 && var5 == 0) {
        theTeam = createTeamList(input_2, &TeamsNumber);
        TeamsPoints(theTeam);
        theNewList(&theTeam, &TeamsNumber);
        showTeamsList(theTeam, output_3);
        QueueMatch *theQueue;
        Team *TheEight = NULL;
        theQueue = CreateTheQueue(theTeam);
        TheFinalScore(theQueue, TeamsNumber, output_3, &TheEight);

        FILE *myfile = fopen(output_3, "at");
        if (myfile == NULL) {
            perror("Can't open this file");
            exit(1);
        }
        BST *tree = NULL;
        tree = CreateTheTree(TheEight);
        fprintf(myfile, "\nTOP 8 TEAMS:\n");
        ShowTheStandings(tree, myfile);
        deleteTheTree(tree);
        fclose(myfile);
    }
    if (var1 == 1 && var2 == 1 && var3 == 1 && var4 == 1 && var5 == 1) {
        theTeam = createTeamList(input_2, &TeamsNumber);
        TeamsPoints(theTeam);
        theNewList(&theTeam, &TeamsNumber);
        showTeamsList(theTeam, output_3);
        QueueMatch *theQueue;
        Team *TheEight = NULL;
        theQueue = CreateTheQueue(theTeam);
        TheFinalScore(theQueue, TeamsNumber, output_3, &TheEight);

        FILE *myfile = fopen(output_3, "at");
        if (myfile == NULL) {
            perror("Can't open this file");
            exit(1);
        }
        BST *tree = NULL;
        tree = CreateTheTree(TheEight);
        fprintf(myfile, "\nTOP 8 TEAMS:\n");
        ShowTheStandings(tree, myfile);

        Team *Inorderlist = NULL;
        InorderList(tree, &Inorderlist);
        BST *AVL = NULL;
        AVL = buildAVL(&Inorderlist, 0, 7);
        fprintf(myfile, "\nTHE LEVEL 2 TEAMS ARE: \n");
        printLevel(AVL, 3, myfile);
        deleteTheTree(AVL);
        fclose(myfile);
    }
}