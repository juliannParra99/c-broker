#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "structs.h"

extern Cliente listaClientes[MAX_CLIENTES];
extern Empresa listaEmpresas[];
extern int numClientes;
extern int numEmpresas;

void inicializar_aleatoriedad() {

    srand(time(NULL));

}

void actualizar_precio_accion(float *precio_actual) {

    float porcentaje_maximo = 0.05; // 5% de variación máxima

    float cambio = (float)rand() / RAND_MAX * 2 * porcentaje_maximo - porcentaje_maximo;

    *precio_actual += *precio_actual * cambio;

}


float obtenerPrecioActual(const char* id_ticker) {
    for (int k = 0; k < numEmpresas; k++) {
        if (strcmp(listaEmpresas[k].id_ticker, id_ticker) == 0) {
            return listaEmpresas[k].precio_actual;
        }
    }
    return 0.0;
}

double sumarValoresActuales(int clienteIndex) {
    double sumaValorActual = 0.0;

    for (int i = 0; i < listaClientes[clienteIndex].num_inversiones; i++) {
        Inversion inv = listaClientes[clienteIndex].inversiones[i];
        double precioActual = obtenerPrecioActual(inv.id_ticker);

        // Calcular el valor actual de esta inversión
        double valorActual = inv.cantidad_acciones * precioActual;

        // Sumar el valor actual de cada inversión al total
        sumaValorActual += valorActual;
    }

    return sumaValorActual;
}


/// broker
//filtrar operaciones por clientes
void filtrarOperacionesPorCliente(const char* cuit_cliente) {
    int clienteIndex = -1;

    // Buscar el índice del cliente con el CUIT ingresado
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(listaClientes[i].cuit, cuit_cliente) == 0) {
            clienteIndex = i;
            break;
        }
    }

    // Si el cliente existe, muestra sus inversiones
    if (clienteIndex != -1) {
        printf("Operaciones del cliente %s:\n", listaClientes[clienteIndex].nombre);
        printf("-------------------------------------------------------------------------------\n");
        printf("ID Ticker    | Cantidad de Acciones | Precio Compra | Fecha\n");
        printf("-------------------------------------------------------------------------------\n");

        for (int i = 0; i < listaClientes[clienteIndex].num_inversiones; i++) {
            Inversion inv = listaClientes[clienteIndex].inversiones[i];
            printf("%-12s | %-20d | %-13.2f | %s\n",
                   inv.id_ticker, inv.cantidad_acciones, inv.precio_compra, inv.fecha);
        }
    } else {
        printf("Cliente con CUIT %s no encontrado.\n", cuit_cliente);
    }
}

int validarCuitCliente() {
    char cuit[11]; // El CUIT tiene una longitud de 11 caracteres, +1 para el carácter nulo

    // Solicitar el CUIT del cliente
    printf("Ingrese su CUIT (11 dígitos): ");
    scanf("%s", cuit);

    // Buscar al cliente en la lista usando el CUIT
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(listaClientes[i].cuit, cuit) == 0) {
            printf("Cliente encontrado: %s\n", listaClientes[i].nombre);
            return i; // Devolver el índice del cliente
        }
    }

    printf("CUIT no encontrado.\n");
    return -1; // No se encontró un cliente con el CUIT ingresado
}


///
///
float obtenerValorCarteraHistorico(float precio_compra) {
    float porcentaje_maximo = 0.05; // 5% de variación máxima
    float cambio = (float)rand() / RAND_MAX * 2 * porcentaje_maximo - porcentaje_maximo;
    return precio_compra + (precio_compra * cambio);
}

// Función para mostrar el rendimiento histórico de la cartera
// Función para comparar las fechas de las inversiones
int compararFechas(const void* a, const void* b) {
    const Inversion* invA = (const Inversion*)a;
    const Inversion* invB = (const Inversion*)b;
    return strcmp(invA->fecha, invB->fecha); // Orden ascendente por fecha
}

