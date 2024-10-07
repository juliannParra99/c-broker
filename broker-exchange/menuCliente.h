#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED

// Prototipos de funciones espec�ficas para el men� de cliente
void realizarInversion();
void verRendimiento();
void cargarSaldo();
void extraerSaldo();
void verPortafolio();
void mostrarEmpresasDisponibles();
void comprarAcciones();
void venderAcciones();
void rendimientoDiario();
void rendimientoHistorico();
void listarActivos();
void rendimientoPorActivo();
void menuCliente();  // Prototipo de la funci�n del men� de Cliente


// Funci�n que muestra el men� del cliente
void mostrarMenuCliente() {
    printf("\n--- Men� de Cliente ---\n");
    printf("1. Realizar inversi�n\n");
    printf("2. Ver rendimiento\n");
    printf("3. Cargar saldo\n");
    printf("4. Extraer saldo\n");
    printf("5. Ver portafolio\n");
    printf("6. Volver al men� principal\n");
}

// Funci�n del men� del Cliente
void menuCliente() {
    int opcion;

    do {
        mostrarMenuCliente();
        printf("\nSelecciona una opci�n: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                realizarInversion();
                break;
            case 2:
                verRendimiento();
                break;
            case 3:
                cargarSaldo();
                break;
            case 4:
                extraerSaldo();
                break;
            case 5:
                verPortafolio();
                break;
            case 6:
                printf("Volviendo al men� principal...\n");
                break;
            default:
                printf("Opci�n no v�lida. Int�ntalo nuevamente.\n");
        }
    } while (opcion != 6);
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
                mostrarEmpresasDisponibles();
                break;
            case 2:
                comprarAcciones();
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

// Funci�n para ver el rendimiento
void verRendimiento() {
    int subopcion;
    do {
        printf("\n--- Ver Rendimiento ---\n");
        printf("1. Rendimiento Diario\n");
        printf("2. Rendimiento Hist�rico\n");
        printf("3. Volver al men� del cliente\n");
        printf("Selecciona una opci�n: ");
        scanf("%d", &subopcion);

        switch(subopcion) {
            case 1:
                rendimientoDiario();
                break;
            case 2:
                rendimientoHistorico();
                break;
            case 3:
                printf("Volviendo al men� de cliente...\n");
                break;
            default:
                printf("Opci�n no v�lida. Int�ntalo nuevamente.\n");
        }
    } while (subopcion != 3);
}

// Funci�n para cargar saldo en la cuenta
void cargarSaldo() {
    printf("Funcionalidad para cargar saldo (por implementar).\n");
    // L�gica para cargar saldo en la cuenta del cliente
}

// Funci�n para extraer saldo de la cuenta
void extraerSaldo() {
    printf("Funcionalidad para extraer saldo (por implementar).\n");
    // L�gica para extraer saldo de la cuenta del cliente
}

// Funci�n para ver el portafolio
void verPortafolio() {
    int subopcion;
    do {
        printf("\n--- Ver Portafolio ---\n");
        printf("1. Listado de Activos\n");
        printf("2. Rendimiento por Activo\n");
        printf("3. Volver al men� del cliente\n");
        printf("Selecciona una opci�n: ");
        scanf("%d", &subopcion);

        switch(subopcion) {
            case 1:
                listarActivos();
                break;
            case 2:
                rendimientoPorActivo();
                break;
            case 3:
                printf("Volviendo al men� de cliente...\n");
                break;
            default:
                printf("Opci�n no v�lida. Int�ntalo nuevamente.\n");
        }
    } while (subopcion != 3);
}

// Funci�n para mostrar las empresas disponibles para la compra
void mostrarEmpresasDisponibles() {
    printf("Funcionalidad para mostrar empresas disponibles (por implementar).\n");
}

// Funci�n para comprar acciones
void comprarAcciones() {
    printf("Funcionalidad para comprar acciones (por implementar).\n");
}

// Funci�n para vender acciones
void venderAcciones() {
    printf("Funcionalidad para vender acciones (por implementar).\n");
}

// Funci�n para ver el rendimiento diario de la cartera
void rendimientoDiario() {
    printf("Funcionalidad para ver rendimiento diario (por implementar).\n");
}

// Funci�n para ver el rendimiento hist�rico de la cartera
void rendimientoHistorico() {
    printf("Funcionalidad para ver rendimiento hist�rico (por implementar).\n");
}

// Funci�n para listar los activos del cliente
void listarActivos() {
    printf("Funcionalidad para listar activos del cliente (por implementar).\n");
}

// Funci�n para ver el rendimiento individual de cada activo
void rendimientoPorActivo() {
    printf("Funcionalidad para ver rendimiento por activo (por implementar).\n");
}

#endif // MENUCLIENTE_H_INCLUDED
