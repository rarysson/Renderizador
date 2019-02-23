#ifndef HEADER_INTERSECAO
#define HEADER_INTERSECAO

#include "esfera.h"
#include "vec.h"



class ObjIntersecao {
public:
	Esfera objeto;
	Vec3 ponto_interceptado;
	bool interceptou = false;

public:
	ObjIntersecao();
};

#endif