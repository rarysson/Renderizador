#include "cena.h"

Cena::Cena(const std::vector<Esfera>& e, const std::vector<Luz>& l) : 
	lista_esferas {e}, lista_luzes {l} {}

void Cena::adicionar_esfera(const Esfera& e) {
	lista_esferas.push_back(e);
}

void Cena::adicionar_luz(const Luz& l) {
	lista_luzes.push_back(l);
}

ObjIntersecao Cena::tracejar_raio(const Raio& raio) {
	ObjIntersecao obj;

	obj.ponto_interceptado = Vec3(10000.0f, 10000.0f, 10000.0f);

	Vec3 vet_dirt = obj.ponto_interceptado - raio.origem;
	float menor_distancia = vet_dirt.modulo();

	for (auto esfera : lista_esferas) {
		Vec3* ponto_interceptado = esfera.interceptar(raio);

		if (ponto_interceptado != nullptr) {
			Vec3 vd = *ponto_interceptado - raio.origem;
			float dist = vd.modulo();

			if (dist < menor_distancia) {
				obj.esfera = esfera;
				obj.ponto_interceptado = *ponto_interceptado;
				obj.interceptou = true;
				menor_distancia = dist;
			}

			delete ponto_interceptado;
		}
	}

	return obj;
}

Cor Cena::determinar_cor_objeto(const ObjIntersecao& obj) {
	Cor c;
	int n = 1;

	for (auto luz : lista_luzes) {
		if (objeto_visivel_a_luz(obj.ponto_interceptado, luz)) {
			c += luz.cor;
			++n;
		}
	}

	if (c != Cor(0.0f, 0.0f, 0.0f)) {
		c /= n;
	}

	return c;
}

bool Cena::objeto_visivel_a_luz(const Vec3& ponto, const Luz& luz) {
	Raio r = Raio(ponto, luz.posicao);

	for (auto esfera : lista_esferas) {
		Vec3* ponto_l = esfera.interceptar(r);

		if (ponto_l != nullptr) {
			delete ponto_l;
			return false;
		}
	}

	return true;
}