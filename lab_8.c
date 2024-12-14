#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 250
#define FILENAME "123.txt"
#define TEMP_FILENAME "temp.txt"

int print_file(const char* filename) {
    FILE* fp;
    FILE* temp_fp;
    int counter = 0;  // Лічильник слів
    char words[MAX_WORDS * MAX_WORD_LENGTH]; // Введені слова
    char* word;
    char line[MAX_WORD_LENGTH];
    int countline = 0;

    // Введення слів користувачем
    printf("Write your words separated by ',': ");
    scanf("%s", words);

    // Відкриваємо файл для читання
    if ((fp = fopen(filename, "r")) == NULL) {
        // Якщо файл не існує, створюємо його
        printf("File does not exist. Creating a new file...\n");
        fp = fopen(filename, "w");
        if (!fp) {
            perror("Failed to create the file");
            return 1;
        }
        fprintf(fp, "0\n");  // Ініціалізація лічильника слів у файлі
        fclose(fp);
    } else {
        // Зчитуємо лічильник з першого рядка
        if (fscanf(fp, "%d\n", &counter) != 1) {
            printf("File format is invalid. Resetting...\n");
            counter = 0;  // Скидаємо лічильник, якщо формат неправильний
        }
        fclose(fp);
    }

    // Відкриваємо файл для додавання
    fp = fopen(filename, "a+");
    if (!fp) {
        perror("Failed to open the file for appending");
        return 1;
    }

    // Розділяємо слова та додаємо до файлу
    word = strtok(words, ",");
    while (word) {
        counter++;
        fprintf(fp, "%d:%s\n", counter, word);
        word = strtok(NULL, ",");
    }
    fclose(fp);

    // Оновлюємо лічильник у файлі (перший рядок)
    temp_fp = fopen(TEMP_FILENAME, "w+");
    if (!temp_fp) {
        perror("Failed to create the temporary file");
        return 1;
    }
    fprintf(temp_fp, "%d\n", counter);  // Записуємо оновлений лічильник

    // Копіюємо решту рядків у тимчасовий файл
    fp = fopen(filename, "r");
    if (!fp) {
        perror("Failed to open the file for reading");
        fclose(temp_fp);
        return 1;
    }

    fgets(line, sizeof(line), fp); // Пропускаємо перший рядок (лічильник)
    while (fgets(line, sizeof(line), fp)) {
        fputs(line, temp_fp);
    }
    fclose(fp);
    fclose(temp_fp);

    // Замінюємо оригінальний файл оновленим
    if (remove(filename) != 0) {
        perror("Failed to remove the original file");
        return 1;
    }
    if (rename(TEMP_FILENAME, filename) != 0) {
        perror("Failed to rename the temporary file");
        return 1;
    }

    printf("File updated successfully.\n");
    return 0;
}

int main() {
    if (print_file(FILENAME) != 0) {
        printf("An error occurred while processing the file.\n");
    }
    return 0;
}
