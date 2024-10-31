#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "funcionesUtiles.h"


//variables:
extern Cliente listaClientes[]; // Declarar externamente las variables globales
extern Empresa listaEmpresas[];
extern int numClientes;
extern int numEmpresas;


void altaCliente() {
    //verifica si se alcanzo el macimo de clientes
    if (numClientes >= MAX_CLIENTES) {
        printf("No se pueden agregar m�s clientes, l�mite alcanzado.\n");
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

    // contrase�a
    printf("Ingrese la contrase�a del cliente: ");
    scanf("%s", nuevoCliente.password);

    // Solicitar el saldo de la cuenta (debe ser mayor a 0)
    do {
        printf("Ingrese el saldo inicial del cliente: ");
        scanf("%f", &nuevoCliente.saldo_cuenta);
        if (nuevoCliente.saldo_cuenta <= 0) {
            printf("Error: El saldo debe ser mayor a cero.\n");
        }
    } while (nuevoCliente.saldo_cuenta <= 0);

    // Inicializar las inversiones y el n�mero de inversiones
    nuevoCliente.num_inversiones = 0;

    // Agregar el nuevo cliente a la lista
    listaClientes[numClientes] = nuevoCliente;
    numClientes++;

    printf("Cliente agregado con �xito.\n");
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

    // Limpiar el buffer de entrada despu�s de leer el CUIT
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
            // Remover el salto de l�nea que podr�a quedar en el nombre
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

            printf("Cliente modificado con �xito.\n");
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

            // Eliminar el cliente moviendo los siguientes hacia atr�s
            for (int j = i; j < numClientes - 1; j++) {
                listaClientes[j] = listaClientes[j + 1];
            }

            numClientes--; // Disminuir el contador de clientes
            printf("Cliente eliminado con �xito.\n");
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
        printf("No se pueden agregar m�s empresas, l�mite alcanzado.\n");
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

    printf("Empresa agregada con �xito.\n");
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
    char id_ticker[10];
    int encontrado = 0;

    // Solicitar el Id Ticker de la empresa a eliminar
    printf("Ingrese el Id Ticker de la empresa a eliminar: ");
    scanf("%s", id_ticker);

    // Buscar el la empresa en la lista
    for (int i = 0; i < numEmpresas; i++) {
        if (strcmp(listaEmpresas[i].id_ticker, id_ticker) == 0) {
            encontrado = 1;

            // Eliminar el cliente moviendo los siguientes hacia atr�s
            for (int j = i; j < numEmpresas - 1; j++) {
                listaEmpresas[j] = listaEmpresas[j + 1];
            }

            numEmpresas--; // Disminuir el contador de clientes
            printf("Empresa eliminada con �xito.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Empresa no encontrada.\n");
    }

}

void modificarEmpresa()
{
    char id_ticker[10];
    int encontrado = 0;

    // Solicitar el Id Ticker de la empresa a modificar
    printf("Ingrese el Id Ticker de la empresa a modificar: ");
    scanf("%s", id_ticker);

    // Limpiar el buffer de entrada despu�s de leer el Id Ticker
    getchar();

    // Buscar la empresa en la lista
    for (int i = 0; i < numEmpresas; i++) {
        if (strcmp(listaEmpresas[i].id_ticker, id_ticker) == 0) {
            encontrado = 1;

            // Mostrar los datos actuales de la empresa
            printf("Datos actuales de la empresa:\n");
            printf("Nombre: %s\n", listaEmpresas[i].nombre);
            printf("Id Ticker: %s\n", listaEmpresas[i].id_ticker);
            printf("Precio Actual: %.2f\n", listaEmpresas[i].precio_actual);

            // Modificar el nombre de la empresa
            printf("Ingrese el nuevo nombre de la empresa (o presione Enter para no modificar): ");
            char nuevoNombre[50];
            fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
            if (nuevoNombre[strlen(nuevoNombre) - 1] == '\n') {
                nuevoNombre[strlen(nuevoNombre) - 1] = '\0';
            }
            if (strlen(nuevoNombre) > 0) {
                strcpy(listaEmpresas[i].nombre, nuevoNombre);
            }

            // Modificar el Id Ticker de la empresa
            printf("Ingrese el nuevo Id Ticker de la empresa (o presione Enter para no modificar): ");
            char nuevoIdTicker[10];
            fgets(nuevoIdTicker, sizeof(nuevoIdTicker), stdin);
            if (nuevoIdTicker[strlen(nuevoIdTicker) - 1] == '\n') {
                nuevoIdTicker[strlen(nuevoIdTicker) - 1] = '\0';
            }
            if (strlen(nuevoIdTicker) > 0) {
                strcpy(listaEmpresas[i].id_ticker, nuevoIdTicker);
            }

            // Modificar el precio actual de la empresa con validaci�n
            float nuevoPrecio;
            do {
                printf("Ingrese el nuevo precio actual de la empresa (o presione 0 para no modificar): ");
                scanf("%f", &nuevoPrecio);
                if (nuevoPrecio < 0) {
                    printf("Error: El precio debe ser mayor a cero.\n");
                }
            } while (nuevoPrecio < 0);  // Asegurarse de que el precio sea v�lido

            if (nuevoPrecio > 0) {
                listaEmpresas[i].precio_actual = nuevoPrecio;
            }

            // Confirmar que los datos han sido actualizados
            printf("Empresa modificada con �xito.\n");

            // Salir del bucle ya que hemos encontrado y modificado la empresa
            break;
        }
    }

    // Si no se encontr� la empresa
    if (!encontrado) {
        printf("Empresa con Id Ticker %s no encontrada.\n", id_ticker);
    }
}



///------------------------------------
void menuBroker() {
    int opcion;

    do {
        mostrarMenuBroker();
        printf("\nSelecciona una opci�n: ");
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
            case 7:{
                int clienteIndex = validarCuitCliente(); // Validar CUIT y obtener el �ndice
                if (clienteIndex != -1) {
                    filtrarOperacionesPorCliente(listaClientes[clienteIndex].cuit);  // Llamar a la funci�n con el CUIT
                }
                break;  // Aseg�rate de tener un break aqu�
            }
            case 8:
                //filtrarOperacionesPorIDTicker();
                break;
            case 9:
                mostrarClientes();
                break;
            case 10:
                mostrarEmpresas();
                break;
            case 11:
                printf("Volviendo al men� principal...\n");
                break;
            default:
                printf("Opci�n no v�lida. Int�ntalo nuevamente.\n");
        }
    } while (opcion != 11);
}

// Funci�n que muestra el men� del broker
void mostrarMenuBroker() {
    printf("\n--- Men� de Broker ---\n");
    printf("1. Alta de clientes\n");
    printf("2. Baja de clientes\n");
    printf("3. Modificaci�n de clientes\n");
    printf("4. Alta de empresas\n");
    printf("5. Baja de empresas\n");
    printf("6. Modificaci�n de empresas\n");
    printf("7. Filtrar operaciones por cliente\n");
    printf("8. Filtrar operaciones por ID ticker\n");
    printf("9. Mostrar Clientes\n");
    printf("10. Mostrar Empresas\n");
    printf("11. Volver al men� principal\n");


}


