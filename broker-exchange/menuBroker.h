#ifndef MENUBROKER_H_INCLUDED
#define MENUBROKER_H_INCLUDED

#include "structs.h"
#include "constantes.h"

//variables:
extern Cliente listaClientes[]; // Declarar externamente las variables globales
extern Empresa listaEmpresas[];
extern int numClientes;
extern int numEmpresas;

//
void mostrarMenuBroker();
void menuBroker();

//funcionalidades
void altaCliente();
void bajaCliente(); //borrar
void modificarCliente();

void altaEmpresa();
void mostrarEmpresas();
void bajaEmpresa();
void modificarEmpresa();
void filtrarOperacionesPorCliente();
void filtrarOperacionesPorIDTicker();

void altaCliente() {
    //verifica si se alcanzo el macimo de clientes
    if (numClientes >= MAX_CLIENTES) {
        printf("No se pueden agregar más clientes, límite alcanzado.\n");
        return;
    }

    Cliente nuevoCliente;

    // Solicitar el nombre del cliente
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nuevoCliente.nombre);

    // Solicitar el email del cliente
    printf("Ingrese el email del cliente: ");
    scanf("%s", nuevoCliente.email);

    // Solicitar el CUIT del cliente
    printf("Ingrese el CUIT del cliente: ");
    scanf("%s", nuevoCliente.cuit);

    // contraseña
    printf("Ingrese la contraseña del cliente: ");
    scanf("%s", nuevoCliente.password);

    // Solicitar el saldo de la cuenta (debe ser mayor a 0)
    do {
        printf("Ingrese el saldo inicial del cliente: ");
        scanf("%f", &nuevoCliente.saldo_cuenta);
        if (nuevoCliente.saldo_cuenta <= 0) {
            printf("Error: El saldo debe ser mayor a cero.\n");
        }
    } while (nuevoCliente.saldo_cuenta <= 0);

    // Inicializar las inversiones y el número de inversiones
    nuevoCliente.num_inversiones = 0;

    // Agregar el nuevo cliente a la lista
    listaClientes[numClientes] = nuevoCliente;
    numClientes++;

    printf("Cliente agregado con éxito.\n");
}

///------------------------------------------------------------
void mostrarClientes() {
    // Verifica si hay clientes registrados
    if (numClientes == 0) {
        printf("No hay clientes registrados.\n");
        return;
    }

    printf("Listado de Clientes:\n");
    printf("---------------------\n");

    for (int i = 0; i < numClientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nombre: %s\n", listaClientes[i].nombre);
        printf("Email: %s\n", listaClientes[i].email);
        printf("CUIT: %s\n", listaClientes[i].cuit);
        printf("Saldo: %.2f\n", listaClientes[i].saldo_cuenta);
        printf("---------------------\n");
    }
}

void modificarCliente() {
    char cuit[15];
    int encontrado = 0;

    // Solicitar el CUIT del cliente a modificar
    printf("Ingrese el CUIT del cliente a modificar: ");
    scanf("%s", cuit);

    // Limpiar el buffer de entrada después de leer el CUIT
    getchar();

    // Buscar el cliente en la lista
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(listaClientes[i].cuit, cuit) == 0) {
            encontrado = 1;

            // Mostrar los datos actuales del cliente
            printf("Datos actuales del cliente:\n");
            printf("Nombre: %s\n", listaClientes[i].nombre);
            printf("Email: %s\n", listaClientes[i].email);
            printf("CUIT: %s\n", listaClientes[i].cuit);
            printf("Saldo: %.2f\n", listaClientes[i].saldo_cuenta);

            // Modificar los datos
            printf("Ingrese el nuevo nombre del cliente (o presione Enter para no modificar): ");
            char nuevoNombre[50];
            fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
            // Remover el salto de línea que podría quedar en el nombre
            if (nuevoNombre[strlen(nuevoNombre) - 1] == '\n') {
                nuevoNombre[strlen(nuevoNombre) - 1] = '\0';
            }
            if (strlen(nuevoNombre) > 0) {
                strcpy(listaClientes[i].nombre, nuevoNombre);
            }

            printf("Ingrese el nuevo email del cliente (o presione Enter para no modificar): ");
            char nuevoEmail[50];
            fgets(nuevoEmail, sizeof(nuevoEmail), stdin);
            if (nuevoEmail[strlen(nuevoEmail) - 1] == '\n') {
                nuevoEmail[strlen(nuevoEmail) - 1] = '\0';
            }
            if (strlen(nuevoEmail) > 0) {
                strcpy(listaClientes[i].email, nuevoEmail);
            }

            printf("Ingrese el nuevo saldo del cliente (o -1 para no modificar): ");
            float nuevoSaldo;
            scanf("%f", &nuevoSaldo);
            if (nuevoSaldo != -1) {
                listaClientes[i].saldo_cuenta = nuevoSaldo;
            }

            printf("Cliente modificado con éxito.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente no encontrado.\n");
    }
}

