#include "LinkedList.h"
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

}eVuelos;

typedef struct
{
    int id;
    char nombre[50];
}ePiloto;




eVuelos* newVuelo(void);
eVuelos* newVueloParametros(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);
ePiloto* newPilotoParametros(char* id, char* nombre);
int printVuelo(eVuelos* vuelo, LinkedList* pListaPilotos);
int printPiloto(ePiloto* piloto);
void hardCodePilotos(LinkedList* pilotos);
int getNombreById(LinkedList* pListaPilotos, int id, char* nombre);
int contarPasajeros(void* element);
int contarPasajerosIrlanda(void* element);
int filtrarVuelosCortos(void* element);
int filtrarVuelosAPortugal(void* element);
int excludeAlexLifeson(void* element);


int vuelo_setId(eVuelos* vuelo, int id);
int vuelo_setIdAvion(eVuelos* vuelo, int id);
int vuelo_setIdPiloto(eVuelos* vuelo, int id);
int vuelo_setFecha(eVuelos* vuelo, char* fecha);
int vuelo_setDestino(eVuelos* vuelo, char* destino);
int vuelo_setCantPasajeros(eVuelos* vuelo, int cant);
int vuelo_setHoraDespeje(eVuelos* vuelo, int hs);
int vuelo_setHoraLlegada(eVuelos* vuelo, int hs);

int vuelo_getId(eVuelos* vuelo, int* id);
int vuelo_getIdAvion(eVuelos* vuelo, int* id);
int vuelo_getIdPiloto(eVuelos* vuelo, int* id);
int vuelo_getFecha(eVuelos* vuelo, char* fecha);
int vuelo_getDestino(eVuelos* vuelo, char* destino);
int vuelo_getCantPasajeros(eVuelos* vuelo, int* cant);
int vuelo_getHoraDespeje(eVuelos* vuelo, int* hs);
int vuelo_getHoraLlegada(eVuelos* vuelo, int* hs);

int piloto_setId(ePiloto* piloto, int id);
int piloto_setNombre(ePiloto* piloto, char* nombre);

int filtrarPorNombre(void* element, char* parmCadena);
