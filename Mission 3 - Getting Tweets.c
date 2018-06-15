// Lorraine Bichara Assad A01193063
// Fecha: 12 de marzo de 2018.
// M3. Getting information from Twitter
// Your mission, should you choose to accept it (or not), involves getting intelligence from Twitter. 
// Your field agent is about to infiltrate into a museum (You can choose any museum you like). 
// His/her cover is as a social media expert. He/she needs information about the museum, about popular exhibits or events, about what people are talking about. 
// But has no time to browse the Twitter feed. Your task is to build a C program should look for all hashtags available on the museum 
// and show the result on screen (the hashtag and the number of occurrences).
// This is not done in real time

#include <stdio.h>
#include <string.h>

struct map {
	char hashtag[50];
	int count;
};

int main() {
	FILE *file = fopen("soumaya.html", "r");
	int hashtagCount = 0;
	struct map hashtagArray[100];
	struct map final[100];
	char string[1000];
	char hashtagv1[50];
	char hashtagv2[50];
	int indexEOH = 0;
	int ibool = 0; 

	while(EOF != fscanf(file, "%1000s", string)) {
		ibool = 0;
		indexEOH = 0;
		hashtagv1[0] = '\0';
		hashtagv2[0] = '\0';
		if((strstr(string, "dir=\"ltr\"><s>#</s><b>") != NULL)) {
			strncpy(hashtagv1, string + 21, 49); //all hashtags 
			for(int i = 0; i < strlen(hashtagv1); i++) {
				if(!(hashtagv1[i] == '<'))
					indexEOH++;
				else
					break;
			}

			strncpy(hashtagv2, hashtagv1, indexEOH);
			hashtagv2[indexEOH] = '\0';
			//printf("%s\n", hashtagv2);

			for(int i = 0; i <= hashtagCount; i++) {
				if((strcmp(hashtagv2, hashtagArray[i].hashtag) == 0)) {
					hashtagArray[i].count++;
					ibool = 1;
				}
				else {
					ibool = 0;
				}	
			}

			if(ibool == 0) {
				strcpy(hashtagArray[hashtagCount].hashtag, hashtagv2);
				hashtagArray[hashtagCount].count = 1;
			}

			hashtagCount++;	
		} 
	}

	int arr2 = 0;
	for(int i = 0; i < hashtagCount; i++) {
		struct map temp = hashtagArray[i];

		int isDup = 0;
		for(int j = 0; j < arr2; j++) {
			if(strcmp(temp.hashtag, final[j].hashtag) == 0) {
				isDup = 1;
				break;
			}
		}
		if(isDup == 0) {
			final[arr2] = temp;
			++arr2;
		}

	}

	for(int i = 0; i < arr2; i++) {
		printf("#%s %d\n", final[i].hashtag, final[i].count);
	}

	fclose(file);
}