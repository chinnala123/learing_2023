#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_SENSOR_NO_LENGTH 10
#define MAX_TIME_LENGTH 10

typedef struct {
    int entryNo;
    char sensorNo[MAX_SENSOR_NO_LENGTH];
    float temperature;
    int humidity;
    int light;
    char time[MAX_TIME_LENGTH];
} LogEntry;

int readLogFile(LogEntry logEntries[]) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the log file.\n");
        return 0;
    }

    char line[100];
    int numEntries = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL) {
        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%s",
               &entry.entryNo,
               entry.sensorNo,
               &entry.temperature,
               &entry.humidity,
               &entry.light,
               entry.time);

        logEntries[numEntries] = entry;
        numEntries++;

        if (numEntries >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);

    return numEntries;
}

void displayLogEntries(const LogEntry logEntries[], int numEntries) {
    printf("Log Entries:\n");
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].time);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = readLogFile(logEntries);

    displayLogEntries(logEntries, numEntries);

    return 0;
}
