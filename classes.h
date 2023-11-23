#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

class Persona{
protected:
    int dni,telefono;
    char nombre[30],apellido[30];
    bool estado;
public:
    ///GETTERS
    const int getDni(){return dni;}
    const int getTelefono(){return telefono;}
    const bool getEstado(){return estado;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    ///SETTERS
    void setTelefono(int telefono){this->telefono=telefono;}
    void setEstado(bool estado){this->estado=estado;}
    void setDni(int dni){this->dni=dni;}
};

class Cliente : public Persona{
private:
    int cantidadTransacciones;
    char monedaPreferida[30];
    Fecha inscripcion;
public:
    ///CONSTRUCTOR CON PARAMETROS POR OMISIÓN
    Cliente(const char *nombre="N/A", const char *apellido="N/A", const char *monedaPreferida="NINGUNA", int cantidadTransacciones=0, bool estado=true){
        strcpy(this->nombre,nombre);
        strcpy(this->apellido,apellido);
        strcpy(this->monedaPreferida,monedaPreferida);
        this->cantidadTransacciones=cantidadTransacciones;
        this->estado=estado;
    }

    ///METODOS
    void cargar();
    void mostrar();

};

void Cliente::cargar(){
    int dia,mes,anio;
    char opc[4];
    bool pedir=true;
    estado=true;
    cout<<"INGRESAR EL NOMBRE DEL CLIENTE"<<endl;
    cargarCadena(nombre,30);
    cout<<"INGRESAR EL APELLIDO DEL CLIENTE"<<endl;
    cargarCadena(apellido,30);
    cout<<"INGRESAR EL DNI DEL CLIENTE"<<endl;
    cin>>dni;
    cout<<"INGRESAR NUMERO DE TELEFONO"<<endl;
    cin>>telefono;
    while(pedir){
        cout<<"LA FECHA DE INSCRIPCION ES LA ACTUAL?(Si/No)"<<endl;
        cargarCadena(opc,4);
        if(strcmp(opc,"NO")==0||strcmp(opc,"no")==0||strcmp(opc,"No")==0||strcmp(opc,"nO")==0){
            cout<<"INGRESAR EL DIA"<<endl;
            cin>>dia;
            cout<<"INGRESAR EL MES"<<endl;
            cin>>mes;
            cout<<"INGRESAR EL ANIO"<<endl;
            cin>>anio;
            inscripcion.setDia(dia);
            inscripcion.setMes(mes);
            inscripcion.setAnio(anio);
            pedir=false;
        }else if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"Si")==0||strcmp(opc,"sI")==0){
            cout<<"FECHA ASIGNADA: "<<endl;
            inscripcion.MostrarFecha();
            pedir=false;
        }else{
            cout<<"OPCION INVALIDA"<<endl;
        }
    }
}

void Cliente::mostrar(){
    cout<<"-DATOS DEL CLIENTE-"<<endl;
    cout<<" NOMBRE: "<<nombre<<endl;
    cout<<" APELLIDO: "<<apellido<<endl;
    cout<<" DNI: "<<dni<<endl;
    cout<<" TELEFONO: "<<telefono<<endl;
    cout<<" CANTIDAD DE OPERACIONES: "<<cantidadTransacciones<<endl;
    cout<<" MONEDA PREFERIDA: "<<monedaPreferida<<endl;
    cout<<" FECHA DE INSCRIPCION: ";
    inscripcion.MostrarFecha();
    cout<<" ESTADO: "<<estado<<endl<<endl;
}

class Empleado : public Persona{
private:
    char cargo[30];
    int cantidadTransacciones;
public:
    Empleado(const char *nombre="N/A", const char *apellido="N/A", int cantidadTransacciones=0, bool estado=true){
        strcpy(this->nombre,nombre);
        strcpy(this->apellido,apellido);
        this->cantidadTransacciones=cantidadTransacciones;
        this->estado=estado;
    }
    ///GETTERS
    const char* getCargo(){return cargo;}
    const int getCantidadTransacciones(){return cantidadTransacciones;}
    ///SETTERS
    void setCargo(const char* cargo){strcpy(this->cargo,cargo);}
    void setCantidadTransacciones(int cantidadTransacciones){this->cantidadTransacciones=cantidadTransacciones;}

    void sumarVenta(){cantidadTransacciones++;} //suma una venta
    void cargar();
    void mostrar();
};

void Empleado::cargar(){
    cout<<"INGRESAR EL NOMBRE DEL EMPLEADO"<<endl;
    cargarCadena(nombre,30);
    cout<<"INGRESAR EL APELLIDO DEL EMPLEADO"<<endl;
    cargarCadena(apellido,30);
    cout<<"INGRESAR EL DNI DEL EMPLEADO "<<endl;
    cin>>dni;
}

