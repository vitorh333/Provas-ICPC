import random

# Formatos das letras
T = [
    "###",
    ".#.",
    ".#.",
    ".#.",
    ".#."
]

A = [
    "###",
    "#.#",
    "###",
    "#.#",
    "#.#"
]

P = [
    "###",
    "#.#",
    "###",
    "#..",
    "#.."
]

letters = [('T', T), ('A', A), ('P', P)]

ROWS = 30
COLS = 30

# Matriz inicial
mat = [["." for _ in range(COLS)] for _ in range(ROWS)]

def can_place(mat, shape, r, c):
    h = len(shape)
    w = len(shape[0])
    if r + h > ROWS or c + w > COLS:
        return False
    for i in range(h):
        for j in range(w):
            if shape[i][j] == "#" and mat[r+i][c+j] != ".":
                return False
    return True

def place(mat, shape, r, c):
    for i in range(len(shape)):
        for j in range(len(shape[0])):
            if shape[i][j] == "#":
                mat[r+i][c+j] = "#"

# Em 10x10 cabem poucas letras, coloco de 3 a 7
num_letters = random.randint(3, 7)

for _ in range(num_letters):
    name, shape = random.choice(letters)
    for _ in range(200):
        r = random.randint(0, ROWS - 1)
        c = random.randint(0, COLS - 1)
        if can_place(mat, shape, r, c):
            place(mat, shape, r, c)
            break

# Imprimir resultado
print(30, 30)
for row in mat:
    print("".join(row))

