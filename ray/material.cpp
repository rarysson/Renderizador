#include "material.h"
#include "esfera.h"
#include "util.h"

#include <iostream>

Raio Liso::dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) {
	Vec3 l = raio_origem.direcao.normalizar();
	Vec3 n = esfera_interceptada.normal(raio_origem.destino());
	Vec3 vet_re = (2 * l.produto_escalar(n) * n) - l;

	return Raio(raio_origem.destino(), vet_re);
}

Raio Difuso::dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) {
	Vec3 v = raio_origem.destino() + esfera_interceptada.normal(raio_origem.destino()) + ut::int_aleatorio(-1, 1);
	return Raio(raio_origem.destino(), v);
}