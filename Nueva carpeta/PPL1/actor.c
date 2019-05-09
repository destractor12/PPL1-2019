#include "actor.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>

void cargarHarcodeActor(eActor listado[],int tamanio)
{
    char Nombre[5][50]= {"julieta roberto","Roberto deniro","Richar darin","tita merelo","sandro"};
    /*int dni[20]= {42589785,23456978,10457863,32014756,42147544,52333457,24965784,30145965,29771276,16279490,14575887,10476685,16686238,41371597,10385485,41754221,19373276,4385555,10173055,3073077};
    int edad[20]= {15,25,12,100,97,3,46,92,24,96,43,83,25,89,41,79,97,37,21,28};
    char direccion[20][50]= {"Beron de Astrada 4589","Montiel 154","Ana Diaz 892","Guamini 6600","Fructuoso Rivera 9785","Corrales 4788","Tabare 1024","Avenida Roca 6658","Timoteo Gordillo 9785","Cañada de Gomez 7845","Cosquin 1290","Itaqui 785","Avenida Cruz 2300","Chilavert 1900","Jose Leon Suarez 9800","Ferre 800","Soldado de la Frontera 3000","Madariaga 1200","Unanue 3300","Avenida Mitre 750"};
    int telefono[20]= {39665247,46057895,22367458,66654897,10456964,46222596,78453256,34521689,11169878,45567785,37894563,22224458,66697852,22364415,77829953,82930100,05126472,55962232,47859965,88956621};
    char apellido[20][50]= {"Gomez","Godinez","Fernandez","Vargas","Bardini","Galli","Rios Taurasi","Vitale","Pacheco","Jimenez","Quispe","Lezano","Velazco","Gonzalez","Sinay","Gasbarro","Estarque","Acuña","Vecchio","Brienza"};
    */
    int i;
    for(i=0; i<5; i++)
    {
        strcpy(listado[i].Nombre,Nombre[i]);
        if(Nombre=="julieta roberto"||Nombre=="Roberto deniro")
        {
            strcpy(listado[i].Pais, "EEUU");
        }
        else
        {
            strcpy(listado[i].Pais, "Argentina");
        }
        listado[i].Id;
        listado[i].Estado=1;
    }
}

eActor datos(eActor listado[], int tam)
{
    eActor aux;
    int opcion;

    opcion=mostrarActores();

    switch(opcion)
    {

    }

    return aux;
}

int mostrarActores()
{
    int opcion;

    printf("1- julieta roberto, EEUU \n2- Roberto deniro , EEUU \n3- Richar darin, Argentina \n4-tita merelo,Argentina \n5 -sandro, Argentina\n Ingrese el id del actor que desea en su pelicula: ");
    scanf("%d",&opcion);

    return opcion;
}
