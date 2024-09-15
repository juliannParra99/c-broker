#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED

// Prototipos de funciones específicas para el menú de cliente
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
void menuCliente();  // Prototipo de la función del menú de Cliente


// Función que muestra el menú del cliente
void mostrarMenuCliente() {
    printf("\n--- Menú de Cliente ---\n");
    printf("1. Realizar inversión\n");
    printf("2. Ver rendimiento\n");
    printf("3. Cargar saldo\n");
    printf("4. Extraer saldo\n");
    printf("5. Ver portafolio\n");
    printf("6. Volver al menú principal\n");
}

// Función del menú del Cliente
void menuCliente() {
    int opcion;

    do {
        mostrarMenuCliente();
        printf("\nSelecciona una opción: ");
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
                printf("Volviendo al menú principal...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo nuevamente.\n");
        }
    } while (opcion != 6);
}

// Función para realizar una inversión
void realizarInversion() {
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
                mostrarEmpresasDisponibles();
                break;
            case 2:
                comprarAcciones();
                break;
            case 3:
                venderAcciones();
                break;
            case 4:
                printf("Volviendo al menú de cliente...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo nuevamente.\n");
        }
    } while (subopcion != 4);
}

// Función para ver el rendimiento
void verRendimiento() {
    int subopcion;
    do {
        printf("\n--- Ver Rendimiento ---\n");
        printf("1. Rendimiento Diario\n");
        printf("2. Rendimiento Histórico\n");
        printf("3. Volver al menú del cliente\n");
        printf("Selecciona una opción: ");
        scanf("%d", &subopcion);

        switch(subopcion) {
            case 1:
                rendimientoDiario();
                break;
            case 2:
                rendimientoHistorico();
                break;
            case 3:
                printf("Volviendo al menú de cliente...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo nuevamente.\n");
        }
    } while (subopcion != 3);
}

// Función para cargar saldo en la cuenta
void cargarSaldo() {
    printf("Funcionalidad para cargar saldo (por implementar).\n");
    // Lógica para cargar saldo en la cuenta del cliente
}

// Función para extraer saldo de la cuenta
void extraerSaldo() {
    printf("Funcionalidad para extraer saldo (por implementar).\n");
    // Lógica para extraer saldo de la cuenta del cliente
}

// Función para ver el portafolio
void verPortafolio() {
    int subopcion;
    do {
        printf("\n--- Ver Portafolio ---\n");
        printf("1. Listado de Activos\n");
        printf("2. Rendimiento por Activo\n");
        printf("3. Volver al menú del cliente\n");
        printf("Selecciona una opción: ");
        scanf("%d", &subopcion);

        switch(subopcion) {
            case 1:
                listarActivos();
                break;
            case 2:
                rendimientoPorActivo();
                break;
            case 3:
                printf("Volviendo al menú de cliente...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo nuevamente.\n");
        }
    } while (subopcion != 3);
}

// Función para mostrar las empresas disponibles para la compra
void mostrarEmpresasDisponibles() {
    printf("Funcionalidad para mostrar empresas disponibles (por implementar).\n");
}

// Función para comprar acciones
void comprarAcciones() {
    printf("Funcionalidad para comprar acciones (por implementar).\n");
}

// Función para vender acciones
void venderAcciones() {
    printf("Funcionalidad para vender acciones (por implementar).\n");
}

// Función para ver el rendimiento diario de la cartera
void rendimientoDiario() {
    printf("Funcionalidad para ver rendimiento diario (por implementar).\n");
}

// Función para ver el rendimiento histórico de la cartera
void rendimientoHistorico() {
    printf("Funcionalidad para ver rendimiento histórico (por implementar).\n");
}

// Función para listar los activos del cliente
void listarActivos() {
    printf("Funcionalidad para listar activos del cliente (por implementar).\n");
}

// Función para ver el rendimiento individual de cada activo
void rendimientoPorActivo() {
    printf("Funcionalidad para ver rendimiento por activo (por implementar).\n");
}

#endif // MENUCLIENTE_H_INCLUDED
