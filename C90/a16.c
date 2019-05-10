#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "textfun.c"

typedef struct node* nodep;

struct node {
    void* data;
    nodep prev, next;
};

void printList(nodep lst){
    nodep akt;
    int i;

    printf("\n");
    printf("Liste %p\n", (void*)lst);
    if (lst == NULL) {
        printf("Liste ist leer.\n\n");
        return;
    }

    akt = lst;
    i = 0;

    while (akt != NULL){
        if (akt->data != NULL) {
            char* data = akt->data;
            printf(" %d | %25s | %p \n", i, data, (void*)akt);
            i++;
        }
        akt = akt->next;
    }
    printf("\n");
    fflush(stdout);
}


nodep insertAt(nodep lst, int pos, void* data) {
    nodep akt;
    nodep new = malloc(sizeof(struct node));

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    akt = lst;

    if (pos == 0 || akt->data == NULL){
        lst = new;
        new = NULL;
        free(new);
        return lst;
    } else {
        while (akt->next != NULL && pos != 1){
            akt = akt->next;
            pos--;
        }
        if (akt->next == NULL){
            new->prev = akt;
            akt->next = new;
            return lst;
        } else {
            new->prev = akt;
            new->next = akt->next;
            akt->next = new;
            new->next->prev = new;
            return lst;
        }
    }
}


nodep deleteAt(nodep lst, int pos){
    nodep del = lst;
    int i = 0;

    while (del->next != NULL && i != pos){
        del = del->next;
        i++;
    }

    if (i == pos){
        if (del->prev == NULL) lst = del->next;
        if (del->prev != NULL) {
            del->prev->next = del->next;
        }
    } else if (pos == -1){
        del->prev->next = NULL;
    }

    return lst;


}

nodep copyList(nodep lst){
    nodep akt = lst;
    nodep copy = lst;
    int i = 0;

    while (akt != NULL){
        copy = insertAt(copy, i, akt->data);
        akt = akt->next;
        i++;
    }
    return copy;
}

void deleteList(nodep lst){
    if (lst->data == NULL) {
        printf("Liste ist bereits leer.\n\n");
        return;
    }

    while(lst != NULL){
        lst = deleteAt(lst, -1);
    }
    free(lst);
}



nodep lineToList(char *line){
    nodep lst;
    char delimiter[] = {' ', '\n'};
    char* word;

    lst = malloc(sizeof(struct node));
    lst->data = NULL;
    lst->prev = NULL;
    lst->next = NULL;

    word = strtok(line, delimiter);

    while(word != NULL) {
        lst = insertAt(lst, -1, word);
        word = strtok(NULL, delimiter);
    }

    return lst;
}


void splitAndAddPairs(nodep woerter){
    nodep akt;
    char delimiter[] = {'='};
    char *such, *ersatz;

    akt = woerter;

    if (akt->data != NULL){
        do {
            such = strtok(akt->data, delimiter);
            ersatz = strtok(NULL, delimiter);
            addPair(such, ersatz);
            akt = akt->next;
        }while(akt->next != NULL);
    }
}


int main(int argc, char** argv) {

    /*Zu zensierende Wörter aus argv in Liste einfügen*/
    int i=1;
    nodep woerter;
    char* line;



    woerter = malloc(sizeof(struct node));

    woerter->data = NULL;
    woerter->prev = NULL;
    woerter->next = NULL;

    for (; i < argc; i++){
        woerter = insertAt(woerter, (-1), argv[i]);
    }

    splitAndAddPairs(woerter);
    printWordlist(wordlist);


    /*Standardeingabe bis EOF einlesen und direkt zensiert ausgeben*/
    line = malloc(sizeof(char)*200);

    while (fgets(line, 200, stdin) != NULL){
        nodep text;
        text = malloc(sizeof(struct node));

        /*
        text = lineToList(line);
        censorPrint(woerter, text);
        */
        free(text);
    }

    free(woerter);
    free(line);

    return 0;
}
