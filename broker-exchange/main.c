#include <stdio.h>
#include <stdlib.h>
#include "menuBroker.h"
#include "structs.h"
#include "constantes.h"
#include "interfacesGraf.h"
#include <string.h>


//// Ejemplos demostracion
void empresaAgregarModificarBorrar();
void ejemploComprarCargarExtraerSaldo();

////


// Arreglo de clientes
Cliente listaClientes[MAX_CLIENTES];
Empresa listaEmpresas[MAX_EMPRESAS];

// Contador de clientes
int numClientes = 0;
int numEmpresas = 0;

int main()
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
        "27123456789",
        "securePass456",
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
    strcpy(cliente.nombre, "Juan Perez");
    strcpy(cliente.email, "pablo@gmail.com");
    strcpy(cliente.cuit, "20123456789");
    strcpy(cliente.password, "1234");
    cliente.saldo_cuenta = 10000.0;

    // Inversiones del cliente
    cliente.inversiones[0] = (Inversion){"AAPL", 5, 155.0, "2023-01-02"};
    cliente.inversiones[1] = (Inversion){"TSLA", 3, 215.0, "2023-01-05"};
    cliente.inversiones[2] = (Inversion){"AMZN", 10, 95.0, "2023-01-10"};
    cliente.inversiones[3] = (Inversion){"AAPL", 7, 160.0, "2023-02-15"};
    cliente.inversiones[4] = (Inversion){"TSLA", 2, 220.0, "2023-02-20"};
    cliente.inversiones[5] = (Inversion){"AMZN", 4, 102.0, "2023-02-25"};
    cliente.inversiones[6] = (Inversion){"AAPL", 6, 162.0, "2023-03-01"};
    cliente.inversiones[7] = (Inversion){"TSLA", 5, 230.0, "2023-03-10"};
    cliente.inversiones[8] = (Inversion){"AMZN", 8, 105.0, "2023-03-15"};
    cliente.inversiones[9] = (Inversion){"AAPL", 10, 165.0, "2023-03-20"};
    cliente.num_inversiones = 10;

    // Agregar el cliente a la lista de clientes y actualizar el contador
    listaClientes[numClientes] = cliente;
    numClientes++;


    inicializar_aleatoriedad();

    // Actualizar precios de las empresas de manera aleatoria
    for (int i = 0; i < numEmpresas; i++) {
        actualizar_precio_accion(&listaEmpresas[i].precio_actual);
        //printf("Nuevo precio de %s: %.2f\n", listaEmpresas[i].nombre, listaEmpresas[i].precio_actual);
    }




    login();
    //menuBroker();

    //empresaAgregarModificarBorrar();
    //mostrarClientes();
    //mostrarEmpresas();
    //bajaCliente();
    //modificarCliente();
    //mostrarClientes();

    return 0;
}

/////////////////
///////////////
//Ejemplos
void empresaAgregarModificarBorrar()
{
    for(int i = 0; i<3; i++)
    {
        //altaCliente();
        altaEmpresa();

    }
    mostrarEmpresas();
    modificarEmpresa();
    mostrarEmpresas();
    bajaEmpresa();
    mostrarEmpresas();
}

//Ejemplo :
void ejemploComprarCargarExtraerSaldo()
{
     // Muestra de datos
    mostrarClientes();
    mostrarEmpresas();
    comprarVenderAcciones();
    mostrarClientes();
    cargarSaldo(0);
    mostrarClientes();
    extraerSaldo(0);
}




