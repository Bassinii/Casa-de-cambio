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
    int y = 10;
    int tam,dni;
    bool noMostro=true;
    tam=arch.contarRegistros();

    if(tam == 0) {
        locate(40, y);
        cout<< "NO HAY REGISTROS" <<endl;
        return;
    }
    locate(40, y);
    cout<<"INGRESAR EL DNI DEL CLIENTE"<<endl;
    locate(40, y+1);
    cin>>dni;
    for(int i=0;i<tam;i++){
        cliente=arch.leerRegistro(i);
        if(cliente.getDni()==dni&&cliente.getEstado()){
            ///locate(40, y+3);
            cliente.mostrar();
            cout<<endl;
            noMostro=false;
        }
    }
    if(noMostro){
        locate(40, 10);
        cout<<"NO SE ENCONTRO EL DNI"<<endl;
    }
}

//Muestra todos los clientes
void mostrarTodosLosClientes(){
    ArchivoClientes arch("clientes.dat");
    Cliente cliente;
    int tam;
    tam=arch.contarRegistros();

    if(tam == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return;
    }

    for(int i=0;i<tam;i++){
        cliente=arch.leerRegistro(i);
        if(cliente.getEstado()){
            cliente.mostrar();
            cout<<endl;
        }
    }
}

//Baja logica de un cliente, se setea su estado en false para que las funciones
//mostrarClientePorDni() y mostrarTodosLosClientes no lo listen por pantalla
bool eliminarCliente(){
    ArchivoClientes archCli("clientes.dat");
    Cliente cliente;
    int y = 10;
    int dni,pos,posReg;
    char opc[5];
    bool bajo=false,encontro=false;
    pos=archCli.contarRegistros();

    if(pos == 0) {
        locate(40, y);
        cout<< "NO HAY REGISTROS" <<endl;
        return 0;
    }
    locate(40, y);
    cout<<"INGRESAR EL DNI DEL CLIENTE"<<endl;
    locate(40, y+1);
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
            locate(40, 10);
            cout<<"NO SE HIZO LA BAJA"<<endl;
        }else{
            locate(40, 10);
            cout<<"OPCION INCORRECTA"<<endl;
        }
    }
    return bajo;
}

