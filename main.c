#include <stdio.h>
#include <string.h>

#define MAX_COURSES 5

int main() {
    char courses[MAX_COURSES][30] = {"Math", "Physics", "Chemistry", "CS", "English"};
    int enrolled[MAX_COURSES] = {0}; // 0 = not enrolled, 1 = enrolled
    int choice, i;

    do {
        printf("\n--- Course Enrollment System ---\n");
        printf("1. View Courses\n");
        printf("2. Enroll in a Course\n");
        printf("3. View Enrolled Courses\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nAvailable Courses:\n");
                for(i = 0; i < MAX_COURSES; i++)
                    printf("%d. %s\n", i+1, courses[i]);
                break;

            case 2:
                printf("\nEnter course number to enroll (1-%d): ", MAX_COURSES);
                scanf("%d", &i);
                if(i >= 1 && i <= MAX_COURSES) {
                    if(enrolled[i-1] == 0) {
                        enrolled[i-1] = 1;
                        printf("Enrolled in %s!\n", courses[i-1]);
                    } else {
                        printf("Already enrolled in %s!\n", courses[i-1]);
                    }
                } else {
                    printf("Invalid choice!\n");
                }
                break;

            case 3:
                printf("\nYour Enrolled Courses:\n");
                for(i = 0; i < MAX_COURSES; i++)
                    if(enrolled[i])
                        printf("- %s\n", courses[i]);
                break;

            case 4:
                printf("Exiting... Thank you!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}