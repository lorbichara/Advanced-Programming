//Lorraine Bichara Assad
//A01193063
//february 13, 2018
//Hour of Code 2

// You have to convey a new agent ID to your field agent. To do this, you will build a program that:

// Validate the user is an agent.
// Gather random numbers from the agent until you have nine digits.
// Scramble the numbers and generate a new agent code.
// There are some restrictions. As you can remember an agent ID is a 6 letter and 9 numbers code (lomael123456789). You have to validate this information (we are not checking if it is a valid agent code (active on a database), just a properly formed one), if it is not properly formed you get an error screen.
// Random numbers from the agent are going to be captured as words (nine, one hundred). Valid numbers will be from 0-999. If it is not a valid number you will tell the user and prepare to capture another one. The program will convert this words to integer numbers and generate an array.
// After you fill the array with numbers, you can scramble it as you want, then add six letter characters at the beginning and present the result to the user.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TRUE 1

//Function that validates if the ID entered by the user is valid (according to the format).
//Parameters: ID. Returns 0 if invalid, 1 if valid.
int validID(char cID[]) {
	for(int i = 0; i < 6; i++) {
		if(!isalpha(cID[i])) {
			printf("The ID you entered is not a valid ID.\n");
			return 0;
		}
	}

	for(int i = 6; i < 15; i++) {
		if(!isdigit(cID[i])) {
			printf("The ID you entered is not a valid ID.\n");
			return 0;
		}
	}
	return 1;
}

//Function that separates based on spaces,
//the number entered by the user into a 2D array.
//Parameters: string with number, 2D array. Returns amount of elements.
//Extracted from: http://www.includehelp.com/code-snippets/c-program-to-split-string-into-the-words-separated-by-spaces.aspx
int separateStrings(char *base, char target[10][20])
{
	int n = 0;
	int j = 0;
	
	for(int i = 0; TRUE; i++)
	{
		if(base[i]!=' '){
			target[n][j++]=base[i];
		}
		else{
			target[n][j++]='\0';
			n++;
			j=0;
		}
		if(base[i]=='\0')
		    break;
	}
	return n;
}

//Function that compares two strings without using <string.h>
//Parameters: two strings
//Returns 0 if they're the same, -1 if they're different.
int stringcmp(char string1[], char string2[])
{
    int i = 0;

    while(string1[i]==string2[i])
    {
        if(string1[i]=='\0'||string2[i]=='\0')
            break;
        i++;
    }
    if(string1[i]=='\0' && string2[i]=='\0')
        return 0;
    else
        return -1;
}

//Function that shuffles the digits in the ID.
//Parameters: ID. Returns shuffled ID.
char * shuffle(char s1[]) {
	for(int i = 9; i < 16; i++) {
		s1[i] = '\0';
	}

	char temp;
	int j = 8;
	for(int i = 0; i < 5; i++) {
		temp = s1[i];
		s1[i] = s1[j];
		s1[j] = temp;
		j--;
	}
	return s1;
}

//Function that counds amount of digits.
//From: https://stackoverflow.com/questions/9721042/count-number-of-digits-which-method-is-most-efficient
//Parameters: number whose digits will be counted.
int countDigits(int num)
{
    return (int) log10(num) + 1;
}

//Function that concatenates two strings, to keep adding the new numbers entered by user.
//Parameters: string, and new number.
//Returns the string with the number added as a string.
//Extracted from: https://www.programiz.com/c-programming/examples/concatenate-string
char * concatenate(char s1[], int num) {
	char s2[5];
	sprintf(s2, "%d", num);

	int i;
	int j;

    // calculate the length of string s1
    // and store it in i
    for(i = 0; s1[i] != '\0'; ++i);

    for(j = 0; s2[j] != '\0'; ++j, ++i)
    {
        s1[i] = s2[j];
    }

    s1[i] = '\0';
    return s1;
}

//Function that adds the original letters to the new ID.
//Parameters: old and new ID, returns new ID.
char * addLetters(char newID[], char oldID[]) {
	for(int i = 0; i < 9; i++) {
		newID[i+6] = newID[i];
	}

	for(int i = 0; i < 6; i++) {
		newID[i] = oldID[i];
	}

	return newID;
}

