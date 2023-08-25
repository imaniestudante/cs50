from csv import reader, DictReader
from sys import argv, exit

sequences = {}

if len(argv) < 3:
    print("Usage:", "python dna.py data.csv sequence.txt")
    exit(1);

def get_max(dna, STR):
    i = 0
    j = len(STR)
    max = 0;
    for x in range(len(dna)):
        if dna[i:j] == STR:
            temp = 0;
            while dna[i:j] == STR:
                temp += 1;
                i += len(STR)
                j += len(STR)
                if(temp > max):
                    max = temp