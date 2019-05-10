#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "textfun.h"

listP wordlist;

void printWordlist(listP lst){
    int i;
    listP akt;

    printf("\n");
    printf("Wordlist %p\n", (void*)lst);
    if (lst == NULL) {
        printf("Wordlist ist leer.\n\n");
        return;
    }

    akt = lst;
    i = 0;
    while (akt != NULL){
        if (akt->swort != NULL && akt->ewort != NULL) {
            printf(" %d | %15s = %15s | %p \n", i, akt->swort, akt->ewort, (void*)akt);
            i++;
        }
        akt = akt->next;
    }
    printf("\n");
    fflush(stdout);
}

static void addPair(const char *such, const char *ersatz){
    listP akt;

    akt = wordlist;

    if (wordlist->swort == NULL){
        strcpy(wordlist->swort, such);
        strcpy(wordlist->ewort, ersatz);
        wordlist->next = NULL;
    } else {
        while (akt->next != NULL){
            akt = akt->next;
        }
        strcpy(akt->next->swort, such);
        strcpy(akt->next->ewort, ersatz);
        akt->next->next = NULL;
    }

}


