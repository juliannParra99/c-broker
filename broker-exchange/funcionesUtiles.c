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
