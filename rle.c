#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress()
{
    int seen_char = getchar();
    if (seen_char == EOF){
        putchar(seen_char);
        return;
    }

    int repeat_counter = 1;
    int next_char;

    while ((next_char = getchar()) != EOF) 
    {
        if (next_char == seen_char && repeat_counter <= 0xFF)
        {
            repeat_counter++;

            if (repeat_counter > 0xFF)
            {
                putchar(seen_char);
                putchar(repeat_counter);
                repeat_counter = 1;
            }
        }
        else
        {
            putchar(seen_char);
            putchar(repeat_counter);
            repeat_counter = 1;
            seen_char = next_char;
        }
    }
    putchar(seen_char);
    putchar(repeat_counter);
}

void decompress() 
{
    while(1)
    {
        int value = getchar();
        if (value == EOF) break;
        int count = getchar();
        if (count == EOF) break;

        for (int i = 0; i < count; i++)
        {
            putchar(value);
        }
    };
}

int main(int argc, char *argv[]) 
{    
    if (argc !=2)
    {
        printf("Usage: %s [compress|decompress]\n", argv[0]);
        exit(-1);
    }
    else if (!strcmp(argv[1], "compress"))
    {
        compress();
    }
    else if (!strcmp(argv[1], "decompress"))
    {
        decompress();
    }
    else 
    {
        printf("Usage: %s [compress|decompress]\n", argv[0]);
        exit(-1);
    }
};