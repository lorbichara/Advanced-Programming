//Lorraine Bichara Assad A01193063
//Fecha: 8 de marzo de 2018.
//P12. File API

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int iCantAgentes = 0;

struct agente {
	int iCode;
    char cName[21];
    char cLName[21];
    char cAgentID[16];
    char cAssets[5][35];
    int iContAssets;
    int iAge;
    char cGender;
    char cMission[5][13];
    int iContMisiones;
};

typedef struct agente agente;

//VALIDATE AGENT ID
//Function that validates if the ID entered by the user is valid (according to the format).
//Parameters: ID. Returns 0 if invalid, 1 if valid.
int validID(char cID[]) {
	for(int i = 0; i < 6; i++) {
		if(!isalpha(cID[i])) {
			printf("El ID no es válido.\n");
			return 0;
		}
	}

	for(int i = 6; i < 15; i++) {
		if(!isdigit(cID[i])) {
			printf("El ID no es válido.\n");
			return 0;
		}
	}
	return 1;
}

//VALIDATE MISSION ID
//Function that validates if the mission entered by the user is valid (according to the format).
//Parameters: Mission. Returns 0 if invalid, 1 if valid.
int validMission(char cMiss[]) {
	for(int i = 0; i < 3; i++) {
		if(!isalpha(cMiss[i])) {
			printf("La misión no es válida.\n");
			return 0;
		}
	}

	for(int i = 3; i < 12; i++) {
		if(!isdigit(cMiss[i])) {
			printf("La misión no es válida.\n");
			return 0;
		}
	}
	return 1;
}

//VALIDATE ASSET ID
//Function that validates if the asset entered by the user is valid (according to the format).
//Parameters: Asset. Returns 0 if invalid, 1 if valid.
int validAsset(char cAsst[]) {
	for(int i = 0; i < 4; i++) {
		if(!isalpha(cAsst[i])) {
			printf("El asset no es válido.\n");
			return 0;
		}
	}

	for(int i = 4; i < 13; i++) {
		if(!isdigit(cAsst[i])) {
			printf("El asset no es válido.\n");
			return 0;
		}
	}

	for(int i = 13; i < 15; i++) {
		if(!isalpha(cAsst[i])) {
			printf("El asset no es válido.\n");
			return 0;
		}
	}
	return 1;
}

//Función que agrega nuevos agentes.
//Parámetro: el arreglo de estructuras de agentes.
void agregarAgente(agente* agentesArr) {
    iCantAgentes++;
    if(iCantAgentes > 10)
        printf("Ya no se pueden agregar más agentes.\n");
    else {
        agentesArr[iCantAgentes].iCode = iCantAgentes;
        agentesArr[iCantAgentes].iContAssets = 1;
        agentesArr[iCantAgentes].iContMisiones = 1;

        printf("Introduzca el nombre del agente: ");
        scanf("%s", agentesArr[iCantAgentes].cName);

        printf("Introduzca el apellido del agente: ");
        scanf("%s", agentesArr[iCantAgentes].cLName);

        do {
        	printf("Introduzca el ID del agente: ");
        	scanf("%s", agentesArr[iCantAgentes].cAgentID);
        } while(validID(agentesArr[iCantAgentes].cAgentID) != 1);

        do {
        	printf("Introduzca el código de un asset: ");
        	scanf("%s", agentesArr[iCantAgentes].cAssets[0]);

       	} while(validAsset(agentesArr[iCantAgentes].cAssets[0]) != 1);

        printf("Introduzca la edad del agente: ");
        scanf("%d", &agentesArr[iCantAgentes].iAge);

        printf("H/M? ");
        scanf(" %c", &agentesArr[iCantAgentes].cGender);

        do {
        	printf("Introduzca la misión del agente: ");
       		scanf("%s", agentesArr[iCantAgentes].cMission[0]);
       } while(validMission(agentesArr[iCantAgentes].cMission[0]) != 1);
    }
}

//Función que agrega nuevos assets a cierto agente.
//Parámetro: el arreglo de estructuras de agentes.
void agregarAsset(agente* agentesArr) {
    printf("Seleccione el código del agente a quien desea agregarle un asset. Los códigos disponibles son: ");
    for(int i = 1; i <= iCantAgentes; i++) {
        printf("%d ", i);
    }

    printf("\n");
    int iCode;
    scanf("%d", &iCode);
    int iCant = agentesArr[iCode].iContAssets;

    if(agentesArr[iCode].iContAssets > 5)
        printf("Este agente ya no puede tener más assets.\n");
    else {
    	do {
    		printf("Introduzca el código de un asset: ");
        	scanf("%s", agentesArr[iCode].cAssets[iCant]);
    	} while(validAsset(agentesArr[iCode].cAssets[iCant]) != 1);
        
    }
}

