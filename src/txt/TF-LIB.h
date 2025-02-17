#ifndef TDF_LIB_H
#define TDF_LIB_H 

#include <stdio.h>

#define MAX_WORDS 5000

typedef struct {
  char word[50];
  int freq;
} WordFrequency;

typedef struct {
  WordFrequency words[MAX_WORDS];
  int word_count;
} Document;

void calculate_tf(Document *doc, const char *text);
void calculate_idf();
void calculate_tfidf();

#endif
