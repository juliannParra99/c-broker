#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "structs.h"

extern Cliente listaClientes[MAX_CLIENTES]; // Declaración de listaClientes como variable externa
extern Empresa listaEmpresas[];
extern int numClientes;
extern int numEmpresas;

void inicializar_aleatoriedad() {

    srand(time(NULL)); // Utiliza la hora actual como semilla

}

void actualizar_precio_accion(float *precio_actual) {

    float porcentaje_maximo = 0.05; // 5% de variación máxima

    float cambio = (float)rand() / RAND_MAX * 2 * porcentaje_maximo - porcentaje_maximo;

    *precio_actual += *precio_actual * cambio;

}

///
//funcion rendimiento de calcular valor de cartera
//float calcularValorTotalCartera(int clienteIndex) {
//    float valorTotal = 0.0f;
//
//    for (int i = 0; i < listaClientes[clienteIndex].num_inversiones; i++) {
//        Inversion inv = listaClientes[clienteIndex].inversiones[i];
//        float precioActual = obtenerPrecioActual(inv.id_ticker);
//        float valorActual = inv.cantidad_acciones * precioActual;
//        printf("Inversión %d: Precio Actual = %.2f, Valor Actual = %.2f\n", i+1, precioActual, valorActual);
//        valorTotal += valorActual;
//    }
//
//    printf("Valor total de la cartera: %.2f\n", valorTotal);
//    return valorTotal;
//}
float obtenerPrecioActual(const char* id_ticker) {
    for (int k = 0; k < numEmpresas; k++) {
        if (strcmp(listaEmpresas[k].id_ticker, id_ticker) == 0) {
            return listaEmpresas[k].precio_actual;
        }
    }
    return 0.0; // Retornar 0.0 si no se encuentra la empresa (manejo de error simple)
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
// Nueva función para obtener el valor total de la cartera de un cliente
//float obtenerValorCarteraCliente(int clienteIndex) {
//    // Verificar si el cliente tiene inversiones
//    if (listaClientes[clienteIndex].num_inversiones == 0) {
//        printf("El cliente no tiene inversiones en su portafolio.\n");
//        return 0.0f;  // Retornar 0 si no hay inversiones
//    }
//
//    // Llamar a la función calcularValorCartera
//    return calcularValorCartera(listaClientes[clienteIndex].inversiones, listaClientes[clienteIndex].num_inversiones);
//}


//rendimiientos historicos:




// Función para agregar el histórico del valor de la cartera
//void registrarRendimientoHistorico(Cliente *cliente) {
//    float valorActual = 0.0;
//    for (int i = 0; i < cliente->num_inversiones; i++) {
//        // Aquí, podrías recorrer las inversiones y sumar el valor de cada una
//        valorActual += calcularValorCartera(*cliente); // Ajusta según cómo calcules el valor de la cartera
//    }
//
//    // Suponiendo que tienes una función para obtener la fecha actual en formato "YYYY-MM-DD"
//    char fechaActual[11];
//    obtenerFechaActual(fechaActual);
//
//    // Registra el valor actual en cada empresa asociada
//    for (int j = 0; j < cliente->num_inversiones; j++) {
//        Empresa *empresa = obtenerEmpresa(cliente->inversiones[j].id_ticker);
//        agregarPrecioHistorico(empresa, fechaActual, valorActual);
//    }
//}

// Función para agregar un nuevo precio histórico
//void agregarPrecioHistorico(Empresa *empresa, const char *fecha, float precio) {
//    if (empresa->num_historico < MAX_HISTORICO) {
//        strcpy(empresa->historico[empresa->num_historico].fecha, fecha);
//        empresa->historico[empresa->num_historico].precio = precio;
//        empresa->num_historico++;
//    } else {
//        printf("Se ha alcanzado el máximo de precios históricos para la empresa %s.\n", empresa->id_ticker);
//    }
//}
