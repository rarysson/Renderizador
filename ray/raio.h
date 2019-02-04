#ifndef HEADER_RAIO
#define HEADER_RAIO

#include "vec.h"


struct Raio {
	Vec3 origem;
	Vec3 direcao;

	Raio();

	Raio(const Vec3& o, const Vec3& d);

	Vec3 ponto_no_parametro(float t) const;

	Vec3 destino() const;
};

#endif