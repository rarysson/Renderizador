#ifndef HEADER_COR
#define HEADER_COR

#include "vec.h"




struct Cor {
public:
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

public:
	Cor();

	Cor(float r_, float g_, float b_);

	Cor soma_com_saturacao(const Cor& c) const;

	void saturar();

	friend Cor operator*(const Cor& vlh, const Cor& vrh);

	friend Cor operator*(const Cor& vlh, float vrh);

	friend Cor operator+(const Cor& vlh, const Cor& vrh);

	Cor& operator+=(const Cor& vrh);

	Cor& operator/=(int vrh);

	Cor& operator*=(const Cor& vrh);

	bool operator==(const Cor& vrh) const;

	bool operator!=(const Cor& vrh) const;
};

#endif