#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rle_node
{
    char letter;
    int freq;
} rle_node;

int rle_encode(char *string, rle_node *output)
{
    int i = 0;
    int out_index = 0;

    while (string[i] != '\0')
    {
        int count = 0;
        char current = string[i];
        while (string[i] == current)
        {
            ++count;
            ++i;
        }
        output[out_index].letter = current;
        output[out_index].freq = count;
        out_index++;
    }
     return out_index;
}

void rle_decode(rle_node *input, int size, char *output)
{
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < input[i].freq; j++)
        {
            output[k++] = input[i].letter;
        }
    }

    output[k] = '\0';
}

int main()
{
    char *string = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";

    rle_node encoded[100];  // max possible runs
    char decoded[200]; // decoded buffer

     int encoded_size = rle_encode(string, encoded);

    printf("Encoded Output:\n");
    for (int i = 0; i < encoded_size; i++)
    {
        printf("(%c,%d) ", encoded[i].letter, encoded[i].freq);
    }

    printf("\n\nDecoded Output:\n");

    rle_decode(encoded, encoded_size, decoded);
    printf("%s\n", decoded);

    return 0;
    return 0;
}