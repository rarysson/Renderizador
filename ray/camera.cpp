#include "camera.h"



Camera::Camera(const Vec3& o, const Vec3& d, const Vec3& h, const Vec3& v) :
	origem_visao {o}, destino_visao {d}, vet_h {h}, vet_v {v} {}

Raio Camera::tracejar_raio(float x, float y) const {
	return Raio(destino_visao, (destino_visao + (vet_h * x) + (vet_v * y)) - origem_visao);
}