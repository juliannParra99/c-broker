#include <stdio.h>
#include <stdlib.h>
#include "menuBroker.h"
#include "structs.h"
#include "constantes.h"

extern Cliente listaClientes[MAX_CLIENTES]; // Declaraci�n de listaClientes como variable externa
extern Empresa listaEmpresas[];
extern int numClientes;
extern int numEmpresas;



// Funci�n del men� del Cliente
void menuCliente() {
    int opcion;

    do {
        printf("\n--- Men� Cliente ---\n");
        printf("1. Realizar inversi�n\n");
        printf("2. Mostrar listado de empresas disponibles\n");
        printf("3. Comprar o vender acciones\n");
        printf("4. Ver rendimiento\n");
        printf("5. Cargar saldo\n");
        printf("6. Extraer saldo\n");
        printf("7. Ver portafolio\n");
        printf("8. Volver al men� principal\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                realizarInversion();
                break;
            case 2:
                mostrarEmpresas();
                break;
            case 3:
                comprarVenderAcciones();
                break;
            case 4:
//                verRendimiento();
                break;
            case 5:
//                cargarSaldo();
                break;
            case 6:
//                extraerSaldo();
                break;
            case 7:
//                verPortafolio();
                break;
            case 8:
                printf("Volviendo al men� principal...\n");
                break;
            default:
                printf("Opci�n inv�lida. Intente de nuevo.\n");
        }
    } while (opcion != 8);
}

// Funci�n para realizar una inversi�n
void realizarInversion() {
    int subopcion;
    do {
        printf("\n--- Realizar Inversi�n ---\n");
        printf("1. Mostrar listado de empresas disponibles\n");
        printf("2. Comprar acciones\n");
        printf("3. Vender acciones\n");
        printf("4. Volver al men� del cliente\n");
        printf("Selecciona una opci�n: ");
        scanf("%d", &subopcion);

        switch(subopcion) {
            case 1:
                mostrarEmpresas();
                break;
            case 2:
                comprarAcciones(0);
                break;
            case 3:
                venderAcciones();
                break;
            case 4:
                printf("Volviendo al men� de cliente...\n");
                break;
            default:
                printf("Opci�n no v�lida. Int�ntalo nuevamente.\n");
        }
    } while (subopcion != 4);
}

//
void comprarAcciones(int indiceCliente) {
    if (listaClientes[indiceCliente].saldo_cuenta <= 0) {
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

            if (listaClientes[indiceCliente].saldo_cuenta >= precioTotal) {
                int inversionEncontrada = 0;

                // Verificar si el cliente ya tiene acciones de esta empresa
                for (int j = 0; j < listaClientes[indiceCliente].num_inversiones; j++) {
                    if (strcmp(listaClientes[indiceCliente].inversiones[j].id_ticker, idTicker) == 0) {
                        listaClientes[indiceCliente].inversiones[j].cantidad_acciones += cantidadAcciones;
                        inversionEncontrada = 1;
                        break;
                    }
                }

                // Si no tiene inversiones previas en esta empresa, agregar nueva inversi�n
                if (!inversionEncontrada) {
                    Inversion nuevaInversion;
                    strcpy(nuevaInversion.id_ticker, idTicker);
                    nuevaInversion.cantidad_acciones = cantidadAcciones;
                    nuevaInversion.precio_compra = listaEmpresas[i].precio_actual;
                    listaClientes[indiceCliente].inversiones[listaClientes[indiceCliente].num_inversiones] = nuevaInversion;
                    listaClientes[indiceCliente].num_inversiones++;
                }

                listaClientes[indiceCliente].saldo_cuenta -= precioTotal;
                printf("Compra realizada con �xito.\n");
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

void venderAcciones(int indiceCliente) {
    char idTicker[10];
    int cantidadAcciones;
    int inversionEncontrada = 0;

    printf("Ingrese el ID Ticker de la empresa: ");
    scanf("%s", idTicker);

    for (int i = 0; i < listaClientes[indiceCliente].num_inversiones; i++) {
        if (strcmp(listaClientes[indiceCliente].inversiones[i].id_ticker, idTicker) == 0) {
            inversionEncontrada = 1;

            printf("Ingrese la cantidad de acciones a vender: ");
            scanf("%d", &cantidadAcciones);

            if (cantidadAcciones <= listaClientes[indiceCliente].inversiones[i].cantidad_acciones) {
                listaClientes[indiceCliente].inversiones[i].cantidad_acciones -= cantidadAcciones;

                // Obtener el valor de venta basado en el precio actual
                float ganancia = cantidadAcciones * listaEmpresas[i].precio_actual;
                listaClientes[indiceCliente].saldo_cuenta += ganancia;

                printf("Venta realizada con �xito. Ganancia: %.2f\n", ganancia);

                // Si el cliente vendi� todas las acciones, eliminar la inversi�n
                if (listaClientes[indiceCliente].inversiones[i].cantidad_acciones == 0) {
                    for (int j = i; j < listaClientes[indiceCliente].num_inversiones - 1; j++) {
                        listaClientes[indiceCliente].inversiones[j] = listaClientes[indiceCliente].inversiones[j + 1];
                    }
                    listaClientes[indiceCliente].num_inversiones--;
                    printf("Inversi�n en %s eliminada de su portafolio.\n", idTicker);
                }
            } else {
                printf("No tiene suficientes acciones para vender.\n");
            }
            break;
        }
    }

    if (!inversionEncontrada) {
        printf("Inversi�n no encontrada.\n");
    }
}


void comprarVenderAcciones() {
    int opcion;

    printf("�Desea (1) comprar o (2) vender acciones? ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        comprarAcciones(0);
    } else if (opcion == 2) {
        venderAcciones(0);
    } else {
        printf("Opci�n no v�lida.\n");
    }
}
