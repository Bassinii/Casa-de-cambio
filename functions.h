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
    ArchivoClientes arch("clientes.dat");
    Cliente cliente;
    bool escribio;
    cout<<"----------------------------------"<<endl;
    cout<<"-         AGREGAR CLIENTE        -"<<endl;
    cout<<"----------------------------------"<<endl;
    cliente.cargar();
    escribio=arch.agregarRegistro(cliente);
    return escribio;
}

//Muestra el cliente dependiendo su numero de dni
void mostrarClientePorDni(){
    ArchivoClientes arch("clientes.dat");
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

//muestra todos los clientes
void mostrarTodosLosClientes(){
    ArchivoClientes arch("clientes.dat");
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

//baja logica de un cliente, se setea su estado en false para que las funciones
//mostrarClientePorDni() y mostrarTodosLosClientes no lo listen por pantalla
bool eliminarCliente(){
    ArchivoClientes archCli("clientes.dat");
    Cliente cliente;
    int dni,pos,posReg;
    char opc[5];
    bool bajo=false,encontro=false;
    pos=archCli.contarRegistros();
    cout<<"INGRESAR EL DNI DEL CLIENTE"<<endl;
    cin>>dni;
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
        cout<<"BORRAR CLIENTE? (SI/NO)"<<endl;
        cargarCadena(opc,5);
        if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"sI")==0||strcmp(opc,"Si")==0){
            cliente.setEstado(false);
            bajo=archCli.modificarRegistro(posReg,cliente);
        }else if(strcmp(opc,"NO")==0||strcmp(opc,"no")==0||strcmp(opc,"nO")==0||strcmp(opc,"No")==0){
            cout<<"NO SE HIZO LA BAJA"<<endl;
        }else{
            cout<<"OPCION INCORRECTA"<<endl;
        }
    }
    return bajo;
}

//funcion para saber el dni del un cliente si se desconoce este.
void buscarDni(){
    ArchivoClientes archCli("clientes.dat");
    Cliente cliente;
    int pos,dni;
    char nombreBusco[30],nombre[30],opc[5];
    bool encontro=false;
    while(true){
        pos=archCli.contarRegistros();
        cout<<"INGRESAR NOMBRE DEL CLIENTE"<<endl;
        cargarCadena(nombreBusco,30);
        for(int i=0;i<pos;i++){
            cliente=archCli.leerRegistro(i);
            strcpy(nombre,cliente.getNombre());
            if(strcmp(nombreBusco,nombre)==0){
                dni=cliente.getDni();
                encontro=true;
            }
        }
        if(encontro){
            cout<<"EL DNI DE "<<nombreBusco<<" ES: "<<dni<<endl;
            break;
        }else{
            cout<<"NO SE ENCONTRO EL NOMBRE"<<endl;
            cout<<"QUIERE HACER OTRA BUSQUEDA? (SI/NO)"<<endl;
            cargarCadena(opc,5);
            if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"sI")==0||strcmp(opc,"Si")==0){

            }else if(strcmp(opc,"NO")==0||strcmp(opc,"no")==0||strcmp(opc,"nO")==0||strcmp(opc,"No")==0){
                break;
            }else{
                cout<<"OPCION INCORRECTA"<<endl;
            }
        }
    }
}

///MENU MONEDAS
bool agregarMoneda(){
    ArchivoMonedas archMonedas("monedas.dat");
    Moneda moneda;
    bool escribio;
    cout<<"----------------------------------"<<endl;
    cout<<"-         AGREGAR MONEDA         -"<<endl;
    cout<<"----------------------------------"<<endl;
    moneda.cargar();
    escribio=archMonedas.agregarRegistro(moneda);
    return escribio;
}

void mostrarMonedas(){
    ArchivoMonedas archMonedas("monedas.dat");
    Moneda moneda;
    int pos;
    pos=archMonedas.contarRegistros();
    for(int i=0;i<pos;i++){
        moneda=archMonedas.leerRegistro(i);
        if(moneda.getEstado()){
            moneda.mostrar();
            cout<<endl;
        }
    }
}

void cambiarCotizacion(){
    ArchivoMonedas archMonedas("monedas.dat");
    Moneda moneda;
    char monedaCambiar[20];
    int pos;
    float compra,venta;
    bool encontro=false;
    pos=archMonedas.contarRegistros();
    cout<<"----------------------------------"<<endl;
    cout<<"-         CAMBIAR COTIZACION     -"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"ELIGE UNA DIVISA A CAMBIAR"<<endl;
    cargarCadena(monedaCambiar,20);
    for(int i=0;i<pos;i++){
        moneda=archMonedas.leerRegistro(i);
        if(strcmp(moneda.getDivisa(),monedaCambiar)==0&&moneda.getEstado()){
            cout<<"INGRESE EL NUEVO PRECIO COMPRA"<<endl;
            cin>>compra;
            cout<<"INGRESE EL NUEVO PRECIO VENTA"<<endl;
            cin>>venta;
            moneda.setCompra(compra);
            moneda.setVenta(venta);
            archMonedas.modificarRegistro(i,moneda);
            encontro=true;
            break;
        }
    }
    if(!encontro){
        cout<<"NO SE PUDO ENCONTRAR LA DIVISA"<<endl;
    }
}

bool eliminarMoneda(){
    ArchivoMonedas archMonedas("monedas.dat");
    Moneda moneda;
    int pos,posReg;
    char opc[5],monedaBuscada[20];
    bool bajo=false,encontro=false;
    pos=archMonedas.contarRegistros();
    cout<<"INGRESAR EL NOMBRE DE LA DIVISA"<<endl;
    cargarCadena(monedaBuscada,20);
    for(int i=0;i<pos;i++){
        moneda=archMonedas.leerRegistro(i);
        if(strcmp(moneda.getDivisa(),monedaBuscada)==0){
            encontro=true;
            posReg=i;
            break;
        }
    }
    if(!encontro) cout<<"NO SE ENCONTRO MONEDA CON ESE NOMBRE"<<endl;
    if(encontro){
        moneda.mostrar();
        cout<<"BORRAR MONEDA? (SI/NO)"<<endl;
        cargarCadena(opc,5);
        if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"sI")==0||strcmp(opc,"Si")==0){
            moneda.setEstado(false);
            bajo=archMonedas.modificarRegistro(posReg,moneda);
        }else if(strcmp(opc,"NO")==0||strcmp(opc,"no")==0||strcmp(opc,"nO")==0||strcmp(opc,"No")==0){
            cout<<"NO SE HIZO LA BAJA"<<endl;
        }else{
            cout<<"OPCION INCORRECTA"<<endl;
        }
    }
    return bajo;
}

#endif // FUNCTIONS_H_INCLUDED
