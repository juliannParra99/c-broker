#ifndef INTERFACESGRAF_H_INCLUDED
#define INTERFACESGRAF_H_INCLUDED

extern int numClientes;
extern Cliente listaClientes[MAX_CLIENTES];

void login();
void loginValidation(int role );
int validarBroker();

void login()
{
    int role;
    do {
        printf("Ingrese como: \n");
        printf("1. Broker\n");
        printf("2. Cliente\n");
        printf("3. Exit\n");
        printf("Seleccione una opcion: ");
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


// Implementaci�n de la funci�n loginValidation
void loginValidation(int role)
{
    switch(role) {
        case 1: {
            int brokerInfo = validarBroker();
            if ( brokerInfo == 1) {
                printf("Bienvenido Broker\n");
                menuBroker();
            } else {
                printf("Error: Email o contrase�a incorrectos.\n");
            }
            break;
        }
        case 2: {
            int clienteIndex = validarCliente();
            if (clienteIndex >= 0) {
                printf("Bienvenido Cliente\n");
                menuCliente(clienteIndex);
            } else {
                printf("Error: Email o contrase�a incorrectos.\n");
            }
            break;
        }
        case 3:
            printf("Saliendo...\n");
            exit(0);
            break;
        default:
            printf("Opci�n inv�lida.\n");
    }
}


// validar las credenciales del cliente
int validarCliente()
{
    char email[50];
    char password[20];

    // Solicita datos para la validacion
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

int validarBroker() {
    char email[50];
    char password[20];

    // Credenciales del broker
    const char brokerEmail[] = "admin@gmail.com";
    const char brokerPassword[] = "admin";

    // Solicitar datos para la validaci�n
    printf("Ingrese su email: ");
    scanf("%s", email);
    printf("Ingrese su contrase�a: ");
    scanf("%s", password);

    // Validar credenciales del broker
    if (strcmp(email, brokerEmail) == 0 && strcmp(password, brokerPassword) == 0) {
        printf("Login exitoso para el broker\n");
        return 1; // Login exitoso
    } else {
        printf("Email o contrase�a incorrectos. Acceso denegado.\n");
        return 0; // Login fallido
    }
}


#endif // INTERFACESGRAF_H_INCLUDED
