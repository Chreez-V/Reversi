#include "pcMode.hpp"
#include "Proyecto1.hpp"

void realizarMovimientoComputadora(vector<pair<int, int>> movimientos) {

  vector<pair<int, int>> movimientosComputadora = movimientos;
  if (!movimientosComputadora.empty()) {
    srand(time(0));
    int indice = rand() % movimientosComputadora.size();
    int fila = movimientosComputadora[indice].first;
    int columna = movimientosComputadora[indice].second;

    Reversi::colocarPieza(fila, columna);
    Reversi::cambiarFichas(fila, columna);
    Reversi::cambiarUsuario();
  } else {
    Reversi::cambiarUsuario();
  }
}
