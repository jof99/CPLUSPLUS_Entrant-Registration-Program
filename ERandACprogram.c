
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <mem.h>
#include <stdbool.h>
#define ISEMPTY printf("\n empty list:");
#define  MAX_LEN  80
#include "headerForERandACprogram.h"


//the linked list structure


char eventName[20];
char eventDate[20];

//initialised the functions


//main menu
/**
 * Main menu method takes user input and directs use to either the entrant registration program (4) or the analysis of results program (5)
 */

void main()
{
    int ch;

    while (1)
    {
        printf("=========================================================\n\n");
        printf("\t\tWelcome To The Ponterwyd Horticultural Competition Management Program!!\n\n");
        printf("=========================================================\n\n");
        printf("1. Entrant Registration Program\n\n");
        printf("2. Analysis Competition Results Program\n\n");
        printf("0. Exit\n\n");
        printf("=========================================================\n\n");
        printf("\nPlease enter your Choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1: {
                manageCompetitor();
                break;
            }
            case 2: {
                manageCompetition();
                break;
            }
            case 0: exit(0);
            default: printf("Valid choice not entered!");
        }

    }

}
/**
 * Manage competition menu is (5) of the problem that handles entering competitor results, producing results table and listing competitor addresses/
 */
void manageCompetition()
{
    int choice;

    while (1)
    {
        printf("=========================================================\n\n");
        printf("\t\t WELCOME TO THE COMPETITION RESULTS ANALYSIS PROGRAM!!\n\n");
        printf("=========================================================\n\n");
        printf("1. Open Competitor File\n\n");
        printf("2. Enter Competition Vegetable Results\n\n");
        printf("3. Produce Results Table\n\n");
        printf("4. List Competitor Address\n\n");
        printf("0. Back\n\n");
        printf("=========================================================\n\n");
        printf("\nPlease enter your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: {
                loadCompetitorFile();
                break;
            }
            case 2:{
                addVegResultMenu();
            }
                break;
            case 3:{
                displayVegetableResultsTable();
                break;
            }
            case 4:{
                displayCompetitorAddressPhoneData();
                break;
            }
            case 0:{
                return;
            }
            default: printf("Valid choice not entered!");

        }

    }
}
/**
 * Method allows user to add vegetable sizes based on competitor ID.
 */
void addVegResultMenu()
{
    int id = 0;
    double cucumberSize = 0;
    double carrotSize = 0;
    double runnerBeanSize = 0;
    double totalLength = cucumberSize + carrotSize + runnerBeanSize;
    int choice;
    while (1)
    {
        printf("=========================================================\n\n");
        printf("\t\t WELCOME TO COMPETITION RESULTS PROGRAM\n\n");
        printf("=========================================================\n\n");
        printf("1. Enter Competitor ID\n\n");
        printf("2. Enter Cucumber Size Inches\n\n");
        printf("3. Enter Carrot Size Inches\n\n");
        printf("4. Enter Runner Bean Size Inches\n\n");
        printf("0. Back\n\n");
        printf("=========================================================\n\n");
        printf("\nPlease enter your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: {
                    printf("\nEnter Competitor ID: ");
                    scanf("%d", &id);
                break;
            }
            case 2:{
                printf("\nEnter the Cucumber Size Inches: ");
                scanf("%lf", &cucumberSize);
                break;
            }
            case 3:{
                printf("Enter Carrot Size Inches: ");
                scanf("%lf", &carrotSize);
                break;
            }
            case 4:{
                printf("\nEnter Runner Bean Size Inches: ");
                scanf("%lf", &runnerBeanSize);
                break;
            }
            case 0:{
                return;
            }
            default: printf("Valid choice not entered!");

        }

        // In order for the vegetable lengths to be updated to the file user must fill all sized where then the total size will be calculated
        if(cucumberSize > 0 && carrotSize > 0 && runnerBeanSize > 0 && id > 0) {
            printf("All Results Full.. Updating Competitor Results!\n");
            updateVegetableLengths(id,cucumberSize,carrotSize,runnerBeanSize,totalLength);
        } else {
            printf("Finish adding all vegetable lengths! And ensure competitor Id has been selected\n");
        }

    }
}

