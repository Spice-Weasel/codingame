#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void malloc_output_arrays(int height, char ** pa)
{
    for(int i = 0; i < height; i++)
    {
        pa[i] = malloc(1025 * sizeof(char));
    }
}

void print_output(int height, char ** pa)
{
    for(int i = 0; i < height; i++)
    {
        puts(pa[i]);
    }
}


int get_ascii_art(int height, char ** pa)
/* Read in ascii art into arrays 
*/
{
    for(int i = 0; i < height; i++)
    {
        pa[i] = malloc(1025 * sizeof(char));
        scanf("%[^\n]", pa[i]); fgetc(stdin);
        //printf("%s\n", pa[i]);
    }
    return 0;
}


bool is_lower_case(char c)
/* check if input character falls between 97 & 122
in the ASCII table, if so it is lower case - return true.
*/
{
    bool is_lower = false;

    if(c >= 97 && c <= 122)
    {
        is_lower = true;
    }
    return is_lower;
}


void to_upper(char * c)
/* to be called if input char is lowercase
*/
{
    if(is_lower_case(*c))
    {
        *c -= 32; 
    }
}

int alphabet_position(char c)
/* for char c output position in Roman alphabet
a = 0, b = 1 etc..
*/
{
    if(c >= 65 && c <= 90)
    {
        c -= 65;
    } else {
        c = 26; // position of question mark
    }
    return c;
}

int find_art_row_index(int width, int pos)
/* For a given letter width, find the corresponding start
index of the ascii art letter
*/
{
    return pos * width;  
}

void copy_ascii_to_string(int index, int position, char ** input, char ** output, int height, int width)
/* For a known index, copy the char(s) of width L to an output string
for each row, an offset of (27 * L) should be applied. This will be repeated
for as many rows as there are.
*/
{
    //char temp[5];
    static int output_index = 0;

    for(int i = 0; i < height; i++)
    {
        //memset(temp, '\0', sizeof(char) * 5);

        //printf("Copying from index %d in ascii array\n", index);
        //memcpy(temp, (input[i] + index), sizeof(char) * 4);
        memcpy((output[i] + output_index), (input[i] + index), sizeof(char) * width);

        //printf("%s\n", temp);
    }

    output_index += width;
}
/*
For the long string of ASCII art, each line will be L * 26 chars long
followed by a newline. We need to copy each letter chunk by chunk into
into the output string

We therefore need to find the index corresponding to the beginning of each letter
in the ASCII art input string
*/


int main()
{
    int pos, index;
    char * ROWS[30]; // Store strings in these arrays.
    char * output[30];

    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H); fgetc(stdin);
    char T[257];
    scanf("%[^\n]", T); fgetc(stdin);

    //printf("height %d, width %d\n", H, L);

    get_ascii_art(H, ROWS);

    malloc_output_arrays(H, output);

    for(int letter = 0; T[letter] != '\0'; letter++)
    {
        to_upper(&T[letter]);
    }

    for(int letter = 0; T[letter] != '\0'; letter++)
    {
        // What is the position of the character in the alphabet?
        pos = alphabet_position(T[letter]);

        // Use that information to get the place we need to copy from in
        // the ascii art
        index = find_art_row_index(L, pos);

        //printf("pos %d, index %d\n", pos, index);

        // copy that chunk to an output
        copy_ascii_to_string(index, letter, ROWS, output, H, L);
    }

    print_output(H, output);

    return 0;
}
