#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
if (argc != 2)
{

    printf("vc deve digitar ./recover filename\n");
    return 1;
}

FILE *f = fopen(argv[1], "r");
if (!f)
{
    return 1;
}
BYTE buffer[BLOCK];
int count = 0;
char filename[8];
FILE *output = NULL;
while (fread(buffer, sizeof(BYTE), BLOCK, f) == BLOCK)
{

    if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) ==0xe0)
    {
        if(count>0)
        {
            fclose(output);
        }

        sprintf(filename,"%03i.jpg", count);
        output = fopen(filename, "w");
        fwrite(buffer,	sizeof(buffer),	1,	output);
        count++;

    }
    else if (count>0)
    {
        fwrite(buffer, sizeof(buffer), 1, output);
    }
}
}