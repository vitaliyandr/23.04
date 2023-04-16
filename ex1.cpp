#include <stdio.h> // Додано заголовок для використання printf

// Функція визначення довжини рядка
int mystrlen(const char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// Функція копіювання рядка
char* mystrcpy(char* str1, const char* str2) {
    char* orig = str1;
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return orig;
}

// Функція приєднання рядка
char* mystrcat(char* str1, const char* str2) {
    char* orig = str1;
    while (*str1 != '\0') {
        str1++;
    }
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return orig;
}

// Функція пошуку символу у рядку
char* mystrchr(char* str, char s) {
    while (*str != '\0') {
        if (*str == s) {
            return str;
        }
        str++;
    }
    return NULL;
}

// Функція пошуку підрядка у рядку
char* mystrstr(char* str1, const char* str2) { // Змінено тип другого аргументу на const char*
    int len1 = mystrlen(str1); // Змінено тип на int
    int len2 = mystrlen(str2); // Змінено тип на int
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j]) {
                break;
            }
        }
        if (j == len2) {
            return str1 + i;
        }
    }
    return NULL;
}

// Власний вузол main для тестування функцій
int main() {
    // Приклад використання функцій бібліотеки
    const char* str1 = "Hello";
    const char* str2 = "World";
    char buffer[100];

    printf("Length of str1: %d\n", mystrlen(str1));

    mystrcpy(buffer, str1);
    printf("Copy of str1: %s\n", buffer);

    mystrcat(buffer, str2);
    printf("Concatenation of str1 and str2: %s\n", buffer);

    char* found = mystrchr(buffer, 'r');
    if (found != NULL) {
        printf("Found 'r' in buffer: %s\n", found);
    }
    else {
        printf("'r' not found in buffer\n");
    }

    char* found2 = mystrstr(buffer, "orl");
    if (found2 != NULL) {
        printf("Found 'orl' in buffer: %s\n", found2);
    }
    else {
        printf("'orl' not found in buffer\n");
    }
  return 0;
}