//Funcion para saber el dni del un cliente si se desconoce este.
void buscarDniCliente(){
    ArchivoClientes archCli("clientes.dat");
    Cliente cliente;
    int y = 10;
    int pos,dni;
    char nombreBusco[30],nombre[30],opc[5];
    bool encontro=false;
    while(true){
        pos=archCli.contarRegistros();

        if(pos == 0) {
            cout<< "NO HAY REGISTROS" <<endl;
            locate(40, y);
            return;
        }
        locate(40, y);
        cout<<"INGRESAR NOMBRE DEL CLIENTE"<<endl;
        locate(40, y+1);
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

///MENU EMPLEADOS
bool agregarEmpleado(){
    ArchivoEmpleados archEmpleados("empleados.dat");
    Empleado empleado;
    bool escribio;
    cout<<"----------------------------------"<<endl;
    cout<<"-         AGREGAR EMPLEADO        -"<<endl;
    cout<<"----------------------------------"<<endl;
    empleado.cargar();
    escribio=archEmpleados.agregarRegistro(empleado);
    return escribio;
}

void mostrarEmpleadoPorDni(){
    ArchivoEmpleados archEmpleados("empleados.dat");
    Empleado empleado;
    int tam,dni;
    bool noMostro=true;
    tam=archEmpleados.contarRegistros();

    if(tam == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return;
    }

    cout<<"INGRESAR EL DNI DEL EMPLEADO"<<endl;
    cin>>dni;
    for(int i=0;i<tam;i++){
        empleado=archEmpleados.leerRegistro(i);
        if(empleado.getDni()==dni&&empleado.getEstado()){
            empleado.mostrar();
            cout<<endl;
            noMostro=false;
        }
    }
    if(noMostro){
        cout<<"NO SE ENCONTRO EL DNI"<<endl;
    }
}

void mostrarTodosLosEmpleados(){
    ArchivoEmpleados archEmpleados("empleados.dat");
    Empleado empleado;
    int tam;
    tam=archEmpleados.contarRegistros();

    if(tam == 0) {
        cout<< "NO HAY REGISTROS";
        return;
    }

    for(int i=0;i<tam;i++){
        empleado=archEmpleados.leerRegistro(i);
        if(empleado.getEstado()){
            empleado.mostrar();
            cout<<endl;
        }
    }
}

bool eliminarEmpleado(){
    ArchivoEmpleados archEmpleados("empleados.dat");
    Empleado empleado;
    int dni,pos,posReg;
    char opc[5];
    bool bajo=false,encontro=false;
    pos=archEmpleados.contarRegistros();

    if(pos == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return 0;
    }

    cout<<"INGRESAR EL DNI DEL EMPLEADO"<<endl;
    cin>>dni;
    for(int i=0;i<pos;i++){
        empleado=archEmpleados.leerRegistro(i);
        if(empleado.getDni()==dni){
            encontro=true;
            posReg=i;
            break;
        }
    }
    if(!encontro) cout<<"NO SE ENCONTRO EMPLEADO CON ESE DNI"<<endl;
    if(encontro){
        empleado.mostrar();
        cout<<"BORRAR EMPLEADO? (SI/NO)"<<endl;
        cargarCadena(opc,5);
        if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"sI")==0||strcmp(opc,"Si")==0){
            empleado.setEstado(false);
            bajo=archEmpleados.modificarRegistro(posReg,empleado);
        }else if(strcmp(opc,"NO")==0||strcmp(opc,"no")==0||strcmp(opc,"nO")==0||strcmp(opc,"No")==0){
            cout<<"NO SE HIZO LA BAJA"<<endl;
        }else{
            cout<<"OPCION INCORRECTA"<<endl;
        }
    }
    return bajo;
}

