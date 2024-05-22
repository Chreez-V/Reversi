
#include <vector>
enum class Pieza {
  Vacio,
  Blanco,
  Negro
}; // representa las fichas y los lugares vacios del tablero
enum class Simbolo {
  N,
  B
}; // representan los jugadores (fichas negras y fichas blancas)

enum class TipoUsuario { Humano, Computadora };
class Reversi { // Clase para representar el tablero del juego y las acciones
private:
  std::vector<std::vector<Pieza>> tablero;
  Simbolo simbolo; // usuario inicial
  const std::vector<std::pair<int, int>>
      direcciones; // coleccion de tuplas(pair) para las direcciones
  const int size = 8;
  TipoUsuario tipoUsuario;

public:
  Reversi();

  void inicializarTablero(); // inicia el tablero del juego
  void imprimirTablero();
  void realizarMovimiento();
  bool movimientoValido(int fila, int columna);
  void colocarPieza(int fila, int columna);
  void cambiarFichas(int fila, int columna);
  void cambiarUsuario();
  std::vector<std::pair<int, int>> obtenerMovimientosValidos();
  bool tieneMovimientosValidos(Simbolo simbolo);
  std::vector<std::vector<Pieza>> getTablero() const;
  Simbolo getUsuarioActual() const;
  int getTamanio() const;

  void jugarPartida();
};
