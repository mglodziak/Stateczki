#define _CRT_SECURE_NO_WARNINGS // na stacjonarnym inaczej nie dziala

#include "stdafx.h"
#include "backtracking.h"
#include <stdio.h>


void SetTab( char* sFile, int** pTab, int nRow, int nCol );
void PrintTab( int** pTab, int nRow, int nCol );

int main( int argc, char* argv[] )
{
	if ( argc != 1 ) //Gdy nie zgadza si� liczba parametr�w, wziete z matrixa //2 !!!
		
	{
		printf( "Bledna liczba argumentow!! \n\n" );
		return 1;
	}

	int** pTab = NULL; // tworz� macierz g��boko�ci morza
	CreateMatrix( &pTab, N, M );

	int** pRoot = NULL;
	CreateMatrix( &pRoot, N, M ); // tworz� macierz pobytu statku na morzu

	SetTab( "test.txt", pTab, N, M );

	**pRoot = 1; //podstawiam pod pierwszy element (punkt startu)
	

	if ( root( pTab, N, M, DEPTH_MIN, 0, 0, pRoot, N - 1, M - 1 ) ) //n-1, m-1 bo tablice indeksujemy od zera!!
																	//funkcja sprawdza, czy udalo sie doplynac do portu
		PrintTab( pRoot, N, M ); //jesli statek doplynal

	else
		printf( "Wszedzie mielizna!! Nie ma mozliwosci doplynac do portu!! \n\n" );

	DeleteMatrix( &pTab, N );
	DeleteMatrix( &pRoot, N );


    return 0;
}


void SetTab( char* sFile, int** pTab, int nRow, int nCol )// na podstawie matrixa
{
	FILE* fin = NULL;
	if ( ( fin = ( fopen( sFile, "r" ) ) ) == NULL ) //otwieranie pliku // czy !!!!?, r oznacza tylko do odczytu

	{
		printf( "ERROR: Nie udalo sie otworzyc pliku!\n\n" ); //obs�uga ewentualnego b��du
		return;
	}

	for ( int i = 0; i < nRow; i++ ) // wpisywanie warto�ci z pliku do macierzy g��boko�ci
	{
		int* p = *pTab++;
		for ( int j = 0; j < nCol; j++ )
			fscanf( fin, "%d", p++ );
	}
	fclose( fin ); // na koniec plik trzeba zamkn��!!!
}


void PrintTab( int** pTab, int nRow, int nCol ) // wy�wietla macierz, funkcja wzi�ta z matrixa (nieznacznie zmieniona ), do testow\
												w naszym wypadku wy�wietli macierz miejsc parkingu statku (0,1,2 - nie by�o, by� raz, �lepa uliczka)
{
	printf( "\n\n" );
	for ( int i = 0; i<nRow; i++ )
	{
		int* pTemp = *pTab++;
		for ( int j = 0; j<nCol; j++ )
			printf( "%d ", *pTemp++ );
		printf( "\n" );
	}
	printf( "\n" );
}