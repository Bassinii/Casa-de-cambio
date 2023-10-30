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
        cout<<"- 4_ CAMBIAR MONEDAS    -"<<endl;
        cout<<"- 5_ CONFIGURACIONES    -"<<endl;
        cout<<"- 0_ SALIR              -"<<endl;
        cout<<"-------------------------"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cin>>opc;

        system("cls");
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                menuMonedas();
                break;
            case 5:
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
        }
    }
}

#endif // MENUS_H_INCLUDED