/**
 * Entrant registration program main menu.
 * Ensures file must be selected when adding competitor to database
 */
void manageCompetitor()
{
    FILE *stream;
    int competitorID = generateUniqueCompetitorId(), choice;
    int competitorAge = 0;
    char firstName[60],secondName[60],competitorAgeString[60],competitorPostalAddress[60],competitorPhoneNumber[60], userSpecifiedFileName[60];
    itoa(competitorAge, competitorAgeString, 10);
    while (1)
    {
        printf("=========================================================\n\n");
        printf("\t\t WELCOME TO THE ENTRANT REGISTRATION PROGRAM!!\n\n");
        printf("=========================================================\n\n");
        printf("1. Add New Competitor\n\n");
        printf("2. Display All Competitors\n\n");
        printf("3. Open Competitor File\n\n");
        printf("4. Save To File\n\n");
        printf("0. Back\n\n");
        printf("=========================================================\n\n");
        printf("\nPlease enter your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: {

                printf("\nEnter the name of the file you would like to save too: \n");

                scanf("%s", userSpecifiedFileName);

                stream = fopen(userSpecifiedFileName, "r");

                if( stream != NULL) {
                    printf("File %s .txt has been opened successfully\n", userSpecifiedFileName);
                    printf("=========================================================\n\n");
                    printf("\t\t ADD COMPETITOR TO TEXT FILE!!\n\n");
                    printf("=========================================================\n\n");
                    printf("\nEnter the first name: ");
                    scanf("%s", firstName);
                    printf("\nEnter the second name: ");
                    scanf("%s", secondName);
                    printf("\nEnter the age: ");
                    scanf("%d", &competitorAge);
                    printf("\nEnter the competitor postal address: ");
                    scanf("%s", competitorPostalAddress);
                    printf("\nEnter the competitor phone number: ");
                    scanf("%s", competitorPhoneNumber);
                    //write to file function call that takes 5 parameters
                    printf("\nCompetitor Stored in memory! Press save to save data to file!\n");
                } else {
                    printf("File does not exist!\n");
                }
                break;
            }
            case 2:{
                displayCompetitorData();
                break;
            }
            case 3:{
                loadCompetitorFile();
                break;
            }
            case 4:{
                saveCompetitorToFile(userSpecifiedFileName,firstName, secondName,competitorAge, competitorPostalAddress, competitorPhoneNumber,competitorID);
                break;
            }
            case 0:{
                return;
            }
            default: printf("Valid choice not entered!");

        }

    }
}
/**
 * Updates the vegetables lengths based on competitor ID
 * @param id
 * @param cucumberLength
 * @param carrotLength
 * @param runnerBeanLength
 * @param totalLength
 */
void updateVegetableLengths(int id, double cucumberLength, double carrotLength, double runnerBeanLength, double totalLength)
{
    if (first == NULL)
    {
        printf("Empty!");
    }
    else
    {
        for (ptr = first; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->competitorID == id)
            {
                ptr->cucumberLength = cucumberLength;
                ptr->carrotLength = carrotLength;
                ptr->runnerBeanLength = runnerBeanLength;
                ptr->totalLength = totalLength;


            }
        }
    }
}
/**
 * function that initialises the competitor data.
 * @param firstName
 * @param secondName
 * @param competitorAge
 * @param competitorPostalAddress
 * @param competitorPhoneNumber
 * @param competitorID
 * @return
 */
snode* createCompetitorNode(char *firstName, char *secondName, int competitorAge, char *competitorPostalAddress, char *competitorPhoneNumber,int competitorID)
{
    //allocated uninitialised storage
    newnode=(snode*)malloc(sizeof(snode));
    if(newnode==NULL)
    {
        printf("\nSorry, no competitors.");
        return 0;
    }
    else
    {
        // initises the variables
        strcpy(newnode->firstName,firstName);
        strcpy(newnode->secondName, secondName);
        newnode->competitorAge=competitorAge;
        strcpy(newnode->competitorPostalAddress, competitorPostalAddress);
        strcpy(newnode->competitorPhoneNumber, competitorPhoneNumber);
        newnode->competitorID=competitorID;
        return newnode;
    }
}
/**
 * This method displays the vegetable lengths for a competitor in a table format.
 */
