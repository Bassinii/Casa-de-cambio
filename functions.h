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

void mostrarClientePorDni(){
    ArchivoClientes arch("Clientes.dat");
    Cliente cliente;
    int tam,dni;
    bool noMostro=true;
    tam=arch.contarRegistros();
    cout<<"INGRESAR EL DNI DEL CLIENTE"<<endl;
    cin>>dni;
    for(int i=0;i<tam;i++){
        cliente=arch.leerRegistro(i);
        if(cliente.getDni()==dni&&cliente.getEstado()){
            cliente.mostrar();
            cout<<endl;
            noMostro=false;
        }
    }
    if(noMostro){
            cout<<"NO SE ENCONTRO EL DNI"<<endl;
        }
}

void mostrarTodosLosClientes(){
    ArchivoClientes arch("Clientes.dat");
    Cliente cliente;
    int tam;
    tam=arch.contarRegistros();
    for(int i=0;i<tam;i++){
        cliente=arch.leerRegistro(i);
        if(cliente.getEstado()){
            cliente.mostrar();
            cout<<endl;
        }
    }
}

#endif // FUNCTIONS_H_INCLUDED
