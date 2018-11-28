#if !defined(TRIPLA_H)
#define TRIPLA_H

#include "Camera.h"

class Tripla : public Camera {
 public:
  int calcolaCosto() override { return 75; }
  int tipologia() override { return 3; }
};
#endif  // TRIPLA_H
