#include "esfera.h"
#include "material.h"
#include "intersecao.h"



Esfera::Esfera() :
	centro {Vec3(0, 0, 0)}, raio {0.0f}, cor {Cor(0, 0, 0)}, material {nullptr} {}

Esfera::Esfera(const Vec3& cen, float r, const Cor& c, Material* m) :
	centro {cen}, raio {r}, cor {c}, material {m} { }

Vec3 Esfera::normal(const Vec3& p) const {
	return (p - centro).normalizar();
}

Cor Esfera::get_cor() const {
	return cor;
}

Vec3* Esfera::interceptar(const Raio& r) const {
	Vec3 vet_dir = r.direcao;

	float a = vet_dir.produto_escalar(vet_dir);
	float b = (2 * r.origem.produto_escalar(vet_dir)) - (2 * centro.produto_escalar(vet_dir));	
	float c = r.origem.produto_escalar(r.origem) - (2 * r.origem.produto_escalar(centro)) + centro.produto_escalar(centro) - (raio * raio);

	float delta = (b * b) - (4 * a * c);

	if (delta < 0.0f) {
		return nullptr;
	} else {
		if (delta == 0.0f) {
			float raiz = -b / (2.0f * a);

			return new Vec3(r.ponto_no_parametro(raiz));
		} else {
			float raiz = (-b - std::sqrtf(delta)) / (2.0f * a);

			return new Vec3(r.ponto_no_parametro(raiz));
		}
	}
}

Raio Esfera::dispersar_raio(const Raio& raio, const ObjIntersecao& obj) const {
	return  material->dispersar(raio, obj);
}

Vec3 Esfera::get_centro() const {
	return centro;
}
