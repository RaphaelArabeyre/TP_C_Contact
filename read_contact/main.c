#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main() {

    FILE* file;
    Contact contact;
    file = fopen ("../data.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "\nError, can't open the file\n");
        exit (1);
    }

    int count = 0;

    while(fread(&contact, sizeof(Contact), 1, file)){
        printf("firstname : %s, lastname : %s, %d years old\n", &contact.firstname, &contact.lastname, contact.age);
        count++;
    }

    printf("End of : %d contacts", count);

    fclose (file);

    return 0;
}
