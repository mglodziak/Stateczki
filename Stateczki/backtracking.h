#ifndef _INCLUDE_BACKTRACKING_
#define _INCLUDE_BACKTRACKING_

#define DEPTH_MIN 7
#define N 10 //wspolrzedna x
#define M 10 //wspolrzedna y

int CreateMatrix( int*** pTab, int nRow, int nCol );
int DeleteMatrix( int*** pTab, int nRow );

int move( int** pTab, int nRow, int nCol, int nDepth, int move_nr, int x, int y, int* px, int* py, int** pRoot );
/* 
pTab, tablica okreslajaca glebokosc w kazdym kwadracie  //bêdzie format %d, z matrixa
nrow, nCol, rozmiar pTab
nDepth, minimalna glebokosc aby statek przep³yn¹³
move_nr, kierunek ruchu
x, y, indeksy w tablicy skad wykonujemy kolejny ruch, zaczynamy od 0,0
px, py, nowe wspolrzedne
pRoot, tablica paietajaca ruchy o rozm nRow, nCol

*/

int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest );
/* pTab tabl glebokosci   o romiarze nRow  i nCol
dDepth - glebokosc zanurzenia ststku
x, y - wspol skad robimy kolejny ruch
pRoot tablica kolejnych ruchow
x_dest, y_dest - wsporzedne portu
*/
typedef enum {UP, RIGHT, DOWN, LEFT } kierunek;

#endif