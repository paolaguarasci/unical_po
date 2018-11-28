
#if !defined(SUITE_H)
#define SUITE_H
#include "Camera.h"

class Suite : public Camera {
 public:
  int calcolaCosto() override { return 100; }
  int tipologia() override { return 4; }
};
#endif  // SUITE_H
