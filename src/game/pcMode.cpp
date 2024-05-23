#include "pcMode.hpp"
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include <vector>

using namespace std;

PcMode::PcMode() {}

void PcMode::realizarMovimientoComputadora(Reversi &juego) {
  std::cout << std::endl << "Turno de la Computadora." << std::endl;
  std::vector<std::pair<int, int>> movimientosValidos =
      juego.obtenerMovimientosValidos();

  bool movValid = false;
  while (!movValid) {
    int fila = rand() % juego.getTamanio();
    int columna = rand() % juego.getTamanio();
    if (juego.movimientoValido(fila, columna)) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      juego.colocarPieza(fila, columna);
      juego.cambiarFichas(fila, columna);
      movValid = true;
    }
  }
}
