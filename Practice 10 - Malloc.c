//Lorraine Bichara Assad A01193063
//Fecha: 22 de febrero de 2018
//P10. Malloc
/*Design the source code for the following routines:
	extremlyLargeString() that will get an increasingly large string from the keyboard.
Using getchar() and pointers to move around the string. */

#include <stdio.h>
#include <stdlib.h>

void extremelyLargeString() {
	char *ptr_c = malloc(sizeof(ptr_c));

	int iTam = 0;
	iTam = sizeof(ptr_c);
	int iCont = 0; //contador de la memoria disponible
	char c = '\0';
	
	printf("Introduzca un string (use . como el fin de su string): ");

	if(ptr_c == NULL) {
        printf("Error! La memoria no fue alocada.");
        exit(0);
    }
	else {

		while((c = getchar()) != '.') {
			ptr_c[iCont++] = (char)c;

			if(iCont == iTam) { //si ya no hay mem, se cambia el tamaño de la mem asignada y se asigna más
	            iTam = iCont + 2;
				ptr_c = realloc(ptr_c, iTam);
			}
		}

		printf("Su string es: \n%s\n", ptr_c);

		free(ptr_c); //libera la memoria
	}
}

int main() {

	extremelyLargeString();

}