#include <math.h>
#include <cs50.h>
#include <stdio.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
for (int i = 0; i < height; i++)
{
for (int j = 0; j < width; j++)

{ int media_rgb = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
image[i][j].rgbtBlue = media_rgb;
image[i][j].rgbtGreen = media_rgb;
image[i][j].rgbtRed = media_rgb; }

}
return;
}
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
for (int i = 0; i < height; i++)
{
for (int j = 0; j < ceil(width / 2); j++)
{
//Auxiliam a troca do inicio
RGBTRIPLE end_reflects;
end_reflects.rgbtBlue = image[i][width - j].rgbtBlue;
end_reflects.rgbtGreen = image[i][width - j].rgbtGreen;
end_reflects.rgbtRed = image[i][width - j].rgbtRed;

//Auxiliam a troca do final
RGBTRIPLE start_reflects;
start_reflects.rgbtBlue = image[i][j].rgbtBlue;
start_reflects.rgbtGreen = image[i][j].rgbtGreen;
start_reflects.rgbtRed = image[i][j].rgbtRed;

//Troca pixels inicio
image[i][j].rgbtBlue = end_reflects.rgbtBlue;
image[i][j].rgbtGreen = end_reflects.rgbtGreen;
image[i][j].rgbtRed = end_reflects.rgbtRed;

//Troca pixels final
image[i][width - j].rgbtBlue = start_reflects.rgbtBlue;
image[i][width - j].rgbtGreen = start_reflects.rgbtGreen;
image[i][width - j].rgbtRed = start_reflects.rgbtRed;
} }
return;
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
for (int i = 0; i < height; i++)
{
for (int j = 0; j < width; j++)
{
//Soma, e quantidade de pixels do lado
double qtd = 0.0;
double somaRed = 0.0;
double somaGreen = 0.0;
double somaBlue = 0.0;

//Total de pixels
for (int k = i - 1; k < i + 2; k++)
{
for (int l = j - 1; l < j + 2; l++)
{
if ((k >= 0 && k < height) && (l >= 0 && l < width))

{ qtd++;
somaRed += image[k][l].rgbtRed;
somaGreen += image[k][l].rgbtGreen;
somaBlue += image[k][l].rgbtBlue; }

} }

image[i][j].rgbtRed = round(somaRed / qtd);
image[i][j].rgbtGreen = round(somaGreen / qtd);
image[i][j].rgbtBlue = round(somaBlue / qtd);
} }
return;
}
void edges(int height, int width, RGBTRIPLE image[height][width])
{
RGBTRIPLE img[height][width];
for (int i = 0; i < height; i++)
{
for (int j = 0; j < width; j++)

{ img[i][j] = image [i][j]; }
}

//Verifica a linha e coluna de pixel
for (int i = 0; i < height; i++)
{
for (int j = 0; j < width; j++)
{

//Calcula os pixels na primeira linha e separa as colunas em primeira, ultima e demais.
if (i == 0)