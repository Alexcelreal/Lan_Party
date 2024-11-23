# LanParty - Tema 1 in cadrul disciplinei "Proiectarea Algoritmilor"

Acest proiect are ca scop implementarea notiunilor dobandite in urma laboratorului si cursului de Proiectarea Algoritmilor.

## Cuprins

1. [Descriere](#descriere)
2. [Structura Proiectului](#structura-proiectului)
3. [Taskuri realizate](#taskuri-realizate)
    - [Task 1](#task-1)
      - [Functii Utilizate T1](#functii-utilizate-1)
    - [Task 2](#task-2)
      - [Functii Utilizate T2](#functii-utilizate-2)
    - [Task 3](#task-3)
      - [Functii_Utilizate T3](#functii-utilizate-3)
    - [Task 4](#task-4)
      - [Functii_Utilizate T4](#functii-utilizate-4)
    - [Task 5](#task-5)
      - [Functii Utilizate T5](#functii-utilizate-5)
4. [Cerinte de sistem](#cerinte-de-sistem)
5. [Utilizare](#utilizare)

## Descriere
- Programul creat implementeaza o simulare a unui turneu de gayming (Lan Party), unde echipele sunt eliminate progresiv, in functie de scor. Va exista un unic castigator.
La final, ultimele 8 echipe ramase vor fi ierarhizate si afisate in functie de rezultatul obtinut.(Se urmareste manipularea unui arbore BST si AVL). 
- Fisierele `.c` contin functiile utilizate, iar fisierele `.h` (headerele) contin antetele functiilor, bibliotecide utilizate si structurile de date necesare programului.

## Structura Proiectului
```
├── CMakeLists.txt
├── Lan_Party_header.h
├── Lan_Party_trees.h
├── Lists.c
├── Makefile
├── Queues.c
├── README_LanParty.md
├── ReadfromFile.c
├── Stacks.c
├── TheLastEightAVL.c
├── TheLastEightBST.c
├── checker.sh
├── cmake-build-debug
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── Testing
│   ├── build.ninja
│   └── cmake_install.cmake
├── date
│   ├── t1
│   ├── ...
├── eliminateLowPoints.c
├── main.c
├── out
│   ├── out1.out
│   ├── ...
├── r.out
├── rezultate
│   ├── r1.out
│   ├── ...
└── theRealCompetition.c
```

## Taskuri realizate:
### Task 1:
    Fisier: ReadfromFile.c
Citirea din fisierul date/tn/d.in a datelor si afisarea acestora;

#### Functii Utilizate 1:
    Team *createTeamList(char *input_2, int *TeamsNumber)
- Crearea unei liste de echipe; 
- Atribuirea unei liste de jucatori (ce contine date despre acestia) fiecarei echipe din lista principala;


    char *strtrim(char *string)
- Stergerea spatiilor goale de la inceputul si finalul fiecarui string;
- Stergere "\n";

  
    void showTeamsList(Team *theTeam, char *output_3)
- Afisarea continutului listei de echipe;

### Task 2:
    Fisier: eliminateLowPoints.c
Stergerea echipelor cu punctaj minim, pana cand numarul de echipe este o putere a lui 2; Afisarea echipelor ramase.

#### Functii Utilizate 2:
    void TeamsPoints(Team *head)
- Calculeaza numarul total de puncte al fiecarei echipe, in functie de punctele obtinute de fiecare jucator;
- Modifica valorile `teamPoints` ale fiecarei echipe;


    Team *minScoreTeam(Team *head)
- Identifica echipa cu cel mai mic scor din lista;
- Returneaza pointer catre echipa cu cel mai mic scor;


    bool powerOfTwo(int number)
- Verifica daca un numar este putere a lui 2
- Returneaza `true` daca `number` este o putere a lui 2, altfel `false`;


    void theNewList(Team **head, int *teamsNumber)
- Elimina echipele cu cel mai mic scor, apeland functia `deleteTeam(Team **head, Team *findTeam)`, pana cand numarul de echipe este o putere a lui 2;

### Task 3:
    Fisier: theRealCompetition.c
Afisarea meciurilor intre echipe si castigatorii acestora, pana la cel victorios, utilizand doua stive win/lost, lista rezultata de la taskul anterior si o coada ce contine echipele ce trec in urmatoarea etapa eliminatorie. 
Pentru victorie se adauga un punct la fiecare echipa, punct ce va fi distribuit fiecarui jucator (1/nr de juactori din echipa).
Ultimele 8 echipe ramase vor fi adaugate intr-o noua lista, necesara la taskul 4.

#### Functii Utilizate 3:
    void addSpace(char *str, FILE *myfile)
- Adaugare spatii in fisier pentru formatare, in functie de numarul de caractere al stringului introdus ca parametru;


    QueueMatch *CreateTheQueue(Team *theTeam)
- Creaza coada initiala, utilizand lista de echipe de la taskul precedent;
- Returneaza adresa cozii create;


    void modifyPlyPoint(Player *thePlayer, int teamMembers)
- Modifica punctajele jucatorilor unei echipe dupa ce echipa a castigat un meci;


    void showtheTable(QueueMatch *Match, Team **win, Team **lost, FILE *myfile)
- Afiseaza meciurile si actualizeaza stivele win/ lost;
- Se extrag cate 2 echipe din coada de meciuri, pana cand aceasta este goala, iar acestea sunt redistribuite in functie de penctaj catre stiva win sau lost;
- Daca punctajele sunt egale se va alege a doua echipa adaugata in meciul disputat;

    
    void RestoreData(Team **win, Team **lose, QueueMatch **Match, FILE *myfile)
- Muta datele din stiva de castigatori in coada de meciuri, utilizand o coada ajutatoare, si afiseaza castigatorii rundei precedente;
- Se sterg echipele din stiva `lost`, utilizand functia `deleteStack(Team **Top)`;

  
    Team *TheLastEight(QueueMatch **Match)
- Creaza o lista cu ultimele 8 echipe din coada meciurilor;
- Returneaza adresa de inceput a noii liste;

    
    void TheFinalScore(QueueMatch *Match, int TeamsNumber, char *output_3, Team **TheEight)
- Calculeaza numarul de runde in functie de numarul de participanti si afiseaza rezultatele finale pentru fiecare etapa, apeland functiile descrise anterior;

### Task 4:
    Fisier: TheLastEightBST.c
Generare arbore BST, utilizand lista de la Taskul 3, si afisarea echipelor in ordine descrescatoare punctajelor.

#### Functii Utilizate 4:
    bool verifyCond(float score1, float score2, char *name1, char *name2)
- Verifica conditiile pentru a determina ordinea intr-un BST;
- Returneaza TRUE daca conditia este indeplinita, altfel FALSE;


    BST *Insert(BST *node, Team *theTeam)
- Insereaza o echipa intr-un BST in functie de punctaj si nume;
- Returneaza pointer catre arborele modificat;

     
    BST *CreateTheTree(Team *theEight)
- Creaza un BST utilizant lista initiala;
- Returneaza pointer catre radacina arborelui creat;


    void ShowTheStandings(BST *root, FILE *myfile)
- Parcurge arborele in inordine in sens invers (DRS) si afiseaza echipele si punctajele lor intr-un fisier;

### Task 5:
     Fisier: TheLastEightAVL.c
Generare arbore AVL utilizand o lista ,rezultata in urma parcurgerii in inordine a arborelui de la taskul 4, si afisarea echipelor de pe nivelul 2 al arborelui AVL.

#### Functii Utilizate 5:
    void InorderList(BST *root, Team **theTeam)
- Parcurge un arbore BST in inordine si adauga echipele intr-o lista;


    BST *buildAVL(Team **theTeam, int start, int finish)
- Construieste un arbore AVL, utilizand o lista de echipe ordonata crescator in functie de punctaje;
- Este folosita metoda divide et impera;
- Returneaza pointer catre radacina arborelui AVL construit;


    void printLevel(BST *root, int level, FILE *myfile)
- Afiseaza echipele din arbore de la un anumit nivel;

## Cerinte de sistem:
- Sistem de operare: Linux, macOS, Windows
- Compilator: GCC
- CMake: Versiunea 3.10 sau mai noua
- Spatiu pe Disc: Minimum 100MB
- Memorie RAM: Minimum 512 MB

## Utilizare
- Functia `main` din acest program gestioneaza fluxul principal de executie al programului LanParty;
- Aplicatia citeste informatiile din fisierele c.in si d.in al fiecarui test;
- In fisierul c.in se afla 5 variabile, ce conditioneaza executia unui anumit task: 1- executie/ 0- nu se executa;
- In fisierul d.in se afla informatii in legatura cu: numarul de echipe, numele acestora, informatii despre membrii echipei ...;
- Fiecare task este dependent de taskul anterior;
- Pentru a compila programul se va scrie in terminal comanda `make build`;
- Pentru a rula programul se va scrie in terminal comanda `make run` (doar pentru un test specificat);
- Pentru a rula testul dorit se vor face modificari in urmatoarea linie de cod din Makefile: `./lanParty date/tn/c.in date/tn/d.in r.out`, unde n reprezinta numarul taskului;
- Pentru a rula checkerul se va scrie in terminal comanda `.\checker.sh`;
- Pentru a vizualiza rezultatul se acceseaza fisierul r.out;
- Pentru a sterge fisierul executabil si fisierul r.out se va scrie in terminal comanda `make clean`;


