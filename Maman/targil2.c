/* ***********************************************************************
// Assembly         : 
// Author           : Oren Berkovitch
// Created          : 03-25-2020
//
// Last Modified By : Oren Berkovitch
// Last Modified On : 04-05-2020
// ***********************************************************************
// <summary>this programs take 2 string inputs from the user:
text and pattern , it Returns the index location from which the best match occurs
(between the text to the pattern).
</summary>
***********************************************************************/
#include <stdio.h>
#include <string.h>


int match_score(char text[], char pattern[]);
int match(char text[], char pattern[]);


/// <summary>
/// Mains this instance.
/// </summary>
/// <returns>int.</returns>
int main() {
	
	int index;/* the best index position match between the pattern to the text */
	char text[100], /*text string */
		pattern[20]; /* pattern string */

	printf("Please insert text:\n");
	fgets(text,strlen(text),stdin);
	/* remove the \n trail char*/
	text[strlen(text) - 1] = '\0';
	printf("Please insert pattern:\n");

	fgets(pattern,strlen(pattern),stdin);
	/* remove the \n trail char*/
	pattern[strlen(pattern) - 1] = '\0';

	index = match(text, pattern);

	printf("the best string match is in the place %d", index);
	getchar();

	return 0;

}


/// <summary>
/// Matches the specified text.
/* this function match the patten string  to the text string,
first it cut the text string to sub string in the same length as the pattern string 
than it call the match_score function
that give score for the match between the text sub string to the pattern string, 
this procedure go on for every sub string in the text from index 0 to loop_size,
the function return the index position  of the best minimum match score 
(the score scale is: 0 for perfect match, pattern length - worst match). */
/// </summary>
/// <param name="text">The text string .</param>
/// <param name="pattern">The pattern string .</param>
/// <returns>int index for the min match score.</returns>
int match(char text[], char pattern[]) {
	
	int score_match,/* score for the match between the pattern to text*/
		pattern_length = (int)strlen(pattern), /*pattern string length*/
		best_min_score = pattern_length, /*min score for all the subs string */
		index_match_position = 0,/*index best match position*/
		loop_size = (int)strlen(text) - pattern_length; /*loop size iteration*/

	char sub_string[20]; /*partial string of text string */

	for (int i = 0; i <= loop_size; ++i) {
		//sub string 
		strncpy(sub_string,text+ i, pattern_length) ;

		// give score for the match
		score_match = match_score(sub_string, pattern);

		if (score_match < best_min_score){
			/* take the best score of all iteration sub string (minimum score)*/
			best_min_score = score_match;
			index_match_position = i;
		
			if (best_min_score == 0) {
				/* in the case their is perfect match
				their is no need for more search */
				break;

			}
		}

	}
	return index_match_position;

}


/// <summary>
/// Matches score.
/*  it compare the pattern string to the text string (the same length)
	for every latter , if their is a un match between
	the text latter to the pattern latter
	it give score for every latter that un match. 
	the function return the score, (how much latter in the pattern not found in  the text).
	*/
/// </summary>
/// <param name="text">The text string.</param>
/// <param name="pattern">The pattern string.</param>
/// <returns>int. return the un match score  </returns>
int match_score(char text[], char pattern[]) {

	int score_un_match = 0,/* score for the match between the pattern to text*/
		pattern_length = (int)strlen(pattern); /*pattern string length*/
	
	for (int j = 0; j <= pattern_length; ++j) {

		if (text[j]!=pattern[j]) {
			score_un_match++;
		}
	}
	return score_un_match;
}





