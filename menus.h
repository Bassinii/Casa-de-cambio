#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

int menuPrincipal(){

    hidecursor();
    int SposicionY = 0;

    while(true){
        int opc;
        const int x = 47;
        int y = 10;

        cls();

        ////
        for(int i = 1; i <= 119; i++){
                locate(i, 0);
                cout<< (char)219;
        }

        locate (x, 4);
        cout<<"       CHANGE COIN       ";


        for(int o = 1; o <= 119; o++){
                locate(o, 7);
                cout<< (char)219;
        }
        ////

        locate (x, y);
        cout<<"-------------------------";
        locate (x, y+2);
        cout<<"-------------------------";
        locate (x, y+3);
        cout<<"-    MENU CLIENTES      -";
        locate (x, y+4);
        cout<<"-    MENU EMPLEADOS     -";
        locate (x, y+5);
        cout<<"-    MENU TRANSACCIONES -";
        locate (x, y+6);
        cout<<"-    MENU MONEDAS       -";
        locate (x, y+7);
        cout<<"-    CONFIGURACIONES    -";
        locate (x, y+8);
        cout<<"-    SALIR              -";
        locate (x, y+9);
        cout<<"-------------------------";

        /// Seleccion


        locate(50, 13 + SposicionY);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key) {
            /// Tecla UP
            case 14:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY > 0) {
                    SposicionY--;
                }

                break;
            /// Tecla DOWN
            case 15:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY < 5) {
                    SposicionY++;
                }

                break;
            /// Tecla ENTER
            case 1:
                    if(SposicionY == 0){
                       cls();
                       menuClientes();
                    }

                    if(SposicionY == 1){
                       cls();
                       menuEmpleados();
                    }

                    if(SposicionY == 2){
                       cls();
                       menuTransacciones();
                    }

                    if(SposicionY == 3){
                       cls();
                       menuMonedas();
                    }

                    if(SposicionY == 4){
                       cls();
                       menuConfiguraciones();
                    }

                    if(SposicionY == 5){
                       cls();
                        locate(38, 13);
                        cout << "Hasta Luego!";
                        return 0;
                    }

                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
}

int menuClientes(){
    int SposicionY = 0;
    while(true){
        int opc;
        const int x = 40;
        int y = 10;

        locate (x, 10);
        cout<<"----------------------------------";
        locate (x, y+1);
        cout<<"-          MENU CLIENTES         -";
        locate (x, y+2);
        cout<<"----------------------------------";
        locate (x, y+3);
        cout<<"-     AGREGAR CLIENTE            -";
        locate (x, y+4);
        cout<<"-     MOSTRAR CLIENTE POR DNI    -";
        locate (x, y+5);
        cout<<"-     MOSTRAR TODOS LOS CLIENTES -";
        locate (x, y+6);
        cout<<"-     ELIMINAR CLIENTE           -";
        locate (x, y+7);
        cout<<"-     BUSCAR DNI POR NOMBRE      -";
        locate (x, y+8);
        cout<<"-     SALIR                      -";
        locate (x, y+9);
        cout<<"----------------------------------";

        locate(43, 13 + SposicionY);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key) {
            /// Tecla UP
            case 14:
                locate(43, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY > 0) {
                    SposicionY--;
                }

                break;
            /// Tecla DOWN
            case 15:
                locate(43, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY < 5) {
                    SposicionY++;
                }

                break;
            /// Tecla ENTER
            case 1:
                    if(SposicionY == 0){
                        cls();
                        if(agregarCliente()) cout<<"SE AGREGO EL CLIENTE CORRECTAMENTE"<<endl;
                        else cout<<"NO SE PUDO AGREGAR EL CLIENTE"<<endl;
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 1){
                        cls();
                        mostrarClientePorDni();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 2){
                        cls();
                       mostrarTodosLosClientes();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 3){
                        cls();
                        if(eliminarCliente()) cout<<"SE ELIMINO EL CLIENTE CORRECTAMENTE"<<endl;
                        else cout<<"NO SE HIZO LA BAJA DEL CLIENTE"<<endl;
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 4){
                        cls();
                        buscarDniCliente();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 5){
                       cls();
                        return 0;
                    }

                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        /*
        switch(opc){
        case 1:
            if(agregarCliente()) cout<<"SE AGREGO EL CLIENTE CORRECTAMENTE"<<endl;
            else cout<<"NO SE PUDO AGREGAR EL CLIENTE"<<endl;
            system("pause");
            cls();
            break;
        case 2:
            mostrarClientePorDni();
            system("pause");
            cls();
            break;
        case 3:
            mostrarTodosLosClientes();
            system("pause");
            cls();
            break;
        case 4:
            if(eliminarCliente()) cout<<"SE ELIMINO EL CLIENTE CORRECTAMENTE"<<endl;
            else cout<<"NO SE HIZO LA BAJA DEL CLIENTE"<<endl;
            system("pause");
            cls();
            break;
        case 0:
            return -1;
            break;
        default:
            cout<<"OPCION INCORRECTA"<<endl;
            break;
        }*/
    }
}

