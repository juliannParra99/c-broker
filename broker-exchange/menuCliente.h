#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED

// Prototipos de funciones espec�ficas para el men� de cliente
void realizarInversion();
void verRendimiento();
void cargarSaldo();
void extraerSaldo();
void verPortafolio(int clienteIndex);

void comprarVenderAcciones();
void comprarAcciones(int indiceCliente);
void venderAcciones(int indiceCliente);
//void verRendimiento();
void rendimientoDiario();
void rendimientoHistorico();
void listarActivos();
void rendimientoPorActivo();
void menuCliente(int clienteIndex);  // Prototipo de la funci�n del men� de Cliente


//Cargar / Extraer saldo
void cargarSaldo(int indiceCliente);
void extraerSaldo(int indiceCliente);


#endif // MENUCLIENTE_H_INCLUDED
