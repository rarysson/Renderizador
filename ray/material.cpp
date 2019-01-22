#include "material.h"
#include "esfera.h"
#include "util.h"



Raio Liso::dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) {
	Vec3 l = (raio_origem.destino - raio_origem.origem).normalizar();
	Vec3 n = esfera_interceptada.normal(raio_origem.destino);

	return Raio(raio_origem.destino, (2 * n.produto_escalar(l))*n - l);
}

Raio Difuso::dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) {
	Vec3 v = raio_origem.destino + esfera_interceptada.normal(raio_origem.destino) + ut::int_aleatorio(-1, 1);
	return Raio(raio_origem.destino, v);
}