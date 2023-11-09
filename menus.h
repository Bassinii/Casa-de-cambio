#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

int menuPrincipal(){
    while(true){
        int opc;
        cout<<"-------------------------"<<endl;
        cout<<"-      CHANGE COIN      -"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"- 1_ MENU CLIENTES      -"<<endl;
        cout<<"- 2_ MENU EMPLEADOS     -"<<endl;
        cout<<"- 3_ MENU TRANSACCIONES -"<<endl;
        cout<<"- 4_ MENU MONEDAS       -"<<endl;
        cout<<"- 5_ CONFIGURACIONES    -"<<endl;
        cout<<"- 0_ SALIR              -"<<endl;
        cout<<"-------------------------"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuClientes();
                break;
            case 2:
                menuEmpleados();
                break;
            case 3:
                menuTransacciones();
                break;
            case 4:
                menuMonedas();
                break;
            case 5:
                menuConfiguraciones();
                break;
            case 0:
                return 0;
                break;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
}

int menuClientes(){
    while(true){
        int opc;
        cout<<"----------------------------------"<<endl;
        cout<<"-          MENU CLIENTES         -"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"-  1_ AGREGAR CLIENTE            -"<<endl;
        cout<<"-  2_ MOSTRAR CLIENTE POR DNI    -"<<endl;
        cout<<"-  3_ MOSTRAR TODOS LOS CLIENTES -"<<endl;
        cout<<"-  4_ ELIMINAR CLIENTE           -"<<endl;
        cout<<"-  0_ SALIR                      -"<<endl;
        cout<<"----------------------------------"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            if(agregarCliente()) cout<<"SE AGREGO EL CLIENTE CORRECTAMENTE"<<endl;
            else cout<<"NO SE PUDO AGREGAR EL CLIENTE"<<endl;
            system("pause");
            system("cls");
            break;
        case 2:
            mostrarClientePorDni();
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarTodosLosClientes();
            system("pause");
            system("cls");
            break;
        case 4:
            if(eliminarCliente()) cout<<"SE ELIMINO EL CLIENTE CORRECTAMENTE!"<<endl;
            else cout<<"NO SE PUDO ELIMINAR EL CLIENTE"<<endl;
            system("pause");
            system("cls");
            break;
        case 0:
            return -1;
            break;
        default:
            cout<<"OPCION INCORRECTA"<<endl;
            break;
        }
    }
}

int menuEmpleados(){

    return 0;
}

int menuTransacciones(){
    return 0;
}

int menuMonedas(){
    while(true){
        int opc;
        cout<<"-------------------------"<<endl;
        cout<<"-      MENU MONEDAS     -"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"- 1_ AGREGAR MONEDA     -"<<endl;
        cout<<"- 2_ QUITAR MONEDA      -"<<endl;
        cout<<"- 3_ CAMBIAR COTIZACION -"<<endl;
        cout<<"- 0_ SALIR              -"<<endl;
        cout<<"-------------------------"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cin>>opc;
        switch(opc){


        case 0:
            return -1;
            break;
        default:
            cout<<"OPCION INCORRECTA"<<endl;
            break;
        }
    }
}

int menuConfiguraciones(){
    return 0;
}


#endif // MENUS_H_INCLUDED
