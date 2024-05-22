#include "pcMode.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

void PcMode::realizarMovimientoComputadora(Reversi &juego) {
  std::cout << std::endl << "Turno de la Computadora." << std::endl;
  std::vector<std::pair<int, int>> movimientosValidos =
      juego.obtenerMovimientosValidos();

  if (!movimientosValidos.empty()) {
    srand(time(0));
    int indice = rand() % movimientosValidos.size();
    int fila = movimientosValidos[indice].first;
    int columna = movimientosValidos[indice].second;

    juego.colocarPieza(fila, columna);
    juego.cambiarFichas(fila, columna);
    juego.cambiarUsuario();
  } else {
    std::cout << "La computadora no tiene movimientos válidos. Turno pasado."
              << std::endl;
    juego.cambiarUsuario();
  }
}
