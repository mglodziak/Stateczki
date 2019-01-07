#include "backtracking.h"
#include <stdlib.h>
#include <stdio.h>


int CreateMatrix( int*** pTab, int nRow, int nCol ) // wziête z matrixa, double zamienione na int, malloc zmieniony na calloc
{
	*pTab = ( int** )calloc( nRow, sizeof( int* ) ); //jeden nawias zbêdny??
	if ( !*pTab ) return 0;

	int **p = *pTab;

	for ( int i = 0; i<nRow; i++, p++ )
	{
		*p = ( int* )calloc( nCol, sizeof( int ) ); //inicjujemy tablice do ka¿dego wczeœniej wygenerowanego wskaŸnika
		if ( !*p ) return 0;
	}
	return 1;
}
int DeleteMatrix( int*** pTab, int nRow ) //wziête z matrixa, 
{
	int** p = *pTab;
	for ( int i = 0; i<nRow; i++, p++ )
		free( *p );
	free( *pTab );
	*pTab = NULL;
	return 1;

}
int move( int** pTab, int nRow, int nCol, int nDepth, int move_nr, int x, int y, int* px, int* py, int** pRoot )
{
	switch ( move_nr )
	{
			case UP: *px = x, *py = ++y; break;
	case RIGHT: *px = ++x, *py = y; break; 
	case DOWN: *px = x, *py = --y; break;
	case LEFT: *px = --x, *py = y; break;

	}

	if ( ( *px >= 0 ) && ( *px < N ) && ( *py >= 0 ) && ( *py < M ) )
	{
		if ( ( pTab[*px][*py] > nDepth  ) && ( pRoot[*px][*py] == 0 ) ) //czy min depth oznacza, ze ma byc wieksze, czy wieksze badz rowne
			// sprawdzam czy statek nie usi¹dzie na mieliŸnie i czy przypadkiem nie cumowa³ tu ju¿ wczeœniej..
		{
		//	printf ( "Jeszcze plyne...\n" );
			return 1;
		}
			
	
		//	printf ( "ERROR: statek osiadl na mieliznie. Ruski holownik w drodze. Prosze czekac..\n" );
			return 0;
		
	}
	return 0;
}

int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest )
{

	pRoot[x][y] = 1; // tablica pRoot okreœla, czy statek dane pole odwiedzi³ (jeœli tak  to 1)
	if ( pRoot[x][y] == 1 )
	
		printf( "(%d,%d) -> ", y, x ); /// ! jak rozumieæ x oraz y? Co jest czym?
	

	if ( ( x == x_dest ) && ( y == y_dest ) )// sprawdzam czy dotar³em do portu
	{
	//	printf ( "\nHome, sweet home!\n\n" );
		return 1;
	}

	else
	{
		int nowy_x = x;				 // definiuje nowe wspó³rzêdne
		int nowy_y = y;

		for ( int i = UP; i <= LEFT; i++ )
			if ( move( pTab, nRow, nCol, nDepth, i, x, y, &nowy_x, &nowy_y, pRoot ) )	// sprwadzic wszystkie mozliwosci ruchu
				if ( root( pTab, N, M, DEPTH_MIN, nowy_x, nowy_y, pRoot, x_dest, y_dest ) )
					return 1;				//jesli wykonanie kolejnego kroku sie powiodlo - rekurencyjnie root()
		
		pRoot[x][y] = 2;// jesli wracamy to ustawiamy w pRoot ze ruch byl zly
	//	if ( pRoot[x][y] == 2 )
		
		return 0;

	}

	return 0;
}