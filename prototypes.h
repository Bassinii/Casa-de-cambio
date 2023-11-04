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

///MENU CLIENTES
bool agregarCliente();
void mostrarClientePorDni();
void mostrarTodosLosClientes();

#endif // PROTOTYPES_H_INCLUDED
