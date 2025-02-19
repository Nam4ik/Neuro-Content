/*

  _______                                ________              __________
  ___    |__________________ _______________  __ \_______   __ ___  ___  \
  __  /| |_  ___/  ___/  __ `/_  __ \  _ \_  / / /  _ \_ | / / __  / _ \  |
  _  ___ |  /   / /__ / /_/ /_  / / /  __/  /_/ //  __/_ |/ /  _  / , _/ /
  /_/  |_/_/    \___/ \__,_/ /_/ /_/\___//_____/ \___/_____/   |_/_/|_|_/


*/

/*
extern "C" {
  void calculate_tf(Document *doc, const char *text);
  int hash_function(const char *word);
  void calculate_idf();
  void calculate_tfidf();

}

typedef struct {
    char word[50];
    int freq;
} WordFrequency;

typedef struct {
    WordFrequency words[MAX_WORDS];
    int word_count;
} Document;
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "TF-LIB.h"

Document documents[MAX_DOCUMENTS];
int document_count = 0;

typedef struct {
    char word[50];
    int doc_count;
} IDFEntry;

IDFEntry idf_table[MAX_WORDS];
int idf_table_size = 0;

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

void calculate_idf() {
    for (int i = 0; i < idf_table_size; i++) {
        idf_table[i].doc_count = 0;
    }

    for (int i = 0; i < document_count; i++) {
        for (int j = 0; j < documents[i].word_count; j++) {
            int found = 0;
            for (int k = 0; k < idf_table_size; k++) {
                if (strcmp(idf_table[k].word, documents[i].words[j].word) == 0) {
                    idf_table[k].doc_count++;
                    found = 1;
                    break;
                }
            }
            if (!found && idf_table_size < MAX_WORDS) {
                strcpy(idf_table[idf_table_size].word, documents[i].words[j].word);
                idf_table[idf_table_size].doc_count = 1;
                idf_table_size++;
            }
        }
    }

    for (int i = 0; i < idf_table_size; i++) {
        if (idf_table[i].doc_count > 0) {
            idf_table[i].doc_count = log(document_count / (double)idf_table[i].doc_count);
        }
    }
}

void calculate_tfidf() {
    calculate_idf();

    for (int i = 0; i < document_count; i++) {
        int total_words = 0;

        for (int j = 0; j < documents[i].word_count; j++) {
            total_words += documents[i].words[j].freq;
        }

        //TF-IDF
        for (int j = 0; j < documents[i].word_count; j++) {
            double tf = (double)documents[i].words[j].freq / total_words;
            double idf = 0.0;

            for (int k = 0; k < idf_table_size; k++) {
                if (strcmp(idf_table[k].word, documents[i].words[j].word) == 0) {
                    idf = idf_table[k].doc_count;
                    break;
                }
            }

            double tfidf = tf * idf;

            printf("Doc %d, Word: %s, TF-IDF: %.4f\n", i, documents[i].words[j].word, tfidf);
        }
    }
}
/*
// main.c
int main() {
    char input_text[MAX_LINE_LENGTH];

    printf("Введите текст документа: ");
    if (fgets(input_text, MAX_LINE_LENGTH, stdin) == NULL) {
        printf("Ошибка при чтении ввода.\n");
        return 1;
    }

    input_text[strcspn(input_text, "\n")] = '\0';

    if (document_count >= MAX_DOCUMENTS) {
        printf("Достигнут максимум документов (%d).\n", MAX_DOCUMENTS);
        return 1;
    }

    Document *current_doc = &documents[document_count];
    calculate_tf(current_doc, input_text);
    document_count++;

    calculate_idf();
    calculate_tfidf();

    return 0;
}


Optionally, if you will not compile to .so uncomment this 
*/

