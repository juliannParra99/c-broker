#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

void *obtenerMemoria(size_t size);
char *stringDinamico(char *origen);
void liberar_memoria(void *puntero);


void *obtenerMemoria(size_t size)
{
    void *espacioMem = malloc(size);

    if(espacioMem == NULL)
    {
        printf("Error al solicitar memoria\n");
        exit(1);
    }

    return espacioMem;
}

// Función que recibe un string y devuelve una copia en memoria dinámica
char *stringDinamico(char *origen) {

    if (origen == NULL) {
        printf("Error: String de origen es NULL.\n");
        exit(1);  // Salir con código de error
    }

    size_t longitud = strlen(origen) + 1;

    // Reservar memoria para la copia
    char *copia = (char *)obtenerMemoria(longitud * sizeof(char));

    // Verificar si la memo fue asignada correctamente
    if (copia == NULL) {
        printf("Error al solicitar memoria\n");
        exit(1);
    }
    // Copiar el contenido del string original a la copia
    strcpy(copia, origen);

    return copia;
}

void liberar_memoria(void *puntero) {
    free(puntero);
    printf("Memoria liberada correctamente\n");
}


#endif // UTIL_H_INCLUDED
