//Lorraine Bichara Assad A01193063
//Fecha: 30 de enero de 2018
//Hour of Code 1

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//Función que cálcula el método mitad del cuadrado.
//Recibe como parámetro la "semilla" a utilizar.
//Regresa el número aleatorio generado.
int midsquare(int seed) {
	seed = pow(seed, 2);
	char num[9];
	char new[5];
	sprintf(num, "%d", seed);
	if(strlen(num) == 6)
		strcat(num, "00");
	else if(strlen(num) == 7)
		strcat(num, "0");
	
	memcpy(new, num+2, 4);
	return atoi(new);
}

int main() {
	time_t seed;
	seed %= 10000;

	for(int i = 0; i < 10; i++) {
		printf("%d \n", midsquare(seed));
		seed = midsquare(seed);
	}	
}