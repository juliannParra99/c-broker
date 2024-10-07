#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED


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


#endif // STRUCTS_H_INCLUDED
