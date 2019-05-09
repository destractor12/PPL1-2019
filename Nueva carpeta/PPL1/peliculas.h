#include "actor.h"

typedef struct
{
    int Id;
    int codigo;
    char titulo[50];
    char fechadeestreno[50];
    char genero[50];
    eActor actor;
    int estado;
}ePelicula;

/** \brief inicializa los estados de las peliculas en 0
 *
 * \param eGenericaUsuario[] array de estructura
 * \param int tamaño del array
 * \return void
 *
 */
void inicializarEstadosEstructura(ePelicula[],int);

void menu(ePelicula[],int);

char getString(char mensaje[], char caracter[]);

int getInt(char mensaje[],int A);

float getFloat(char mensaje[],float numeroIngresado);

char getChar(char mensaje[],char caracter);

char deseaContinuar(char[]);

void altaEstructura(ePelicula listado[],int tamanio,int indice);

int buscarLibreEstructura(ePelicula listado[],int tamanio);

int idAutoIncrementalEstructura(ePelicula listado[],int tamanio);

char validarStringCadena(char[]);

void stringToUpper(char[]);

void mostrarUnoEstructura(ePelicula listado[],int tamanio,int i);

void mostrarListaEstructura(ePelicula listado[],int tamanio);

int mostrarGeneros();
