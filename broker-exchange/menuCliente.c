#include <stdio.h>
#include <stdlib.h>
#include "menuBroker.h"
#include "structs.h"
#include "constantes.h"

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
//                verRendimiento();
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
                int inversionEncontrada = 0;

                // Verificar si el cliente ya tiene acciones de esta empresa
                for (int j = 0; j < listaClientes[clienteIndex].num_inversiones; j++) {
                    if (strcmp(listaClientes[clienteIndex].inversiones[j].id_ticker, idTicker) == 0) {
                        listaClientes[clienteIndex].inversiones[j].cantidad_acciones += cantidadAcciones;
                        inversionEncontrada = 1;
                        break;
                    }
                }

                // Si no tiene inversiones previas en esta empresa, agregar nueva inversión
                if (!inversionEncontrada) {
                    Inversion nuevaInversion;
                    strcpy(nuevaInversion.id_ticker, idTicker);
                    nuevaInversion.cantidad_acciones = cantidadAcciones;
                    nuevaInversion.precio_compra = listaEmpresas[i].precio_actual;

                    // Capturar la fecha actual
                    printf("Ingrese la fecha de compra (YYYY-MM-DD): ");
                    scanf("%s", nuevaInversion.fecha);  // O puedes capturar la fecha automáticamente

                    listaClientes[clienteIndex].inversiones[listaClientes[clienteIndex].num_inversiones] = nuevaInversion;
                    listaClientes[clienteIndex].num_inversiones++;
                }

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

//primera manera
void verPortafolio(int clienteIndex) {
    if (listaClientes[clienteIndex].num_inversiones == 0) {
        printf("El cliente no tiene inversiones en su portafolio.\n");
        return;
    }

    printf("Listado de Activos del Cliente: %s\n", listaClientes[clienteIndex].nombre);
    printf("-------------------------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
           "ID Ticker", "Nombre Empresa", "Acciones", "Precio Compra",
           "Precio Actual", "Valor Compra", "Valor Actual",
           "Rendimiento ($)", "Rendimiento (%)");

    // Recorrer todas las inversiones del cliente
    for (int i = 0; i < listaClientes[clienteIndex].num_inversiones; i++) {
        Inversion inv = listaClientes[clienteIndex].inversiones[i];
        char nombreEmpresa[50] = "Desconocido"; // Valor predeterminado si no se encuentra la empresa
        float precioActual = 0.0; // Precio actual de la empresa (si se encuentra)

        // Buscar el nombre de la empresa y su precio actual con base en el ID Ticker
        for (int j = 0; j < numEmpresas; j++) {
            if (strcmp(listaEmpresas[j].id_ticker, inv.id_ticker) == 0) {
                strcpy(nombreEmpresa, listaEmpresas[j].nombre);  // Copiar nombre de la empresa
                precioActual = listaEmpresas[j].precio_actual;   // Obtener el precio actual de la empresa
                break;
            }
        }

        // Calcular el valor total de la inversión al precio de compra
        float valorCompra = inv.cantidad_acciones * inv.precio_compra;

        // Calcular el valor total de la inversión al precio actual
        float valorActual = inv.cantidad_acciones * precioActual;

        // Calcular rendimiento en términos de valor
        float rendimientoValor = valorActual - valorCompra;

        // Calcular rendimiento en porcentaje
        float rendimientoPorcentaje = (valorCompra > 0) ? (rendimientoValor / valorCompra) * 100 : 0;

        // Mostrar la información de la inversión y el rendimiento
        printf("%-10s %-20s %-15d %-15.2f %-15.2f %-15.2f %-15.2f %-15.2f %-15.2f%%\n",
               inv.id_ticker, nombreEmpresa, inv.cantidad_acciones,
               inv.precio_compra, precioActual, valorCompra, valorActual,
               rendimientoValor, rendimientoPorcentaje);
    }

    printf("-------------------------------------------------------------------------------\n");
}

////
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
        printf("Extracción realizada con éxito. Su saldo actual es: %.2f\n", listaClientes[indiceCliente].saldo_cuenta);
    } else if (monto > listaClientes[indiceCliente].saldo_cuenta) {
        printf("Saldo insuficiente. No puede extraer más de lo que tiene.\n");
    } else {
        printf("El monto debe ser mayor a cero.\n");
    }
}

