#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функція 1: Середнє геометричне додатних елементів на побічній діагоналі
void task1() {
    int* a;
    int i, j, n, el = 0, dob = 1;
    float res;

    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);

    a = (int*)malloc(n * n * sizeof(int));
    if (!a) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", (a + i * n + j));
        }
    }

    for (i = 0; i < n; ++i) {
        if (*(a + i * n + (n - 1 - i)) > 0) { // Побічна діагональ
            dob *= *(a + i * n + (n - 1 - i));
            el++;
        }
    }

    free(a);

    if (el == 0) {
        printf("No positive elements on the secondary diagonal.\n");
        return;
    }

    res = pow(dob, 1.0 / el);
    printf("Geometric mean of positive elements: %.2f\n", res);
}

// Функція 2: Видалення нульових елементів з масиву
void task2() {
    int origin[9] = {0, 2, 5, 8, 9, 0, 10, 9, 7};
    int result[9];
    int i, n = 0;

    for (i = 0; i < 9; i++) {
        if (origin[i] != 0) {
            result[n++] = origin[i];
        }
    }

    printf("Array without zeros:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// Функція 3: Модифікація найменшого числа серед трьох
void task3() {
    float a, b, c, min;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);

    float* p_a = &a, *p_b = &b, *p_c = &c, *temp;
    min = *p_a;

    if (*p_b < min && *p_b < *p_c) {
        *p_b *= 2;
        temp = p_a;
        p_a = p_c;
        p_c = temp;
        printf("min * 2 = %.2f\n", *p_b);
        return;
    }

    if (*p_c < min && *p_c < *p_b) {
        *p_c *= 2;
        temp = p_a;
        p_a = p_b;
        p_b = temp;
        printf("min * 2 = %.2f\n", *p_c);
        return;
    }

    *p_a *= 2;
    temp = p_b;
    p_b = p_c;
    p_c = temp;
    printf("min * 2 = %.2f\n", *p_a);
}

// Головне меню
int main() {
    int choice;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Geometric mean of positive elements on secondary diagonal\n");
        printf("2. Remove zeros from array\n");
        printf("3. Modify the smallest number among three\n");
        printf("0. Exit\n");
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
                task3();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
