#include "camera.h"



Camera::Camera(const Vec3& o, const Vec3& d, const Vec3& v_hori, const Vec3& v_vert) :
	origem_visao {o}, destino_visao {d}, vet_h {v_hori}, vet_v {v_vert} {}

Raio Camera::tracejar_raio(float x, float y) const {
	Vec3 origem = destino_visao + (vet_h * x) + (vet_v * y);
	return Raio(origem, origem - origem_visao);
}