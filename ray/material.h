#ifndef HEADER_MATERIAL
#define HEADER_MATERIAL

#include "raio.h"
#include "intersecao.h"

class Esfera;



struct Material {
	virtual Raio dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) = 0;
};

struct Liso : Material {
	Raio dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) override;
};

struct Difuso : Material {
	Raio dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) override;
};

#endif