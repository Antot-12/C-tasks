#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функція перевіряє, чи всі символи у рядку є цифрами
int is_all_digits(const char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (!isdigit(string[i])) {
            return 0; // Якщо хоч один символ не є цифрою, повертаємо 0
        }
    }
    return 1; // Усі символи є цифрами
}

int main() {
    char input[256]; // Буфер для введення рядка
    printf("Enter a string to check if it contains only digits: ");
    scanf("%255s", input); // Захист від переповнення буфера

    // Викликаємо функцію перевірки
    int result = is_all_digits(input);

    // Вивід результату
    if (result) {
        printf("The string contains only digits.\n");
    } else {
        printf("The string contains letters or other non-digit characters.\n");
    }

    return 0;
}
