// ***********************************************************************
// Assembly         : 
// Author           : Oren Berkovitch
// Created          : 03-25-2020
//
// Last Modified By : Oren Berkovitch
// Last Modified On : 04-05-2020
// ***********************************************************************
// <copyright file="targil2.c" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#include <stdio.h>
#include <string.h>


char* sub_string(char string[], int position, int length);
int match_score(char text[], char pattern[]);
int match(char text[], char pattern[]);


/// <summary>
/// Mains this instance.
/// </summary>
/// <returns>int.</returns>
int main() {
	
	int index;
	char text[100], pattern[100];

	printf("Please insert text:\n");
	gets(text);
	printf("Please insert pattern:\n");
	gets(pattern);

	index = match(text, pattern);

	printf("the best string match is in the place %d", index);
	getchar();

	return 0;

}


/// <summary>
/// Matches the specified text.
/* this function match the text string  to the pattern string,
first it cut the text string to sub string in the same length as the pattern string 
than it call the match_score function
that give score  for for the match between the text sub string to the pattern string 
this procedure go on for every sub string in the text from index 0,
the function return the minimum un match score  */
/// </summary>
/// <param name="text">The text string .</param>
/// <param name="pattern">The pattern string .</param>
/// <returns>int index for the min match score.</returns>
int match(char text[], char pattern[]) {
	
	int score_unmatch,
		width = strlen(pattern),
		index_minimum = 0,
		loop_size = strlen(text) - strlen(pattern);
	char sample_str[20];

	for (int i = 0; i <= loop_size; ++i) {
		// call sub string
	    *sample_str = sub_string(text, i, width) ;
		// give score for the match
		score_unmatch = match_score(sample_str, pattern);
		if (score_unmatch < width){
			width = score_unmatch;
			index_minimum = i;
		
			if (width == 0) {
				/* in the case their is perfect match
				their is no need for more search */
				break;

			}
		}

	}
	return index_minimum;

}


/// <summary>
/// Matches score.
/*  it compare the pattern string to the text string 
	for every latter , if their is a un match between
	the text latter to the pattern latter
	it give score for every latter that un match. 
	the function return the score, (how much latter in the pattern not fund in  the text).
	*/
/// </summary>
/// <param name="text">The text string.</param>
/// <param name="pattern">The pattern string.</param>
/// <returns>int. return the un match score  </returns>
int match_score(char text[], char pattern[]) {

	int score_unmatch = 0;
	for (int j = 0; j <= strlen(pattern); ++j) {

		if (text[j]!=pattern[j]) {
			score_unmatch++;
		}
	}
	return score_unmatch;
}




/// <summary>
/// Subs the string.
/* this function cut the string from index position to the giving length
it return the sub string that cut from the original string */
/// </summary>
/// <param name="string">The original string.</param>
/// <param name="position">The initial index position.</param>
/// <param name="length">The length of the sub string.</param>
/// <returns>char *. sub string</returns>
char* sub_string(char string[], int position, int length) {
	int c = 0;
	char sub[20];
	
	while (c < length) {
		sub[c] = string[position + c];
		c++;
	}
	sub[c] = '\0';
	

	return *sub;
}




