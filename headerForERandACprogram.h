//
// Created by Joel on 08/08/2022.
//

#ifndef ASSIGNMENTC2022_ENTRANTREGISTRATIONPROGRAMHEADER_H
#define ASSIGNMENTC2022_ENTRANTREGISTRATIONPROGRAMHEADER_H

#endif //ASSIGNMENTC2022_ENTRANTREGISTRATIONPROGRAMHEADER_H

// competitor data structure
struct competitorNode
{
    int competitorID;
    char firstName[60];
    char secondName[60];
    int competitorAge;
    char competitorPostalAddress[60];
    char competitorPhoneNumber[60];
    double cucumberLength;
    double carrotLength;
    double runnerBeanLength;
    double totalLength;
    struct competitorNode *next;
};

typedef struct competitorNode snode;
//node pointers for traversal
snode *newnode, *ptr, *prev,*temp,*first= NULL,*last = NULL;

//function definitions
snode* createCompetitorNode(char *firstName, char *secondName,int competitorAge, char *competitorPostalAddress, char *competitorPhoneNumber, int competitorNumber);
void updateVegetableLengths(int id, double cucumberLength, double carrotLength, double runnerBeanLength, double totalLength);
void manageCompetitor();
void manageCompetition();
void displayCompetitorAddressPhoneData();
int positionOfCompetitor(int id);
void addVegResultMenu();
void displayVegetableResultsTable();
void displayCompetitorData();
void loadCompetitorFile();
int generateUniqueCompetitorId();
bool checkIfIdExists(int id);
void saveCompetitorToFile(char* userSpecifiedFileName,char firstName[60], char secondName[60], int competitorAge, char competitorPostalAddress[60], char competitorPhoneNumber[60],int competitorNumber);