int menuEmpleados(){
        int SposicionY = 0;

        while(true){
        int opc;
        const int x = 40;
        int y = 10;

        locate (x, 10);
        cout<<"-----------------------------------";
        locate (x, y+1);
        cout<<"-          MENU EMPLEADOS         -";
        locate (x, y+2);
        cout<<"-----------------------------------";
        locate (x, y+3);
        cout<<"-     AGREGAR EMPLEADO            -";
        locate (x, y+4);
        cout<<"-     MOSTRAR EMPLEADO POR DNI    -";
        locate (x, y+5);
        cout<<"-     MOSTRAR TODOS LOS EMPLEADOS -";
        locate (x, y+6);
        cout<<"-     ELIMINAR EMPLEADO           -";
        locate (x, y+7);
        cout<<"-     BUSCAR DNI POR NOMBRE       -";
        locate (x, y+8);
        cout<<"-     SALIR                       -";
        locate (x, y+9);
        cout<<"-----------------------------------";


        locate(43, 13 + SposicionY);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key) {
            /// Tecla UP
            case 14:
                locate(43, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY > 0) {
                    SposicionY--;
                }

                break;
            /// Tecla DOWN
            case 15:
                locate(43, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY < 5) {
                    SposicionY++;
                }

                break;
            /// Tecla ENTER
            case 1:
                    if(SposicionY == 0){
                        cls();
                        agregarEmpleado();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 1){
                        cls();
                        mostrarEmpleadoPorDni();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 2){
                        cls();
                        mostrarTodosLosEmpleados();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 3){
                        cls();
                        eliminarEmpleado();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 4){
                        cls();
                        buscarDniEmpleado();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 5){
                       cls();
                        return 0;
                    }

                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
}

int menuTransacciones(){

    return 0;
}

int menuMonedas(){
        int SposicionY= 0;

    while(true){
        int opc;
        const int x = 40;
        int y = 10;

        locate (x, 10);
        cout<<"-------------------------";
        locate (x, y+1);
        cout<<"-      MENU MONEDAS     -";
        locate (x, y+2);
        cout<<"-------------------------";
        locate (x, y+3);
        cout<<"-    AGREGAR MONEDA     -";
        locate (x, y+4);
        cout<<"-    MOSTRAR MONEDAS    -";
        locate (x, y+5);
        cout<<"-    CAMBIAR COTIZACION -";
        locate (x, y+6);
        cout<<"-    ELIMINAR MONEDA    -";
        locate (x, y+7);
        cout<<"-    SALIR              -";
        locate (x, y+8);
        cout<<"-------------------------";

        locate(50, 13 + SposicionY);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key) {
            /// Tecla UP
            case 14:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY > 0) {
                    SposicionY--;
                }

                break;
            /// Tecla DOWN
            case 15:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY < 4) {
                    SposicionY++;
                }

                break;
            /// Tecla ENTER
            case 1:
                    if(SposicionY == 0){
                        cls();
                        if(agregarMoneda()) cout<<"SE AÑADIO LA MONEDA CORRECTAMENTE"<<endl;
                        else cout<<"NO SE PUDO AGREGAR LA MONEDA"<<endl;
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 1){
                        cls();
                        mostrarMonedas();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 2){
                        cls();
                        cambiarCotizacion();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 3){
                        cls();
                        if(eliminarMoneda()) cout<<"SE ELIMINO LA MONEDA CORRECTAMENTE"<<endl;
                        else cout<<"NO SE HIZO LA BAJA DE LA MONEDA"<<endl;
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 4){
                        cls();
                        return 0;
                    }

                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
}

int menuConfiguraciones(){
        int SposicionY = 0;
    while(true){
        int opc;
        const int x = 46;
        int y = 10;

        locate (x, 10);
        cout<<"----------------------------------";
        locate (x, y+1);
        cout<<"-          MENU CLIENTES         -";
        locate (x, y+2);
        cout<<"----------------------------------";
        locate (x, y+3);
        cout<<"-     COPIA DE SEGURIDAD         -";
        locate (x, y+4);
        cout<<"-     RESTAURAR                  -";
        locate (x, y+5);
        cout<<"-     SALIR                      -";
        locate (x, y+6);
        cout<<"----------------------------------";

        locate(50, 13 + SposicionY);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key) {
            /// Tecla UP
            case 14:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY > 0) {
                    SposicionY--;
                }

                break;
            /// Tecla DOWN
            case 15:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY < 2) {
                    SposicionY++;
                }

                break;
            /// Tecla ENTER
            case 1:
                    if(SposicionY == 0){
                        cls();
                        menuCopiaSeguridad();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 1){
                        cls();
                        menuRestaurar();
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 2){
                       cls();
                        return 0;
                    }

                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
}

