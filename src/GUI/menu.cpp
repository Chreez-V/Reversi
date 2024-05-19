#include "menu.hpp"
#include "Proyecto1.hpp"

class Gui {
    private:
        Reversi tableroGui;

        Gui(Reversi tablero) {
            tableroGui = tablero;
        }

    public:

    void menu() {

    }
            // funcion que imprime el tablero
  /*void imprimirTablero() {
    // Limpia la pantalla de las anteriores impresiones
    system("cls");
    // imprime el numero de las columnas del tablero en la parte sup.
    cout << "  ";
    for (int i = 0; i < size; i++)
      cout << i + 1 << " ";
    cout << endl;

    for (int i = 0; i < size; i++) {
      // imprime el numero de las filas del tablero en la parte inf.
      cout << i + 1 << " ";
      // switch para identificar que pieza es y representarla
      for (int j = 0; j < size; j++) {

        switch (tableroGui.[i][j]) {
            case Pieza::Vacio:
            cout << ".";
            break;

            case Pieza::Negro:
            cout << "N";
            break;

            case Pieza::Blanco:
            cout << "B";
            break;
        }
        cout << " ";
      }
      // Instruccion para que baje a la siguiente linea
      cout << endl;
    }
  }*/
};


