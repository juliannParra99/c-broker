#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED

// Prototipos de funciones específicas para el menú de cliente
void realizarInversion();
void verRendimiento();
void cargarSaldo();
void extraerSaldo();
void verPortafolio(int clienteIndex);

void comprarVenderAcciones();
void comprarAcciones(int indiceCliente);
void venderAcciones(int indiceCliente);
void listarActivos();
void rendimientoPorActivo();
void menuCliente(int clienteIndex);  // Prototipo de la función del menú de Cliente


//Cargar / Extraer saldo
void cargarSaldo(int indiceCliente);
void extraerSaldo(int indiceCliente);




///vista de rendimiento
void calcularRendimientoDiario(Cliente* cliente, Empresa empresas[], int num_empresas);
float calcularRendimientoHistorico(Cliente* cliente, Empresa empresas[], int num_empresas, char* fecha);

void verRendimiento(int clienteIndex, Empresa empresas[], int num_empresas);
void rendimientoDiario();

void rendimientoHistorico();

#endif // MENUCLIENTE_H_INCLUDED
