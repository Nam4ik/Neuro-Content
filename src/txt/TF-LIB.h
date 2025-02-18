/*

  _______                                ________              __________
  ___    |__________________ _______________  __ \_______   __ ___  ___  \
  __  /| |_  ___/  ___/  __ `/_  __ \  _ \_  / / /  _ \_ | / / __  / _ \  |
  _  ___ |  /   / /__ / /_/ /_  / / /  __/  /_/ //  __/_ |/ /  _  / , _/ /
  /_/  |_/_/    \___/ \__,_/ /_/ /_/\___//_____/ \___/_____/   |_/_/|_|_/
                                                              

*/

#ifndef TF_LIB_H
#define TF_LIB_H 

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

/*
  `calculate_idf()` and `calculate_tfidf()` have not args, now to compute 
  TF-IDF you need use ALL this funcs in order

 'calculate_idf()' и 'calculate_tfidf()' не имеют аргументов, 
 сейчас для вычисления TF-IDF вам нужно использовать ВСЕ эти функции для того, по порядку

*/


#endif
