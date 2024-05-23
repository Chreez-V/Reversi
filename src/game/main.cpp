#include "../GUI/menu.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;
/*
  Esta clase contiene una notacion asintota de Big O (n^2) + big 0 n = (n^2)
*/
int main() 
{
  Reversi juego;
  string decision;

  GUI::mostrarMensaje("Quieres jugar una partida contra la computadora? (S/N)");
  cin >> decision;

  if (decision == "N" || decision == "n") 
  {
    GUI::mostrarMensaje("Okey, pa q inicias el programa entonse?, chauuuu!!!");
  } 
  else 
  {
    while (juego.tieneMovimientosValidos(Simbolo::N) || juego.tieneMovimientosValidos(Simbolo::B))  // Big O (n)
    {
      GUI::imprimirTablero(juego); //n^2
      if (juego.tieneMovimientosValidos(juego.getUsuarioActual())) 
      {
        juego.realizarMovimiento(); //n
      } 
      else
       {
        string mensaje = "No hay movimientos válidos para el jugador de piezas ";
        mensaje += (juego.getUsuarioActual() == Simbolo::N ? "Negras" : "Blancas") + string(". Turno pasado.");
        GUI::mostrarMensaje(mensaje);
        juego.cambiarUsuario();
      }
    }

    GUI::imprimirTablero(juego);
    int piezasNegras = 0, piezasBlancas = 0;

    for (const auto &fila : juego.getTablero()) 
    {
      for (const auto &celda : fila)                    // Big O (n^2)
      {
        celda == Pieza::Blanco ? piezasBlancas++ : piezasNegras++;
      }
    }

    string ganador = (piezasBlancas > piezasNegras) ? "el jugador de Piezas Blancas!!!" : "el jugador de Piezas Negras!!!";
    GUI::mostrarMensaje("\nEl ganador es " + ganador);
  }

  system("pause");
  return 0;
}
