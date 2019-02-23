#include "luz.h"



Luz::Luz() {}

Luz::Luz(const Vec3& v, const Cor& c) : 
	posicao {v}, cor {c} {}

Vec3 Luz::get_posicao() const {
	return posicao;
}

Cor Luz::get_cor() const {
	return cor;
}
