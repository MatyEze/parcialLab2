#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "vuelos-piloto.h"
#include "parser.h"

int parcerVueloFromText(FILE* pFile, LinkedList* pArrayListVuelo)
{
    int auxRet =-1;
    char idVuelo[500], idAvion[500], idPiloto[500], fecha[500], destino[500], cantPasajeros[500], horaDespegue[500], horaLlegada[500];
    eVuelos* auxVuelo;
    if(pFile != NULL && pArrayListVuelo)
    {
        auxRet=0;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
               idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
        while(!feof(pFile))
        {
            if(feof(pFile))
            {
                break;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
               idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            auxVuelo = newVueloParametros(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            ll_add(pArrayListVuelo, (void*)auxVuelo);
        }
    }
    return auxRet;
}

int parcerPilotoFromText(FILE* pFile, LinkedList* pArrayListPiloto)
{
    int auxRet =-1;
    char id[500], nombre[500];
    ePiloto* pilotoAux;
    if(pFile != NULL && pArrayListPiloto)
    {
        auxRet=0;
        fscanf(pFile, "%[^,],%[^\n]\n",id,nombre);
        while(!feof(pFile))
        {
            if(feof(pFile))
            {
                break;
            }
            fscanf(pFile, "%[^,],%[^\n]\n",id, nombre);
            pilotoAux = newPilotoParametros(id, nombre);
            ll_add(pArrayListPiloto, (void*)pilotoAux);
        }
    }
    return auxRet;
}
