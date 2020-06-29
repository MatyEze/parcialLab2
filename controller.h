






int controller_Sellanes_loadVuelos(char* path, LinkedList* pArrayListVuelo);
int controller_Sellanes_loadPilotos(char* path, LinkedList* pArrayListPiloto);
int controller_Sellanes_listarVuelos(LinkedList* pArrayListVuelo, LinkedList* pListaPiloto);
int controller_Sellanes_contarPasajeros(LinkedList* pArrayListVuelo);
int controller_Sellanes_contarPasajerosIrlanda(LinkedList* pArrayListVuelo);
int controller_Sellanes_saveVuelos(char* path, LinkedList* pArrayListVuelo);
int controller_Sellanes_filterAndSaveVuelosCortos(char* path, LinkedList* pArrayListVuelo);
int controller_Sellanes_listarVuelosPortugal(LinkedList* pArrayListVuelo, LinkedList* pListPilots);
int controller_Sellanes_listarVuelosSinAlexLifeson(LinkedList* pArrayListVuelo, LinkedList* pListPilots);

int controller_Sellanes_listarPiltos(LinkedList* pListPilots);
