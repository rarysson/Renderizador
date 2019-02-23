#ifndef HEADER_ESFERA
#define HEADER_ESFERA

#include "vec.h"
#include "cor.h"
#include "raio.h"


class Material;
class ObjIntersecao;


class Esfera {
private:
	Vec3 centro;
	float raio;
	Cor cor;
	Material* material;

public:
	explicit Esfera();

	Esfera(const Vec3& cen, float r, const Cor& c, Material* m);

	Vec3 normal(const Vec3& p) const;

	Vec3* interceptar(const Raio& r) const;

	Raio dispersar_raio(const Raio& raio, const ObjIntersecao& obj) const;

	Vec3 get_centro() const;

	float get_raio() const;

	Cor get_cor() const;
};

#endif