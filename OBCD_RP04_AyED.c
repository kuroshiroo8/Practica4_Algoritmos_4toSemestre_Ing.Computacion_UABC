// Carlos Daniel Orozco Bravo 351285 441 L4
//**************************************************LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**************************************************ESTRUCTURAS
typedef struct _tdato{
								int status ;
								long matri ;
								char nombre[30] , appat[30] , apmat[30] ;
								struct _tdato *sig ;
							} stdato ;

typedef stdato *Tdato ;

//**************************************************PROTOTIPO DE FUNCIONES
int MENU() ;
int MENUpila() ;
int MENUcola() ;
void PUSHpila( Tdato *pila , Tdato *nuevo );
Tdato POPpila( Tdato *pila );
void PUSHcola( Tdato *cabeza , Tdato *cola , Tdato *nuevo );
Tdato POPcola( Tdato *cola , Tdato *cabeza );
int leenum( int InfLim , int SupLim , char *msg , char *msgError ) ;
void servicio( Tdato temp ) ;
Tdato Gendatos( void ) ;

//**************************************************MAIN
int main()
{
	MENU();
	return 0;
}

//**************************************************MENU
int MENU()
{
	int opcion=0 ;
	do{
			system( "cls" ) ;
			printf( "M   E   N   U\n\n" ) ;
			printf( "a).\n" ) ;
			printf( "\t1- PILA.\n" ) ;
			printf( "\nb).\n" ) ;
			printf( "\t2- COLA.\n" ) ;
			printf( "\n\n3- Salir.\n" ) ;
			printf("\n\nESCOGE UNA OPCION.\n\n");
			opcion=leenum( 1 , 3 , "Dame un numero.\t" , "Error.." );
			switch( opcion )
				{
					case 1 :	system( "cls" );	MENUpila();	break;
					case 2:	system( "cls" );	MENUcola();	break;
				}
    	}while( opcion !=3 );
}

//**************************************************MENU PILA
int MENUpila()
{
	int opcion=0 ;
	Tdato pila=NULL , nuevo=NULL , temp=NULL ;
	do{
			system( "cls" ) ;
			printf( "M   E   N   U   -   P   I   L   A\n\n" ) ;
			printf( "a).\n" ) ;
			printf( "\t1- PUSHpila.\n" ) ;
			printf( "\t2- POPpila.\n" ) ;
			printf( "\n\n3- Salir.\n" ) ;
			printf("\n\nESCOGE UNA OPCION.\t");
			opcion=leenum( 1 , 3 , "Dame un numero.\t" , "Error.." );
			switch( opcion )
				{
					case 1 :
									system( "cls" ) ;
									nuevo=Gendatos() ;
              					PUSHpila( &pila , &nuevo ) ;
              					system( "pause" ) ;
									break;
					case 2:
									system( "cls" ) ;
               				temp=POPpila( &pila ) ;
              					if(temp)
              						{
            							servicio( temp ) ;
            							free( temp ) ;
              						}
              					else
              						{
                  					printf( "pila vacia...\n" ) ;
                  					system( "pause" ) ;
              						}
									break;
				}
    	}while( opcion !=3 );
}

//**************************************************MENU COLA
int MENUcola()
{
	int opcion=0 ;
  	Tdato nuevo=NULL , temp=NULL , cola=NULL , cabeza=NULL ;
	do{
			system( "cls" ) ;
			printf( "M   E   N   U   -   C   O   L   A\n\n" ) ;
			printf( "b).\n" ) ;
			printf( "\t1- PUSHcola.\n" ) ;
			printf( "\t2- POPcola.\n" ) ;
			printf( "\n\n3- Salir.\n" ) ;
			printf("\n\nESCOGE UNA OPCION.\n\n");
			opcion=leenum( 1 , 3 , "Dame un numero.\t" , "Error.." );
			switch( opcion )
				{
					case 1 :
									system( "cls" ) ;
									nuevo=Gendatos() ;
               				PUSHcola( &cola , &cabeza , &nuevo ) ;
               				system( "pause" ) ;
									break ;
					case 2:
									system( "cls" ) ;
									temp=POPcola( &cola , &cabeza ) ;
             					if( temp )
             						{
                						servicio( temp ) ;
                						free( temp ) ;
             						}
             						else
             							{
                 							printf( "cola vacia...\n" ) ;
                 							system("pause");
             							}
									break;
				}
    	}while( opcion !=3 );
}

