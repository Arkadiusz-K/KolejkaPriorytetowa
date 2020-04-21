#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "pQ.h"

#define SIZE 11

using namespace std;

void input( PQueue* q, int nSize );

int main()
{
	srand( (unsigned int)time( NULL ) );
	PQueue* q = PQInit( SIZE );

	input( q, SIZE - 1 );

	printf( "Queue:\n" );
	PQPrint( q );
	printf( "\n\n" );

	printf("Dequeue: %d\n",PQDequeue( q ));

	PQPrint( q );
	printf( "\n\n" );

	printf( "Dwa enqueue\n" );
	input( q, 2 );

	PQPrint( q );
	printf( "\n\n" );

	printf( "Dequeue: %d\n", PQDequeue( q ) );

	PQPrint( q );
	printf( "\n\n" );

	printf( "Dwa enqueue\n" );
	input( q, 2 );

	PQPrint( q );
	printf( "\n\nClear\n\n" );

	PQClearQueue( q );

	printf( "Dequeue: %d\n", PQDequeue( q ) );

	PQPrint( q );
	printf( "\n\n" );

	printf( "Trzy enqueue\n" );
	input( q, 3 );

	PQPrint( q );
	printf( "\n\n" );

	PQRelease( &q );

    return 0;
}

//==================================================================================
void input( PQueue* q, int nSize )
{
	for( int i = 0; i < nSize; i++ )
	{
		int nKey = rand() % 40 + 1;
		int nPrior = rand() % 15 + 1;
		PQEnqueue( q, nKey, nPrior );
		printf( "%d. %d\tprior:%d\n", i, nKey, nPrior );
	}
}



//Modul kolejki priorytetowej
//malloc

//JAK TO PRZETESTOWAC W MAIN
/*
wygenerowa� 10 element�w losowo %40+1 (liczby od 1 do 40) mo�na zorubi� tak� funkcj� do randomowego szuaknia liczb
wrzuci� 10 elemnt�w, kolejka jest na 11
zrobi� raz deuquqq
i nastepnie dwa razy enququ - powinno by� dobrze

potem zonowu raz deququq i dwa razy eneqqeq i powinno by� �le

potem czyszczenie,
raz deququq i 3 razy eququeue

tak przetestowa� �eby przestowa� skrajne przypadki
*/