int menuCopiaSeguridad(){
    int SposicionY = 0;

    while(true){
        int opc;
        const int x = 47;
        int y = 10;

        locate (x, y);
        cout<<"--------------------------------------------------";
        locate (x, y+1);
        cout<<"-            MENU COPIA DE SEGURIDAD             -";
        locate (x, y+2);
        cout<<"--------------------------------------------------";
        locate (x, y+3);
        cout<<"-    COPIA DE SEGURIDAD ARCHIVO CLIENTE          -";
        locate (x, y+4);
        cout<<"-    (LEER) COPIA DE SEGURIDAD ARCHIVO EMPLEADOS        -";
        locate (x, y+5);
        cout<<"-    COPIA DE SEGURIDAD ARCHIVO TRANSACCIONES    -";
        locate (x, y+6);
        cout<<"-    COPIA DE SEGURIDAD ARCHIVO MONEDA           -";
        locate (x, y+7);
        cout<<"-    SALIR                                       -";
        locate (x, y+8);
        cout<<"--------------------------------------------------";

        locate(50, 13 + SposicionY);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key) {
            /// Tecla UP
            case 14:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY > 0) {
                    SposicionY--;
                }

                break;
            /// Tecla DOWN
            case 15:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY < 4) {
                    SposicionY++;
                }

                break;
            /// Tecla ENTER
            case 1:
                    if(SposicionY == 0){
                        cls();
                        if (!bajaFisicaArchClientes()) cout << "COPIA DE SEGURIDAD NO EFECTIVA" << endl;
                        else {
                                cout << "COPIA DE SEGURIDAD EFECTIVA" << endl;
                        }
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 1){
                        cls();

Cliente reg;
FILE* file = fopen("Clientes.bak", "rb");

if (file == NULL) {
	cout << "ERROR DE ARCHIVO";
	return false;
}

while (fread(&reg, sizeof(Cliente), 1, file) == 1) {
	reg.mostrar();
	cout << endl;
}
fclose(file);


                        system("pause");
                        cls();
                    }

                    if(SposicionY == 2){
                        cls();

                        system("pause");
                        cls();
                    }

                    if(SposicionY == 3){
                        cls();
                        if (!bajaFisicaArchMonedas()) cout << "COPIA DE SEGURIDAD NO EFECTIVA" << endl;
                        else {
                                cout << "COPIA DE SEGURIDAD EFECTIVA" << endl;
                        }
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 4){
                        cls();
                        return 0;
                    }

                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
}

int menuRestaurar(){
    int SposicionY= 0;

    while(true){
        int opc;
        const int x = 47;
        int y = 10;

        locate (x, y);
        cout<<"-----------------------------------------";
        locate (x, y+1);
        cout<<"-            MENU RESTAURAR             -";
        locate (x, y+2);
        cout<<"-----------------------------------------";
        locate (x, y+3);
        cout<<"-    RESTAURAR ARCHIVO CLIENTE          -";
        locate (x, y+4);
        cout<<"-    RESTAURAR ARCHIVO EMPLEADOS        -";
        locate (x, y+5);
        cout<<"-    RESTAURAR ARCHIVO TRANSACCIONES    -";
        locate (x, y+6);
        cout<<"-    RESTAURAR ARCHIVO MONEDA           -";
        locate (x, y+7);
        cout<<"-    SALIR                              -";
        locate (x, y+8);
        cout<<"-----------------------------------------";

        locate(50, 13 + SposicionY);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key) {
            /// Tecla UP
            case 14:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY > 0) {
                    SposicionY--;
                }

                break;
            /// Tecla DOWN
            case 15:
                locate(50, 13 + SposicionY);
                cout << " " << endl;

                if (SposicionY < 4) {
                    SposicionY++;
                }

                break;
            /// Tecla ENTER
            case 1:
                    if(SposicionY == 0){
                        cls();
                        if (SposicionY == 0) cout << "RESTAURACION NO EFECTIVA" << endl;
                        else {
                                cout << "RESTAURACION EFECTIVA" << endl;
                        }
                        system("pause");
                        cls();
                    }

                    if(SposicionY == 1){
                        cls();

                        system("pause");
                        cls();
                    }

                    if(SposicionY == 2){
                        cls();

                        system("pause");
                        cls();
                    }

                    if(SposicionY == 3){
                        cls();

                        system("pause");
                        cls();
                    }

                    if(SposicionY == 4){
                        cls();
                        return 0;
                    }

                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
}

#endif // MENUS_H_INCLUDED
