#ifndef PROYECTO1_HPP
#define PROYECTO1_HPP

#include <stdlib.h>
#include <vector>

enum class Pieza { Vacio, Blanco, Negro };
enum class Usuario { N, B };

class Reversi {
private:
  std::vector<std::vector<Pieza>> tablero;
  Usuario usuario;

  const int size = 8;

public:
  Reversi();

  void inicializarTablero(); // inicia el tablero del juego
  void imprimirTablero();
  void realizarMovimiento();
  bool movimientoValido(int fila, int columna);
  void colocarPieza(int fila, int columna);
  void cambiarFichas(int fila, int columna);
  void cambiarUsuario();
  bool tieneMovimientosValidos(Usuario usuarioActual);

  void jugarPartida();
};

#endif
