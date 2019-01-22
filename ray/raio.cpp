#include "raio.h"



Raio::Raio(const Vec3& o, const Vec3& d) : 
	origem {o}, destino {d} {}

Vec3 Raio::ponto_no_parametro(float t) const {
	return origem + (t * get_vetor());
}

Vec3 Raio::get_vetor() const {
	return destino - origem;
}