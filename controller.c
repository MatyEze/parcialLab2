#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "vuelos-piloto.h"
#include "parser.h"
#include "funcionesgnr.h"



int controller_Sellanes_loadVuelos(char* path, LinkedList* pArrayListVuelo)
{
    int auxRet=-1;
    FILE* pFile= NULL;
    ll_clear(pArrayListVuelo);

    pFile=fopen(path, "r");
    auxRet=parcerVueloFromText(pFile, pArrayListVuelo);
    fclose(pFile);
    return auxRet;
}

int controller_Sellanes_loadPilotos(char* path, LinkedList* pArrayListPiloto)
{
    int auxRet=-1;
    FILE* pFile= NULL;
    ll_clear(pArrayListPiloto);

    pFile=fopen(path, "r");
    auxRet=parcerVueloFromText(pFile, pArrayListPiloto);
    fclose(pFile);
    return auxRet;
}

int controller_Sellanes_listarVuelos(LinkedList* pArrayListVuelo, LinkedList* pListaPiloto)
{
    int i;
    int len;
    int auxRet=-1;
    if(pArrayListVuelo != NULL && pListaPiloto != NULL)
    {
        auxRet=0;
        len=ll_len(pArrayListVuelo);
        printf("%10s%15s%20s%15s%15s%15s%15s%15s\n", "ID VUELO", "ID AVION",
               "PILOTO", "FECHA", "DESTINO", "PASAJEROS", "HORA DESPEGE", "HORA LLEGADA");
        for(i=0; i<len; i++)
        {
            printVuelo((eVuelos*)ll_get(pArrayListVuelo, i), pListaPiloto);
        }
    }
    return auxRet;
}

int controller_Sellanes_contarPasajeros(LinkedList* pArrayListVuelo)
{
    int auxRet=-1;
    int cant=0;

    if(pArrayListVuelo != NULL)
    {
        cant=ll_count(pArrayListVuelo, contarPasajeros);
        printf("\nLa cantidad de pasajeros es: %d\n", cant);
    }
    return auxRet;
}

int controller_Sellanes_contarPasajerosIrlanda(LinkedList* pArrayListVuelo)
{
    int auxRet=-1;
    int cant=0;
    if(pArrayListVuelo != NULL)
    {
        auxRet=0;
        cant=ll_count(pArrayListVuelo, contarPasajerosIrlanda);
        printf("\nLa cantidad de pasajeros con destino Irlanda es: %d\n", cant);
    }
    return auxRet;
}

int controller_Sellanes_saveVuelos(char* path, LinkedList* pArrayListVuelo)
{
    int auxRet=-1;
    eVuelos* vueloAux;
    FILE* pFile = NULL;
    int i;
    int len;
    int idVuelo, idPiloto, idAvion, cantPsj, hsDespege, hsLlegada;
    char fecha[20], destino[50];

    if(pArrayListVuelo != NULL)
    {
        pFile=fopen(path, "w");
        if(pFile != NULL)
        {
            auxRet=0;
            len=ll_len(pArrayListVuelo);
            fprintf(pFile, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");

            for(i=0; i<len; i++)
            {
                vueloAux= (eVuelos*) ll_get(pArrayListVuelo, i);

                vuelo_getId(vueloAux, &idVuelo);
                vuelo_getIdAvion(vueloAux, &idAvion);
                vuelo_getIdPiloto(vueloAux, &idPiloto);
                vuelo_getFecha(vueloAux, fecha);
                vuelo_getDestino(vueloAux, destino);
                vuelo_getCantPasajeros(vueloAux, &cantPsj);
                vuelo_getHoraDespeje(vueloAux, &hsDespege);
                vuelo_getHoraLlegada(vueloAux, &hsLlegada);

                fprintf(pFile, "%d,%d,%d,%s,%s,%d,%d,%d\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPsj, hsDespege, hsLlegada);
            }
        }
        fclose(pFile);
    }
    return auxRet;
}

int controller_Sellanes_filterAndSaveVuelosCortos(char* path, LinkedList* pArrayListVuelo)
{
    LinkedList* filterList=NULL;
    int auxRet=0;
    if(path != NULL && pArrayListVuelo != NULL)
    {
        filterList=ll_filter(pArrayListVuelo, filtrarVuelosCortos);
        if(filterList != NULL)
        {
            auxRet=1;
            controller_Sellanes_saveVuelos(path, filterList);
        }
    }
    ll_deleteLinkedList(filterList);
    return auxRet;
}

int controller_Sellanes_listarVuelosPortugal(LinkedList* pArrayListVuelo, LinkedList* pListPilots)
{
    LinkedList* filterList=NULL;
    int auxRet=0;
    if(pArrayListVuelo != NULL)
    {
        filterList=ll_filter(pArrayListVuelo, filtrarVuelosAPortugal);
        if(filterList != NULL)
        {
            auxRet=1;
            controller_Sellanes_listarVuelos(filterList, pListPilots);
        }
    }
    return auxRet;
}

int controller_Sellanes_listarVuelosSinAlexLifeson(LinkedList* pArrayListVuelo, LinkedList* pListPilots)
{
    LinkedList* filterList=NULL;
    int auxRet=0;
    if(pArrayListVuelo != NULL)
    {
        filterList=ll_filter(pArrayListVuelo, excludeAlexLifeson);
        if(filterList != NULL)
        {
            auxRet=1;
            controller_Sellanes_listarVuelos(filterList, pListPilots);
        }
    }
    return auxRet;
}

int controller_Sellanes_listarPiltos(LinkedList* pListPilots)
{
    int len;
    int i;
    int auxRet=0;
    if(pListPilots != NULL)
    {
        auxRet=1;
        len=ll_len(pListPilots);
        for(i=0; i<len; i++)
        {

            printPiloto((ePiloto*) ll_get(pListPilots, i));
        }
    }
    return auxRet;
}
int controller_Sellanes_filtrarPilotosNombre(LinkedList* pListPilots, char* nombre)
{
    LinkedList* filterList=NULL;
    int auxRet=0;
    if(pListPilots != NULL)
    {
        filterList=ll_filterParametros(pListPilots, filtrarPorNombre, nombre);
        if(filterList!= NULL)
        {
            auxRet=1;
            controller_Sellanes_listarPiltos(filterList);
        }
    }
    return auxRet;
}

