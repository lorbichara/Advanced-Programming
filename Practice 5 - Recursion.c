//Lorraine Bichara Assad A01193063
//Fecha: 28 de enero de 2018
//P5. Recusión
//1. Factorial de un número dado
//2. Secuencia Fibonacci
#include <stdio.h>

//Función que calcula el factorial de un número que recibe como parámetro, y regresa el factorial.
int factorial(int iN) {
	if(iN == 1)
		return 1;
	else
		return iN * factorial(iN - 1);
}

//Función que calcula la secuencia fibonacci hasta el número iN recibido como parámetro.
//Regresa el número fibonacci de un número.
int fibonacci(int iN)  {
    if(iN == 0 || iN == 1)
        return iN;
   else
      return fibonacci(iN - 1) + fibonacci(iN - 2);
}

int main() {
	int iFact;
	int iFib;
	printf("Introduzca un número para calcular su factorial: ");
	scanf("%d", &iFact);
	printf("El factorial de %d es %d.\n", iFact, factorial(iFact));

	printf("-----------------------------------------------------\n");

	printf("Introduzca cuántos números quiere de la secuencia Fibonacci: ");
	scanf("%d", &iFib);
	printf("Los primeros %d números de la secuencia Fibonacci son: ", iFib);
	for(int i = 0; i < iFib; i++) {
		printf("%d ", fibonacci(i));
	}
	printf("\n");
}