void Empleado::mostrar(){
    cout<<"-DATOS DEL EMPLEADO-"<<endl;
    cout<<" NOMBRE: "<<nombre<<endl;
    cout<<" APELLIDO: "<<apellido<<endl;
    cout<<" DNI: "<<dni<<endl;
    cout<<" CANTIDAD DE OPERACIONES: "<<cantidadTransacciones<<endl;
    cout<<" ESTADO: "<<estado<<endl<<endl;
}

class Moneda{
private:
    char divisa[20];
    float compra,venta;
    bool estado;
public:
    Moneda(const char* divisa="N/A",float compra=0,float venta=0){
        strcpy(this->divisa,divisa);
        this->compra=compra;
        this->venta=venta;
    }
    ///GETTERS
    const char* getDivisa(){return divisa;}
    const float getCompra(){return compra;}
    const float getVenta(){return venta;}
    const bool getEstado(){return estado;}
    ///SETTERS
    void setDivisa(const char* divisa){strcpy(this->divisa,divisa);}
    void setCompra(const int compra){this->compra=compra;}
    void setVenta(const int venta){this->venta=venta;}
    void setEstado(const bool estado){this->estado=estado;}
    ///METODOS
    void cargar();
    void mostrar();
};

void Moneda::cargar(){
    estado=true;
    cout<<"INGRESAR NOMBRE DE LA DIVISA"<<endl;
    cargarCadena(divisa,20);
    cout<<"INGRESAR PRECIO COMPRA"<<endl;
    cin>>compra;
    cout<<"INGRESAR PRECIO VENTA"<<endl;
    cin>>venta;
}

void Moneda::mostrar(){
    cout<<"NOMBRE DE LA DIVISA: "<<divisa<<endl;
    cout<<"PRECIO COMPRA: "<<compra<<endl;
    cout<<"PRECIO VENTA: "<<venta<<endl<<endl;
}

class Transaccion{
private:
    int ID,dniCliente,dniEmpleado;
    float importe;
    char nombreCliente[30],nombreEmpleado[30];
    Fecha fecha;
public:
    ///GETTERS
    const int getID(){return ID;}
    const int getDniCliente(){return dniCliente;}
    const int getDniEmpleado(){return dniEmpleado;}
    const float getImporte(){return importe;}
    const char* getNombreCliente(){return nombreCliente;}
    const char* getNombreEmpleado(){return nombreEmpleado;}
    const Fecha& getFecha(){return fecha;}
    ///SETTERS
    void setID(int ID){this->ID=ID;}
    void setDniCliente(int dniCliente){this->dniCliente=dniCliente;}
    void setDniEmpleado(int dniEmpleado){this->dniEmpleado=dniEmpleado;}
    void setImporte(float importe){this->importe=importe;}
    void setNombreCliente(char* nombreCliente){strcpy(this->nombreCliente,nombreCliente);}
    void setNombreEmpleado(char* nombreEmpleado){strcpy(this->nombreEmpleado,nombreEmpleado);}
    void setFecha(int dia,int mes,int anio){
        fecha.setDia(dia);
        fecha.setMes(mes);
        fecha.setAnio(anio);
    }
    ///METODOS
    void cargar();
    void mostrar();
    void mostrarFecha(){fecha.MostrarFecha();}
};

class ArchivoClientes{
private:
    char nombre[30];
public:
    ArchivoClientes(const char *nombre){
        strcpy(this->nombre,nombre);
        }
    bool agregarRegistro(Cliente);
    Cliente leerRegistro(int);
    int contarRegistros();
    bool modificarRegistro(int,Cliente&);
};

bool ArchivoClientes::agregarRegistro(Cliente cliente){
    bool escribio;
    FILE *f;
    f=fopen(nombre,"ab");
    if(f==NULL){
        cout<<"ERROR AL ABRIR EL REGISTRO :("<<endl;
        return false;
    }
    escribio=fwrite(&cliente,sizeof (Cliente),1,f);
    fclose(f);
    return escribio;
}

Cliente ArchivoClientes::leerRegistro(int pos){
    FILE *f;
    Cliente cliente;
    f=fopen(nombre,"rb");
    if(f==NULL) cout<<"ERROR AL ABRIR EL REGISTRO"<<endl;
    fseek(f,sizeof cliente*pos,SEEK_SET);
    fread(&cliente,sizeof cliente,1,f);
    fclose(f);
    return cliente;
}

int ArchivoClientes::contarRegistros(){
    int kb;
    FILE *f;
    f=fopen(nombre,"rb");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,0,SEEK_END);
    kb=ftell(f);
    fclose(f);
    return kb/sizeof(Cliente);
}

