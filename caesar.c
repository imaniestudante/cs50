#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, string argv[])
{
if (argc != 2) 
{
printf("Usage: ./caesar key\n");
return 1;
}

string chave = argv[1];
for (int i = 0, n = strlen(chave); i < n; i++) 
{
    if (isdigit(chave[i]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
int key = atoi(argv[1]); 
   
if (key > 26) 
{
    key %= 26;
}

string p = get_string("plaintext: "); 

printf("ciphertext: ");
for (int i = 0, n = strlen(p); i < n; i++) 
{
    if ((p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z'))  
    {
        if ((isupper(p[i]) && p[i] + key > 90) || (islower(p[i]) &&  p[i] + key > 122))  
        {
            p[i] = (int) p[i] - 26;
        }
        p[i] = (int) p[i] + key; 
    }
    printf("%c", p[i]); 
}
printf("\n");
return 0;
}