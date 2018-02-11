//Lorraine Bichara Assad A01193063
//Fecha: 23 de enero de 2018
//P3. Arrays and functions
//Programa que calcula suma, resta y multiplicación de 2 matrices 2x2.
#include <stdio.h>

//Función que despliega una matriz que recibe como parámetro.
void despliega(int iArr[2][2]) {
	for(int iRen = 0; iRen < 2; iRen++) {
		for(int iCol = 0; iCol < 2; iCol++) {
			printf("%d \t", iArr[iRen][iCol]);
		}
		printf("\n");
	}
}

//Función que suma dos matrices que recibe como parámetro.
void suma(int iArrA[2][2], int iArrB[2][2]) {
	int iArrC[2][2];
	for(int iRen = 0; iRen < 2; iRen++) {
		for(int iCol = 0; iCol < 2; iCol++) {
			iArrC[iRen][iCol] = iArrA[iRen][iCol] + iArrB[iRen][iCol];
		}
	}
	despliega(iArrC);
}

//Función que resta dos matrices que recibe como parámetro.
void resta(int iArrA[2][2], int iArrB[2][2]) {
	int iArrC[2][2];
	for(int iRen = 0; iRen < 2; iRen++) {
		for(int iCol = 0; iCol < 2; iCol++) {
			iArrC[iRen][iCol] = iArrA[iRen][iCol] - iArrB[iRen][iCol];
		}
	}
	despliega(iArrC);
}

//Función que multiplica dos matrices que recibe como parámetro.
void multiplicacion(int iArrA[2][2], int iArrB[2][2]) {
	int iArrC[2][2];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 2; k++) {
				iArrC[i][j] += iArrA[i][k] * iArrB[k][j];
			}
		}
	}
	despliega(iArrC);
}

//Función que ejecuta las acciones del menu, recibe las dos matrices.
void menu(int iArrA[2][2], int iArrB[2][2]) {
	int iMenu = 1;
	char cOpcion;

	while (iMenu == 1) {
		printf("\n-----------------MENU-----------------\n");
		printf("A. Desplegar matriz A\n");
		printf("B. Desplegar matriz B\n");
		printf("C. Sumar matrices\n");
		printf("D. Restar matrices\n");
		printf("E. Multiplicar matrices\n");
		printf("F. Terminar\n");
		printf("Teclee la letra de la opción deseada: ");

		scanf(" %c", &cOpcion);
		switch (cOpcion) {
			case 'A':
			case 'a':
				despliega(iArrA);
				break;
			case 'B':
			case 'b':
				despliega(iArrB);
				break;
			case 'C':
			case 'c':
				suma(iArrA, iArrB);
				break;
			case 'D':
			case 'd':
				resta(iArrA, iArrB);
				break;
			case 'E':
			case 'e':
				multiplicacion(iArrA, iArrB);
				break;
			case 'F':
			case 'f':
				iMenu = 0;
				break;
			default:
				printf("Opción inválida.\n");
				break;
		}
	}
}

int main() {
	int iArrA[2][2];
	int iArrB[2][2];

	//Matriz A
	for(int iRen = 0; iRen < 2; iRen++) {
		for(int iCol = 0; iCol < 2; iCol++) {
			printf("Para la matriz A, introduzca el dato de la posición %d %d: ", iRen, iCol);
			scanf("%d", &iArrA[iRen][iCol]);
		}
	}

	//Matriz B
	for(int iRen = 0; iRen < 2; iRen++) {
		for(int iCol = 0; iCol < 2; iCol++) {
			printf("Para la matriz B, introduzca el dato de la posición %d %d: ", iRen, iCol);
			scanf("%d", &iArrB[iRen][iCol]);
		}
	}

	menu(iArrA, iArrB);
}