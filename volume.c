#include <stdint.h>

#include <stdio.h>

#include <stdlib.h>


const int HEADER_SIZE = 44;

int main(int argc, char *argv[])

{


    if (argc != 4)

    {

        printf("Usage: ./volume input.wav output.wav factor\n");

        return 1;

    }


    FILE *input = fopen(argv[1], "r");

    if (input == NULL)

    {

        printf("Could not open file.\n");

        return 1;

    }

    FILE *output = fopen(argv[2], "w");

    if (output == NULL)

    {

        printf("Could not open file.\n");

        return 1;

    }


    float factor = atof(argv[3]);

    uint8_t header[HEADER_SIZE];

    int16_t buffer;


    fread(header, HEADER_SIZE, 1, input);

    fwrite(header, HEADER_SIZE, 1, output);


    while (fread(&buffer, sizeof(buffer), 1, input))

    {

        buffer *= factor;

        fwrite(&buffer, sizeof(buffer), 1, output);

    }


    fclose(input);

    fclose(output);

}
