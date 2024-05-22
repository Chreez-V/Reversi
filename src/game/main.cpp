#include "../GUI/menu.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  Reversi juego;
  std::string decision;

  GUI::mostrarMensaje("Quieres jugar una partida contra la computadora? (S/N)");
  std::cin >> decision;

  if (decision == "N" || decision == "n") {
    GUI::mostrarMensaje("Okey, pa q inicias el programa entonse?, chauuuu!!!");
  } else {
    while (juego.tieneMovimientosValidos(Simbolo::N) ||
           juego.tieneMovimientosValidos(Simbolo::B)) {
      GUI::imprimirTablero(juego);
      if (juego.tieneMovimientosValidos(juego.getUsuarioActual())) {
        juego.realizarMovimiento();
      } else {
        std::string mensaje =
            "No hay movimientos válidos para el jugador de piezas ";
        mensaje +=
            (juego.getUsuarioActual() == Simbolo::N ? "Negras" : "Blancas") +
            std::string(". Turno pasado.");
        GUI::mostrarMensaje(mensaje);
        juego.cambiarUsuario();
      }
    }

    GUI::imprimirTablero(juego);
    int piezasNegras = 0, piezasBlancas = 0;
    const auto &tablero = juego.getTablero();

    for (const auto &fila : tablero) {
      for (const auto &celda : fila) {
        if (celda == Pieza::Blanco) {
          piezasBlancas++;
        } else if (celda == Pieza::Negro) {
          piezasNegras++;
        }
      }
    }

    std::string ganador = (piezasBlancas > piezasNegras)
                              ? "el jugador de Piezas Blancas!!!"
                              : "el jugador de Piezas Negras!!!";
    GUI::mostrarMensaje("\nEl ganador es " + ganador);
  }

  system("pause");
  return 0;
}
