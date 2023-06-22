#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateTimeDifference(struct Time start, struct Time end) {
    struct Time diff;
    int startSeconds, endSeconds, timeDiff;
    startSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    
    
    endSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;
    timeDiff = endSeconds - startSeconds;
    diff.hours = timeDiff / 3600;
    timeDiff %= 3600;
    diff.minutes = timeDiff / 60;
    diff.seconds = timeDiff % 60;
    
    return diff;
}

int main() {
    struct Time startTime, endTime, timeDiff;
    
    printf("Enter start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    
    printf("Enter end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    
    timeDiff = calculateTimeDifference(startTime, endTime);
    
    printf("Time difference: %d hours %d minutes %d seconds\n", timeDiff.hours, timeDiff.minutes, timeDiff.seconds);
    
    return 0;
}
