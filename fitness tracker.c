#include <stdio.h>

#define NUM_ACTIVITIES 3 // Number of activities
#define NUM_DAYS 7 // Number of days for the analysis
char *performance(float avg);
void print(int exercise_data[NUM_ACTIVITIES][NUM_DAYS], char activities[NUM_ACTIVITIES][50]);
int main() {


    //Predefined sample exercise data (in minutes)
    int exercise_data[NUM_ACTIVITIES][NUM_DAYS];
    char activities[NUM_ACTIVITIES][50];

    printf("Enter name of activities:\n");
    for (int i = 0; i < NUM_ACTIVITIES; i++) {
        printf("Activity #%d: ", i + 1);
        scanf("%s", activities[i]);
    }

    printf("\n");

    for (int i = 0; i < NUM_ACTIVITIES; i++) {
        printf("Exercise Data for %s:\n", activities[i]);
        for (int j = 0; j < NUM_DAYS; j++) {
            printf("Enter exercise data: ");
            scanf("%d", &exercise_data[i][j]);
        }
        printf("\n");
    }

    float activity_avg[NUM_ACTIVITIES], overall, sum = 0;
    // Calculate average duration per activity

    for (int i = 0; i < 3; i++) {
        float avg = 0;
        for (int j = 0; j < 7; j++) {
            avg += (float)exercise_data[i][j];
        }
        activity_avg[i] = avg / 7;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            sum += (float)exercise_data[i][j];
        }
    }

    overall = sum / (NUM_ACTIVITIES * NUM_DAYS);

    print(exercise_data, activities);

    for (int i = 0; i < NUM_ACTIVITIES; i++) {
        printf("Activity %d:\n", i + 1);
        printf("Average Duration: %.1f\n", activity_avg[i]);
        printf("Recomendation: %s\n", performance(activity_avg[i]));
    }

    printf("Overall Performance:\n");
    printf("Average Duration: %.1f\n", overall);

    if (overall < 40) {
        printf("Recommendation: Increase overall exercise intensity for better results.\n");
    } else {
        printf("Recommendation: Maintain current level.\n");
    }

    return 0;
}

char *performance(float avg)
{
    if (avg < 40) {
        return "Increase intensity for better results.\n";
    } else {
        return "Maintain current level.\n";
    }
}

void print(int exercise_data[NUM_ACTIVITIES][NUM_DAYS], char activities[NUM_ACTIVITIES][50])
{
    printf("Exercise Data:\n");
    for (int i = 0; i < NUM_ACTIVITIES; i++) {
        printf("%s: ", activities[i]);
        for (int j = 0; j < NUM_DAYS; j++) {
            printf("%d  ", exercise_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
