//Lorraine Bichara Assad A01193063
//Fecha: 6 de febrero de 2018
//P7. Data Union
//Programa que guarda en una estructura la información de un agente a través de un data union.

#include <stdio.h>
#include <string.h>

struct Agent {
	char cName[11];
	char cLName[11];
	int iAge;
	char cGender[2];
	char cMission[13];
}s;

//Union that consists of:
//an integer, a double, a string of 100 chars, and a pointer to the structure agent.
union Agente {
	int iEntero;
	double dDecimal;
	char cString[100];
	struct Agent agente;
}u;

int main() {	
	printf("Introduce the agent's name: ");
	scanf("%s", u.cString);
	strcpy(s.cName, u.cString);

	printf("Introduce the agent's last name: ");
	scanf("%s", u.cString);
	strcpy(s.cLName, u.cString);

	printf("Introduce the agent's age: ");
	scanf("%d", &u.iEntero);
	s.iAge = u.iEntero;

	printf("M/F? ");
	scanf("%s", u.cString);
	strcpy(s.cGender, u.cString);

	printf("Introduce their mission Id: ");
	scanf("%s", u.cString);
	strcpy(s.cMission, u.cString);

	printf("-------AGENT-------\n");
	printf("Name: %s %s\n", s.cName, s.cLName);
	printf("Age: %d\n", s.iAge);
	printf("Gender: %s\n", s.cGender);
	printf("Mission: %s\n", s.cMission);
}