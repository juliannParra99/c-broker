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


    // Inicializar clientes
    listaClientes[0] = (Cliente) {
        "Juan Perez",
        "juan@gmail.com",
        "20345678901",
        "1234",//password
        15000.50,
        {}, // Inicialización vacía para inversiones
        0   // num_inversiones
    };

    listaClientes[1] = (Cliente) {
        "Maria Gomez",
        "maria.gomez@email.com",
        "27123456789",
        "securePass456",
        30000.00,
        {}, // Inicialización vacía para inversiones
        0   // num_inversiones
    };

    listaClientes[2] = (Cliente) {
        "Carlos Lopez",
        "carlos.lopez@email.com",
        "30111222333",
        "passLopez789",
        5000.75,
        {}, // Inicialización vacía para inversiones
        0   // num_inversiones
    };

    numClientes +=3;
    numEmpresas += 3;




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




