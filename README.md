# Tic-Tac-Toe (X și O)

## Lab01

### Descrierea proiectului

Joc clasic Tic-Tac-Toe pentru 2 jucători, jucat în consolă. Jucătorii introduc pe rând coordonatele unde vor să plaseze simbolul lor pe o tablă 3x3.

### Regulile jocului

* Tabla are 3x3 celule, inițial goale.
* Jucătorul 1 folosește simbolul 'X', jucătorul 2 folosește 'O'.
* Jucătorii introduc pe rând poziția (rând, coloană) unde vor să plaseze simbolul.
* Câștigă cine formează primul un rând, o coloană sau o diagonală completă.
* Dacă tabla se umple fără câștigător, jocul se termină la egalitate.

### Structuri de date

* `Point` — reprezintă o coordonată (rând, coloană) pe tablă.
* `Player` — reprezintă un jucător: nume și simbol asociat (X sau O).
* `Board` — reprezintă tabla de joc 3x3 și starea celulelor.
* `GameState` — enum ce reprezintă starea curentă a jocului (IN_PROGRESS, WIN, DRAW).
* `GameEngine` — motorul jocului, coordonează tabla, jucătorii și logica de joc.
* `Renderer` — responsabil cu afișarea tablei în consolă.
* `Listener` — responsabil cu citirea input-ului de la jucător.

---

## Lab02

### Construirea proiectului

Pentru a construi proiectul, se folosește comanda:

`make`

Pentru a șterge fișierele create la compilare, se folosește comanda:

`make clean`

După construirea proiectului se obține fișierul executabil `TicTacToe.exe`.

---

## Lab03

Am implementat cerințele pentru Laboratorul 3:

* Am adăugat constructorii și operatorii pentru clasa `Point` (`=`, `==`, `>>`, `<<`)
* Am adăugat constructorii și operatorii pentru clasa `Board` (`=`, `==`, `>>`, `<<`)
* Am creat clasa abstractă `AbstractPainter` și clasa `Painter` care o moștenește
* Am adaptat `listener.cpp` pentru noile câmpuri `x` și `y` din `Point`

