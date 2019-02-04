#include "material.h"
#include "esfera.h"
#include "util.h"

#include <iostream>

Raio Liso::dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) {
	Vec3 l = (raio_origem.origem - obj_interceptado.ponto_interceptado).normalizar();
	Vec3 n = obj_interceptado.esfera.normal(obj_interceptado.ponto_interceptado);
	Vec3 vet_re = (2 * l.produto_escalar(n) * n) - l;

	return Raio(obj_interceptado.ponto_interceptado, vet_re);
}

Raio Difuso::dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) {
	return Raio();
}