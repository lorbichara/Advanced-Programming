//Lorraine Bichara Assad A01193063
//Fecha: 30 de enero de 2018.
//M0. Capture information of an agent.

#include <stdio.h>

int iCantAgentes = 0;

//Cada agente puede tener máximo 5 assets y 5 misiones.
struct agente {
    int iCode;
    char cName[21];
    char cLName[21];
    char cAssets[5][35];
    int iContAssets;
    int iAge;
    char cGender;
    char cMission[5][13];
    int iContMisiones;
};

typedef struct agente agente;

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

        printf("Introduzca el código de un asset: ");
        scanf("%s", agentesArr[iCantAgentes].cAssets[0]);

        printf("Introduzca la edad del agente: ");
        scanf("%d", &agentesArr[iCantAgentes].iAge);

        printf("H/M? ");
        scanf(" %c", &agentesArr[iCantAgentes].cGender);

        printf("Introduzca la misión del agente: ");
        scanf("%s", agentesArr[iCantAgentes].cMission[0]);
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
        printf("Introduzca el código de un asset: ");
        scanf("%s", agentesArr[iCode].cAssets[iCant]);
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
        printf("Introduzca el código de una misión: ");
        scanf("%s", agentesArr[iCode].cMission[iCant]);
    }
}

//Función que despliega la información de un agente.
//Parámetro: el arreglo de estructuras de agentes.
void desplegar(agente* agentesArr) {
    printf("Seleccione el código del agente cuya información desea desplegar. Los códigos disponibles son: ");
    for(int i = 1; i <= iCantAgentes; i++) {
        printf("%d ", i);
    }

    printf("\n");
    int iCode;
    scanf("%d", &iCode);

    printf("-------AGENT-------\n");
    printf("Nombre: %s %s\n", agentesArr[iCode].cName, agentesArr[iCode].cLName);
    printf("Edad: %d\n", agentesArr[iCode].iAge);
    printf("Género: %c\n", agentesArr[iCode].cGender);
    printf("Assets: "); 
    for(int i = 0; i <= agentesArr[iCode].iContAssets; i++) {
        printf("%s ", agentesArr[iCode].cAssets[i]);
    }
    printf("\nMisiones: "); 
    for(int i = 0; i <= agentesArr[iCode].iContMisiones; i++) {
        printf("%s ", agentesArr[iCode].cMission[i]);
    }
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
        printf("D. Desplegar información de un agente\n");
        printf("E. Terminar\n");
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
                desplegar(agentesArr);
                break;
            case 'E':
            case 'e':
                iMenu = 0;
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    }
}
 
int main(void)
{
    //Máximo se pueden tener 10 agentes.
    agente agentesArr[10];
    menu(agentesArr);
}