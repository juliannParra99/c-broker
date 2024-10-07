#ifndef MENUBROKER_H_INCLUDED
#define MENUBROKER_H_INCLUDED
void mostrarMenuBroker();
void menuBroker();

//funcionalidades
void altaCliente();
void bajaCliente(); //borrar
void modificarCliente();

void altaEmpresa();
void bajaEmpresa();
void modificarEmpresa();
void filtrarOperacionesPorCliente();
void filtrarOperacionesPorIDTicker();

void altaCliente()
{
    return;
}

void bajaCliente()
{
    return;
}

void modificarCliente()
{
    return;
}
//Empresas
void altaEmpresa()
{
    return;
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
            case 7:
                filtrarOperacionesPorCliente();
                break;
            case 8:
                filtrarOperacionesPorIDTicker();
                break;
            case 9:
                printf("Volviendo al men� principal...\n");
                break;
            default:
                printf("Opci�n no v�lida. Int�ntalo nuevamente.\n");
        }
    } while (opcion != 9);
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
    printf("9. Volver al men� principal\n");
}

#endif // MENUBROKER_H_INCLUDED
