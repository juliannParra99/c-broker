#ifndef INTERFACESGRAF_H_INCLUDED
#define INTERFACESGRAF_H_INCLUDED

extern int numClientes;
extern Cliente listaClientes[MAX_CLIENTES];

void login();
void loginValidation(int role );

// Implementaci�n de la funci�n de login
void login()
{
    int role;
    do {
        printf("Login: \n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Exit\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &role);

        // Validar que el rol est� dentro del rango v�lido
        while (role <= 0 || role > 3) {
            printf("Role must be between 1 to 3\n");
            printf("Login: \n");
            printf("1. Admin\n");
            printf("2. User\n");
            printf("3. Exit\n");
            scanf("%d", &role);
        }

        // Validar y ejecutar la opci�n seleccionada
        loginValidation(role);

    } while (role != 3); // Repetir hasta que el usuario elija salir (opci�n 3)

    printf("Programa finalizado.\n");
}


//
// Implementaci�n de la funci�n loginValidation
void loginValidation(int role)
{
    switch(role) {
        case 1:
            printf("Bienvenido Admin\n");
            menuBroker(); // Si es Admin, ejecutar el men� del Broker
            break;
        case 2: {
            int clienteIndex = validarCliente();
            if (clienteIndex >= 0) { // Si el cliente es validado correctamente
                printf("Bienvenido Cliente\n");
                menuCliente(clienteIndex); // Pasar el �ndice del cliente validado
            } else {
                printf("Error: Email o contrase�a incorrectos.\n");
            }
            break;
        }
        case 3:
            printf("Saliendo...\n");
            exit(0); // Finalizar el programa si elige salir
            break;
        default:
            printf("Opci�n inv�lida.\n");
    }
}

// Funci�n para validar las credenciales del cliente
// Funci�n para validar las credenciales del cliente
int validarCliente()
{
    char email[50];
    char password[20];

    // Solicitar el email y contrase�a del cliente
    printf("Ingrese su email: ");
    scanf("%s", email);
    printf("Ingrese su contrase�a: ");
    scanf("%s", password);

    // Buscar al cliente en la lista
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(listaClientes[i].email, email) == 0 && strcmp(listaClientes[i].password, password) == 0) {
            printf("Login exitoso para el cliente: %s\n", listaClientes[i].nombre);
            return i; // Devolver el �ndice del cliente
        }
    }

    return -1; // Login fallido
}

#endif // INTERFACESGRAF_H_INCLUDED
