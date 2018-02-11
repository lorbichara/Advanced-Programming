//Lorraine Bichara Assad A01193063
//Fecha: 2 de febrero de 2018
//P6. Pointer Math
//Reemplazar caracteres en un arreglo utilizando apuntadores y no la librería string.

    // Recibe la dirección del inicio de un string.
    // Utilizando apuntadores solamente, recorre el string y realiza los cambios segun la tabla:
    //     a a 4
    //     e a 3
    //     i a 1
    //     o a 0
    //     u a 2

#include <stdio.h>

//Función que reemplaza los caracteres
//Parámetro: un apuntador al inicio del string.
void cambios(char* ptr) {
	char *ptrPrint = NULL;
	ptrPrint=ptr;

	 while (*ptr != '\0') {
	 	switch(*ptr) {
		case 'a':
			*(ptr)='4';
			break;
		case 'e':
			*(ptr)='3';
			break;
		case 'i':
			*(ptr)='1';
			break;
		case 'o':
			*(ptr)='0';
			break;
		case 'u':
			*(ptr)='2';
			break;
		default: 
			break;
		}
		ptr++;
	 }

	printf("%s\n", ptrPrint);
}

int main() {

	char sString[51];
	char *charPtr = NULL;

	charPtr = &sString[0];

	printf("Introduzca un string (max 50 carácteres): ");
	scanf("%[^\n]s", sString);

	cambios(charPtr);
}