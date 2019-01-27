#include "material.h"
#include "esfera.h"
#include "util.h"

#include <iostream>

Raio Liso::dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) {
	Vec3 l = (raio_origem.origem - raio_origem.destino).normalizar();
	Vec3 n = esfera_interceptada.normal(raio_origem.destino);
	Vec3 vet_re = ((2 * n.produto_escalar(l)) * n) - l;
	/*std::cout << vet_re.x << "|" << vet_re.y << "|" << vet_re.z << "\n";
	std::cout << (raio_origem.destino + vet_re).x << "|" << (raio_origem.destino + vet_re).y << "|" << (raio_origem.destino + vet_re).z << "\n";
	std::cin.get();*/
	return Raio(raio_origem.destino, raio_origem.destino + vet_re);
	/*Vec3 e = raio_origem.destino - esfera_interceptada.get_centro();
	Vec3 o = Vec3(0, 0, 1);

	float p = e.produto_escalar(o) / o.produto_escalar(o);

	return Raio(raio_origem.destino, (2 * e * p) - o);*/
}

Raio Difuso::dispersar(const Raio& raio_origem, const Esfera& esfera_interceptada) {
	Vec3 v = raio_origem.destino + esfera_interceptada.normal(raio_origem.destino) + ut::int_aleatorio(-1, 1);
	return Raio(raio_origem.destino, v);
}