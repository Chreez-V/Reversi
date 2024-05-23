#include "pcMode.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void PcMode::realizarMovimientoComputadora(Reversi &juego) 
{
 cout << endl << "Turno de la Computadora." << endl;
  vector<pair<int, int>> movimientosValidos =
      juego.obtenerMovimientosValidos();

  if (!movimientosValidos.empty())
   {
    srand(time(0));
    int indice = rand() % movimientosValidos.size();
    int fila = movimientosValidos[indice].first;
    int columna = movimientosValidos[indice].second;

    juego.colocarPieza(fila, columna);
    juego.cambiarFichas(fila, columna);
    juego.cambiarUsuario();
  } else {
    cout << "La computadora no tiene movimientos válidos. Turno pasado."
              << endl;
    juego.cambiarUsuario();
  }
}
