#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelos-piloto.h"



eVuelos* newVuelo(void)
{
    return (eVuelos*) malloc(sizeof(eVuelos));
}

eVuelos* newVueloParametros(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
    eVuelos* pNewVuelo = NULL;
    pNewVuelo = newVuelo();
    if(pNewVuelo != NULL)
    {
        vuelo_setId(pNewVuelo, atoi(idVuelo));
        vuelo_setIdAvion(pNewVuelo, atoi(idAvion));
        vuelo_setIdPiloto(pNewVuelo, atoi(idPiloto));
        vuelo_setFecha(pNewVuelo, fecha);
        vuelo_setDestino(pNewVuelo, destino);
        vuelo_setCantPasajeros(pNewVuelo, atoi(cantPasajeros));
        vuelo_setHoraDespeje(pNewVuelo, atoi(horaDespegue));
        vuelo_setHoraLlegada(pNewVuelo, atoi(horaLlegada));
    }
    return pNewVuelo;
}

ePiloto* newPiloto(void)
{
    return (ePiloto*) malloc(sizeof(ePiloto));
}

ePiloto* newPilotoParametros(char* id, char* nombre)
{
    ePiloto* pNewPiloto=NULL;
    pNewPiloto=newPiloto();
    if(pNewPiloto != NULL)
    {
        piloto_setId(pNewPiloto, atoi(id));
        piloto_setNombre(pNewPiloto, nombre);
    }
    return pNewPiloto;
}


int piloto_setId(ePiloto* piloto, int id)
{
    int auxRet =-1;
    if(piloto != NULL)
    {
        auxRet=0;
        piloto->id=id;
    }
    return auxRet;
}
int piloto_setNombre(ePiloto* piloto, char* nombre)
{
    int auxRet =-1;
    if(piloto != NULL && nombre != NULL)
    {
        auxRet=0;
        strcpy(piloto->nombre, nombre);
    }
    return auxRet;
}

int piloto_getId(ePiloto* piloto, int* id)
{
    int auxRet =-1;
    if(piloto != NULL && id != NULL)
    {
        auxRet=0;
        *id=piloto->id;
    }
    return auxRet;
}

int piloto_getNombre(ePiloto* piloto, char* nombre)
{
    int auxRet =-1;
    if(piloto != NULL && nombre != NULL)
    {
        auxRet=0;
        strcpy(nombre, piloto->nombre);
    }
    return auxRet;
}

int vuelo_setId(eVuelos* vuelo, int id)
{
    int auxRet =-1;
    if(vuelo != NULL)
    {
        auxRet=0;
        vuelo->idVuelo=id;
    }
    return auxRet;
}
int vuelo_setIdAvion(eVuelos* vuelo, int id)
{
    int auxRet =-1;
    if(vuelo != NULL)
    {
        auxRet=0;
        vuelo->idAvion=id;
    }
    return auxRet;
}
int vuelo_setIdPiloto(eVuelos* vuelo, int id)
{
    int auxRet =-1;
    if(vuelo != NULL)
    {
        auxRet=0;
        vuelo->idPiloto=id;
    }
    return auxRet;
}
int vuelo_setFecha(eVuelos* vuelo, char* fecha)
{
    int auxRet =-1;
    if(vuelo != NULL && fecha != NULL)
    {
        auxRet=0;
        strcpy(vuelo->fecha, fecha);
    }
    return auxRet;
}
int vuelo_setDestino(eVuelos* vuelo, char* destino)
{
    int auxRet =-1;
    if(vuelo != NULL && destino != NULL)
    {
        auxRet=0;
        strcpy(vuelo->destino, destino);
    }
    return auxRet;
}
int vuelo_setCantPasajeros(eVuelos* vuelo, int cant)
{
    int auxRet =-1;
    if(vuelo != NULL)
    {
        auxRet=0;
        vuelo->cantPasajeros=cant;
    }
    return auxRet;
}
int vuelo_setHoraDespeje(eVuelos* vuelo, int hs)
{
    int auxRet =-1;
    if(vuelo != NULL)
    {
        auxRet=0;
        vuelo->horaDespegue=hs;
    }
    return auxRet;
}
int vuelo_setHoraLlegada(eVuelos* vuelo, int hs)
{
    int auxRet =-1;
    if(vuelo != NULL)
    {
        auxRet=0;
        vuelo->horaLlegada=hs;
    }
    return auxRet;
}


