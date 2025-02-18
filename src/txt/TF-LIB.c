/*

  _______                                ________              __________
  ___    |__________________ _______________  __ \_______   __ ___  ___  \
  __  /| |_  ___/  ___/  __ `/_  __ \  _ \_  / / /  _ \_ | / / __  / _ \  |
  _  ___ |  /   / /__ / /_/ /_  / / /  __/  /_/ //  __/_ |/ /  _  / , _/ /
  /_/  |_/_/    \___/ \__,_/ /_/ /_/\___//_____/ \___/_____/   |_/_/|_|_/
                                                              

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "TF-LIB.h"

#define MAX_DOCUMENTS 1000
#define MAX_WORDS 5000
#define MAX_LINE_LENGTH 1024

/*
extern "C" {
  void calculate_tf(Document *doc, const char *text);
  int hash_function(const char *word);
  void calculate_idf();
  void calculate_tfidf();

}
*/
/*
typedef struct {
    char word[50];
    int freq;
} WordFrequency;

typedef struct {
    WordFrequency words[MAX_WORDS];
    int word_count;
} Document;
*/

Document documents[MAX_DOCUMENTS];
int document_count = 0;

// Хэш-таблица для подсчёта IDF
int idf_table_size = 0;
int idf_table[MAX_WORDS] = {0};

void calculate_tf(Document *doc, const char *text) {
    doc->word_count = 0;

    char word[50];
    int i = 0, j = 0;


    while (text[i]) {
        if (isalpha(text[i])) {
            word[j++] = tolower(text[i]);
        } else if (j > 0) {
            word[j] = '\0';
            j = 0;


            int found = 0;
            for (int k = 0; k < doc->word_count; k++) {
                if (strcmp(doc->words[k].word, word) == 0) {
                    doc->words[k].freq++;
                    found = 1;
                    break;
                }
            }


            if (!found && doc->word_count < MAX_WORDS) {
                strcpy(doc->words[doc->word_count].word, word);
                doc->words[doc->word_count].freq = 1;
                doc->word_count++;
            }
        }
        i++;
    }
}


int hash_function(const char *word) {
    unsigned long hash = 5381;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % MAX_WORDS;
}


void calculate_idf() {
    memset(idf_table, 0, sizeof(idf_table));


    for (int i = 0; i < document_count; i++) {
        for (int j = 0; j < documents[i].word_count; j++) {
            int hash = hash_function(documents[i].words[j].word);
            idf_table[hash]++;
        }
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (idf_table[i] > 0) {
            idf_table[i] = log(document_count / (double)idf_table[i]);
        }
    }
}



void calculate_tfidf() {
    for (int i = 0; i < document_count; i++) {
        int total_words = 0;


        for (int j = 0; j < documents[i].word_count; j++) {
            total_words += documents[i].words[j].freq;
        }

        //TF-IDF
        for (int j = 0; j < documents[i].word_count; j++) {
            double tf = (double)documents[i].words[j].freq / total_words;
            int hash = hash_function(documents[i].words[j].word);
            double idf = idf_table[hash];
            double tfidf = tf * idf;

            printf("Doc %d, Word: %s, TF-IDF: %.4f\n", i, documents[i].words[j].word, tfidf);
        }
    }
}

/*
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
*/
