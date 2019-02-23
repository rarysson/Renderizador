#ifndef HEADER_RAIO
#define HEADER_RAIO

#include "vec.h"


class Raio {
public:
	Vec3 origem;
	Vec3 direcao;

public:
	Raio();

	Raio(const Vec3& o, const Vec3& d);

	Vec3 ponto_no_parametro(float t) const;

	Vec3 destino() const;
};

#endif