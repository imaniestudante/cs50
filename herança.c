#include <stdbool.h>

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

// Cada pessoa tem dois pais e dois alelos

typedef struct person

{

struct person *parents[2];

char alleles[2];
}

person;

const int GENERATIONS = 3;

const int INDENT_LENGTH = 4;

person *create_family(int generations);

void print_family(person *p, int generation);

void free_family(person *p);

char random_allele();

int main(void)

{

// Gerador de números aleatórios de sementes

srand(time(0));

// Crie uma nova família com três gerações

person *p = create_family(GENERATIONS);

// Imprimir árvore genealógica dos tipos sanguíneos

print_family(p, 0);

// Memoria livre

free_family(p);
}

// Crie um novo indivíduo com gerações

person *create_family(int generations)

{

// TODO: Alocar memória para nova pessoa

person *p = malloc(sizeof(person));

if (p == NULL)
{

exit(1);

}

// Geração com dados pai

if (generations > 1)

{

    // TODO: crie recursivamente históricos de tipo sanguíneo para os pais

    p->parents[0] = create_family(generations - 1);

    p->parents[1] = create_family(generations - 1);

    // TODO: Atribuir aleatoriamente alelos filhos com base nos pais

    p->alleles[0] = p->parents[0]->alleles[rand() % 2];

    p->alleles[1] = p->parents[1]->alleles[rand() % 2];

}

// Geração sem dados pai

else
{

    // TODO: Definir ponteiros pai para NULL

    p->parents[0] = NULL;

    p->parents[1] = NULL;

    // TODO: atribuir alelos aleatoriamente

    p->alleles[0] = random_allele();

    p->alleles[1] = random_allele();

}

// TODO: Retornar pessoa recém-criada

return p;
}

// Livre p e todos os ancestrais de p.

void free_family(person *p)

{

if (p == NULL)

{

return;

}

// TODO: Manipular o estojo base

// TODO: Pais livres

// TODO: Criança livre
free_family(p->parents[0]);

free_family(p->parents[1]);

// Libera memória

free(p);

}

// Imprima cada membro da família e seus alelos.

void print_family(person *p, int generation)

{

// Lidar com a caixa de base

if (p == NULL)

{

    return;

}

// Imprimir recuo

for (int i = 0; i < generation * INDENT_LENGTH; i++)

{

    printf(" ");

}

// Impressão de Pessoa

printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
print_family(p->parents[0], generation + 1);

print_family(p->parents[1], generation + 1);
}

// Escolhe aleatoriamente um alelo do tipo sanguíneo.

char random_allele()

{

int r = rand() % 3;

if (r == 0)

{

    return 'A';

}

else if (r == 1)

{

    return 'B';

}

else

{

    return 'O';
}
}