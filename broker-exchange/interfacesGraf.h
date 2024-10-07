#ifndef INTERFACESGRAF_H_INCLUDED
#define INTERFACESGRAF_H_INCLUDED

void login();
void loginValidation(int role );

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

#endif // INTERFACESGRAF_H_INCLUDED
