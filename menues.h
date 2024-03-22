#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

int menuPrincipal(){
    hidecursor();
    int SposicionY=0;
    while(true){
        const int x=40;
        int y=10;

        locate (x, 10);
        cout<<"--------------------------------------";
        locate (x, y+1);
        cout<<"-              FREEZADOS             -";
        locate (x, y+2);
        cout<<"--------------------------------------";
        locate (x, y+3);
        cout<<"-    FREEZER DELANTERO               -";
        locate (x, y+4);
        cout<<"-    FREEZER TRASERO                 -";
        locate (x, y+5);
        cout<<"-    SALIR                           -";
        locate (x, y+6);
        cout<<"--------------------------------------";

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

                if (SposicionY < 2) {
                    SposicionY++;
                }

                break;
            /// Tecla ENTER
            case 1:
                    if(SposicionY == 0){
                        cls();

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
                        return 0;
                    }


                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
}

int menuFreezados(){

}

#endif // MENUES_H_INCLUDED
