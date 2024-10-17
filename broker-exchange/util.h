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

// Funci�n que recibe un string y devuelve una copia en memoria din�mica
char *stringDinamico(char *origen) {

    // Verificar si el origen no es NULL
    if (origen == NULL) {
        printf("Error: String de origen es NULL.\n");
        exit(1);  // Salir con c�digo de error
    }
    // Calcular el tama�o del string, incluyendo el espacio para '\0'
    size_t longitud = strlen(origen) + 1;

    // Reservar memoria para la copia
    char *copia = (char *)obtenerMemoria(longitud * sizeof(char));

    // Verificar si la memoria fue asignada correctamente
    if (copia == NULL) {
        printf("Error al solicitar memoria\n");
        exit(1);
    }
    // Copiar el contenido del string original a la copia
    strcpy(copia, origen);

    return copia;
}

void liberar_memoria(void *puntero) {
    free(puntero);  // Liberar la memoria asignada
    printf("Memoria liberada correctamente\n");
}


#endif // UTIL_H_INCLUDED
