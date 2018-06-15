//Lorraine Bichara Assad A01193063
//24 de febrero de 2018
/* Hour of Code 3: 
The attached file has a list of location coordinates. You need to do the following: 
    Create two files based on the distributed file:
        One with the coordinates in degrees, minutes, seconds and cardinal points.
        One with just the numbers.
    Sort the coordinates from smallest to largest. On both files. (Smallest Latitude first, then smallest Longitude)
    Change the characters for cardinal points to words: N to North
*/

#include <stdio.h>
#include <string.h>

struct coordenada {
	char titulo1[11];
	char titulo2[11];
	char latiCoord[15];
	char longiCoord[15];
	double latiNum;
	double longiNum;
};

//Función que ordena los valores en base al double de latitud.
//Recibe el arreglo de estructuras y la cantidad de coordenadas.
void sort(struct coordenada arr[100], int cantCoords)
{
    struct coordenada temp;
    
    for (int i = 0; i < cantCoords; i++)
    {
        for (int j = 0; j < cantCoords - 1; j++)
        {
            if (arr[j].latiNum > arr[j + 1].latiNum)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }
    }
}

int main() {
	int cantCoords = 0;
	struct coordenada coords[100];

	FILE *file = fopen("gpsLocations.txt", "r");
	FILE *archCoords = fopen("archivoCoordenadas.txt", "w");
	FILE *archNums = fopen("archivoNumeros.txt", "w");
	char titu1[20];
	char titu2[20];
	char saltoLinea;
	char coord1[20];
	char coord2[20];
	double numero1;
	double numero2;
	
	while(EOF != fscanf(file, "%s %s %lf%c%s %s %lf", titu1, coord1, &numero1, &saltoLinea, titu2, coord2, &numero2)) {
		strcpy(coords[cantCoords].titulo1, titu1);
		strcpy(coords[cantCoords].titulo2, titu2);
		strcpy(coords[cantCoords].latiCoord, coord1);
		strcpy(coords[cantCoords].longiCoord, coord2);
		coords[cantCoords].latiNum = numero1;
		coords[cantCoords].longiNum = numero2;

		cantCoords++;
	}

	sort(coords, cantCoords);

	for(int i = 0; i < cantCoords; i++) {
		//Imprimir en archivo de números.
		fprintf(archNums, "%.8lf\t", coords[i].latiNum);
		fprintf(archNums, "%.8lf\t\n", coords[i].longiNum);

		//Imprimir en archivo de coordenadas
		if(coords[i].latiCoord[8] == 'N' || coords[i].latiCoord[9] == 'N' || coords[i].latiCoord[10] == 'N') {
			strcat(coords[i].latiCoord, "orth");
		}
		else if(coords[i].latiCoord[8] == 'S' || coords[i].latiCoord[9] == 'S' || coords[i].latiCoord[10] == 'S') {
			strcat(coords[i].latiCoord, "outh");
		}
		fprintf(archCoords, "%s\t", coords[i].latiCoord);

		if(coords[i].longiCoord[8] == 'E' || coords[i].longiCoord[9] == 'E' || coords[i].longiCoord[10] == 'E') {
			strcat(coords[i].longiCoord, "ast");
		}
		else if(coords[i].longiCoord[8] == 'W' || coords[i].longiCoord[9] == 'W' || coords[i].longiCoord[10] == 'W') {
			strcat(coords[i].longiCoord, "est");
		}
		fprintf(archCoords, "%s\n", coords[i].longiCoord);
	}
	fclose(file);
}