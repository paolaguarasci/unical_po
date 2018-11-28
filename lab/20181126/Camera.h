#if !defined(CAMERA_H)
#define CAMERA_H
class Camera {
 public:
  virtual ~Camera() {}
  virtual int calcolaCosto() = 0;
  virtual int tipologia() = 0;
};
#endif  // CAMERA_H