//**************************************************PUSHpila
void PUSHpila( Tdato *pila , Tdato *nuevo )
{
	( *nuevo )->sig=*pila ;
	*pila=*nuevo;
	*nuevo=NULL;
}

//**************************************************POPpila
Tdato POPpila( Tdato *pila )
{
	Tdato temp=NULL ;
	if( *pila )
		{
			temp=*pila ;
			*pila=( *pila )->sig ;
			temp->sig=NULL ;
		}
	return temp ;
}

//**************************************************PUSHcola
void PUSHcola( Tdato *cola , Tdato *cabeza , Tdato *nuevo )
{
	if(!*cabeza)
		{
			*cabeza=*nuevo;
			*cola=*nuevo;
		}
		else
			{
				(*cabeza)->sig=*nuevo;
				*cabeza=*nuevo;
			}
	*nuevo=NULL ;
}

//**************************************************POPcola
Tdato POPcola( Tdato *cola , Tdato *cabeza )
{
	Tdato temp=NULL ;
	if( *cola )
		{
			temp=*cola ;
			*cola=temp->sig ;
			temp->sig=NULL ;
			if( !*cola )
				{
					*cabeza=NULL ;
				}
		}
		return temp ;
}

//**************************************************VALIDAR NUMERO
int leenum( int InfLim , int SupLim , char *msg , char *msgError )
{
	char strnum[30] ;
	int num ;
	do
		{
			puts( msg ) ;
			fflush( stdin ) ;
			gets( strnum ) ;
			num=atoi( strnum ) ;
			if( num<InfLim || num>SupLim )
				{
					puts( msgError ) ;
					system( "pause" ) ;
				}
		}while( num<InfLim || num>SupLim ) ;
	return num ;
}

//**************************************************SERVICIO
void servicio( Tdato temp )
{
	system( "cls" );
	printf( "%10ld %15s %15s %15s\n", temp->matri , temp->nombre , temp->appat, temp->apmat );
	system( "pause" );
}

//**************************************************GENDATO
Tdato Gendatos( void )
{
	int sex ;
	char vecNomFem[30][30]={ "Sofia" , "Camila" , "Valentina" , "Isabella" , "Ximena" , "Natalia" , "Mia" , "Fernanda" , "Nicole" , "Melanie" , "Regina" , "Renata" , "Antonella" , "Luna" , "Constanza" , "Zoe" , "Michelle" , "Aitana" , "Stephanie" , "Maria" , "Ana" , "Adriana" , "Fernanda" , "Sheila" , "Samantha" , "Mariana" , "Samara" , "Josefa" , "Alexa" , "Guadalupe" };
	char vecNomMas[30][30]={ "Luis" , "Miguel" , "Jose" , "Jesus" , "Alejandro" , "Juan" , "Ricardo" , "Daniel" , "Fernando" , "Jorge" , "Roberto" , "Carlos" , "Francisco" , "Manuel" , "Santiago" , "Sebastian" , "Javier" , "Nicolas" , "Eliud" , "Mateo" , "Matias" , "Gabriel" , "Emiliano" , "Rodrigo" , "Pablo" , "Emmanuel" , "Emilio" , "Christopher" , "Jonathan" , "Iker" };
	char vecAp[30][30]={ "Gonzalez" , "Rodriguez" , "Gomez" , "Huertas" , "Lopez" , "Diaz" , "Martinez" , "Perez" , "Garcia" , "Sanchez" , "Romero" , "Sosa" , "Alvarez" , "Torres" , "Ruiz" , "Ramirez" , "Flores" , "Acosta" , "Benitez" , "Medina" , "Suarez" , "Herrera" , "Aguirre" , "Pereyra" , "Gutierrez" , "Jimenez" , "Molina" , "Silva" , "Castro" , "Rojas" };
	Tdato nodo=NULL ;
	nodo=( Tdato )malloc( sizeof( stdato ) ) ;
	nodo->status=1;
	nodo->matri=(rand()%1000000)+300000;
	sex=(rand()%2)+1;
	if( sex==1 )
		{
			strcpy( nodo->nombre , vecNomMas[rand()%30] );
		}
		else
			{
				strcpy( nodo->nombre , vecNomFem[rand()%30] );
			}
	strcpy( nodo->appat, vecAp[rand()%30] ) ;
	strcpy( nodo->apmat, vecAp[rand()%30] ) ;
	printf( "%10ld %15s %15s %15s\n", nodo->matri , nodo->nombre , nodo->appat, nodo->apmat );
	nodo->sig=NULL;
	return nodo ;
}
