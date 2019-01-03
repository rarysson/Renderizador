#ifndef HEADER_MATERIAL
#define HEADER_MATERIAL

#include "raio.h"

class Esfera;



struct Material {
	virtual Raio dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) = 0;
};

struct Liso : Material {
	Raio dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) override;
};

struct Difuso : Material {
	Raio dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) override;
};

#endif