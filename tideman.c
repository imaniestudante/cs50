#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

int preferences[MAX][MAX];

bool locked[MAX][MAX];

typedef struct
{
int winner;
int loser;
}
pair;

string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
// VOTO INVALIDO
if (argc < 2)
{
printf("DIGITE OS NOMES DOS CANDIDATOS\n");
return 1;
}

candidate_count = argc - 1;
if (candidate_count > MAX)
{
    printf("NUMERO MÁXIMO DE CANDIDATOS É %i\n", MAX);
    return 2;
}
for (int i = 0; i < candidate_count; i++)
{
    candidates[i] = argv[i + 1];
}

for (int i = 0; i < candidate_count; i++)
{
    for (int j = 0; j < candidate_count; j++)
    {
        locked[i][j] = false;
    }
}

pair_count = 0;
int voter_count = get_int("NÚMERO DE ELEITORES: ");

for (int i = 0; i < voter_count; i++)
{
    int ranks[candidate_count];

    for (int j = 0; j < candidate_count; j++)
    {
        string name = get_string("VENCEDOR %i: ", j + 1);

        if (!vote(j, name, ranks))
        {
            printf("VOTO INVÁLIDO.\n");
            return 3;
        }
    }

    record_preferences(ranks);

    printf("\n");
}

add_pairs();
sort_pairs();
lock_pairs();
print_winner();
return 0;
}

bool vote (int rank, string name, int ranks[])
{
for (int i = 0; i < candidate_count; i++)
{
if(strcmp(name, candidates[i]) == 0)
{
ranks[rank] = i;
return true;
}
}
return false;
}

void record_preferences(int ranks[])
{
for (int i = 0; i < candidate_count; i++)
{
for (int j = i + 1; j < candidate_count; j++)
{
preferences[ranks[i]][ranks[j]] += 1;
}
}
return;
}

void add_pairs(void)

{
for (int i = 0; i < candidate_count; i++)
{
for (int j = i + 1; j < candidate_count; j++)
{
if (preferences[i][j] > preferences[j][i])
{
pairs[pair_count].winner = i;
pairs[pair_count].loser = j;
pair_count++;
}
else if (preferences[i][j] < preferences[j][i])
{
pairs[pair_count].winner = j;
pairs[pair_count].loser = i;
pair_count++;
}
}
}
return;
}

void sort_pairs(void)
{
for (int i = 0; i < pair_count; i++)
{
int max = i;
for (int j = i + 1; j < pair_count; j++) {
if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[max].winner][pairs[max].loser])
{
max = j;
}
}
pair temp = pairs[i];
pairs[i] = pairs[max];
pairs[max] = temp;
}
return;
}

bool is_circle(int loser, int winner)
{
if (loser == winner) {
return true;
}

for (int i = 0; i < candidate_count; i++)
{
    if(locked[loser][i])
    {
        return is_circle(i, winner);
    }
}

return false;
}

void lock_pairs(void)
{
for (int i = 0; i < pair_count; i++)
{
if (!is_circle(pairs[i].loser, pairs[i].winner))
{
locked[pairs[i].winner][pairs[i].loser] = true;
}

}
return;
}

void print_winner(void)
{
for (int i = 0; i < candidate_count; i++)
{
bool isLoser = false;
for (int j = 0; j < candidate_count; j++)
{
if (locked[j][i])
{
isLoser = true;
break;
}

    }

    if (isLoser) continue;
    if(!isLoser) 
    {
        printf("%s\n", candidates[i]);
    }
}
return;
}