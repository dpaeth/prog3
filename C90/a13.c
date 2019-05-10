#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
    char name[25];
    struct person* next;
};

struct ring{
    struct person* first;
    struct person* last;
    int size;
};

struct ring* insertToRing(struct ring* ring, char* name){

    //Initialisiere neue Person mit namenparameter und next -> NULL
    struct person new = {
            *name, 0
    };

   //Falls Ring leer, füge neue Person als erstes Element hinzu
   if (ring->size == 0) {
       ring->first = &new;
       ring->size = 1;
       return ring;
   }

   if (ring->size == 1){
       ring->first->next = &new;
       ring->size = 2;
       return ring;
   }

   return NULL;
}

struct ring* createPersonRing(void){
    char* name = malloc(25* sizeof(char));
    struct ring* persons = malloc(sizeof(struct ring));

    persons->first = NULL;
    persons->last = NULL;
    persons->size = 0;

    //while (scanf("%s", name) != EOF){
        scanf("%s", name);
        persons = insertToRing(persons, name);
        scanf("%s", name);
        persons = insertToRing(persons, name);

    //}


    //free(name);
    return persons;

}



int main() {

    struct ring* persons;
    persons = createPersonRing();

    printf("%s", persons->first->name);

    return 0;
}