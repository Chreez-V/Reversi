#include "menu.hpp"
#include <iostream>

void GUI::imprimirTablero(const Reversi &juego) {
  system("cls");
  const auto &tablero = juego.getTablero();
  int size = juego.getTamanio();

  std::cout << "  ";
  for (int i = 0; i < size; i++)
    std::cout << i + 1 << " ";
  std::cout << std::endl;

  for (int i = 0; i < size; i++) {
    std::cout << i + 1 << " ";
    for (int j = 0; j < size; j++) {
      switch (tablero[i][j]) {
      case Pieza::Vacio:
        std::cout << ".";
        break;
      case Pieza::Negro:
        std::cout << "N";
        break;
      case Pieza::Blanco:
        std::cout << "B";
        break;
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}

void GUI::mostrarMensaje(const std::string &mensaje) {
  std::cout << mensaje << std::endl;
}
