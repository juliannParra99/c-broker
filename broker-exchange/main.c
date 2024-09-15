#include <stdio.h>
#include <stdlib.h>
#include "menuBroker.h"

void login();
void loginValidation(int role );

typedef struct {
    char id_ticker[10];
    char nombre[50];
    float precio_actual;
} Empresa;

//  Inversión
typedef struct {
    char id_ticker[10];
    int cantidad_acciones;
    float precio_compra;
    char fecha[11];
} Inversion;

// Cliente
typedef struct {
    char nombre[50];
    char email[50];
    char cuit[15];
    char password[20];
    float saldo_cuenta;
    Inversion inversiones[500];
    int num_inversiones;
} Cliente;


int main()
{
    menuBroker();
    //login();
    return 0;
}

void login()
{
    int role;
    printf("Login: \n");
    printf("1.Admin\n");
    printf("2.User\n");
    printf("3. Exit\n");
    scanf("%d", &role);

    while(role <= 0 || role> 3)
    {
        printf("Role must be between 1 to 3\n");
        printf("Login: \n");
        printf("1.Admin\n");
        printf("2.User\n");
        printf("3. Exit\n");
        scanf("%d", &role);
    }

    loginValidation(role);
}

//
void loginValidation(int role )
{
    char userName[20];
    char password[20];

    if (role == 1) {
        printf("Login: Admin\n");
        printf("User Name: ");
        scanf("%19s", userName);

        printf("Password: ");
        scanf("%19s", password);

        // development
        printf("Nombre de Usuario: %s\n", userName);
        printf("Contraseña: %s\n", password);
    } else {
        printf("Login: User\n");
        printf("User Name: ");
        scanf("%19s", userName);
        printf("Password: ");
        scanf("%19s", password);  // Leer entrada del usuario

        // development
        printf("Nombre de Usuario: %s\n", userName);
        printf("Contraseña: %s\n", password);
    }
}

