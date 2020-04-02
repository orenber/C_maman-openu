#include <stdio.h>
#include <string.h>


char* subString(char string[], int position, int length);
int matchScore(char text[], char patern[]);
int Match(char text[], char patern[]);


int main() {
	
	int index;
	char text[20], patern[20];

	printf("Please insert text:\n");
	//scanf("%s",text);
	printf("Please insert pattern:\n");
	//scanf("%s", patern);

	index = Match( text, patern);

	printf("the best string match is in the place %d", index);
	getchar();

	return 0;

}


int Match(char text[],char patern[]) {
	int score_Unmatch,
		last_minimum = strlen(patern), 
		index_minimum = 0,
		loop_size = strlen(text) - strlen(patern);

	char *sampleStr;


	for (int i = 0; i <= loop_size; ++i) {
		
		sampleStr = subString(text, i, strlen(patern));
		score_Unmatch = matchScore(sampleStr,patern);
		if (score_Unmatch < last_minimum){
			last_minimum = score_Unmatch;
			index_minimum = i;
		
			if (last_minimum == 0) {
				/* in the case ther is perfect match
				ther is no need for more search */
				break;

			}
		}

	}
	return index_minimum;

}


int matchScore(char text[], char patern[]) {

	int score_Unmatch = 0;
	for (int j = 0; j <= strlen(patern); ++j) {

		if (text[j]!=patern[j]) {
			score_Unmatch++;
		}
	}
	return score_Unmatch;
}




char* subString(char string[], int position, int length) {
	int c = 0;
	char sub[1000];

	while (c < length) {
		sub[c] = string[position + c];
		c++;
	}
	sub[c] = '\0';


	return *sub;
}




