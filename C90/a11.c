#include <stdio.h>
#include <string.h>

//Ent- und verschlüsselt einen gegeben String mithilfe einer Entschlüsselungstabelle
char a[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'
};

char b[] = {
        'w', 'g', 's', 'n', 'q', 'c', 'd',
        'v', 'm', 'e', 'y', 'l', 'u', 'z',
        'o', 'a', 'b', 'h', 'r', 'j', 'f',
        'k', 'x', 'i', 'p', 't'
};

char * readInput(void){
	char input[20];
	printf("Bitte Text eingeben: (max %lu Zeichen)\n", sizeof(input));
	fgets(input, sizeof(input), stdin);

	return input;
}

void decrypt(char text[]){
    int textsize = (int) strlen(text);
    int alphabetsize = (int) strlen(a);

    int i =0;
    for (; i<textsize; i++){
        int j =0;
        for (; j<alphabetsize; j++){
            if (text[i] == b[j]) {
                text[i] = a[j];
                break;
            }
        }
    }
    printf("%s", text);
}

void encrypt(char * text){
    int textsize = (int) strlen(text);
    int alphabetsize = (int) strlen(a);

    int i =0;
    for (; i<textsize; i++){
        int j =0;
        for (; j<alphabetsize; j++){
            if (text[i] == a[j]) {
                text[i] = b[j];
                break;
            }
        }
    }
    printf("%s", text);
}

int main(int argc, char*argv[]){

	if (!strncmp(argv[1], "decrypt", strlen(argv[1]))) {
		printf("[Decrypt]\n");
		char * text = readInput();
        decrypt(text);
	}

	else if (!strncmp(argv[1], "encrypt", strlen(argv[1]))) {
		printf("[Encrypt]\n");
        encrypt(readInput());
	}

	else printf("ungueltige Eingabe.\n");


}
