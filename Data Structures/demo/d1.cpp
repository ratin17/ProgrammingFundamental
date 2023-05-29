#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile;
    inputFile = fopen("demo\from.txt", "r");

    if (inputFile == NULL) {
        printf("File Not Found!\n");
        return 0;
    }

    FILE *outputFile;
    outputFile = fopen("demo\to.txt", "w");

    while (1) {
        char ch = fgetc(inputFile);
        if (ch == EOF) {
            break;
        }
        fputc(ch, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile); 

    return 0;
}