//BAJA
void bajaCliente() {
    char cuit[15];
    int encontrado = 0;

    // Solicitar el CUIT del cliente a eliminar
    printf("Ingrese el CUIT del cliente a eliminar: ");
    scanf("%s", cuit);

    // Buscar el cliente en la lista
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(listaClientes[i].cuit, cuit) == 0) {
            encontrado = 1;

            // Eliminar el cliente moviendo los siguientes hacia atrás
            for (int j = i; j < numClientes - 1; j++) {
                listaClientes[j] = listaClientes[j + 1];
            }

            numClientes--; // Disminuir el contador de clientes
            printf("Cliente eliminado con éxito.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente no encontrado.\n");
    }
}


//Empresas
void altaEmpresa()
{
    //verifica si se alcanzo el macimo de clientes
    if (numEmpresas >= MAX_EMPRESAS) {
        printf("No se pueden agregar más empresas, límite alcanzado.\n");
        return;
    }

    Empresa nuevaEmpresa;

    // Solicitar el nombre del cliente
    printf("Ingrese el nombre la empresa a agregar: ");
    scanf("%s", nuevaEmpresa.nombre);

    // Solicitar el Id Ticker de la empresa
    printf("Ingrese el Id Ticker de la empresa: ");
    scanf("%s", nuevaEmpresa.id_ticker);



    // Solicitar el saldo de la cuenta (debe ser mayor a 0)
    do {
            //Solicitar el precio
            printf("Ingrese el Precio Actual de la empresa: ");
            scanf("%f", &nuevaEmpresa.precio_actual);
        if (nuevaEmpresa.precio_actual <= 0) {
            printf("Error: El saldo debe ser mayor a cero.\n");
        }
    } while (nuevaEmpresa.precio_actual <= 0);

    // Agregar el nuevo cliente a la lista
    listaEmpresas[numEmpresas] = nuevaEmpresa;
    numEmpresas++;

    printf("Empresa agregada con éxito.\n");
}

void mostrarEmpresas()
{
    // Verifica si hay empresas
    if (numEmpresas == 0) {
        printf("No hay empresas registradas.\n");
        return;
    }

    printf("Listado de Empresas:\n");
    printf("---------------------\n");

    for (int i = 0; i < numEmpresas; i++) {
        printf("Empresa %d:\n", i + 1);
        printf("Nombre: %s\n", listaEmpresas[i].nombre);
        printf("ID Ticker: %s\n", listaEmpresas[i].id_ticker);
        printf("Precio Actual: %.2f\n", listaEmpresas[i].precio_actual);
        printf("---------------------\n");
    }
}

void bajaEmpresa()
{
    return;
}

void modificarEmpresa()
{
    return;
}

void filtrarOperacionesPorCliente()
{
    return;
}

void filtrarOperacionesPorIDTicker()
{
    return;
}


///------------------------------------
void menuBroker() {
    int opcion;

    do {
        mostrarMenuBroker();
        printf("\nSelecciona una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                altaCliente();
                break;
            case 2:
                bajaCliente();
                break;
            case 3:
                modificarCliente();
                break;
            case 4:
                altaEmpresa();
                break;
            case 5:
                bajaEmpresa();
                break;
            case 6:
                modificarEmpresa();
                break;
            case 7:
                filtrarOperacionesPorCliente();
                break;
            case 8:
                filtrarOperacionesPorIDTicker();
                break;
            case 9:
                printf("Volviendo al menú principal...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo nuevamente.\n");
        }
    } while (opcion != 9);
}

// Función que muestra el menú del broker
void mostrarMenuBroker() {
    printf("\n--- Menú de Broker ---\n");
    printf("1. Alta de clientes\n");
    printf("2. Baja de clientes\n");
    printf("3. Modificación de clientes\n");
    printf("4. Alta de empresas\n");
    printf("5. Baja de empresas\n");
    printf("6. Modificación de empresas\n");
    printf("7. Filtrar operaciones por cliente\n");
    printf("8. Filtrar operaciones por ID ticker\n");
    printf("9. Volver al menú principal\n");
}


#endif // MENUBROKER_H_INCLUDED
