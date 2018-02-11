//Lorraine Bichara Assad A01193063
//Fecha: 18 de enero de 2018
//P2. Data Types and sizeof()
//El programa solicita tipos de datos distintos y muestra su tamaño usando
//la función sizeof().

#include <stdio.h>
#include <float.h>

int main() {
	int iEntero;
	char cChar;
	double dDecimal;

	printf("Introduzca un número entero: ");
	scanf("%d", &iEntero);

	printf("Introduzca un caracter: ");
	scanf(" %c", &cChar);

	printf("Introduzca un número decimal (tipo double): ");
	scanf("%lf", &dDecimal);

	printf("Your integer %d storage size is %lu bytes.\n", iEntero, sizeof(iEntero));
	printf("Your char %c storage size is %lu bytes. And I can read it as %c or as %d.\n", cChar, sizeof(cChar), cChar, cChar);
	printf("Your double %lf storage size is %lu bytes, I can read any number from %.10e to %.10e in this data type.\n", dDecimal, sizeof(dDecimal), DBL_MIN, DBL_MAX);
}