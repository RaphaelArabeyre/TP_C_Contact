#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int askIfContinue() {
    char responce;

    printf("Would you stop ? (Y/N)\n");

    scanf("%s", &responce);

    if (responce == 'y' || responce == 'Y') {
        printf("Ok, Bye.");
        return -1;
    } else {
        return 1;
    }

}


void writeNameInFile(Contact *contact) {

    printf("Write a firstname :");
    scanf("%s", &contact->firstname);

    printf("Write a lastname :");
    scanf("%s", &contact->lastname);

    printf("Write a age :");
    scanf("%d", &contact->age);

}


int main() {

    FILE *file = fopen("../data.txt", "w");

    if (file == NULL) {
        fprintf(stderr, "\nError, can't open the file\n");
        exit(1);
    }

    Contact contact;
    writeNameInFile(&contact);

    printf("%s, %s (%d years old) has been added\n", &contact.firstname, &contact.lastname, contact.age);

    fwrite(&contact, sizeof(Contact), 1, file);


    while (askIfContinue() == 1) {

        writeNameInFile(&contact);

        fwrite(&contact, sizeof(Contact), 1, file);

        printf("%s, %s (%d years) has been added\n", &contact.firstname, &contact.lastname, contact.age);

    }

    fclose(file);

    return 0;
}


