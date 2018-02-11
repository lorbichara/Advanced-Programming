//Lorraine Bichara Assad A01193063
//Fecha: 25 de enero de 2018
//P4. Structures
//Programa que guarda en una estructura la información de un agente.
#include <stdio.h>
#include <string.h>

struct Agent {
	char cName[10];
	char cLName[10];
	int iAge;
	char cGender;
	char cMission[12];
};

int main() {
	struct Agent a1;
	
	printf("Introduce the agent's name: ");
	scanf("%s", a1.cName);

	printf("Introduce the agent's last name: ");
	scanf("%s", a1.cLName);

	printf("Introduce the agent's age: ");
	scanf("%d", &a1.iAge);

	printf("M/F? ");
	scanf(" %c", &a1.cGender);

	printf("Introduce his mission Id: ");
	scanf("%s", a1.cMission);

	printf("-------AGENT-------\n");
	printf("Name: %s %s\n", a1.cName, a1.cLName);
	printf("Age: %d\n", a1.iAge);
	printf("Gender: %c\n", a1.cGender);
	printf("Mission: %s\n", a1.cMission);
}