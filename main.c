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
    fscanf(readFile1, "%d%d%d%d%d", &var1, &var2, &var3, &var4, &var5); //variabile ce definesc operatiile ce trbuiesc realizate
    fclose(readFile1);
    Team *theTeam = NULL;
    int TeamsNumber = 0;

    if(var1==1){
        theTeam= createTeamList(input_2,&TeamsNumber);
        TeamsPoints(theTeam);
        if(var2==1){
            theNewList(&theTeam,&TeamsNumber);
            showTeamsList(theTeam, output_3);
        }
        else {
            showTeamsList(theTeam, output_3);
            deleteTeamList(&theTeam);
        }
        if(var3==1){
            QueueMatch *theQueue;
            Team *TheEight=NULL;
            theQueue=CreateTheQueue(theTeam);
            TheFinalScore(theQueue,TeamsNumber,output_3,&TheEight);
            if(var4==1){
                FILE *myfile = fopen(output_3, "at");
                if (myfile == NULL) {
                    perror("Can't open this file");
                    exit(1);
                }
                BST *tree = NULL;
                tree = CreateTheTree(TheEight);
                fprintf(myfile, "\nTOP 8 TEAMS:\n");
                ShowTheStandings(tree, myfile);
                if(var5==1){
                    Team *Inorderlist = NULL;
                    InorderList(tree, &Inorderlist);
                    BST *AVL = NULL;
                    AVL = buildAVL(&Inorderlist, 0, 7);
                    fprintf(myfile, "\nTHE LEVEL 2 TEAMS ARE: \n");
                    printLevel(AVL, 3, myfile);
                    deleteTheTree(AVL);
                    fclose(myfile);
                }
                else {
                    fclose(myfile);
                    deleteTheTree(tree);
                }
            }
            else{
                deleteTeamList(&TheEight);
            }
        }
        else {
            deleteTeamList(&theTeam);
        }
    }
}