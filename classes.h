#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

class Persona{
protected:
    int dni,edad,telefono;
    char nombre[30],apellido[30];
    bool estado;
public:
    ///getters
    int getDni(){return dni;}
    bool getEstado(){return estado;}
    int getTelefono(){return telefono;}
    ///setters
    void setTelefono(int telefono){this->telefono=telefono;}
};

class Cliente : protected Persona{
private:
    int cantTransacciones;
    char monedaPreferida[30];
    Fecha inscripcion;
public:
    Cliente(const char *nombre="N/A", const char *apellido="N/A",int dni=0, const char *monedaPreferida="NINGUNA"){
        strcpy(this->nombre,nombre);
        strcpy(this->apellido,apellido);
        this->dni=dni;
        strcpy(this->monedaPreferida,monedaPreferida);
    }
    void mostrar(){
        cout<<"-DATOS DEL CLIENTE-"<<endl;
        cout<<" NOMBRE: "<<nombre<<endl;
        cout<<" APELLIDO: "<<apellido<<endl;
        cout<<" DNI: "<<dni<<endl;
        cout<<" CANTIDAD DE OPERACIONES: "<<cantTransacciones<<endl;
        cout<<" MONEDA PREFERIDA: "<<monedaPreferida<<endl;
        cout<<" FECHA DE INSCRIPCION: ";
        inscripcion.MostrarFecha();
    }
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


#endif // CLASSES_H_INCLUDED
