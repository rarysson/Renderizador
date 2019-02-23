#ifndef HEADER_MATERIAL
#define HEADER_MATERIAL

#include "raio.h"
#include "intersecao.h"

class Esfera;



class Material {
public:
	virtual Raio dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) = 0;
};

class Liso : public Material {
public:
	Raio dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) override;
};

class Difuso : public Material {
public:
	Raio dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) override;
};

class Opaco : public Material {
public:
	Raio dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) override;
};

#endif