bool ArchivoClientes::modificarRegistro(int pos, Cliente& cliente){
    FILE *f;
    bool modifico;
    f=fopen(nombre,"rb+");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,sizeof(Cliente)*pos,SEEK_SET);
    modifico=fwrite(&cliente,sizeof(Cliente),1,f);
    fclose(f);
    return modifico;
}

class ArchivoEmpleados{
private:
    char nombre[30];
public:
    ArchivoEmpleados(const char *nombre){
        strcpy(this->nombre,nombre);
        }
    bool agregarRegistro(Empleado);
    Empleado leerRegistro(int);
    int contarRegistros();
    bool modificarRegistro(int,Empleado&);
};

bool ArchivoEmpleados::agregarRegistro(Empleado empleado){
    bool escribio;
    FILE *f;
    f=fopen(nombre,"ab");
    if(f==NULL){
        cout<<"ERROR AL ABRIR EL REGISTRO :("<<endl;
        return false;
    }
    escribio=fwrite(&empleado,sizeof (Empleado),1,f);
    fclose(f);
    return escribio;
}

Empleado ArchivoEmpleados::leerRegistro(int pos){
    FILE *f;
    Empleado empleado;
    f=fopen(nombre,"rb");
    if(f==NULL) cout<<"ERROR AL ABRIR EL REGISTRO"<<endl;
    fseek(f,sizeof empleado*pos,SEEK_SET);
    fread(&empleado,sizeof empleado,1,f);
    fclose(f);
    return empleado;
}

int ArchivoEmpleados::contarRegistros(){
    int kb;
    FILE *f;
    f=fopen(nombre,"rb");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,0,SEEK_END);
    kb=ftell(f);
    fclose(f);
    return kb/sizeof(Empleado);
}

bool ArchivoEmpleados::modificarRegistro(int pos, Empleado& empleado){
    FILE *f;
    bool modifico;
    f=fopen(nombre,"rb+");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,sizeof(Empleado)*pos,SEEK_SET);
    modifico=fwrite(&empleado,sizeof(Empleado),1,f);
    fclose(f);
    return modifico;
}

class ArchivoMonedas{
private:
    char nombre[30];
public:
    ArchivoMonedas(const char *nombre){
        strcpy(this->nombre,nombre);
        }
    bool agregarRegistro(Moneda);
    Moneda leerRegistro(int);
    int contarRegistros();
    bool modificarRegistro(int,Moneda&);
};

bool ArchivoMonedas::agregarRegistro(Moneda moneda){
    bool escribio;
    FILE *f;
    f=fopen(nombre,"ab");
    if(f==NULL){
        cout<<"ERROR AL ABRIR EL REGISTRO :("<<endl;
        return false;
    }
    escribio=fwrite(&moneda,sizeof (Moneda),1,f);
    fclose(f);
    return escribio;
}

Moneda ArchivoMonedas::leerRegistro(int pos){
    FILE *f;
    Moneda moneda;
    f=fopen(nombre,"rb");
    if(f==NULL) cout<<"ERROR AL ABRIR EL REGISTRO"<<endl;
    fseek(f,sizeof moneda*pos,SEEK_SET);
    fread(&moneda,sizeof moneda,1,f);
    fclose(f);
    return moneda;
}

int ArchivoMonedas::contarRegistros(){
    int kb;
    FILE *f;
    f=fopen(nombre,"rb");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,0,SEEK_END);
    kb=ftell(f);
    fclose(f);
    return kb/sizeof(Moneda);
}

bool ArchivoMonedas::modificarRegistro(int pos, Moneda& moneda){
    FILE *f;
    bool modifico;
    f=fopen(nombre,"rb+");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,sizeof(Moneda)*pos,SEEK_SET);
    modifico=fwrite(&moneda,sizeof(Moneda),1,f);
    fclose(f);
    return modifico;
}

class ArchivoTransacciones{
private:
    char nombre[30];
public:
    ArchivoTransacciones(const char *nombre){
        strcpy(this->nombre,nombre);
        }
    bool agregarRegistro(Transaccion);
    Transaccion leerRegistro(int);
    int contarRegistros();
    bool modificarRegistro(int,Transaccion&);
};

bool ArchivoTransacciones::agregarRegistro(Transaccion transaccion){
    bool escribio;
    FILE *f;
    f=fopen(nombre,"ab");
    if(f==NULL){
        cout<<"ERROR AL ABRIR EL REGISTRO :("<<endl;
        return false;
    }
    escribio=fwrite(&transaccion,sizeof (Transaccion),1,f);
    fclose(f);
    return escribio;
}

