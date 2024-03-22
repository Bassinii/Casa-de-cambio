#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

class Productos{
private:
    int stock;
    char nombre[30];
public:
    Productos(){
        stock=0;
        strcpy(nombre,"N/A");
    }
    Productos(const char *nombre,const int stock){
        strcpy(this->nombre,nombre);
        this->stock=stock;
    }
};

class ArchivoProductos{
private:
        char nombre[30];
public:
    ArchivoProductos(const char *nombre){
        strcpy(this->nombre,nombre);
    }
    bool agregarProducto(){;}
    bool leerProductos(){;}
    bool elimarProducto(){;}
};

#endif // CLASSES_H_INCLUDED
