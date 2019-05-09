#include<stdio.h>
#include "peliculas.h"
#include<string.h>
#include<ctype.h>

void inicializarEstadosEstructura(ePelicula listado[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        listado[i].estado=0;
    }
}

void menu(ePelicula listado[],int tamanio)
{
    inicializarEstadosEstructura(listado,tamanio);
    //cargarHarcode(listado,tamanio);
    char seguir='s';
    int opcion;
    int indice;
    int contador=0;
    do
    {
        printf("1- Agregar");
        printf("\n2- Mostrar");
        /*printf("\n3- Modificar");
        printf("\n4- Borrar");
        printf("\n5- Ordenar");
        printf("\n6- Mostrar Borrados");
        printf("\n7- Mostrar uno a uno");
        printf("\n8- Mostrar uno a muchos");*/
        printf("\n9- Salir\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            indice=buscarLibreEstructura(listado,tamanio);
            altaEstructura(listado,tamanio,indice);
            break;
        case 2:
            mostrarListaEstructura(listado,tamanio);
            break;
        /*case 3:
            modificarEstructura(listado,tamanio);
            break;
        case 4:
            darDeBajaEstructura(listado,tamanio,"\nEstas seguro que queres dar de baja este usuario? (S/N) ");
            break;
        case 5:
            ordenarSegunCriterio(listado,tamanio);
            break;
        case 6:
            mostrarBorrados(listado,tamanio);
            break;
        case 7:
            break;
        case 8:
            break;
        */ default:
            seguir='n';
            break;
        }
        if(seguir!='n')
        {
            seguir=deseaContinuar("\nDesea continuar con el programa? (S/N) ");

        }

        system("cls");
    }
    while(seguir=='s');
}


char getString(char mensaje[], char caracter[])
{

    printf("%s",mensaje);
    gets(caracter);
    fflush(stdin);
    return caracter;
}

int getInt(char mensaje[],int A)
{

    char auxstring[100];
    printf("%s",mensaje);
    scanf("%d",&A);
    fflush(stdin);
    return A;
}

float getFloat(char mensaje[],float numeroIngresado)
{
    char auxstring[100];
    printf("%s",mensaje);
    scanf("%f",&numeroIngresado);
    fflush(stdin);
    return numeroIngresado;
}

char getChar(char mensaje[],char caracter)
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%c",&caracter);
    return caracter;
}

char deseaContinuar(char mensaje[])
{
    char seguir;
    do
    {
        seguir=getChar(mensaje,seguir);
        seguir=tolower(seguir);
        fflush(stdin);
    }
    while(seguir!='s'&&seguir!='n');
    return seguir;
}

void altaEstructura(ePelicula listado[],int tamanio,int indice)
{
    int opcion;
    char op;
    if(indice!=-1)
    {
        getString("Ingresa el titulo de la pelicula: ",listado[indice].titulo);
        validarStringCadena(listado[indice].titulo);
        stringToUpper(listado[indice].titulo);
        getString("Ingresa la fecha de estreno: ",listado[indice].fechadeestreno);
        listado[indice].Id=idAutoIncrementalEstructura(listado,tamanio);
        listado[indice].codigo=codigoAutoIncrementalEstructura(listado,tamanio);
        listado[indice].estado=1;
        cargarHarcodeActor(listado, tamanio);
        printf("Desea un actor principal en su pelicula?: ");
        scanf("%c", &op);
        if(op=='s')
        {

        }
        opcion=mostrarGeneros();
        if(opcion==1)
        {
            strcpy(listado[indice].genero,"accion");
        }
        else if(opcion==2)
        {
            strcpy(listado[indice].genero,"comedia");
        }
        else if(opcion==3)
        {
            strcpy(listado[indice].genero,"terror");
        }
        else
        {
            strcpy(listado[indice].genero,"otro");
        }

    }
    else
    {
        printf("\nNo hay lugares libres");
    }
}

int buscarLibreEstructura(ePelicula listado[],int tamanio)
{
    int indice;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int idAutoIncrementalEstructura(ePelicula listado[],int tamanio)
{
    int contador=1000;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i].estado==1)
        {
            contador=contador+1;
        }
    }
    return contador;
}

int codigoAutoIncrementalEstructura(ePelicula listado[],int tamanio)
{
     int contador=100;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i].estado==1)
        {
            contador=contador+1;
        }
    }
    return contador;
}

char validarStringCadena(char datoAValidar[])
{
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isalpha(datoAValidar[i])==0&&datoAValidar[i]!=' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar[i])==0);
        }
        else if(datoAValidar[0]== ' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(datoAValidar[0]==' ');
        }
        else
        {
            i=i+1;
        }

    }
    return datoAValidar;
}

void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0;i<largo;i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}

void mostrarUnoEstructura(ePelicula listado[],int tamanio,int i)
{
    printf("\n\nNombre: %s\nId: %d\n Genero: %s\n Fecha de estreno: %s\n codigo: %d",listado[i].titulo,listado[i].Id,listado[i].genero,listado[i].fechadeestreno,listado[i].codigo);
}

void mostrarListaEstructura(ePelicula listado[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].estado==1)
        {
            mostrarUnoEstructura(listado,tamanio,i);
        }

    }
}


int mostrarGeneros()
{
    int opcion;

    printf("1-accion\n2-comedia\n3-terror\n4-otro\nIngrese el id del genero que desea en su pelicula: ");
    scanf("%d",&opcion);

    return opcion;
}
