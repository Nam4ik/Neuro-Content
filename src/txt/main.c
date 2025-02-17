#include "TF-LIB.h"
#include <stdio.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char input_text[MAX_LINE_LENGTH];

    // Считывание текста от пользователя
    printf("Введите текст документа: ");
    if (fgets(input_text, MAX_LINE_LENGTH, stdin) == NULL) {
        printf("Ошибка при чтении ввода.\n");
        return 1;
    }

    // Проверка на превышение лимита документов
    if (document_count >= MAX_DOCUMENTS) {
        printf("Достигнут максимум документов (%d).\n", MAX_DOCUMENTS);
        return 1;
    }

    // Добавление документа и расчёт TF
    Document *current_doc = &documents[document_count];
    calculate_tf(current_doc, input_text);
    document_count++;

    // Расчёт IDF и TF-IDF
    calculate_idf();
    calculate_tfidf();

    return 0;
}
