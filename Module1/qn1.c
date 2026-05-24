#include <stdio.h>
#include <string.h>

#define DAYS 7
#define MAX_TASKS 3
#define TASK_LEN 50

struct Day {
    char dayName[20];
    char tasks[MAX_TASKS][TASK_LEN];
    int taskCount;
};

int main() {
    struct Day week[DAYS] = {
        {"Monday", {}, 0},
        {"Tuesday", {}, 0},
        {"Wednesday", {}, 0},
        {"Thursday", {}, 0},
        {"Friday", {}, 0},
        {"Saturday", {}, 0},
        {"Sunday", {}, 0}
    };

    int dayChoice, numTasks, i;

    printf("Select a day (0-Monday to 6-Sunday): ");
    scanf("%d", &dayChoice);

    if(dayChoice < 0 || dayChoice >= DAYS) {
        printf("Invalid day selection.\n");
        return 0;
    }

    printf("Enter number of tasks (max 3): ");
    scanf("%d", &numTasks);

    if(numTasks > MAX_TASKS)
        numTasks = MAX_TASKS;

    getchar();

    for(i = 0; i < numTasks; i++) {
        printf("Enter task %d: ", i + 1);
        fgets(week[dayChoice].tasks[i], TASK_LEN, stdin);

        week[dayChoice].tasks[i][strcspn(
            week[dayChoice].tasks[i], "\n")] = '\0';
    }

    week[dayChoice].taskCount = numTasks;

    printf("\n--- Weekly Tasks ---\n");

    for(i = 0; i < DAYS; i++) {
        printf("\n%s:\n", week[i].dayName);

        if(week[i].taskCount == 0) {
            printf("No tasks\n");
        } else {
            for(int j = 0; j < week[i].taskCount; j++) {
                printf("- %s\n", week[i].tasks[j]);
            }
        }
    }

    return 0;
}
