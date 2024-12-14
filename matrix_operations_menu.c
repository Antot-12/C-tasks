#include <stdio.h>
#include <math.h>

void task1() {
    int r = 1, c = 1, i, j;
    printf("\n--- Task 1: Find Minimum in Each Column ---\n");
    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    if (r <= 0 || c <= 0) {
        printf("Invalid dimensions! Returning to menu...\n");
        return;
    }

    int a[10][10];
    int min_el = 10000;
    for (i = 0; i < r; ++i) {
        printf("\n");
        for (j = 0; j < c; ++j) {
            a[i][j] = pow((i - j + 5), 2);
            printf("a[%d,%d] = %d ", i + 1, j + 1, a[i][j]);
        }
    }

    printf("\n");
    int min_mass[10][2];
    int min_t, min_i;

    for (i = 0; i < c; i++) {
        min_t = a[0][i];
        min_i = 0;
        for (j = 0; j < r; j++) {
            if (a[j][i] < min_t) {
                min_t = a[j][i];
                min_i = j;
            }
        }
        min_mass[i][0] = min_t;
        min_mass[i][1] = min_i;
    }
    for (i = 0; i < c; i++) {
        printf("\nMinimum of column %d = %d in row %d", i + 1, min_mass[i][0], min_mass[i][1] + 1);
    }
    printf("\n");
}

void task2() {
    int r, c, i, j;
    printf("\n--- Task 2: Find Pair with Product Equal to 1 ---\n");
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    if (r <= 0 || c <= 0) {
        printf("Invalid dimensions! Returning to menu...\n");
        return;
    }

    double a[10][10];
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    int k, n;
    double first, second;
    for (k = 0; k < r; k++) {
        for (n = 0; n < c; n++) {
            first = a[k][n];
            for (i = k; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (((first * a[i][j]) == 1.0) && ((i != k) || (j != n))) {
                        second = a[i][j];
                        printf("Yes, found pair: %.2lf and %.2lf\n", first, second);
                        return;
                    }
                }
            }
        }
    }
    printf("No such pair found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Task 1: Find Minimum in Each Column\n");
        printf("2. Task 2: Find Pair with Product Equal to 1\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
