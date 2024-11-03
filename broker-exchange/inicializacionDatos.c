#include <stdio.h>
#include <stdlib.h>
#include "menuBroker.h"
#include "structs.h"
#include "constantes.h"
#include "interfacesGraf.h"
#include <string.h>
#include "inicializacionDatos.h"
#include "funcionesUtiles.h"

extern int numClientes;
extern int numEmpresas;

extern Cliente listaClientes[MAX_CLIENTES];
extern Empresa listaEmpresas[MAX_EMPRESAS];

void initDatos()
{
    // Inicializar empresas
    listaEmpresas[0] = (Empresa){"AAPL", "Apple Inc.", 100.00};
    listaEmpresas[1] = (Empresa){"MSFT", "Microsoft Corp.", 200.00};
    listaEmpresas[2] = (Empresa){"GOOGL", "Alphabet Inc.", 300.00};
    numEmpresas = 3;


     // Inicializar clientes
    listaClientes[0] = (Cliente){
        "Juan Perez",
        "juan@gmail.com",
        "20345678901",
        "1234", // password
        15000.50,
        {}, // Inicialización vacía para inversiones
        0   // num_inversiones
    };
    listaClientes[1] = (Cliente){
        "Maria Gomez",
        "maria.gomez@email.com",
        "5555",
        "5555",
        30000.00,
        {}, // Inicialización vacía para inversiones
        0   // num_inversiones
    };
    listaClientes[2] = (Cliente){
        "Carlos Lopez",
        "carlos.lopez@email.com",
        "30111222333",
        "passLopez789",
        5000.75,
        {}, // Inicialización vacía para inversiones
        0   // num_inversiones
    };
    numClientes += 3; // Incrementar el contador de clientes

    // Cliente adicional con inversiones en diferentes fechas
    Cliente cliente;
    strcpy(cliente.nombre, "Pablo Juan Perez");
    strcpy(cliente.email, "pablo@gmail.com");
    strcpy(cliente.cuit, "1111");
    strcpy(cliente.password, "1234");
    cliente.saldo_cuenta = 10000.0;

    // Inversiones del cliente
    cliente.inversiones[0] = (Inversion){"AAPL", 5, 155.0, "2024-01-02"};
    cliente.inversiones[1] = (Inversion){"MSFT", 4, 200.0, "2024-02-10"};
    cliente.inversiones[2] = (Inversion){"GOOGL", 3, 300.0, "2024-03-15"};

    // Manteniendo el resto de las inversiones originales
    cliente.inversiones[3] = (Inversion){"AAPL", 7, 160.0, "2023-02-15"};
    cliente.inversiones[4] = (Inversion){"AAPL", 6, 162.0, "2023-03-01"};
    cliente.inversiones[5] = (Inversion){"AAPL", 10, 165.0, "2023-03-20"};
    cliente.inversiones[6] = (Inversion){"MSFT", 2, 220.0, "2023-02-20"};
    cliente.inversiones[7] = (Inversion){"GOOGL", 4, 95.0, "2023-03-10"};
    cliente.inversiones[8] = (Inversion){"MSFT", 5, 230.0, "2023-03-10"};
    cliente.inversiones[9] = (Inversion){"GOOGL", 8, 105.0, "2023-03-15"};
    cliente.num_inversiones = 10;

    // Agregar el cliente a la lista de clientes y actualizar el contador
    listaClientes[numClientes] = cliente;
    numClientes++;

    Cliente clienteEjemplo;
    strcpy(clienteEjemplo.nombre, "Lucia Fernandez");
    strcpy(clienteEjemplo.email, "lucia.fernandez@gmail.com");
    strcpy(clienteEjemplo.cuit, "2222");
    strcpy(clienteEjemplo.password, "abcd1234");
    clienteEjemplo.saldo_cuenta = 15000.0;

    // Inversiones del cliente
    clienteEjemplo.inversiones[0] = (Inversion){"GOOGL", 8, 2800.0, "2024-04-10"};
    clienteEjemplo.num_inversiones = 1;
    listaClientes[numClientes] = clienteEjemplo;
    numClientes++;

    inicializar_aleatoriedad();

    // Actualizar precios de las empresas de manera aleatoria
    for (int i = 0; i < numEmpresas; i++) {
        actualizar_precio_accion(&listaEmpresas[i].precio_actual);
        //printf("Nuevo precio de %s: %.2f\n", listaEmpresas[i].nombre, listaEmpresas[i].precio_actual);
    }
}