int vuelo_getId(eVuelos* vuelo, int* id)
{
    int auxRet =-1;
    if(vuelo != NULL && id != NULL)
    {
        auxRet=0;
        *id=vuelo->idVuelo;
    }
    return auxRet;
}
int vuelo_getIdAvion(eVuelos* vuelo, int* id)
{
    int auxRet =-1;
    if(vuelo != NULL && id != NULL)
    {
        auxRet=0;
        *id=vuelo->idAvion;
    }
    return auxRet;
}
int vuelo_getIdPiloto(eVuelos* vuelo, int* id)
{
    int auxRet =-1;
    if(vuelo != NULL && id != NULL)
    {
        auxRet=0;
        *id=vuelo->idPiloto;
    }
    return auxRet;
}
int vuelo_getFecha(eVuelos* vuelo, char* fecha)
{
    int auxRet =-1;
    if(vuelo != NULL && fecha != NULL)
    {
        auxRet=0;
        strcpy(fecha, vuelo->fecha);
    }
    return auxRet;
}
int vuelo_getDestino(eVuelos* vuelo, char* destino)
{
    int auxRet =-1;
    if(vuelo != NULL && destino != NULL)
    {
        auxRet=0;
        strcpy(destino, vuelo->destino);
    }
    return auxRet;
}
int vuelo_getCantPasajeros(eVuelos* vuelo, int* cant)
{
    int auxRet =-1;
    if(vuelo != NULL && cant != NULL)
    {
        auxRet=0;
        *cant=vuelo->cantPasajeros;
    }
    return auxRet;
}
int vuelo_getHoraDespeje(eVuelos* vuelo, int* hs)
{
    int auxRet =-1;
    if(vuelo != NULL && hs != NULL)
    {
        auxRet=0;
        *hs=vuelo->horaDespegue;
    }
    return auxRet;
}
int vuelo_getHoraLlegada(eVuelos* vuelo, int* hs)
{
    int auxRet =-1;
    if(vuelo != NULL && hs != NULL)
    {
        auxRet=0;
        *hs=vuelo->horaLlegada;
    }
    return auxRet;
}

