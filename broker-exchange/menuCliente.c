#include <stdio.h>
#include <stdlib.h>
#include "menuBroker.h"
#include "structs.h"
#include "constantes.h"
#include "funcionesUtiles.h"

extern Cliente listaClientes[MAX_CLIENTES]; // Declaración de listaClientes como variable externa
extern Empresa listaEmpresas[];
extern int numClientes;
extern int numEmpresas;



// Función del menú del Cliente
void menuCliente(int clienteIndex) {
    int opcion;

    do {
        printf("\n--- Menú Cliente ---\n");
        printf("SALDO ACTUAL: %.2f \n", listaClientes[clienteIndex].saldo_cuenta );
        printf("1. Realizar inversión\n");
        printf("2. Ver rendimiento\n");
        printf("3. Cargar saldo:\n");
        printf("4. Extraer saldo\n");
        printf("5. Ver portafolio\n");
        printf("6. Volver al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                realizarInversion(clienteIndex);
                break;
            case 2:
                verRendimiento(clienteIndex, listaEmpresas, numEmpresas);
                break;
            case 3:
                cargarSaldo(clienteIndex);
                break;
            case 4:
                extraerSaldo(clienteIndex);
                break;
            case 5:
                verPortafolio(clienteIndex);
                break;
            case 6:
                printf("Volviendo al menú principal...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 6);
}

// Función para realizar una inversión
void realizarInversion(int clienteIndex) {
    int subopcion;
    do {
        printf("\n--- Realizar Inversión ---\n");
        printf("1. Mostrar listado de empresas disponibles\n");
        printf("2. Comprar acciones\n");
        printf("3. Vender acciones\n");
        printf("4. Volver al menú del cliente\n");
        printf("Selecciona una opción: ");
        scanf("%d", &subopcion);

        switch(subopcion) {
            case 1:
                mostrarEmpresas();
                break;
            case 2:
                comprarAcciones(clienteIndex);
                break;
            case 3:
                venderAcciones(clienteIndex);
                break;
            case 4:
                printf("Volviendo al menú de cliente...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo nuevamente.\n");
        }
    } while (subopcion != 4);
}

//
void comprarAcciones(int clienteIndex) {
    if (listaClientes[clienteIndex].saldo_cuenta <= 0) {
        printf("No puede realizar operaciones, su saldo de cuenta es insuficiente.\n");
        return;
    }

    char idTicker[10];
    int cantidadAcciones;
    int empresaEncontrada = 0;

    printf("Ingrese el ID Ticker de la empresa: ");
    scanf("%s", idTicker);

    for (int i = 0; i < numEmpresas; i++) {
        if (strcmp(listaEmpresas[i].id_ticker, idTicker) == 0) {
            empresaEncontrada = 1;

            printf("Ingrese la cantidad de acciones a comprar: ");
            scanf("%d", &cantidadAcciones);

            float precioTotal = cantidadAcciones * listaEmpresas[i].precio_actual;

            if (listaClientes[clienteIndex].saldo_cuenta >= precioTotal) {
                // Capturar la fecha de compra
                char fechaCompra[11];
                printf("Ingrese la fecha de compra (YYYY-MM-DD): ");
                scanf("%s", fechaCompra);

                // Registrar la nueva inversión como una entrada individual
                Inversion nuevaInversion;
                strcpy(nuevaInversion.id_ticker, idTicker);
                nuevaInversion.cantidad_acciones = cantidadAcciones;
                nuevaInversion.precio_compra = listaEmpresas[i].precio_actual;
                strcpy(nuevaInversion.fecha, fechaCompra);  // Guardar la fecha de compra

                // Agregar la nueva inversión a la lista de inversiones del cliente
                listaClientes[clienteIndex].inversiones[listaClientes[clienteIndex].num_inversiones] = nuevaInversion;
                listaClientes[clienteIndex].num_inversiones++;

                // Actualizar el saldo del cliente
                listaClientes[clienteIndex].saldo_cuenta -= precioTotal;
                printf("Compra realizada con éxito.\n");
            } else {
                printf("Saldo insuficiente para realizar la compra.\n");
            }
            break;
        }
    }

    if (!empresaEncontrada) {
        printf("Empresa no encontrada.\n");
    }
}



void venderAcciones(int clienteIndex) {
    if (listaClientes[clienteIndex].num_inversiones == 0) {
        printf("No tiene inversiones para vender.\n");
        return;
    }

    char idTicker[10];
    int cantidadAcciones;
    int empresaEncontrada = 0;

    printf("Ingrese el ID Ticker de la empresa de la que desea vender acciones: ");
    scanf("%s", idTicker);

    // Buscar la empresa
    for (int i = 0; i < numEmpresas; i++) {
        if (strcmp(listaEmpresas[i].id_ticker, idTicker) == 0) {
            empresaEncontrada = 1;

            // Buscar si el cliente tiene acciones de esta empresa
            int inversionEncontrada = 0;
            for (int j = 0; j < listaClientes[clienteIndex].num_inversiones; j++) {
                if (strcmp(listaClientes[clienteIndex].inversiones[j].id_ticker, idTicker) == 0) {
                    inversionEncontrada = 1;

                    printf("Ingrese la cantidad de acciones a vender: ");
                    scanf("%d", &cantidadAcciones);

                    if (cantidadAcciones <= listaClientes[clienteIndex].inversiones[j].cantidad_acciones) {
                        // Calcular el monto total de la venta
                        float precioTotal = cantidadAcciones * listaEmpresas[i].precio_actual;

                        // Reducir las acciones que tiene el cliente
                        listaClientes[clienteIndex].inversiones[j].cantidad_acciones -= cantidadAcciones;

                        // Aumentar el saldo del cliente
                        listaClientes[clienteIndex].saldo_cuenta += precioTotal;

                        // Si el cliente vendió todas sus acciones, eliminar la inversión
                        if (listaClientes[clienteIndex].inversiones[j].cantidad_acciones == 0) {
                            // Mover las inversiones restantes para ocupar el espacio
                            for (int k = j; k < listaClientes[clienteIndex].num_inversiones - 1; k++) {
                                listaClientes[clienteIndex].inversiones[k] = listaClientes[clienteIndex].inversiones[k + 1];
                            }
                            listaClientes[clienteIndex].num_inversiones--;  // Reducir el número de inversiones
                        }

                        printf("Venta realizada con éxito. Se acreditaron %.2f a su cuenta.\n", precioTotal);
                    } else {
                        printf("No tiene suficientes acciones para vender.\n");
                    }
                    break;
                }
            }

            if (!inversionEncontrada) {
                printf("No tiene inversiones en la empresa con el ID Ticker proporcionado.\n");
            }
            break;
        }
    }

    if (!empresaEncontrada) {
        printf("Empresa no encontrada.\n");
    }
}

void verPortafolio(int clienteIndex) {
    if (listaClientes[clienteIndex].num_inversiones == 0) {
        printf("El cliente no tiene inversiones en su portafolio.\n");
        return;
    }

    double totalValoresActuales = sumarValoresActuales(clienteIndex);
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("El valor de la cartera es de: %.2lf\n", totalValoresActuales);

    printf("-------------------------------------------------------------------------------\n");

    printf("Listado de Activos del Cliente: %s\n", listaClientes[clienteIndex].nombre);
    printf("-------------------------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
           "ID Ticker", "Nombre Empresa", "Acciones", "Precio Compra",
           "Precio Actual", "Valor Compra", "Valor Actual",
           "Rendimiento ($)", "Rendimiento (%)");

    // Ordenar las inversiones por rendimiento porcentual de mayor a menor
    for (int i = 0; i < listaClientes[clienteIndex].num_inversiones - 1; i++) {
        for (int j = i + 1; j < listaClientes[clienteIndex].num_inversiones; j++) {
            // Calcular rendimiento para la inversión `i`
            float precioActual_i = obtenerPrecioActual(listaClientes[clienteIndex].inversiones[i].id_ticker);
            float valorCompra_i = listaClientes[clienteIndex].inversiones[i].cantidad_acciones * listaClientes[clienteIndex].inversiones[i].precio_compra;
            float valorActual_i = listaClientes[clienteIndex].inversiones[i].cantidad_acciones * precioActual_i;
            float rendimientoPorcentaje_i = (valorCompra_i > 0) ? ((valorActual_i - valorCompra_i) / valorCompra_i) * 100 : 0;

            // Calcular rendimiento para la inversión `j`
            float precioActual_j = obtenerPrecioActual(listaClientes[clienteIndex].inversiones[j].id_ticker);
            float valorCompra_j = listaClientes[clienteIndex].inversiones[j].cantidad_acciones * listaClientes[clienteIndex].inversiones[j].precio_compra;
            float valorActual_j = listaClientes[clienteIndex].inversiones[j].cantidad_acciones * precioActual_j;
            float rendimientoPorcentaje_j = (valorCompra_j > 0) ? ((valorActual_j - valorCompra_j) / valorCompra_j) * 100 : 0;

            // Intercambiar si la inversión j tiene un mejor rendimiento que i
            if (rendimientoPorcentaje_j > rendimientoPorcentaje_i) {
                Inversion temp = listaClientes[clienteIndex].inversiones[i];
                listaClientes[clienteIndex].inversiones[i] = listaClientes[clienteIndex].inversiones[j];
                listaClientes[clienteIndex].inversiones[j] = temp;
            }
        }
    }

    // Mostrar las inversiones ordenadas por rendimiento
    for (int i = 0; i < listaClientes[clienteIndex].num_inversiones; i++) {
        Inversion inv = listaClientes[clienteIndex].inversiones[i];
        char nombreEmpresa[50] = "Desconocido";
        float precioActual = obtenerPrecioActual(inv.id_ticker);

        for (int j = 0; j < numEmpresas; j++) {
            if (strcmp(listaEmpresas[j].id_ticker, inv.id_ticker) == 0) {
                strcpy(nombreEmpresa, listaEmpresas[j].nombre);
                break;
            }
        }

        float valorCompra = inv.cantidad_acciones * inv.precio_compra;
        float valorActual = inv.cantidad_acciones * precioActual;
        float rendimientoValor = valorActual - valorCompra;
        float rendimientoPorcentaje = (valorCompra > 0) ? (rendimientoValor / valorCompra) * 100 : 0;

        printf("%-10s %-20s %-15d %-15.2f %-15.2f %-15.2f %-15.2f %-15.2f %-15.2f%%\n",
               inv.id_ticker, nombreEmpresa, inv.cantidad_acciones,
               inv.precio_compra, precioActual, valorCompra, valorActual,
               rendimientoValor, rendimientoPorcentaje);
    }

    printf("-------------------------------------------------------------------------------\n");
}


//// no se usa en ningun lado esta funcion
void comprarVenderAcciones() {
    int opcion;

    printf("¿Desea (1) comprar o (2) vender acciones? ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        comprarAcciones(0);
    } else if (opcion == 2) {
        venderAcciones(0);
    } else {
        printf("Opción no válida.\n");
    }
}

////
////
////
///
//Cargar saldo, extraer saldo;
void cargarSaldo(int indiceCliente) {
    float monto;

    printf("Ingrese el monto que desea cargar: ");
    scanf("%f", &monto);

    if (monto > 0) {
        listaClientes[indiceCliente].saldo_cuenta += monto;
        printf("Saldo cargado con éxito. Su saldo actual es: %.2f\n", listaClientes[indiceCliente].saldo_cuenta);
    } else {
        printf("El monto debe ser mayor a cero.\n");
    }
}

// Función para extraer saldo
void extraerSaldo(int indiceCliente) {
    float monto;

    printf("Ingrese el monto que desea extraer: ");
    scanf("%f", &monto);

    if (monto > 0 && monto <= listaClientes[indiceCliente].saldo_cuenta) {
        listaClientes[indiceCliente].saldo_cuenta -= monto;
        printf("Extracción realizada con exito. Su saldo actual es: %.2f\n", listaClientes[indiceCliente].saldo_cuenta);
    } else if (monto > listaClientes[indiceCliente].saldo_cuenta) {
        printf("Saldo insuficiente. No puede extraer mas de lo que tiene.\n");
    } else {
        printf("El monto debe ser mayor a cero.\n");
    }
}

//////////////////////////
//////////////////////////
/////////////////////////
//Vista de rendimiento
//
void calcularRendimientoDiario(Cliente* cliente, Empresa empresas[], int num_empresas) {
    float valor_inversion_actual = 0.0;
    float valor_inversion_compra = 0.0;

    // Recorrer las inversiones del cliente
    for (int i = 0; i < cliente->num_inversiones; i++) {
        // Recorrer las empresas para encontrar el ticker correspondiente
        for (int j = 0; j < num_empresas; j++) {
            // Comparar el ticker de la inversión con el ticker de la empresa
            if (strcmp(cliente->inversiones[i].id_ticker, empresas[j].id_ticker) == 0) {
                // Calcular el valor actual de la inversión
                valor_inversion_actual += cliente->inversiones[i].cantidad_acciones * empresas[j].precio_actual;
                // Calcular el valor de compra de la inversión
                valor_inversion_compra += cliente->inversiones[i].cantidad_acciones * cliente->inversiones[i].precio_compra;

                break; // Salir del bucle de empresas ya que encontramos el ticker
            }
        }
    }

    // Imprimir los valores totales para verificación
    printf("Valor Inversión Actual: %.2f\n", valor_inversion_actual);
    printf("Valor Inversión Compra: %.2f\n", valor_inversion_compra);

    // Comprobar si el valor de compra es cero para evitar división por cero
    if (valor_inversion_compra == 0) {
        printf("No se puede calcular el rendimiento, el valor de compra es 0.\n");
        return; // Salir de la función
    }

    // Calcular el rendimiento en dinero
    float rendimiento_diario = valor_inversion_actual - valor_inversion_compra;
    // Calcular el rendimiento en porcentaje
    float rendimiento_porcentaje = (rendimiento_diario / valor_inversion_compra) * 100.0;

    // Imprimir el rendimiento en dinero y en porcentaje
    printf("-------------------------------------------------------------------------------\n");
    printf("                         Resumen del Rendimiento Diario\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Valor Inversión Actual: %.2f\n", valor_inversion_actual);
    printf("Valor Inversión Compra: %.2f\n", valor_inversion_compra);
    printf("Rendimiento Diario: %.2f\n", rendimiento_diario);
    printf("Rendimiento Diario: %.2f%%\n", rendimiento_porcentaje);
    printf("-------------------------------------------------------------------------------\n");
}

float calcularRendimientoHistorico(Cliente* cliente, Empresa empresas[], int num_empresas, char* fecha) {
    float valor_inversion_hist = 0.0;
    float valor_inversion_actual = 0.0;

    for (int i = 0; i < cliente->num_inversiones; i++) {
        for (int j = 0; j < num_empresas; j++) {
            if (strcmp(cliente->inversiones[i].id_ticker, empresas[j].id_ticker) == 0) {
                // Encuentra el precio en la fecha específica
                for (int k = 0; k < empresas[j].num_historico; k++) {
                    if (strcmp(empresas[j].historico[k].fecha, fecha) == 0) {
                        valor_inversion_hist += cliente->inversiones[i].cantidad_acciones * empresas[j].historico[k].precio;
                        break;
                    }
                }
                // Calcula el valor actual también
                valor_inversion_actual += cliente->inversiones[i].cantidad_acciones * empresas[j].precio_actual;
                break;
            }
        }
    }

    return ((valor_inversion_actual - valor_inversion_hist) / valor_inversion_hist) * 100.0; // % de cambio
}


// Función para mostrar el rendimiento
void verRendimiento(int clienteIndex, Empresa empresas[], int num_empresas) {
    int opcion;
    printf("\n--- Ver Rendimiento ---\n");
    printf("1. Rendimiento Diario\n");
    printf("2. Rendimiento Historico\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1: {
            //tengo que agregar para mostrar el cambio de valor diario, hasta ahora solo tengo el cambio de valor  porcentual;
            //convedria hacerlo directamente dentro las fuciones y no pdir un return, por que quiero mostrar dos valores.
            calcularRendimientoDiario(&listaClientes[clienteIndex], empresas, num_empresas);
            break;
        }
        case 2: {
            char fecha[11];
            printf("Ingrese la fecha (YYYY-MM-DD): ");
            scanf("%s", fecha);

            float rendimiento_hist = calcularRendimientoHistorico(&listaClientes[clienteIndex], empresas, num_empresas, fecha);
            printf("Rendimiento Historico al %s: %.2f%%\n", fecha, rendimiento_hist);
            break;
        }
        default:
            printf("Opcion inválida. Intente de nuevo.\n");
    }
}