//Función que agrega nuevas misiones a cierto agente.
//Parámetro: el arreglo de estructuras de agentes.
void agregarMision(agente* agentesArr) {
    printf("Seleccione el código del agente a quien desea agregarle una misión. Los códigos disponibles son: ");
    for(int i = 1; i <= iCantAgentes; i++) {
        printf("%d ", i);
    }

    printf("\n");
    int iCode;
    scanf("%d", &iCode);
    int iCant = agentesArr[iCode].iContMisiones;


    if(agentesArr[iCode].iContMisiones > 5)
        printf("Este agente ya no puede tener más misiones.\n");
    else {
        do {
	    	printf("Introduzca el código de una misión: ");
	        scanf("%s", agentesArr[iCode].cMission[iCant]);
    	} while(validMission(agentesArr[iCode].cMission[iCant]) != 1);
    }
}

void desplegarTodo(agente* agentesArr) {
    for(int i = 1; i <= iCantAgentes; i++) {
    	printf("-------AGENT-------\n");
	    printf("Nombre: %s\n", agentesArr[i].cName);
	    printf("Apellido: %s\n", agentesArr[i].cLName);
        printf("ID: %s\n", agentesArr[i].cAgentID);
	    printf("Edad: %d\n", agentesArr[i].iAge);
	    printf("Género: %c\n", agentesArr[i].cGender);
	    printf("Assets: "); 
	    for(int j = 0; j <= agentesArr[i].iContAssets; j++) {
	        printf("%s ", agentesArr[i].cAssets[j]);
	    }
	    printf("\nMisiones: "); 
	    for(int k = 0; k <= agentesArr[i].iContMisiones; k++) {
	        printf("%s ", agentesArr[i].cMission[k]);
	    }
    }
}

void desplegarArchivo(agente* agentesArr) {
    FILE *archAgentes = fopen("archivoAgentes.txt", "w");
    for(int i = 1; i <= iCantAgentes; i++) {
        fprintf(archAgentes, "\n-------AGENT-------\n");
        fprintf(archAgentes, "Nombre: %s\n", agentesArr[i].cName);
        fprintf(archAgentes, "Apellido: %s\n", agentesArr[i].cLName);
        fprintf(archAgentes, "ID: %s\n", agentesArr[i].cAgentID);
        fprintf(archAgentes, "Edad: %d\n", agentesArr[i].iAge);
        fprintf(archAgentes, "Género: %c\n", agentesArr[i].cGender);
        fprintf(archAgentes, "Assets: "); 
        for(int j = 0; j <= agentesArr[i].iContAssets; j++) {
            fprintf(archAgentes, "%s ", agentesArr[i].cAssets[j]);
        }
        fprintf(archAgentes, "\nMisiones: "); 
        for(int k = 0; k <= agentesArr[i].iContMisiones; k++) {
            fprintf(archAgentes, "%s ", agentesArr[i].cMission[k]);
        }
    }
    fclose(archAgentes);
}

//Función para el menu de opciones
void menu(agente* agentesArr) {
    int iMenu = 1;
    char cOpcion;

    while (iMenu == 1) {
        printf("\n-----------------MENU-----------------\n");
        printf("A. Crear un agente\n");
        printf("B. Agregar un asset\n");
        printf("C. Agregar una misión\n");
        printf("D. Desplegar información de un agente en consola\n");
        printf("E. Desplegar información de un agente en un archivo\n");
        printf("F. Terminar\n");
        printf("Teclee la letra de la opción deseada: ");

        scanf(" %c", &cOpcion);
        switch (cOpcion) {
            case 'A':
            case 'a':
                agregarAgente(agentesArr);
                break;
            case 'B':
            case 'b':
                agregarAsset(agentesArr);
                break;
            case 'C':
            case 'c':
                agregarMision(agentesArr);
                break;
            case 'D':
            case 'd':
                desplegarTodo(agentesArr);
                break;
            case 'E':
            case 'e':
            	desplegarArchivo(agentesArr);
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

	agente agentesArr[10];
    menu(agentesArr);
}