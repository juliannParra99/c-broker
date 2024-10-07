#include <stdio.h>
#include <stdlib.h>
#include "menuBroker.h"
#include "structs.h"
#include "constantes.h"
#include "interfacesGraf.h"


// Arreglo de clientes
Cliente listaClientes[MAX_CLIENTES];
Empresa listaEmpresas[MAX_EMPRESAS];

// Contador de clientes
int numClientes = 0;
int numEmpresas = 0;

int main()
{
    //login();
    //menuBroker();
    for(int i = 0; i<3; i++)
    {
        //altaCliente();
        altaEmpresa();

    }
    mostrarEmpresas();
    //mostrarClientes();
    //bajaCliente();
    //modificarCliente();
    //mostrarClientes();

    return 0;
}


