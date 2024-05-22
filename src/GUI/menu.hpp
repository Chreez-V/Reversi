#ifndef GUI_HPP
#define GUI_HPP

#include "../game/pcMode.hpp"
#include <string>

class GUI {
public:
  static void imprimirTablero(const Reversi &juego);
  static void mostrarMensaje(const std::string &mensaje);
};

#endif // GUI_HPP
