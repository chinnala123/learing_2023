#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

void changeCase(char *buffer, char option) {
    int i;
    switch (option) {
        case 'u':
            for (i = 0; buffer[i] != '\0'; i++) {
                buffer[i] = toupper(buffer[i]);
            }
            break;
        case 'l':
            for (i = 0; buffer[i] != '\0'; i++) {
                buffer[i] = tolower(buffer[i]);
            }
            break;
        case 's':
            if (buffer[0] != '\0' && islower(buffer[0])) {
                buffer[0] = toupper(buffer[0]);
            }
            for (i = 1; buffer[i] != '\0'; i++) {
                buffer[i] = tolower(buffer[i]);
            }
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments. Usage: ./cp <option> <source_file> <target_file>\n");
        return 1;
    }

    char *option = argv[1];
    char *sourcePath = argv[2];
    char *targetPath = argv[3];

    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    FILE *targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Failed to open the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (option != NULL) {
            changeCase(buffer, option[0]);
        }
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");

    return 0;
}
