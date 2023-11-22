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

//Recibe la posicion donde está el registro a bajar, el registro y establece su estado en false
//y lo escribe
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

//Recibe la posicion donde está el registro a bajar, el registro y establece su estado en false
//y lo escribe
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

//Recibe la posicion donde está el registro a bajar, el registro y establece su estado en false
//y lo escribe
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

#endif // CLASSES_H_INCLUDED