int main() {
	char sAgentID[16]; //string that holds ID introduced by user. 16 = 6 + 9 + \0
	char sNumber[40]; //string that will hold numbers entered by the user in word form.
	int iWords; //amount of words in number
	char sSeparate[10][20]; //2D array that will store each separate word
	char newline; //to avoid inputting new lines in other variable

	printf("Introduce your agent ID: ");
	scanf("%s", sAgentID);

	while(validID(sAgentID) == 0) {
		printf("Introduce your agent ID: ");
		scanf("%s", sAgentID);
	}
	
	iWords = separateStrings(sNumber,sSeparate);

	// "The basic strategy would be to have a value variable that you work with. 
	// Each time you see a string "one", "two", "eleven", "seventy" you would add that amount to value. 
	// When you see a string like "hundred", "thousand", "million", you would multiply value by that amount."
	// - Brad Mace on https://stackoverflow.com/questions/4062022/how-to-convert-words-to-a-number

	int iCont = 0; //checks for 9 digits only
	int iValue = 0; //holds value of number
	char newID[16]; //will hold new ID

	while(iCont < 9) {
		scanf("%c", &newline);
		printf("Introduce a number using letters (use spaces instead of hyphens): ");

		scanf("%[^\n]s", sNumber);
		iWords = separateStrings(sNumber,sSeparate);
		iValue = 0;
		for(int i = 0; i <= iWords; i++) {
			if((stringcmp(sSeparate[i], "one")) == 0)
				iValue += 1;
			else if((stringcmp(sSeparate[i], "two")) == 0)
				iValue += 2;
			else if((stringcmp(sSeparate[i], "three")) == 0)
				iValue += 3;
			else if((stringcmp(sSeparate[i], "four")) == 0)
				iValue += 4;
			else if((stringcmp(sSeparate[i], "five")) == 0)
				iValue += 5;
			else if((stringcmp(sSeparate[i], "six")) == 0)
				iValue += 6;
			else if((stringcmp(sSeparate[i], "seven")) == 0)
				iValue += 7;
			else if((stringcmp(sSeparate[i], "eight")) == 0)
				iValue += 8;
			else if((stringcmp(sSeparate[i], "nine")) == 0)
				iValue += 9;
			else if((stringcmp(sSeparate[i], "ten")) == 0)
				iValue += 10;
			else if((stringcmp(sSeparate[i], "eleven")) == 0)
				iValue += 11;
			else if((stringcmp(sSeparate[i], "twelve")) == 0)
				iValue += 12;
			else if((stringcmp(sSeparate[i], "thirteen")) == 0)
				iValue += 13;
			else if((stringcmp(sSeparate[i], "fourteen")) == 0)
				iValue += 14;
			else if((stringcmp(sSeparate[i], "fifteen")) == 0)
				iValue += 15;
			else if((stringcmp(sSeparate[i], "sixteen")) == 0)
				iValue += 16;
			else if((stringcmp(sSeparate[i], "seventeen")) == 0)
				iValue += 17;
			else if((stringcmp(sSeparate[i], "eighteen")) == 0)
				iValue += 18;
			else if((stringcmp(sSeparate[i], "nineteen")) == 0)
				iValue += 19;
			else if((stringcmp(sSeparate[i], "twenty")) == 0)
				iValue += 20;
			else if((stringcmp(sSeparate[i], "thirty")) == 0)
				iValue += 30;
			else if((stringcmp(sSeparate[i], "fourty")) == 0)
				iValue += 40;
			else if((stringcmp(sSeparate[i], "fifty")) == 0)
				iValue += 50;
			else if((stringcmp(sSeparate[i], "sixty")) == 0)
				iValue += 60;
			else if((stringcmp(sSeparate[i], "seventy")) == 0)
				iValue += 70;
			else if((stringcmp(sSeparate[i], "eighty")) == 0)
				iValue += 80;
			else if((stringcmp(sSeparate[i], "ninety")) == 0)
				iValue += 90;
			else if((stringcmp(sSeparate[i], "hundred")) == 0)
				iValue *= 100;
			else
				printf("Number not valid.\n");
		}
		iCont += countDigits(iValue);
		concatenate(newID, iValue);
	}

	shuffle(newID);
	addLetters(newID, sAgentID);
	printf("%s\n", newID);

	return 0;
}