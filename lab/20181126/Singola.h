#if !defined(SINGOLA_H)
#define SINGOLA_H

#include "Camera.h"

class Singola : public Camera {
  int calcolaCosto() override { return 30; }
  int tipologia() override { return 1; }
};
#endif  // SINGOLA_H
