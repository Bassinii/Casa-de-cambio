#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

///FUNCION CARGAR CADENA
void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

///MENU CLIENTES
//Agrega un cliente, si se pudo agregar retorna true, sino false
bool agregarCliente(){
    ArchivoClientes arch("Clientes.dat");
    Cliente cliente;
    bool escribio;
    cout<<"----------------------------------"<<endl;
    cout<<"-         AGREGAR CLIENTE        -"<<endl;
    cout<<"----------------------------------"<<endl;
    cliente.cargar();
    escribio=arch.agregarRegistro(cliente);
    return escribio;
}

bool mostrarTodosLosClientes(){
    ArchivoClientes arch("Clientes.dat");
    Cliente cliente;
    int tam=arch.contarRegistros();
    cout<<tam;
    /*bool leyo;
    for(int i=0;i<tam;i++){
        cliente=arch.leerRegistro(i);
        cliente.mostrar();
    }*/
}

#endif // FUNCTIONS_H_INCLUDED
