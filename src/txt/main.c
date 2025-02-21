#include "TF-LIB.h"
#include <stdio.h>



int main() {
    // Добавление нескольких документов
    const char *texts[] = {
        "Это первый документ. Он содержит текст для анализа.",
        "Это второй документ. Он также содержит текст, но немного другой.",
        "Третий документ отличается от первых двух. Он содержит уникальные слова."
    };

    // Определяем количество документов
    int num_documents = sizeof(texts) / sizeof(texts[0]);

    // Обработка каждого документа
    for (int i = 0; i < num_documents; i++) {
        if (document_count >= MAX_DOCUMENTS) {
            printf("Достигнут максимум документов (%d).\n", MAX_DOCUMENTS);
            return 1;
        }

        Document *current_doc = &documents[document_count];
        calculate_tf(current_doc, texts[i]);
        document_count++;
    }

    // Вычисление TF-IDF для всех документов
    calculate_tfidf();

    return 0;
}
