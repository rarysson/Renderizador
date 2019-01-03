#ifndef HEADER_INTERSECAO
#define HEADER_INTERSECAO

#include "esfera.h"
#include "vec.h"



struct ObjIntersecao {
	Esfera esfera;
	Vec3 ponto_interceptado;
	bool interceptou = false;

	ObjIntersecao();
};

#endif