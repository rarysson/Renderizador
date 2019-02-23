#include "cena.h"
#include <limits>

Cena::Cena(const std::vector<Esfera>& e, const std::vector<Luz>& l) : 
	lista_esferas {e}, lista_luzes {l} {}

void Cena::adicionar_esfera(const Esfera& e) {
	lista_esferas.push_back(e);
}

void Cena::adicionar_luz(const Luz& l) {
	lista_luzes.push_back(l);
}

ObjIntersecao Cena::tracejar_raio(const Raio& raio, const Esfera& esf_inter) {
	ObjIntersecao obj;

	float menor_distancia = static_cast<float>(INT32_MAX);

	for (auto esfera : lista_esferas) {
		if (esfera.get_centro() == esf_inter.get_centro()) {
			continue;
		}

		Vec3* ponto_interceptado = esfera.interceptar(raio);

		if (ponto_interceptado != nullptr) {
			Vec3 vd = *ponto_interceptado - raio.origem;
			float dist = vd.modulo();

			if (dist < menor_distancia) {
				obj.objeto = esfera;
				obj.ponto_interceptado = *ponto_interceptado;
				obj.interceptou = true;
				menor_distancia = dist;
			}

			delete ponto_interceptado;
		}
	}

	return obj;
}

Cor Cena::determinar_cor_objeto(ObjIntersecao& obj, const Raio& raio, int profundidade) {
	if (!obj.interceptou) {
		return Cor(0.0f, 0.0f, 0.0f);
	} else {
		Cor c;

		for (auto luz : lista_luzes) {
			if (objeto_visivel_a_luz(obj, luz)) {
				Vec3 l = (luz.get_posicao() - obj.ponto_interceptado).normalizar();
				Vec3 e = obj.objeto.normal(obj.ponto_interceptado);

				float cos = l.produto_escalar(e);

				if (cos < 0.0f)
					cos = 0.0f;

				c += (obj.objeto.get_cor() * luz.get_cor()) * cos;
			}
		}

		if (profundidade == 0) {
			return c;
		} else {
			Raio r = obj.objeto.dispersar_raio(raio, obj);
			obj = tracejar_raio(r, obj.objeto);

			return c + determinar_cor_objeto(obj, r, profundidade - 1);
		}
	}
}

bool Cena::objeto_visivel_a_luz(const ObjIntersecao& obj, const Luz& luz) {
	Raio r = Raio(obj.ponto_interceptado, luz.get_posicao() - obj.ponto_interceptado);

	for (auto esfera : lista_esferas) {
		if (esfera.get_centro() == obj.objeto.get_centro()) {
			continue;
		}

		Vec3* ponto_l = esfera.interceptar(r);

		if (ponto_l != nullptr) {
			float raiz = (*ponto_l - luz.get_posicao()).modulo() / r.direcao.modulo();

			delete ponto_l;

			if (raiz >= 0.0f && raiz <= 1.0f) {
				return false;
			}
		}
	}

	return true;
}