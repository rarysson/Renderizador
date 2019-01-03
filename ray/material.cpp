#include "material.h"
#include "esfera.h"



Raio Liso::dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) {
	Vec3 l = (raio_origem.destino - raio_origem.origem).normalizar();
	Vec3 n = esfera_interceptada.normal(raio_origem.destino);

	return Raio(raio_origem.destino, (2 * n.produto_escalar(l))*n - l);
}

Raio Difuso::dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) {
	return Raio(Vec3(), Vec3());
}