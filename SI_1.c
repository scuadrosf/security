#include <stdio.h>
#include <string.h>
#define MAXINPUTLENGTH 1024

unsigned char* secreto = "AQUI TENDRAS QUE ACCEDER PARA OBTENER EL SECRETO DESDE EL EJECUTABLE";

struct User {
    char name[10];
    char isAdmin; // T for True if the user is admin, F for False
} user;

int main(int argc, char *argv[]){
    printf("Escribe tu nombre: ");
    char user_input[MAXINPUTLENGTH];
    fgets(user_input, MAXINPUTLENGTH, stdin);
    user.isAdmin = 'F';

    // User provided name can be really long, take just the first 10 characters to avoid overflows
    for(int i = 0; i <= 10; i++){
        user.name[i] = user_input[i];
    }

    printf("Hola %s\n Te gustaria conocer mis secretos? (SI/NO): ", user_input);

    fgets(user_input, MAXINPUTLENGTH, stdin);
    if(strncmp("SI", user_input, 2) == 0){
        // Should we give our secrets to the user?
        if(user.isAdmin == 'T'){
            printf("Felicidades, has conseguido lo que parecia imposible\n");
            printf("%s", secreto);
        } else {
            printf("Tendras que ganartelo :)");
        }
    } else {
        printf("Tu te lo pierdes...");
    }
    return 0;
}
