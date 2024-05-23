#include "Reversi.hpp"
#include <iostream>
#include <vector>
using namespace std;

/* Esta clase tiene una anotacion asintota de Big O (n^3) */
vector<vector<Pieza>> tablero;
Reversi::Reversi()
    : simbolo(Simbolo::N), direcciones{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1},   {1, -1}, {1, 0},  {1, 1}} {
  inicializarTablero();
}

// inicializarTablero()  tiene un notacion big O (n)
void Reversi::inicializarTablero() {
  // crea el tablero vacio
  tablero.resize(size, vector<Pieza>(size, Pieza::Vacio));

  // Colocar las 4 piezas iniciales
  tablero[3][3] = tablero[4][4] = Pieza::Blanco;
  tablero[3][4] = tablero[4][3] = Pieza::Negro;
}

// imprimirTablero() tiene una notacion big O (n^2)
void Reversi::imprimirTablero() {
  system("cls");

  // Limpia la pantalla de las anteriores impresiones

  // imprime el numero de las columnas del tablero en la parte sup.
  cout << "  ";
  for (int i = 0; i < size; i++)
    cout << i + 1 << " ";
  cout << endl;
  /*El pirmer bucle imprime las filas y el 2do bucle for imprime las columnas
    del tablero*/
  for (int i = 0; i < size; i++) {
    cout << i + 1 << " ";

    for (int j = 0; j < size; j++) {
      // switch para identificar que pieza es y representarla
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
    cout << endl;
  }
}

/* Funcion para que el usuario puede introducir una pieza a  tablero
   Esta funcion tiene un big O (n) */
void Reversi::realizarMovimiento() {
  bool movValid = false;
  int fila = 0, columna = 0;

  while (movValid == false) {
    /* Seccion para saber que movimiento desea hacer el usuario
      de no serlo se repite el ciclo */
    cout << endl << "jugador de piezas ";

    if (simbolo == Simbolo::N) {
      cout << "Negras";
    } else {
      cout << "Blancas";
    }
    cout << endl
         << " Introduzca la posicion de la ficha a introducir:" << endl
         << "Fila: ";
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

    } else {
      // Mensaje de error por si el movimiento no es uno valido
      cout << endl
           << "Movimiento Invalido!!!" << endl
           << "Reiniciando eleccion de movimiento" << endl;
    }
  }
}

// esta funcion tiene un Big O (n^2)
bool Reversi::movimientoValido(int fila, int columna) {
  if (tablero[fila][columna] != Pieza::Vacio || fila < 0 || fila >= size ||
      columna < 0 || columna >= size) {
    return false; // Verificar si la posicion fila,columna está vacía.
  }
  Pieza piezaActual = (simbolo == Simbolo::N) ? Pieza::Negro : Pieza::Blanco;
  Pieza piezaContraria = (simbolo == Simbolo::N) ? Pieza::Blanco : Pieza::Negro;

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

// esta funcion tiene un Big O n
void Reversi::colocarPieza(int fila, int columna) {
  tablero[fila][columna] =
      (simbolo == Simbolo::N) ? Pieza::Negro : Pieza::Blanco;
}

// esta funcion tiene un Big O n*m
void Reversi::cambiarFichas(int fila, int columna) {
  Pieza piezaActual = (simbolo == Simbolo::N) ? Pieza::Negro : Pieza::Blanco;
  Pieza piezaContraria = (simbolo == Simbolo::N) ? Pieza::Blanco : Pieza::Negro;

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

// esta funcion tiene un Big O n
void Reversi::cambiarUsuario() {
  simbolo = (simbolo == Simbolo::N) ? Simbolo::B : Simbolo::N;
}

// esta funcion tiene un Big O n^2
vector<pair<int, int>> Reversi::obtenerMovimientosValidos() {

  vector<pair<int, int>> movimientos;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (movimientoValido(i, j)) {
        movimientos.push_back({i, j});
      }
    }
  }
  return movimientos;
}
// big O n^2
bool Reversi::tieneMovimientosValidos(Simbolo usuarioActual) {
  Pieza piezaActual =
      (usuarioActual == Simbolo::N) ? Pieza::Negro : Pieza::Blanco;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (tablero[i][j] == Pieza::Vacio) {
        for (const auto &direccion : direcciones) {
          int x = i + direccion.first;
          int y = j + direccion.second;
          bool foundOpposite = false;

          while (x >= 0 && x < size && y >= 0 && y < size) {
            if (tablero[x][y] ==
                (piezaActual == Pieza::Negro ? Pieza::Blanco : Pieza::Negro)) {
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

// n^2
void Reversi::jugarPartida() {
  inicializarTablero();

  string decision = "";
  cout << "Quieres jugar una partida? (S/N)" << endl;
  cin >> decision;

  if (decision == "N" || decision == "n") {
    cout << "Okey, pa q inicias el programa entonse?, chauuuu!!!" << endl;
  } else {
    // n^2
    while (tieneMovimientosValidos(Simbolo::N) ||
           tieneMovimientosValidos(Simbolo::B)) {
      imprimirTablero();
      if (tieneMovimientosValidos(simbolo))

      {
        realizarMovimiento();
      } else {
        cout << "No hay movimientos validos para el jugador de piezas ";
        cout << (simbolo == Simbolo::N ? "Negras" : "Blancas")
             << ". Turno pasado." << endl;
        cambiarUsuario();
      }
    }

    imprimirTablero();
    int piezasNegras = 0, piezasBlancas = 0;
    // n^2
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (tablero[i][j] == Pieza::Blanco) {
          piezasBlancas++;
        } else if (tablero[i][j] == Pieza::Negro) {
          piezasNegras++;
        }
      }
    }
    // n
    if (piezasBlancas > piezasNegras) {
      cout << endl << "El ganador es el jugador de Piezas Blancas!!!" << endl;
    } else if (piezasNegras > piezasBlancas) {
      cout << endl << "El ganador es el jugador de Piezas Negras!!!" << endl;
    } else {
      cout << endl << "El juego es un empate!!!" << endl;
    }
  }
}

Simbolo Reversi::getUsuarioActual() const { return simbolo; }

vector<vector<Pieza>> Reversi::getTablero() const { return tablero; }

int Reversi::getTamanio() const { return size; }
