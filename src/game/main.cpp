#include "../GUI/menu.hpp"
#include <iostream>

using namespace std;
/*
  Esta clase contiene una notacion asintota de Big O (n^2) + big 0 n = (n^2)
*/
void menu() {
  cout << "Selecciona el modo de juego:" << endl;
  cout << "1. Jugador vs Jugador" << endl;
  cout << "2. Jugador vs Máquina" << endl;
  cout << "3. Máquina vs Máquina" << endl;
  cout << "Ingrese su opción: ";
}

int main() {
  int opcion;
  Reversi juego;
  GUI gui;
  PcMode maquina;

  menu();
  cin >> opcion;

  switch (opcion) {
  case 1:
    // Jugador vs Jugador
    while (juego.tieneMovimientosValidos(Simbolo::N) ||
           juego.tieneMovimientosValidos(Simbolo::B)) {
      gui.imprimirTablero(juego);
      if (juego.getUsuarioActual() == Simbolo::N &&
          juego.tieneMovimientosValidos(Simbolo::N)) {
        juego.realizarMovimiento();
      } else if (juego.getUsuarioActual() == Simbolo::B &&
                 juego.tieneMovimientosValidos(Simbolo::B)) {
        juego.realizarMovimiento();
      }
      juego.cambiarUsuario();
    }
    break;
  case 2:
    // Jugador vs Máquina
    while (juego.tieneMovimientosValidos(Simbolo::N) ||
           juego.tieneMovimientosValidos(Simbolo::B)) {
      gui.imprimirTablero(juego);
      if (juego.getUsuarioActual() == Simbolo::N &&
          juego.tieneMovimientosValidos(Simbolo::N)) {
        juego.realizarMovimiento();
      } else if (juego.getUsuarioActual() == Simbolo::B &&
                 juego.tieneMovimientosValidos(Simbolo::B)) {
        maquina.realizarMovimientoComputadora(juego);
        juego.cambiarUsuario();
      }
    }
    break;
  case 3:
    // Máquina vs Máquina
    while (juego.tieneMovimientosValidos(Simbolo::N) ||
           juego.tieneMovimientosValidos(Simbolo::B)) {
      gui.imprimirTablero(juego);
      if (juego.getUsuarioActual() == Simbolo::N &&
          juego.tieneMovimientosValidos(Simbolo::N)) {
        maquina.realizarMovimientoComputadora(juego);
      } else if (juego.getUsuarioActual() == Simbolo::B &&
                 juego.tieneMovimientosValidos(Simbolo::B)) {
        maquina.realizarMovimientoComputadora(juego);
      }
      juego.cambiarUsuario();
    }
    break;
  default:
    cout << "Opción no válida. Saliendo del juego." << endl;
    break;
  }

  // Mostrar el resultado final
  gui.imprimirTablero(juego);
  int piezasNegras = 0, piezasBlancas = 0;
  for (int i = 0; i < juego.getTamanio(); ++i) {
    for (int j = 0; j < juego.getTamanio(); ++j) {
      if (juego.getTablero()[i][j] == Pieza::Blanco) {
        piezasBlancas++;
      } else if (juego.getTablero()[i][j] == Pieza::Negro) {
        piezasNegras++;
      }
    }
  }

  cout << "Cantidad de Piezas Negras: " << piezasNegras << endl;
  cout << "Cantidad de Piezas Blancas: " << piezasBlancas << endl;

  if (piezasBlancas > piezasNegras) {
    cout << "El ganador es el jugador de Piezas Blancas!!!" << endl;
  } else if (piezasNegras > piezasBlancas) {
    cout << "El ganador es el jugador de Piezas Negras!!!" << endl;
  } else {
    cout << "El juego es un empate!!!" << endl;
  }

  return 0;
}
