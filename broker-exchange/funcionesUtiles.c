#include <stdlib.h>
#include <time.h>

void inicializar_aleatoriedad() {

    srand(time(NULL)); // Utiliza la hora actual como semilla

}

void actualizar_precio_accion(float *precio_actual) {

    float porcentaje_maximo = 0.05; // 5% de variación máxima

    float cambio = (float)rand() / RAND_MAX * 2 * porcentaje_maximo - porcentaje_maximo;

    *precio_actual += *precio_actual * cambio;

}
