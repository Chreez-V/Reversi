#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// Variable del tamaño del tablero.
#define size 8
// Variables que representan las fichas y los lugares vacios del tablero.
enum class Pieza { Vacio, Blanco, Negro };
//  Variables que representan los jugadores (Fichas Negras y Fichas Blancas).
enum class Usuario { N, B };

// Clase para representar el tablero del juego y las acciones que se pueden
// realizar en él.
class Reversi {
  // Variables del juego, en este caso el tablero
private:
  // Declaracion de la variable que representa el tablero
  vector<vector<Pieza>> tablero;
  Usuario usuario = Usuario::N;
  const vector<pair<int, int>> direcciones = {
      {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

public:
  // Funcion que inicializa el tablero con todas sus posiciones
  // iniciales
  void inicializarTablero() {

    // Inicializar todo el tablero como casillas vacias
    tablero.resize(size, vector<Pieza>(size, Pieza::Vacio));

    // Colocar las 4 piezas iniciales
    tablero[3][3] = tablero[4][4] = Pieza::Blanco;
    tablero[3][4] = tablero[4][3] = Pieza::Negro;
  }

  // funcion que imprime el tablero
  void imprimirTablero() {
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

        switch (tablero[i][j]) {
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
  }

  // Funcion para que el usuario puede introducir una pieza al
  // tablero
  void realizarMovimiento() {
    // Variable que determina si el movimiento es valido o no
    bool movValid = false;
    int fila = 0, columna = 0;

    while (movValid == false) {
      // Seccion para saber que movimiento desea hacer el usuario
      // de no serlo se repite el ciclo do-while
      cout << endl;
      cout << "jugador de piezas ";
      if (usuario == Usuario::N) {
        cout << "Negras";
      } else {
        cout << "Blancas";
      }

      cout << endl
           << ", Introduzca la posicion de la ficha a introducir:" << endl;
      cout << "Fila: ";
      cin >> fila;
      fila--;
      cout << "Columna: ";
      cin >> columna;
      columna--;
      movValid = movimientoValido(fila, columna);

      // Se corrobora que el movimiento sea valido y de serlo se realiza
      if (movValid == true) {

        colocarPieza(fila, columna);
        cambiarFichas(fila, columna);
        cambiarUsuario();
        // Mensaje de error por si el movimiento no es uno valido
      } else {
        cout << endl
             << "Movimiento Invalido!!!" << endl
             << "Reiniciando eleccion de movimiento" << endl;
      }
    }

    // seccion para el cambio de piezas
  }

  bool movimientoValido(int fila, int columna) {
    if (tablero[fila][columna] != Pieza::Vacio || fila < 0 || fila >= size ||
        columna < 0 || columna >= size) {
      return false;
    }

    Pieza piezaActual = (usuario == Usuario::N) ? Pieza::Negro : Pieza::Blanco;
    Pieza piezaContraria =
        (usuario == Usuario::N) ? Pieza::Blanco : Pieza::Negro;

    for (const auto &direccion : direcciones) {
      int x = fila + direccion.first;
      int y = columna + direccion.second;
      bool foundOpposite = false;

      while (x >= 0 && x < size && y >= 0 && y < size) {
        if (tablero[x][y] == piezaContraria) {
          foundOpposite = true;
        } else if (tablero[x][y] == piezaActual) {
          if (foundOpposite) {
            return true;
          } else {
            break;
          }
        } else {
          break;
        }
        x += direccion.first;
        y += direccion.second;
      }
    }
    return false;
  }

  void colocarPieza(int fila, int columna) {
    tablero[fila][columna] =
        (usuario == Usuario::N) ? Pieza::Negro : Pieza::Blanco;
  }

  void cambiarFichas(int fila, int columna) {
    Pieza piezaActual = (usuario == Usuario::N) ? Pieza::Negro : Pieza::Blanco;
    Pieza piezaContraria =
        (usuario == Usuario::N) ? Pieza::Blanco : Pieza::Negro;

    for (const auto &direccion : direcciones) {
      vector<pair<int, int>> piezasACambiar;
      int x = fila + direccion.first;
      int y = columna + direccion.second;
      bool foundOpposite = false;

      while (x >= 0 && x < size && y >= 0 && y < size) {
        if (tablero[x][y] == piezaContraria) {
          foundOpposite = true;
          piezasACambiar.push_back({x, y});
        } else if (tablero[x][y] == piezaActual) {
          if (foundOpposite) {
            for (const auto &pieza : piezasACambiar) {
              tablero[pieza.first][pieza.second] = piezaActual;
            }
          }
          break;
        } else {
          break;
        }
        x += direccion.first;
        y += direccion.second;
      }
    }
  }

  void cambiarUsuario() {
    usuario = (usuario == Usuario::N) ? Usuario::B : Usuario::N;
  }

  bool tieneMovimientosValidos(Usuario usuarioActual) {
    Pieza piezaActual =
        (usuarioActual == Usuario::N) ? Pieza::Negro : Pieza::Blanco;
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        if (tablero[i][j] == Pieza::Vacio) {
          for (const auto &direccion : direcciones) {
            int x = i + direccion.first;
            int y = j + direccion.second;
            bool foundOpposite = false;

            while (x >= 0 && x < size && y >= 0 && y < size) {
              if (tablero[x][y] == (piezaActual == Pieza::Negro
                                        ? Pieza::Blanco
                                        : Pieza::Negro)) {
                foundOpposite = true;
              } else if (tablero[x][y] == piezaActual) {
                if (foundOpposite) {
                  return true;
                } else {
                  break;
                }
              } else {
                break;
              }
              x += direccion.first;
              y += direccion.second;
            }
          }
        }
      }
    }
    return false;
  }

  void jugarPartida() {
    inicializarTablero();

    string decision = "";
    cout << "Quieres jugar una partida? (S/N)" << endl;
    cin >> decision;

    if (decision == "N" || decision == "n") {
      cout << "Okey, pa q inicias el programa entonse?, chauuuu!!!" << endl;
    } else {
      while (tieneMovimientosValidos(Usuario::N) ||
             tieneMovimientosValidos(Usuario::B)) {
        imprimirTablero();
        if (tieneMovimientosValidos(usuario)) {
          realizarMovimiento();
        } else {
          cout << "No hay movimientos validos para el jugador de piezas ";
          cout << (usuario == Usuario::N ? "Negras" : "Blancas")
               << ". Turno pasado." << endl;
          cambiarUsuario();
        }
      }

      imprimirTablero();
      int piezasNegras = 0, piezasBlancas = 0;

      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if (tablero[i][j] == Pieza::Blanco) {
            piezasBlancas++;
          } else if (tablero[i][j] == Pieza::Negro) {
            piezasNegras++;
          }
        }
      }

      if (piezasBlancas > piezasNegras) {
        cout << endl << "El ganador es el jugador de Piezas Blancas!!!" << endl;
      } else if (piezasNegras > piezasBlancas) {
        cout << endl << "El ganador es el jugador de Piezas Negras!!!" << endl;
      } else {
        cout << endl << "El juego es un empate!!!" << endl;
      }
    }
  }
};

int main() {
  Reversi juego;
  juego.jugarPartida();
  system("pause");
  return 0;
} // Funcion para corroborar si la casilla esta disponible