void rendimientoHistoricoCartera(int clienteIndex) {
    // Ordenar las inversiones por fecha de menor a mayor
    qsort(listaClientes[clienteIndex].inversiones, listaClientes[clienteIndex].num_inversiones, sizeof(Inversion), compararFechas);

    printf("Operaciones del cliente %s:\n", listaClientes[clienteIndex].nombre);
    printf("-------------------------------------------------------------------------------\n");
    printf("ID Ticker    | Cantidad de Acciones | Precio Compra | Fecha       | Valor Cartera\n");
    printf("-------------------------------------------------------------------------------\n");

    float valor_cartera = 0.0;

    for (int i = 0; i < listaClientes[clienteIndex].num_inversiones; i++) {
        Inversion inv = listaClientes[clienteIndex].inversiones[i];
        float valor_inicial = inv.cantidad_acciones * inv.precio_compra;

        // Para la primera compra, simplemente se establece el valor de la cartera
        if (i == 0) {
            valor_cartera = valor_inicial;
        } else {
            // Aplica un cambio aleatorio solo después de la primera compra
            float cambio = (float)rand() / RAND_MAX * 0.02 - 0.01; // +/- 1% de variación
            valor_cartera += valor_inicial * (1 + cambio);
        }

        printf("%-12s | %-20d | %-13.2f | %-10s | %-13.2f\n",
               inv.id_ticker, inv.cantidad_acciones, inv.precio_compra, inv.fecha, valor_cartera);
    }

    // Ajusta el valor final de la cartera al total actual
    double totalValoresActuales = sumarValoresActuales(clienteIndex);
    printf("-------------------------------------------------------------------------------\n");
    printf("Valor total de la cartera actual: %.2f\n", totalValoresActuales);
}


float calcularCambioPorcentualCartera(int clienteIndex, int periodo) {
    //días sgún el periodo (7 para semanal, 30 para mensual, 365 para anual)
    int dias = 0;
    switch (periodo) {
        case 1: dias = 7; break;      // Semanal
        case 2: dias = 30; break;     // Mensual
        case 3: dias = 365; break;    // Anual
        default: return 0;            // inválido, retorna 0
    }

    // Calculo del valor inicial y final para el periodo
    float valor_inicial = 0, valor_final = 0;
    for (int i = 0; i < listaClientes[clienteIndex].num_inversiones; i++) {
        Inversion inv = listaClientes[clienteIndex].inversiones[i];
        valor_inicial += inv.precio_compra * inv.cantidad_acciones;

        // Calculo del valor ajustado al final del periodo con la función `obtenerValorCarteraHistorico`
        valor_final += obtenerValorCarteraHistorico(inv.precio_compra) * inv.cantidad_acciones;
    }

    // Calculo del cambio porcentual
    float cambio_porcentual = ((valor_final - valor_inicial) / valor_inicial) * 100;
    return cambio_porcentual;
}




void filtrarInversionesPorTicker(char* buscarPorTicker) {
    printf("Inversiones con Ticker ID '%s':\n", buscarPorTicker);
    printf("-------------------------------------------------------------------------------\n");
    printf("Cliente       | Ticker ID    | Cantidad de Acciones | Precio Compra | Fecha\n");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < numClientes; i++) {
        Cliente cliente = listaClientes[i];

        for (int j = 0; j < cliente.num_inversiones; j++) {
            Inversion inv = cliente.inversiones[j];

            if (strcmp(inv.id_ticker, buscarPorTicker) == 0) {
                printf("%-12s | %-12s | %-20d | %-13.2f | %-10s\n",
                       cliente.nombre, inv.id_ticker, inv.cantidad_acciones, inv.precio_compra, inv.fecha);
            }
        }
    }
}


void calcularGanancia(int clienteIndex) {
    double totalValoresActuales = sumarValoresActuales(clienteIndex);
    double sumaValoresCompra = 0.0;

    // Sumar los valores de compra de todas las inversiones
    for (int i = 0; i < listaClientes[clienteIndex].num_inversiones; i++) {
        Inversion inv = listaClientes[clienteIndex].inversiones[i];
        sumaValoresCompra += inv.cantidad_acciones * inv.precio_compra;
    }

    // Calcular la ganancia
    double ganancia = totalValoresActuales - sumaValoresCompra;


    if (ganancia > 0) {
        printf("Ganancia: +%.2f\n", ganancia);
    } else if (ganancia < 0) {
        printf("Perdida: %.2f\n", ganancia);
    } else {
        printf("Ganancia: 0.00 (sin cambios)\n");
    }
}
