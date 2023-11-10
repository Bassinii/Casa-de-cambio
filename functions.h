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

bool eliminarCliente(){
    ArchivoClientes archCli("Clientes.dat");
    Cliente cliente;
    int dni,pos,posReg;
    char opc[5];
    bool bajo=false,encontro=false;
    cout<<"INGRESAR EL DNI DEL CLIENTE"<<endl;
    cin>>dni;
    pos=archCli.contarRegistros();
    for(int i=0;i<pos;i++){
        cliente=archCli.leerRegistro(i);
        if(cliente.getDni()==dni){
            encontro=true;
            posReg=i;
            break;
        }
    }
    if(!encontro) cout<<"NO SE ENCONTRO CLIENTE CON ESE DNI"<<endl;
    if(encontro){
        cliente.mostrar();
        cout<<"BORRAR REGISTRO? (SI/NO)"<<endl;
        cargarCadena(opc,5);
        if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"sI")==0||strcmp(opc,"Si")==0){
            bajo=archCli.bajaLogica(posReg,cliente);
        }else if(strcmp(opc,"NO")==0||strcmp(opc,"no")==0||strcmp(opc,"nO")==0||strcmp(opc,"No")==0){
            cout<<"NO SE HIZO LA BAJA"<<endl;
        }else{
            cout<<"OPCION INCORRECTA"<<endl;
        }
    }
    return bajo;
}

#endif // FUNCTIONS_H_INCLUDED
