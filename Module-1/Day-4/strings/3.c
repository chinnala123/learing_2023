#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char timeStr[9];
    int hours, minutes, seconds, totalSeconds;
    printf("Enter time in hh:mm:ss format: ");
    fgets(timeStr, sizeof(timeStr), stdin);
    sscanf(timeStr, "%d:%d:%d", &hours, &minutes, &seconds);
    totalSeconds = hours * 3600 + minutes * 60 + seconds;

    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}
