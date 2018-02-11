//Lorraine Bichara Assad A01193063
//Fecha: 16 de enero de 2018
//P1. Conociendo C
//1. Secuencia Fibonacci sin recursión
//2. Verificar si un número es primo

#include <stdio.h>
#include <math.h>

//Función Fibonacci sin recursión, recibe el número de elementos de la secuencia.
void fibonacci(int iN) {
	int iArrFib[iN];
	iArrFib[0] = 0;
	iArrFib[1]= 1;

	if(iN > 2) {
		for(int i = 2; i < iN; i++) {
			iArrFib[i] = iArrFib[i-1] + iArrFib[i-2];
		}
	}

	for(int j = 0; j < iN; j++) {
		printf("%d ", iArrFib[j]);
	}
}

//Función que verifica si un número es primo, recibe el número a verificar.
//regresa 1 si True, 0 si False
int esPrimo(int iN) {
	for(int i = 2; i <= sqrt(iN); i++) {
		if(iN % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int iNSeq;
	printf("Introduzca cuántos números quieres de la secuencia: ");
	scanf("%d", &iNSeq);

	fibonacci(iNSeq);

	printf("\n-----------------------------------------------------");
	int iNPrimo;
	printf("\nIntroduzca un número para verificar si es primo: ");
	scanf("%d", &iNPrimo);

	if(esPrimo(iNPrimo) == 1)
		printf("El número es primo.\n");
	else
		printf("El número no es primo.\n");

	printf("-----------------------------------------------------\n");
}