int printVuelo(eVuelos* vuelo, LinkedList* pListaPilotos)
{
    int auxRet=-1;
    int idVuelo, idAvion, idPiloto, cantPasajeros, horaDespegue, horaLlegada;
    char fecha[20], destino[50], nombrePiloto[50];
    if(vuelo != NULL)
    {
        auxRet=0;
        vuelo_getId(vuelo, &idVuelo);
        vuelo_getIdAvion(vuelo, &idAvion);
        vuelo_getIdPiloto(vuelo, &idPiloto);
        vuelo_getFecha(vuelo, fecha);
        vuelo_getDestino(vuelo, destino);
        vuelo_getCantPasajeros(vuelo, &cantPasajeros);
        vuelo_getHoraDespeje(vuelo, &horaDespegue);
        vuelo_getHoraLlegada(vuelo, &horaLlegada);
        getNombreById(pListaPilotos, idPiloto, nombrePiloto);

        printf("%10d%15d%20s%15s%15s%15d%15d%15d\n", idVuelo, idAvion, nombrePiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
    }
    return auxRet;
}

int printPiloto(ePiloto* piloto)
{
    int auxRet=-1;
    int id;
    char nombre[50];
    if(piloto != NULL)
    {
        auxRet=0;
        piloto_getId(piloto, &id);
        piloto_getNombre(piloto, nombre);
        printf("%d--%s\n", id, nombre);
    }
    return auxRet;
}

void hardCodePilotos(LinkedList* pilotos)
{
    int i;
    ePiloto* pPiloto;
    ePiloto listapilotos[5]={{1, "Alex Lifeson"},
                             {2, "Richar Bach"},
                             {3, "Jhon Kerry"},
                             {4, "Erwin Romel"},
                             {5, "Stephen Coonts"}};

    for(i=0; i<5; i++)
    {
        pPiloto = malloc(sizeof(eVuelos));
        pPiloto->id = listapilotos[i].id;
        strcpy(pPiloto->nombre, listapilotos[i].nombre);
        ll_add(pilotos, (void*)pPiloto);
    }
}


int getNombreById(LinkedList* pListaPilotos, int id, char* nombre)
{
    ePiloto* auxPiloto;
    int len;
    int i;
    int auxRet=-1;
    //printf("getnombrebyid\n");
    if(pListaPilotos != NULL)
    {
        //printf("entra al if getnombrebyid\n");
        auxRet=0;
        len=ll_len(pListaPilotos);
        for(i=0; i<len; i++)
        {
            auxPiloto=(ePiloto*) ll_get(pListaPilotos, i);
            //printf("%d", auxPiloto->id);
            if(auxPiloto->id == id)
            {
                strcpy(nombre, auxPiloto->nombre);
                //printf("el nombre es %s\n", nombre);
                break;
            }
        }
    }
    return auxRet;
}

int contarPasajeros(void* element)
{
    eVuelos* auxVuelo;
    int count=0;
    if(element != NULL)
    {
        auxVuelo = (eVuelos*) element;
        vuelo_getCantPasajeros(auxVuelo, &count);
        //printf("%d+", count);
    }
    return count;
}

int contarPasajerosIrlanda(void* element)
{
    eVuelos* auxVuelo;
    char destino[50];
    int count=0;
    if(element != NULL)
    {
        auxVuelo = (eVuelos*) element;
        vuelo_getDestino(auxVuelo, destino);
        if(strcmp(destino, "Irlanda")== 0)
        {
            vuelo_getCantPasajeros(auxVuelo, &count);
        }
        //printf("%d+", count);
    }
    return count;
}

int filtrarVuelosCortos(void* element)
{
    eVuelos* vueloAux;
    int hsLlegada, hsDesepege;
    int auxRet=0;
    if(element != NULL)
    {
        vueloAux = (eVuelos*) element;
        vuelo_getHoraDespeje(vueloAux, &hsDesepege);
        vuelo_getHoraLlegada(vueloAux, &hsLlegada);

        if((hsLlegada - hsDesepege) < 3)
        {
            auxRet=1;
        }
    }
    return auxRet;
}

int filtrarVuelosAPortugal(void* element)
{
    eVuelos* vueloAux;
    char destino[50];
    int auxRet=0;
    if(element != NULL)
    {
        vueloAux = (eVuelos*) element;
        vuelo_getDestino(vueloAux, destino);

        if(strcmp(destino, "Portugal")==0)
        {
            auxRet=1;
        }
    }
    return auxRet;
}

int excludeAlexLifeson(void* element)
{
    eVuelos* vueloAux;
    int idPiloto;
    int auxRet=1;
    if(element != NULL)
    {
        vueloAux = (eVuelos*) element;
        vuelo_getIdPiloto(vueloAux, &idPiloto);

        if(idPiloto == 1)
        {
            auxRet=0;
        }
    }
    return auxRet;
}

int filtrarPorNombre(void* element, char* parmCadena)
{
    ePiloto* pilotoAux;
    char nombre[50];
    int auxRet=0;
    if(element != NULL && parmCadena != NULL)
    {
        pilotoAux=(ePiloto*) element;
        piloto_getNombre(pilotoAux, nombre);
        if(strcmp(nombre, parmCadena) == 0)
        {
            auxRet=1;
        }
    }
    return auxRet;
}