void displayVegetableResultsTable()
{
    if (first == NULL)
    {
        ISEMPTY;
        getch();
        return main();
    }
    else
    {
        printf("=========================================================\n\n");
        printf("\t\t Competitor Details\n\n");
        printf("=========================================================\n\n");
        printf("\t\t Event Name: %s Event Date: %s\n\n", eventName, eventDate);
        printf("NAME\t\tCompetitor Number\t\tCucumber\t\tCarrot\t\tRunner Bean:\t\t \n");
        for (ptr = first; ptr != NULL; ptr = ptr->next) {
            printf("%s %s\t\t%d\t\t%lf\t\t%lf\t\t%lf\t\n",ptr->firstName, ptr->secondName,ptr->competitorID ,ptr->cucumberLength, ptr->carrotLength,ptr->runnerBeanLength);

        }
        printf("=========================================================\n\n");
        printf("PRESS ANY KEY TO RETURN\n\n");
    }
    getch();
}

/**
 * This method displays a competitors address and postal address data.
 */
void displayCompetitorAddressPhoneData()
{
    if (first == NULL)
    {
        //if the first element is empty then the list is assumed empty then the main function is called again.
        ISEMPTY;
        getch();
        return main();
    }
    else
    {
        printf("=========================================================\n\n");
        printf("\t\t Competitor Details\n\n");
        printf("=========================================================\n\n");
        //event name and date is stored in global variables at when the file is loaded and access again in displays.
        printf("\t\t Event Name: %s Event Date: %s\n\n", eventName, eventDate);
        //loop through the linked list and print the relevant data nodes
        for (ptr = first; ptr != NULL; ptr = ptr->next) {
            printf("Competitor Name: %s %s\nPostal Address: %s\nTelephone: %s\t \n", ptr->firstName, ptr->secondName,ptr->competitorPostalAddress, ptr->competitorPhoneNumber);

        }
        printf("=========================================================\n\n");
        printf("PRESS ANY KEY TO RETURN\n\n");
    }
    getch();
}

void displayCompetitorData()
{
    if (first == NULL)
    {
        ISEMPTY;
        printf("List empty load a file first!\n");
        getch();
        return main();
    }
    else
    {
        printf("=========================================================\n\n");
        printf("\t\t Competitor Details\n\n");
        printf("=========================================================\n\n");
        printf("\t\t Event Name: %s Event Date: %s\n\n", eventName, eventDate);
        printf("First Name\t Second Name\t Competitor Number\t Age.\n\n");
        for (ptr = first; ptr != NULL; ptr = ptr->next) {
            printf("%s\t\t %s\t\t %d\t\t %d\t\t \n", ptr->firstName, ptr->secondName,ptr->competitorID, ptr->competitorAge);

        }
        printf("=========================================================\n\n");
        printf("PRESS ANY KEY TO RETURN\n\n");
    }
    getch();
}
/**
 * Determins the posistion of the competitor in the data structure for ret
 * @param id
 * @return the id
 */
int positionOfCompetitor(int id)
{
    int pos = 0;

    if (first == NULL)
    {
        return pos;
    }
    else
    {
        //Loop through all the id if id = id we are looking for.
        for (ptr = first; ptr != NULL; ptr = ptr->next)
        {
            pos = pos + 1;
            if (ptr->competitorID == id)
            {
                return pos;
            }
        }

    }

}
//temporary variables that the list is stored in.

#define NUM_OF_STRINGS 2
#define STRING_LENGTH 64
/**
 * This method loads the competitor file specified by the user and saves the
 */
