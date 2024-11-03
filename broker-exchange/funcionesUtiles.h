#ifndef FUNCIONESUTILES_H_INCLUDED
#define FUNCIONESUTILES_H_INCLUDED


void inicializar_aleatoriedad();
void actualizar_precio_accion(float *precio_actual);

//filtrar: esto para el admin
void filtrarOperacionesPorCliente(const char* cuit_cliente);
int validarCuitCliente();
void filtrarOperacionesPorIDTicker();



void agregarPrecioHistorico(Empresa *empresa, const char *fecha, float precio);
///calcular valor de cartera
float calcularValorCartera(Inversion* inversiones, int num_inversiones);
float obtenerValorCarteraCliente(int clienteIndex);
float obtenerPrecioActual(const char* id_ticker);

double sumarValoresActuales(int clienteIndex);

float obtenerValorCarteraHistorico(float precio_compra) ;
void rendimientoHistoricoCartera(int clienteIndex);
float calcularCambioPorcentualCartera(int clienteIndex, int periodo);
void filtrarInversionesPorTicker(char* buscarPorTicker);

int compararFechas(const void* a, const void* b);

void calcularGanancia(int clienteIndex);

//aca van ir funciones de ordenamiento y relacionadas  a  funciones de modificar de manera random el precio de
//las empresas al iniciar la app.

//aca van ir funciones de ordenamiento y relacionadas  a  funciones de modificar de manera random el precio de
//las empresas al iniciar la app.

#endif // FUNCIONESUTILES_H_INCLUDED
