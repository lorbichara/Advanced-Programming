//Lorraine Bichara Assad A01193063
//Fecha: 9 de febrero de 2018
//P8. Estructuras como parámetros
//Funciones que modifican estructuras por valor y por referencia.

#include <stdio.h>
#include <ctype.h>

//Estructura donde se guardarán los valores del usuario
struct Original {
	int iA;
	int iB;
	char cString[50];
};

//Estructura donde se guardarán los valores nuevos
struct New {
	int iSuma;
	int iResta;
	char cStringMayus[50];
};

//Funciones por valor.
//Reciben la estructura con los datos por valor (esta no será modificada)
//y la estructura del resultado por valor también.
void sumaValor(struct Original orig, struct New new) {
	new.iSuma = orig.iA + orig.iB;
}

void restaValor(struct Original orig, struct New new) {
	new.iResta = orig.iA - orig.iB;
}

void mayusculaValor(struct Original orig, struct New new) {
	for(int i = 0; i < 50; i++) {
		new.cStringMayus[i] = toupper(orig.cString[i]);
	}
}

//Funciones por referencia.
//Reciben la estructura con los datos por valor (esta no será modificada)
//y la estructura del resultado por referencia porque está si se desea modificar fuera de la función.
void sumaReference(struct Original orig, struct New *new) {
	new->iSuma = orig.iA + orig.iB;
}

void restaReference(struct Original orig, struct New *new) {
	new->iResta = orig.iA - orig.iB;
}

void mayusculaReference(struct Original orig, struct New *new) {
	for(int i = 0; i < 50; i++) {
		new->cStringMayus[i] = toupper(orig.cString[i]);
	}
}

int main() {

	struct Original orig;
	struct New new;
	char newline;

	//Leer los datos
	printf("Introduce un número: ");
	scanf("%d", &orig.iA);

	printf("Introduce otro número: ");
	scanf("%d", &orig.iB);
	scanf("%c", &newline);

	printf("Introduce un string: ");
	scanf("%[^\n]s", orig.cString);

	//Llamar a las funciones con parámetros por valor.
	sumaValor(orig, new);
	restaValor(orig, new);
	mayusculaValor(orig, new);

	printf("--------PARÁMETROS POR VALOR--------\n");
	printf("Suma: %d\n", new.iSuma);
	printf("Resta: %d\n", new.iResta);
	printf("String: %s\n", new.cStringMayus);

	//Llamar a las funciones con parámetros por referencia.
	sumaReference(orig, &new);
	restaReference(orig, &new);
	mayusculaReference(orig, &new);

	printf("--------PARÁMETROS POR REFERENCIA--------\n");
	printf("Suma: %d\n", new.iSuma);
	printf("Resta: %d\n", new.iResta);
	printf("String: %s\n", new.cStringMayus);

}