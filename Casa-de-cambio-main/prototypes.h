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
void buscarDni();

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

#endif // PROTOTYPES_H_INCLUDED