Transaccion ArchivoTransacciones::leerRegistro(int pos){
    FILE *f;
    Transaccion transaccion;
    f=fopen(nombre,"rb");
    if(f==NULL) cout<<"ERROR AL ABRIR EL REGISTRO"<<endl;
    fseek(f,sizeof transaccion*pos,SEEK_SET);
    fread(&transaccion,sizeof transaccion,1,f);
    fclose(f);
    return transaccion;
}

int ArchivoTransacciones::contarRegistros(){
    int kb;
    FILE *f;
    f=fopen(nombre,"rb");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,0,SEEK_END);
    kb=ftell(f);
    fclose(f);
    return kb/sizeof(Transaccion);
}

bool ArchivoTransacciones::modificarRegistro(int pos, Transaccion& transaccion){
    FILE *f;
    bool modifico;
    f=fopen(nombre,"rb+");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,sizeof(Transaccion)*pos,SEEK_SET);
    modifico=fwrite(&transaccion,sizeof(Transaccion),1,f);
    fclose(f);
    return modifico;
}

void Transaccion::cargar(){
    ArchivoTransacciones archTransacciones("transacciones.dat");
    ArchivoMonedas archMonedas("monedas.dat");
    ArchivoClientes archClientes("clientes.dat");
    ArchivoEmpleados archEmpleados("empleados.dat");
    Moneda moneda;
    Transaccion transaccion;
    Cliente cliente;
    Empleado empleado;
    int posMonedas,posClientes,posEmpleados,dniCliente,dniEmpleado,dia,mes,anio;
    float monto;
    char tipo[8],divisa[20],opc[4];
    bool ingreso=true, encontroMoneda=false, encontroCliente=false,encontroEmpleado=false,pedir=true;
    posMonedas=archMonedas.contarRegistros();
    posClientes=archClientes.contarRegistros();
    posEmpleados=archEmpleados.contarRegistros();
    this->ID=archTransacciones.contarRegistros();
    while(ingreso){
        cout<<"INGRESE EL TIPO DE TRANSACCION (compra/venta)"<<endl;
        cargarCadena(tipo,8);
        if(strcmp(tipo,"compra")==0){
            cout<<"INGRESE LA DIVISA QUE SE COMPRO"<<endl;
            cargarCadena(divisa,20);
            for(int i=0;i<posMonedas;i++){
                moneda=archMonedas.leerRegistro(i);
                if(strcmp(divisa,moneda.getDivisa())==0){
                    cout<<"INGRESE EL MONTO"<<endl;
                    cin>>monto;
                    transaccion.setImporte(monto*moneda.getVenta());
                    encontroMoneda=true;
                    while(!encontroCliente){
                        cout<<"INGRESE EL DNI DE EL CLIENTE"<<endl;
                        cin>>dniCliente;
                        for(int j=0;j<posClientes;j++){
                            cliente=archClientes.leerRegistro(j);
                            if(cliente.getDni()==dniCliente){
                                encontroCliente=true;
                                cout<<"INGRESE EL DNI DE EL EMPLEADO"<<endl;
                                cin>>dniEmpleado;
                                for(int k=0;k<posEmpleados;k++){
                                    empleado=archEmpleados.leerRegistro(k);
                                    if(empleado.getDni()==dniEmpleado){
                                        encontroEmpleado=true;
                                        while(pedir){
                                            cout<<"LA FECHA DE INSCRIPCION ES LA ACTUAL?(si/no)"<<endl;
                                            cargarCadena(opc,4);
                                            if(strcmp(opc,"NO")==0||strcmp(opc,"no")==0||strcmp(opc,"No")==0||strcmp(opc,"nO")==0){
                                                cout<<"INGRESAR EL DIA"<<endl;
                                                cin>>dia;
                                                cout<<"INGRESAR EL MES"<<endl;
                                                cin>>mes;
                                                cout<<"INGRESAR EL ANIO"<<endl;
                                                cin>>anio;
                                                transaccion.setFecha(dia,mes,anio);
                                                pedir=false;
                                            }else if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"Si")==0||strcmp(opc,"sI")==0){
                                                cout<<"FECHA ASIGNADA: "<<endl;
                                                transaccion.mostrarFecha();
                                                pedir=false;
                                            }else{
                                                cout<<"OPCION INVALIDA"<<endl;
                                            }
                                        }
                                    }
                                }
                                if(!encontroEmpleado){
                                    cout<<"NO SE ENCONTRO EL EMPLEADO"<<endl;
                                }
                                break;
                            }
                            if(!encontroCliente){
                                cout<<"NO SE ENCONTRO EL CLIENTE"<<endl;
                            }
                        }
                    }
                    break;

                }
            }
            if(!encontroMoneda){
                cout<<"NO SE ENCONTRO LA MONEDA"<<endl;
            }
        }
    }
}

#endif // CLASSES_H_INCLUDED
