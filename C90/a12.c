#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>



void soundex(const char s[], char res[]){
    int m = 0;

        res[m] = (char)toupper(s[0]);


    char tabelle[6][8] = {"BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};

    int ssize = (int)strlen(s);
    int ziffern = 6;

    int i = 1, buchstaben;

    //i: Aktuelle Position in s[], j: tabelle[x][], k: tabelle[][x], m: Aktuelle Position in res[]

        for (; i<ssize; i++){
            char c = (char)toupper(s[i]);
            int j = 0;
            for (; j < ziffern; j++){
                int k = 0;
                buchstaben = sizeof(tabelle[j]);
                for (; k < buchstaben; k++){
                    char l = tabelle[j][k];
                    if (c == l){
                        m++;
                        res[m] = (char) ((j + 1) + 48);
                    }
                }
                //Exit falls res größer gleich 6
            }
            if (strlen(res) >= 6){
                break;
            }
        }


        //Fülle mit 0 auf falls res kleiner 6
        if ((int)strlen(res) < 6){
            m = (int)strlen(res);
            for (; m<6; m++){
                res[m] = 48;
            }
        }

    printf("%s", res);

}

char * readInput(void){
    char input[20];
    fgets(input, sizeof(input), stdin);
    return input;
}

int main() {
    char * s;
    while (s!=EOF) {

        s = readInput();

        char res[7];

        soundex(s, res);
    }

    return 0;
}

