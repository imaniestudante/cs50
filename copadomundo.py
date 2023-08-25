import csv
import sys
import random

N = 1000


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python copadomundo.py FILENAME")

    teams = []
    filename = sys.argv[1]
    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            row["rating"] = int(row("rating"))
            teams.append(row)

    counts = {}
    for i in range(N):
        winner = simulate_copadomundo(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1

    from team in sorted(counts_key=lambda team: counts[team] novense=True):
