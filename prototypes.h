#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

///FUNCIONES
void cargarCadena(char*,int);

///MENUES
int menuPrincipal();
int menuClientes();
int menuEmpleados();
int menuTransacciones();
int menuMonedas();
int menuConfiguraciones();
int menuCopiaSeguridad();
int menuRestaurar();

///MENU CLIENTES
bool agregarCliente();
void mostrarClientePorDni();
void mostrarTodosLosClientes();
bool eliminarCliente();
void buscarDniCliente();

///MENU EMPLEADOS
bool agregarEmpleado();
void mostrarEmpleadoPorDni();
void mostrarTodosLosEmpleados();
bool eliminarEmpleado();
void buscarDniEmpleado();
void clienteMasTransacciones();

///MENU TRANSACCIONES
bool crearTransaccion();
void mostrarTransaccionPorID();
void mostrarTodasLasTransacciones();
bool eliminarTransaccion();
void buscarTransaccion();

///MENU MONEDAS
bool agregarMoneda();
void mostrarMonedas();
void cambiarCotizacion();
bool eliminarMoneda();

///MENU CONFIG
bool bajaFisicaArchClientes();
bool bajaFisicaArchEmpleados();
bool bajaFisicaArchTransacciones();
bool bajaFisicaArchMonedas();

bool RestaurarArchClientes();
bool RestaurarArchEmpleados();
bool RestaurarArchTransacciones();
bool RestaurarArchMonedas();

#endif // PROTOTYPES_H_INCLUDED
