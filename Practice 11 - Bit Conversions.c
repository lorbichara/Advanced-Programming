// Lorraine Bichara Assad A01193063
// feb 27, 2018
// Practice 11: Conversiones y operaciones a bit
// Question 6

#include <stdio.h>
#include <string.h>

// QUESTION 1
// Function that converts an hexadecimal string (received as parameter) to a decimal number.
// It returns the result as an int.
int asciiHEXToInt(char *s)
{   
	int iLength = strlen(s);
    int iBase = 1;
    int iResultado = 0;
     
    for (int i = iLength - 1; i >= 0; i--)
    {   
        if (s[i]>='0' && s[i]<='9') //caracteres de 0-9
        {
        	//valores ascii
            iResultado += (s[i] - 48) * iBase;
            iBase = iBase << 4; //Uso de bitshift para multiplicar por 16
        }
 
        else if (s[i]>='A' && s[i]<='F') //caracteres de A-F
        {
            iResultado += (s[i] - 55)* iBase;
            iBase = iBase * 16;
        }
    }
    return iResultado;
}

// QUESTION 2
// Function that converts a binary string (received as parameter) to a decimal number.
// It returns the result as an int.
int asciiBinaryToInt(char *s) {
	int iResultado = 0;

	while(*s != '\0') {
		
       iResultado = iResultado << 1; //use of bitshift to multiply * 2
       
       if(*s++ == '1')
       {
           iResultado += 1;
       }
	}

   return iResultado;
}

// QUESTION 3
// Function that converts an octal string (received as parameter) to a decimal number.
// It returns the result as an int.
int asciiOCTToInt(char *s) {
	int iLength = strlen(s);
    int iBase = 1;
    int iResultado = 0;
     
    for (int i = iLength - 1; i >= 0; i--)
    {   
        	//valores ascii
            iResultado += (s[i] - 48) * iBase;
            iBase = iBase << 3; //Uso de bitshift para multiplicar por 8
    }
    return iResultado;
}

//QUESTION 4
//Function that receives a pointer to a number.
//Returns the number multiplied by two, using bit shifts.
int divideByTwo(int *i) {
	int answer;
	answer = i[0] >> 1;
	return answer;
}

//QUESTION 5
//Function that receives a pointer to a number.
//Returns the number multiplied by two, using bit shifts.
int multByTwo(int *i) {
	int answer;
	answer = i[0] << 1;
	return answer;
}

int main() {
	int iMenu = 1;
    char cOpcion;
    char sHexa[9];
    char sBinary[9];
    char sOctal[9];
    int x;


    while (iMenu == 1) {
        printf("\n-----------------MENU-----------------\n");
        printf("A. Convertir de hexadecimal a decimal.\n");
        printf("B. Convertir de binario a decimal.\n");
        printf("C. Convertir de octal a decimal.\n");
        printf("D. Dividir por 2.\n");
        printf("E. Multiplicar por 2.\n");
        printf("F. Terminar.\n");
        printf("Teclee la letra de la opción deseada: ");

        scanf(" %c", &cOpcion);
        switch (cOpcion) {
            case 'A':
            case 'a':
				printf("Introduce an hexadecimal number (max 8 bits): ");
				scanf("%s", sHexa);
				printf("The decimal version for your hexadecimal number is: %d\n", asciiHEXToInt(sHexa));
                break;
            case 'B':
            case 'b':
				printf("Introduce a binary number (max 8 bits): ");
				scanf("%s", sBinary);
				printf("The integer version for your binary number is: %d\n", asciiBinaryToInt(sBinary));
                break;
            case 'C':
            case 'c':
				printf("Introduce an octal number (max 8 bits): ");
				scanf("%s", sOctal);
				printf("The integer version for your octal number is: %d\n", asciiOCTToInt(sOctal));
                break;
            case 'D':
            case 'd':
				printf("Introduce a number to divide by 2: ");
				scanf("%d", &x);
				printf("Result: %d\n", divideByTwo(&x));
                break;
            case 'E':
            case 'e':
				printf("Introduce a number to multiply by 2: ");
				scanf("%d", &x);
				printf("Result: %d\n", multByTwo(&x));
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