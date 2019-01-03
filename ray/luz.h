#ifndef HEADER_LUZ
#define HEADER_LUZ

#include "cor.h"
#include "vec.h"



struct Luz {
	Vec3 posicao;
	Cor cor;

	Luz();

	Luz(const Vec3& v, const Cor& c);
};

#endif