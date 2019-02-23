#ifndef HEADER_LUZ
#define HEADER_LUZ

#include "cor.h"
#include "vec.h"



class Luz {
private:
	Vec3 posicao;
	Cor cor;

public:
	Luz();

	Luz(const Vec3& v, const Cor& c);

	Vec3 get_posicao() const;

	Cor get_cor() const;
};

#endif