void loadCompetitorFile() {

    FILE *stream;

    char firstName[MAX_LEN];
    char secondName[MAX_LEN];
    int competitorAge = 0;
    char competitorPostalAddress[MAX_LEN];
    char competitorPhoneNumber[MAX_LEN];
    int competitorNumber = 0;
    char userSpecifiedCompetitorFile[MAX_LEN];

    printf("\nEnter the name of the file to load. For example (hort_2022.txt): ");

    scanf("%s", userSpecifiedCompetitorFile);

    stream = fopen(userSpecifiedCompetitorFile, "r");


    //check the file exists
    if( stream != NULL) {


        /* Put in various data. */
        fscanf(stream, "%[^\n] %[^\n]", &eventName[0], &eventDate[0]);

        int loaded =0;
        int pos,cnt=0,i;
        // until the end of the file is reached loops through and stores competitor entries in temporary variables.
        while (!feof(stream)){

            fscanf(stream, "%s", firstName);
            fscanf(stream, "%s", secondName);
            fscanf(stream, "%d", &competitorAge);
            //gets the text line including spaces for the postal code and phone number
            fscanf(stream, "\t%[^\n\t]", competitorPostalAddress);
            fscanf(stream, "\t%[^\n\t]", competitorPhoneNumber);
            fscanf(stream, "%d", &competitorNumber);
            //Loaded variable if it's not equal to 0 then it indicates the file has been opened
            loaded++;
            pos = positionOfCompetitor(competitorNumber);
            newnode = createCompetitorNode(firstName, secondName, competitorAge, competitorPostalAddress, competitorPhoneNumber, competitorNumber);
            if (pos == 0) {

                if (first == last && first == NULL) {
                    first = last = newnode;
                    first->next = NULL;
                    last->next = NULL;
                } else {
                    temp = first;
                    first = newnode;
                    first->next = temp;
                }

            } else {

                ptr = first;

                while (ptr != NULL) {
                    ptr = ptr->next;
                    cnt++;
                }

                if (pos == 1) {
                    if (first == last && first == NULL) {
                        first = last = newnode;
                        first->next = NULL;
                        last->next = NULL;
                    } else {
                        temp = first;
                        first = newnode;
                        first->next = temp;
                    }
                } else if (pos > 1 && pos <= cnt) {
                    ptr = first;
                    for (i = 1; i < pos; i++) {
                        prev = ptr;
                        ptr = ptr->next;
                    }
                    prev->next = newnode;
                    newnode->next = ptr;
                } else {
                    printf("Competitor Not Found!!\n");
                }
            }



        }
        //loaded test if the file has been opened successfully then loaded + 1;
        if(loaded > 0) {
            printf("\nFile successfully loaded\n");
            loaded = true;
        }

        fclose(stream);

    } else {
        // file doesn't exist
        printf("\nFile not found");
        loadCompetitorFile();
    }



}
/**
 * This method checks if the id exists already, if it does it is ++ by 1 till it does not exist
 * @param id
 * @return
 */
bool checkIfIdExists(int id) {
    for (ptr = first; ptr != NULL; ptr = ptr->next) {
        if (ptr->competitorID == id) {
            // id already exists
            return true;
        }
    }
    return false;
}
/**
 * This method generates a unique id for each competitor
 * @return returns the id generated
 */
int generateUniqueCompetitorId() {
    int id = 1;
    while (true) {
        id++;
        // continue looping if id already exists
        if(checkIfIdExists(id)) {
            continue;
        }
        // else return the id
        return id;
    }

}

/**
 *
 * @param userSpecifiedFileName user input of file name
 * @param firstName competitor first name
 * @param secondName competitor second name
 * @param competitorAge competitor age as integer
 * @param competitorPostalAddress competitors postal address
 * @param competitorPhoneNumber competitors phone number
 * @param competitorNumber competitors id number
 *
 * This funtion takes the competitor data and the file name to save the data too
 *
 */
void saveCompetitorToFile(char* userSpecifiedFileName, char *firstName, char *secondName, int competitorAge, char *competitorPostalAddress, char *competitorPhoneNumber, int competitorNumber) {

    //used to convert the id and age integer into string so it can be added to the text file without problem.
    char competitorIdString[20];
    char competitorAgeString[20];

    FILE *fp = fopen(userSpecifiedFileName,"a");

    fputs(strcat( firstName, "\n"), fp);

    fputs(strcat( secondName, "\n"), fp);

    itoa(competitorAge, competitorAgeString, 10);
    fputs(strcat( competitorAgeString, "\n"), fp);

    fputs(strcat( competitorPostalAddress, "\n"), fp);

    fputs(strcat( competitorPhoneNumber, "\n"), fp);

    itoa(competitorNumber, competitorIdString, 10);
    fputs(strcat( competitorIdString, "\n"), fp);


    fflush(stdin);
    fclose(fp);
}