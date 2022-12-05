#include <stdio.h>

#include "hashing.h"

int main(void)
{
    char command[10], string[20];

    while(scanf("%s %s", command, string) == 2) {
        switch(command[0]) {
        case 'i':
            printf("Insert \"%s\"\n", string);
            insert(string);
            break;
        case 's':
            printf("Search \"%s\": %s\n", string,
                   find(string) ? "found" : "not found");
            break;
        default:
            printf("Huh?\n");
            break;
        }
    }
}
