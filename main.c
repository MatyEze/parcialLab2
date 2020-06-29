#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "vuelos-piloto.h"
#include "funcionesgnr.h"

int main()
{
    int opcion;
    LinkedList* listaVuelos= ll_newLinkedList();
    LinkedList* listaPilotos= ll_newLinkedList();
    hardCodePilotos(listaPilotos);
    ///////////////////////////////////
    /*ePiloto* aux;
    for(int i=0; i<ll_len(listaPilotos); i++)
    {
        aux = (ePiloto*) ll_get(listaPilotos, i);
        printf("%d - %s\n", aux->id, aux->nombre);
    }*/
    /////////////////////////////////////////
    do{
        opcion=getIntMmR(3, "1-CARGAR DATOS DESDE EL CSV (TEXTO)\n2-IMPRIMIR VUELOS\n3-CANTIDAD DE PASAJEROS\n4-CANTIDAD DE PASAJEROS A IRLANDA\n5-FILTRAR VUELOS CORTOS\n6-LISTAR VUELOS A PORTUGAL\n7-FILTRAR A ALEX LIFESON\n8-FILTRAR PILOTOS POR NOMBRE\n9-SALIR\nINGRESE OPCION: ",
                         "OPCION INVALIDA REINGRESE: ", 9, 1);

        switch(opcion)
        {
            case 1:
                if(ll_isEmpty(listaVuelos))
                {
                    controller_Sellanes_loadVuelos("Vuelos.csv", listaVuelos);
                    //controller_Sellanes_loadPilotos("pilotos.csv", listaPilotos);
                    printf("CARGADO CON EXITO...\n");
                }
                else if(getSON("Ya hay una lista cargada, si continua se perderan los datos no guardados esta seguro que quiere cargar (s/n): ", "ERROR dato no valido reingrese (s/n): "))
                {
                    controller_Sellanes_loadVuelos("Vuelos.csv", listaVuelos);
                    //controller_Sellanes_loadPilotos("pilotos.csv", listaPilotos);
                    printf("CARGADO CON EXITO...\n");
                }
                else
                {
                    printf("CARGADO CANCELADO...\n");
                }
                pausa();
            break;
            case 2:
                if(!ll_isEmpty(listaVuelos))
                {
                    controller_Sellanes_listarVuelos(listaVuelos, listaPilotos);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LA OPCION 1 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 3:
                if(!ll_isEmpty(listaVuelos))
                {
                    controller_Sellanes_contarPasajeros(listaVuelos);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LA OPCION 1 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 4:
                if(!ll_isEmpty(listaVuelos))
                {
                    controller_Sellanes_contarPasajerosIrlanda(listaVuelos);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LA OPCION 1 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 5:
                if(!ll_isEmpty(listaVuelos))
                {
                    if(controller_Sellanes_filterAndSaveVuelosCortos("VuelosCortos.csv", listaVuelos))
                    {
                        printf("SE A GUARDADO LA LISTA FILTRADA EN VuelosCortos.csv CORRECTAMENTE");
                    }
                    else
                    {
                        printf("A OCURRIDO UN PROBLEMA AL GUARDAR LA LISTA");
                    }
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LA OPCION 1 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 6:
                if(!ll_isEmpty(listaVuelos))
                {
                    controller_Sellanes_listarVuelosPortugal(listaVuelos, listaPilotos);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LA OPCION 1 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 7:
                if(!ll_isEmpty(listaVuelos))
                {
                    controller_Sellanes_listarVuelosSinAlexLifeson(listaVuelos, listaPilotos);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LA OPCION 1 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 8:
                controller_Sellanes_filtrarPilotosNombre(listaPilotos, "Alex Lifeson");
                pausa();
            break;
        }
        system("cls");
    }while(opcion != 9);


    ll_deleteLinkedList(listaPilotos);
    ll_deleteLinkedList(listaVuelos);
    return 0;
}
