#include <iostream>
#include <vector>
#include <stdlib.h>
#define size 8
using namespace std;

//Variables que representan las fichas y los lugares vacios del tablero.
enum class Pieza{Vacio, Blanco, Negro};
enum class Usuario{N,B};

//Clase para representar el tablero del juego y las acciones que se pueden
//realizar en él.
class Reversi {
    //Variables del juego, en este caso el tablero
    private:

        //Declaracion de la variable que representa el tablero
        vector<vector<Pieza>>tablero;
        Usuario usuario = Usuario::N;
        



    public:

        //Funcion que inicializa el tablero con todas sus posiciones 
        //iniciales
        void inicializarTablero() {
            
            //Inicializar todo el tablero como casillas vacias
            tablero.resize(size,vector<Pieza>(size, Pieza::Vacio));

            //Colocar las 4 piezas iniciales
            tablero[3][3] = tablero[4][4] = Pieza::Blanco;
            tablero[3][4] = tablero[4][3] = Pieza::Negro;

        }




        // funcion que imprime el tablero
        void imprimirTablero() {
            //Limpia la pantalla de las anteriores impresiones
            system("cls");
            //imprime el numero de las columnas del tablero en la parte sup.
            cout << "  ";
            for (int i = 0; i<size; i++)
                cout << i+1 << " ";
            cout << endl;

            for (int i = 0; i<size; i++) {
                //imprime el numero de las filas del tablero en la parte inf.
                cout << i+1 << " ";
                //switch para identificar que pieza es y representarla
                for (int j = 0; j<size; j++) {

                    switch (tablero[i][j])
                    {
                    case Pieza::Vacio:
                        cout<<".";
                        break;

                    case Pieza::Negro:
                        cout<<"N";
                        break;

                    case Pieza::Blanco:
                        cout<<"B";
                        break;
                    }
                    cout<<" ";
                }
                //Instruccion para que baje a la siguiente linea
                cout << endl;
            }
        }



        //Funcion para que el usuario puede introducir una pieza al 
        //tablero
        void realizarMovimiento() {
            //Variable que determina si el movimiento es valido o no
            bool movValid = false;
            int fila = 0, columna = 0;
            
            while (movValid == false) {
                //Seccion para saber que movimiento desea hacer el usuario
                //de no serlo se repite el ciclo do-while
                cout<<endl;
                cout<<"jugador de piezas ";
                if (usuario == Usuario::N) {
                    cout<<"Negras"<<endl;
                } else {
                cout<<"Blancas"<<endl;}


                cout<<endl<<"Introduzca la posicion de la ficha a introducir:"<<endl;
                cout<<"Fila: ";
                cin>>fila;
                fila--;
                cout<<"Columna: ";
                cin>>columna;
                columna--;
                movValid = movimientoValido(fila, columna);



                //Se corrobora que el movimiento sea valido y de serlo se realiza
                if(movValid == true) {
                    
                    if(usuario==Usuario::N) {
                        tablero[fila][columna] = Pieza::Negro;
                    } else {
                        tablero[fila][columna] = Pieza::Blanco;
                    }

                    //cambia el valor del usuario al color contrario despues de realizar el movimiento respectivo en el tablero
                    if(usuario == Usuario::N) {
                        usuario = Usuario::B;
                    } else {
                        usuario = Usuario::N;
                    }

                //Mensaje de error por si el movimiento no es uno valido
                } else {
                    cout<<endl<<"Movimiento Invalido!!!"<<endl<<"Reiniciando eleccion de movimiento"<<endl;
                }

            }
        
        

            //seccion para el cambio de piezas 

        }

        
        




        //Funcion para corroborar si la casilla esta disponible
        bool movimientoValido(int fila, int columna) {

            if(tablero[fila][columna] != Pieza::Vacio || fila > 6 || columna > 6) {
                return false;
            } else {
                return true;
            }
        }

    


    //Funcion para jugar una partida (Viene incluido con el fin del juego y menu)
    void jugarPartida() {
        inicializarTablero();

        string decision = "";
        cout<<"Quieres jugar una partida? (S/N)"<<endl;
        cin>>decision;


        if (decision == "N" || decision == "n") {
            cout<<"Okey, pa q inicias el programa entonse?, chauuuu!!!"<<endl;
        
        
        } else {
            for (int i=3; i<60;i++) {
                imprimirTablero();
                realizarMovimiento();
            }
        }


        //Seccion para contar las piezas
        int piezasNegras = 0, piezasBlancas = 0;

        for(int i=0;i<size;i++) {
            for (int j=0;j<size;j++) {
                if (tablero[i][j]==Pieza::Blanco) {
                    piezasBlancas++;
                } else {
                    piezasNegras++;
                }
        }

        if (piezasBlancas>piezasNegras) {
            cout<<endl<<"el ganador es el jugador de Piezas Blancas!!!";
        } else {
            cout<<endl<<"el ganador es el jugador de Piezas Negras!!!";
        }
    }
    }



    
    
};






int main() {
    Reversi juego;
    juego.jugarPartida();
    system("pause");
    return 0;
}