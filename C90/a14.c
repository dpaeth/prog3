#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node* nodep;

struct node {
    void* data;
    nodep prev, next;
};

void printList(nodep lst){
    printf("Liste %p\n", (void*)lst);
    if (lst == NULL) {
        printf("Liste ist leer.\n\n");
        return;
    }

    nodep akt;
    akt = lst;
    int i;
    i = 0;

    while (akt != NULL){
        printf(" %d | %25s | %p \n", i, (char*)akt->data, (void*)akt);
        akt = akt->next;
        i++;
    }
    printf("\n");
}

nodep insertAt(nodep lst, int pos, void* data) {
    nodep new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    nodep akt;
    akt = lst;

    if (pos == 0){
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



int main() {

    nodep lst;
    lst = malloc(sizeof(struct node));
    lst->next = NULL;

    char* text;
    text = malloc(sizeof(char)*25);

    int i = 0;

    while (scanf("%s", text) != EOF){
        lst = insertAt(lst, i, text);
        free(text);
        text = malloc(sizeof(char)*25);
        i++;
    }

    free(text);
    printList(lst);
    free(lst);

    return 0;
}