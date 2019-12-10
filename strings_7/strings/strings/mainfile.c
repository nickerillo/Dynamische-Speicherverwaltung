#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void printText(char* text[], int nrWords) {

	char** ptr;
	ptr = (char**) malloc(sizeof(char*) * nrWords);
	for (int word = 0; word < nrWords; word++) {
		ptr[word] = (char*)malloc(sizeof(char) * (strlen(text[word]) + 1));
		strcpy(ptr[word], text[word]);
		printf("\n%s ", ptr[word]);
	}

}

void deleteText(char* text[], int nrWords) {
	for (int words = 1; words < nrWords; words++) {
		if (text[words] != NULL) {
			free(text[words]);
		}
		else printf("iwas raff ich nicht");
	}
	if (text != NULL)
		free(text);
}

void textReverse(char* text[], int nrWords) {
	int rev = nrWords - 1;
	char** kopie;
	kopie = (char**)malloc(sizeof(char*) * nrWords);
	for (int words = 1; words < nrWords; words++) {
		kopie[rev] = (char*)malloc(sizeof(char) * (strlen(text[words]) + 1));
		strcpy(kopie[rev], text[words]);
		rev -= 1;
	}
	for (int i = 1; i < nrWords; i++) {
		printf("%s ", kopie[i]);
	}
	deleteText(kopie, nrWords);
}



int main (int argc, char *argv[]) 
{
	textReverse(argv, argc);
//	printText(argv, argc);
	system("pause");
	return 0;
}