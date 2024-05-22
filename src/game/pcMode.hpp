#include "Reversi.hpp"
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;

class PcMode {

public:
  PcMode();
  void realizarMovimientoComputadora(Reversi &juego);
};
