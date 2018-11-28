
#if !defined(DOPPIA_H)
#define DOPPIA_H

#include "Camera.h"

class Doppia : public Camera {
 public:
  int calcolaCosto() override { return 50; }
  int tipologia() override { return 2; }
};

#endif  // DOPPIA_H
