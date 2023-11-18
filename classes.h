#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

class Persona{
protected:
    int dni,telefono;
    char nombre[30],apellido[30];
    bool estado;
public:
    ///getters
    int getDni(){return dni;}
    int getTelefono(){return telefono;}
    bool getEstado(){return estado;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    ///setters
    void setTelefono(int telefono){this->telefono=telefono;}
    void setEstado(bool estado){this->estado=estado;}
    void setDni(int dni){this->dni=dni;}
};

class Cliente : public Persona{
private:
    int cantTransacciones;
    char monedaPreferida[30];
    Fecha inscripcion;
public:
    ///CONSTRUCTOR CON PARAMETROS POR OMISIÓN
    Cliente(const char *nombre="N/A", const char *apellido="N/A", const char *monedaPreferida="NINGUNA", int cantTransacciones=0, bool estado=true){
        strcpy(this->nombre,nombre);
        strcpy(this->apellido,apellido);
        strcpy(this->monedaPreferida,monedaPreferida);
        this->cantTransacciones=cantTransacciones;
        this->estado=estado;
    }

    ///METODOS
    void cargar();
    void mostrar();

};

void Cliente::cargar(){
    int dia,mes,anio;
    char opc[4];
    cout<<"INGRESAR EL NOMBRE DEL CLIENTE"<<endl;
    cargarCadena(nombre,30);
    cout<<"INGRESAR EL APELLIDO DEL CLIENTE"<<endl;
    cargarCadena(apellido,30);
    cout<<"INGRESAR EL DNI DEL CLIENTE"<<endl;
    cin>>dni;
    cout<<"INGRESAR NUMERO DE TELEFONO"<<endl;
    cin>>telefono;
    while(true){
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
            break;
        }else if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"Si")==0||strcmp(opc,"sI")==0){
            cout<<"FECHA ASIGNADA: "<<endl;
            inscripcion.MostrarFecha();
            break;
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
    cout<<" CANTIDAD DE OPERACIONES: "<<cantTransacciones<<endl;
    cout<<" MONEDA PREFERIDA: "<<monedaPreferida<<endl;
    cout<<" FECHA DE INSCRIPCION: ";
    inscripcion.MostrarFecha();
    cout<<" ESTADO: "<<estado<<endl;
}

class Empleado : public Persona{
private:
    char cargo[30];
    int cantidadVentas;
public:
    ///GETTERS
    const char* getCargo(){return cargo;}
    int getCantidadVentas(){return cantidadVentas;}
    ///SETTERS
    void setCargo(const char* cargo){strcpy(this->cargo,cargo);}
    void setCantidadVentas(int cantidadVentas){this->cantidadVentas=cantidadVentas;}

    void sumarVenta(){cantidadVentas++;} //suma una venta
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
    bool bajaLogica(int,Cliente&);
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
bool ArchivoClientes::bajaLogica(int pos, Cliente& cliente){
    FILE *f;
    bool bajo;
    cliente.setEstado(false);
    f=fopen(nombre,"rb+");
    if(f==NULL) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    fseek(f,sizeof(Cliente)*pos,SEEK_SET);
    bajo=fwrite(&cliente,sizeof(Cliente),1,f);
    fclose(f);
    return bajo;
}


#endif // CLASSES_H_INCLUDED
