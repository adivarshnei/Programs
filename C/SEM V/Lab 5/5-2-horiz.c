// 5-2. Write a program to solve Activitiy Selection Problem using Greedy
// Approach

// Included Libraries
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Memory operations and atoi()

// Macro Definitions
#define ACTIVITY_COUNT_STR \
    argv[1]  // Command line argument for number of activities
/**
 * @brief Macro to swap @p A and @p B
 * @param A First Activity
 * @param B Second Activity
 */
#define ACTIVITYSWAP(A, B)    \
    struct Activity temp = A; \
    A                    = B; \
    B                    = temp;

/** @brief Structure to model an Activity Selection Problem item */
struct Activity {
    int name;   // Name of the activity
    int start;  // Starting time of the activity
    int end;    // Ending time of the activity
};

/**
 * @brief Sort @p activites on the basis of their respective end times via
 * bubble sort
 * @param activities Array of activities
 * @param len Number of @p activities
 */
void sort_activities(struct Activity* activities, int len);
/**
 * @brief Print specified @p activities
 * @param activities Array of activities
 * @param len Number of @p activities
 */
void print_activities(struct Activity* activities, int len);
/**
 * @brief Prints the schedule from the @p slots information
 * @param slots Array of populated timeslots
 * @param slot_count Number of @p slots
 */
void print_schedule(int* slots, int slot_count);
/**
 * @brief Solves the Activity Selection Problem via greedy approach on the @p
 * activities array
 * @param activities Array of activities
 * @param len Number of @p activities
 */
void activity_select(struct Activity* activities, int len);

int
main(int argc, char** argv) {
    // If no activity is mentioned, skip execution of program
    if ( ! ACTIVITY_COUNT_STR ) {
        return 0;
    }

    // Initialize activities
    struct Activity activities[] = {
        { .name = 1,  .start = 1,  .end = 3},
        { .name = 2,  .start = 2,  .end = 5},
        { .name = 3,  .start = 3,  .end = 4},
        { .name = 4,  .start = 4,  .end = 7},
        { .name = 5,  .start = 7, .end = 10},
        { .name = 6,  .start = 8,  .end = 9},
        { .name = 7,  .start = 9, .end = 11},
        { .name = 8,  .start = 9, .end = 13},
        { .name = 9, .start = 11, .end = 12},
        {.name = 10, .start = 12, .end = 14},
    };

    // Get the number of activities completed from the list of activities by
    // solving the Activity Selection Problem
    activity_select(activities, atoi(ACTIVITY_COUNT_STR));

    return 0;
}

void
sort_activities(struct Activity* activities, int len) {
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len - i - 1; j++ ) {
            if ( activities[j].end > activities[j + 1].end ) {
                ACTIVITYSWAP(activities[j], activities[j + 1]);
            }
        }
    }
}

void
print_activities(struct Activity* activities, int len) {
    fprintf(stdout, "+------+-------+-----+\n");
    fprintf(stdout, "| Name | Start | End |\n");
    fprintf(stdout, "+------+-------+-----+\n");

    for ( int i = 0; i < len; i++ ) {
        fprintf(stdout, "|  %2d  |   %2d  |  %2d |\n", activities[i].name,
                activities[i].start, activities[i].end);
    }

    fprintf(stdout, "+------+-------+-----+\n");
}

void
print_schedule(int* slots, int slot_count) {
    fprintf(stdout, "\n+----------");

    for ( int i = 0; i < slot_count; i++ ) {
        if ( i < 8 ) {
            fprintf(stdout, "+-----", slots[i]);
        } else if ( i == 8 ) {
            fprintf(stdout, "+------", slots[i]);
        } else {
            fprintf(stdout, "+-------", slots[i]);
        }
    }

    fprintf(stdout, "+\n|   Slot   |");

    for ( int i = 0; i < slot_count; i++ ) {
        fprintf(stdout, " %d-%d |", i + 1, i + 2);
    }

    fprintf(stdout, "\n+----------");

    for ( int i = 0; i < slot_count; i++ ) {
        if ( i < 8 ) {
            fprintf(stdout, "+-----", slots[i]);
        } else if ( i == 8 ) {
            fprintf(stdout, "+------", slots[i]);
        } else {
            fprintf(stdout, "+-------", slots[i]);
        }
    }

    fprintf(stdout, "+\n| Activity ");

    for ( int i = 0; i < slot_count; i++ ) {
        if ( i < 8 ) {
            if ( slots[i] != 0 ) {
                fprintf(stdout, "| %2d  ", slots[i]);
            } else {
                fprintf(stdout, "|     ", slots[i]);
            }
        } else if ( i == 8 ) {
            if ( slots[i] != 0 ) {
                fprintf(stdout, "|  %2d  ", slots[i]);
            } else {
                fprintf(stdout, "|      ", slots[i]);
            }
        } else {
            if ( slots[i] != 0 ) {
                fprintf(stdout, "|  %2d   ", slots[i]);
            } else {
                fprintf(stdout, "|       ", slots[i]);
            }
        }
    }

    fprintf(stdout, "|\n+----------");

    for ( int i = 0; i < slot_count; i++ ) {
        if ( i < 8 ) {
            fprintf(stdout, "+-----", slots[i]);
        } else if ( i == 8 ) {
            fprintf(stdout, "+------", slots[i]);
        } else {
            fprintf(stdout, "+-------", slots[i]);
        }
    }

    fprintf(stdout, "+\n");
}

void
activity_select(struct Activity* activities, int len) {
    fprintf(stdout, "Activities:\n");
    print_activities(activities, len);

    sort_activities(activities, len);

    fprintf(stdout, "\nSorted Activities:\n");
    print_activities(activities, len);

    // The number of slots needed is the end time of the last activity
    int  slot_count          = activities[len - 1].end - 1;
    int* slots               = ( int* ) malloc(slot_count * sizeof(int));
    int  activity_index      = 0;
    int  activites_completed = 0;

    for ( int i = 0; i < slot_count; i++ ) {
        slots[i] = 0;
    }

    // Iterate through the slots, and check the activity under examination
    // starts at that time. If so, assign the slots and any additional required
    // ones to the activity and then go to next activity. If the start time is
    // not the same, either wait or skip the activity, depending on whether the
    // starting time of the activity has yet to pass or has been passed
    for ( int i = 1; i <= slot_count; i++ ) {
        if ( i == activities[activity_index].start ) {
            while ( i <= slot_count ) {
                slots[i - 1] = activities[activity_index].name;
                i++;

                if ( i == activities[activity_index].end ) {
                    activity_index++;
                    activites_completed++;
                    i--;
                    break;
                }
            }
        } else if ( i > activities[activity_index].start ) {
            activity_index++;
            i--;
        }
    }

    fprintf(stdout, "\nSchedule:");
    print_schedule(slots, slot_count);

    fprintf(stdout, "Activities Completed: %d\n", activites_completed);

    free(slots);
}
