#include "menu.hpp"
#include <iostream>

using namespace std;

/*
  Esta clase tiene un big O (n^2)
*/
void GUI::menu() {
  cout << "Selecciona el modo de juego:" << endl;
  cout << "1. Jugador vs Jugador" << endl;
  cout << "2. Jugador vs Máquina" << endl;
  cout << "3. Máquina vs Máquina" << endl;
  cout << "Ingrese su opción: ";
}

// esta funcion posee un bigO(n^2)
void GUI::imprimirTablero(const Reversi &juego) {
  system("cls");
  const auto &tablero = juego.getTablero();
  int size = juego.getTamanio();

  cout << "  ";
  for (int i = 0; i < size; i++)
    cout << i + 1 << " ";
  cout << endl;

  for (int i = 0; i < size; i++) {
    cout << i + 1 << " ";
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
    cout << endl;
  }
}

// big O (n)
void GUI::mostrarMensaje(const string &mensaje) { cout << mensaje << endl; }
