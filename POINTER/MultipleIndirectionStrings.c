#include <stdio.h>

#define LENGTH 3

char* words[LENGTH];		// some strings

int main(int argc, char **argv) {
	char **ppc;			// a pointer to a pointer to a character

	printf ("multiple indirection example\n");

	// initialize our string array
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";

	/*
	* B: a pointer to an array of strings
	*    - the same as a pointer to a pointer to a character
	*
	*/
	ppc = words;							// initialize the pointer to a pointer to a character
	for (int i = 0; i < LENGTH; i++) {	// loop over each string
    	while (**ppc != 0) {      // process each character in a string
            printf("%c", **ppc);  // print out each character of the string individually
            ++*ppc;
        }
        printf("\n");
  		ppc = ppc + 1;
		  
	}


	return 0;
}