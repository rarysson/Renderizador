#include "raio.h"



Raio::Raio() { }

Raio::Raio(const Vec3& o, const Vec3& d) :
	origem {o}, direcao {d} {}

Vec3 Raio::ponto_no_parametro(float t) const {
	return origem + (t * direcao);
}

Vec3 Raio::destino() const {
	return origem + direcao;
}