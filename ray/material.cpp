#include "material.h"
#include "esfera.h"
#include "util.h"

#include <iostream>

Raio Liso::dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) {
	Vec3 l = (raio_origem.origem - obj_interceptado.ponto_interceptado).normalizar();
	Vec3 n = obj_interceptado.objeto.normal(obj_interceptado.ponto_interceptado);
	Vec3 vet_re = (2 * l.produto_escalar(n) * n) - l;

	return Raio(obj_interceptado.ponto_interceptado, vet_re);
}

Raio Difuso::dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) {
	Vec3 ponto_aleatorio;

	do {
		ponto_aleatorio = Vec3(ut::float_aleatorio(-1.0f, 1.0f),
							   ut::float_aleatorio(-1.0f, 1.0f),
							   ut::float_aleatorio(-1.0f, 1.0f));
	} while (ponto_aleatorio.modulo() >= 1.0f);

	Vec3 point = obj_interceptado.ponto_interceptado + obj_interceptado.objeto.normal(obj_interceptado.ponto_interceptado) + ponto_aleatorio;

	return Raio(obj_interceptado.ponto_interceptado, point - obj_interceptado.ponto_interceptado);
}

Raio Opaco::dispersar(const Raio& raio_origem, const ObjIntersecao& obj_interceptado) {
	return raio_origem;
}