void buscarDniEmpleado(){
    ArchivoEmpleados archEmpleados("empleados.dat");
    Empleado empleado;
    int pos,dni;
    char nombreBusco[30],nombre[30],opc[5];
    bool encontro=false;
    while(true){
        pos=archEmpleados.contarRegistros();

        if(pos == 0) {
            cout<< "NO HAY REGISTROS" <<endl;
            return;
        }
        cout<<"INGRESAR NOMBRE DEL EMPLEADO"<<endl;
        cargarCadena(nombreBusco,30);
        for(int i=0;i<pos;i++){
            empleado=archEmpleados.leerRegistro(i);
            strcpy(nombre,empleado.getNombre());
            if(strcmp(nombreBusco,nombre)==0){
                dni=empleado.getDni();
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

///MENU TRANSACCIONES
bool crearTransaccion(){
    ArchivoTransacciones archTransacciones("transacciones.dat");
    Transaccion transaccion;
    bool escribio=false,cargo;
    cout<<"----------------------------------"<<endl;
    cout<<"-         AGREGAR TRANSACCION    -"<<endl;
    cout<<"----------------------------------"<<endl;
    cargo=transaccion.cargar();
    if(cargo){
        escribio=archTransacciones.agregarRegistro(transaccion);
    }
    return escribio;
}

void mostrarTransaccionPorID(){
    ArchivoTransacciones archTransacciones("transacciones.dat");
    Transaccion transaccion;
    int tam,id;
    bool noMostro=true;
    tam=archTransacciones.contarRegistros();

    if(tam == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return;
    }

    cout<<"INGRESAR EL ID DE LA TRANSACCION"<<endl;
    cin>>id;
    for(int i=0;i<tam;i++){
        transaccion=archTransacciones.leerRegistro(i);
        if(transaccion.getID()==id&&transaccion.getEstado()){
            transaccion.mostrar();
            cout<<endl;
            noMostro=false;
        }
    }
    if(noMostro){
        cout<<"NO SE ENCONTRO LA TRANSACCION"<<endl;
    }
}

void mostrarTodasLasTransacciones(){
    ArchivoTransacciones archTransacciones("transacciones.dat");
    Transaccion transaccion;
    int pos;
    pos=archTransacciones.contarRegistros();

    if(pos == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return;
    }

    for(int i=0;i<pos;i++){
        transaccion=archTransacciones.leerRegistro(i);
        transaccion.mostrar();
        cout<<endl;
    }
}

bool eliminarTransaccion(){
    ArchivoTransacciones archTransacciones("transacciones.dat");
    Transaccion transaccion;
    int id,pos,posReg;
    char opc[5];
    bool bajo=false,encontro=false;
    pos=archTransacciones.contarRegistros();

    if(pos == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return 0;
    }

    cout<<"INGRESAR EL ID DE LA TRANSACCION"<<endl;
    cin>>id;
    for(int i=0;i<pos;i++){
        transaccion=archTransacciones.leerRegistro(i);
        if(transaccion.getID()==id){
            encontro=true;
            posReg=i;
            break;
        }
    }
    if(!encontro) cout<<"NO SE ENCONTRO TRANSACCION CON ESE ID"<<endl;
    if(encontro){
        transaccion.mostrar();
        cout<<"BORRAR TRANSACCION? (si/no)"<<endl;
        cargarCadena(opc,5);
        if(strcmp(opc,"SI")==0||strcmp(opc,"si")==0||strcmp(opc,"sI")==0||strcmp(opc,"Si")==0){
            transaccion.setEstado(false);
            bajo=archTransacciones.modificarRegistro(posReg,transaccion);
        }else if(strcmp(opc,"NO")==0||strcmp(opc,"no")==0||strcmp(opc,"nO")==0||strcmp(opc,"No")==0){
            cout<<"NO SE HIZO LA BAJA"<<endl;
        }else{
            cout<<"OPCION INCORRECTA"<<endl;
        }
    }
    return bajo;
}

void buscarTransaccion(){

}

///MENU MONEDAS
//Agrega una moneda, si se pudo agregar retorna true, sino false
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

//Muestra todas las monedas
void mostrarMonedas(){
    ArchivoMonedas archMonedas("monedas.dat");
    Moneda moneda;
    int pos;
    pos=archMonedas.contarRegistros();

    if(pos == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return;
    }

    for(int i=0;i<pos;i++){
        moneda=archMonedas.leerRegistro(i);
        if(moneda.getEstado()){
            moneda.mostrar();
            cout<<endl;
        }
    }
}

//Cambia la cotizacion de una moneda
void cambiarCotizacion(){
    ArchivoMonedas archMonedas("monedas.dat");
    Moneda moneda;
    char monedaCambiar[20];
    int pos;
    float compra,venta;
    bool encontro=false;
    pos=archMonedas.contarRegistros();

    if(pos == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return;
    }

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

//Setea en false el estado de una moneda
bool eliminarMoneda(){
    ArchivoMonedas archMonedas("monedas.dat");
    Moneda moneda;
    int pos,posReg;
    char opc[5],monedaBuscada[20];
    bool bajo=false,encontro=false;
    pos=archMonedas.contarRegistros();

    if(pos == 0) {
        cout<< "NO HAY REGISTROS" <<endl;
        return 0;
    }

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

///MENU CONFIG
bool bajaFisicaArchClientes(){
    FILE* file, * fileBak;
    Cliente reg;

    file = fopen("clientes.dat", "rb");
    if (file == NULL)return false;

    fileBak = fopen("clientes.bak", "wb");
    if (fileBak == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        fclose(file);
        return false;
    }

    while (fread(&reg, sizeof reg, 1, file) == 1) {
        if (reg.getEstado() == true) {
            fwrite(&reg, sizeof reg, 1, fileBak);
        }
    }
    fclose(file);
    fclose(fileBak);
    return true;
}

bool bajaFisicaArchEmpleados(){
    FILE* file, * fileBak;
    Empleado reg;

    file = fopen("empleados.dat", "rb");
    if (file == NULL)return false;

    fileBak = fopen("empleados.bak", "wb");
    if (fileBak == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        fclose(file);
        return false;
    }

    while (fread(&reg, sizeof reg, 1, file) == 1) {
        if (reg.getEstado() == true) {
            fwrite(&reg, sizeof reg, 1, fileBak);
        }
    }
    fclose(file);
    fclose(fileBak);
    return true;
}

bool bajaFisicaArchTransacciones(){
    FILE* file, * fileBak;
    Transaccion reg;

    file = fopen("transacciones.dat", "rb");
    if (file == NULL)return false;

    fileBak = fopen("transacciones.bak", "wb");
    if (fileBak == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        fclose(file);
        return false;
    }

    while (fread(&reg, sizeof reg, 1, file) == 1) {
        if (reg.getEstado() == true) {
            fwrite(&reg, sizeof reg, 1, fileBak);
        }
    }
    fclose(file);
    fclose(fileBak);
    return true;
}

bool bajaFisicaArchMonedas(){
    FILE* file, * fileBak;
    Moneda reg;

    file = fopen("monedas.dat", "rb");
    if (file == NULL)return false;

    fileBak = fopen("monedas.bak", "wb");
    if (fileBak == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        fclose(file);
        return false;
    }

    while (fread(&reg, sizeof reg, 1, file) == 1) {
        if (reg.getEstado() == true) {
            fwrite(&reg, sizeof reg, 1, fileBak);
        }
    }
    fclose(file);
    fclose(fileBak);
    return true;
}

bool RestaurarArchClientes(){
    FILE* file, * fileBak;
    Cliente reg;

    file = fopen("clientes.dat", "wb");
    if (file == NULL)return false;

    fileBak = fopen("clientes.bak", "rb");
    if (fileBak == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        fclose(file);
        return false;
    }

    while (fread(&reg, sizeof reg, 1, fileBak) == 1) {
            fwrite(&reg, sizeof reg, 1, file);
    }
    fclose(file);
    fclose(fileBak);
    return true;
}

bool RestaurarArchEmpleados(){
    FILE* file, * fileBak;
    Empleado reg;

    file = fopen("empleados.dat", "wb");
    if (file == NULL)return false;

    fileBak = fopen("empleados.bak", "rb");
    if (fileBak == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        fclose(file);
        return false;
    }

    while (fread(&reg, sizeof reg, 1, fileBak) == 1) {
            fwrite(&reg, sizeof reg, 1, file);
    }
    fclose(file);
    fclose(fileBak);
    return true;
}

bool RestaurarArchTransacciones(){
    FILE* file, * fileBak;
    Transaccion reg;

    file = fopen("transacciones.dat", "wb");
    if (file == NULL)return false;

    fileBak = fopen("transacciones.bak", "rb");
    if (fileBak == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        fclose(file);
        return false;
    }

    while (fread(&reg, sizeof reg, 1, fileBak) == 1) {
            fwrite(&reg, sizeof reg, 1, file);
    }
    fclose(file);
    fclose(fileBak);
    return true;
}

bool RestaurarArchMonedas(){
    FILE* file, * fileBak;
    Moneda reg;

    file = fopen("monedas.dat", "wb");
    if (file == NULL)return false;

    fileBak = fopen("monedas.bak", "rb");
    if (fileBak == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        fclose(file);
        return false;
    }

    while (fread(&reg, sizeof reg, 1, fileBak) == 1) {
            fwrite(&reg, sizeof reg, 1, file);
    }
    fclose(file);
    fclose(fileBak);
    return true;
}

#endif // FUNCTIONS_H_INCLUDED
