#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

int LENGTH;
// Represents a node in a hash table
typedef struct node
{
char word[LENGTH + 1];
struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH+1) * 'z';

// Hash table
node *table[N];

// Number of total words
int total_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
// Variables
int indice = hash(word);
node *cursor = table[indice];

while(cursor != NULL){

    // If word was found return true
    if(strcasecmp(cursor -> word, word) == 0){

        return true;
    }
    // Else move to the next pointer
    cursor = cursor -> next;
}
return false;
}

// Hashes word to a number
unsigned int hash(const char *word){

int soma = 0;
// Loop to sum each letter from a word
for(int i = 0; i < strlen(word); i++){

    soma += tolower(word[i]);
}
return (soma % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary){

// Open the File
FILE *dictionary_pointer = fopen(dictionary, "r'");

// Check if is valid
if(dictionary_pointer == NULL){

    printf("cannot open file:\n");
    return false;
}

// Variables
char word_scan[LENGTH + 1];
int hash_value = 0;

// Loop through the file until the end
while(fscanf(dictionary_pointer, "%s", word_scan)!=EOF){

    // Ask for memory with the size of a node
    node *new_node = malloc(sizeof(node));

    // Check if is valid
    if(new_node == NULL){

        printf("cannot open file:\n");
        return false;
    }

    // Copy each word from the file and set the pointer to NULL
    strcpy(new_node -> word, word_scan);
    new_node -> next = NULL;

    //Hash word
    hash_value = hash(word_scan);

    // If the pointer is NULL set the new value
    if(table[hash_value] == NULL){

        table[hash_value] = new_node;

    // Else set new_node first
    }else{

        new_node -> next = table[hash_value];
        table[hash_value] = new_node;
    }
    total_words++;
}
// Close the file
fclose(dictionary_pointer);
return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void){

return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void){

for(int i = 0; i < N; i++){

    node *start = table[i];
    node *cursor = start;
    node *temp = start;

    while(cursor != NULL){

        cursor = cursor -> next;
        free(temp);
        temp = cursor;
    }
}
return true;
}