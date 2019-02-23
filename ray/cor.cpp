#include "cor.h"



Cor::Cor() {}

Cor::Cor(float r_, float g_, float b_) : 
	r {r_}, g {g_}, b {b_} {}

void Cor::saturar() {
	if (r > 1.0f)
		r = 1.0f;

	if (g > 1.0f)
		g = 1.0f;

	if (b > 1.0f)
		b = 1.0f;
}

Cor operator*(const Cor & vlh, const Cor & vrh) {
	return Cor(vlh.r * vrh.r, vlh.g * vrh.g, vlh.b * vrh.b);
}

Cor operator*(const Cor & vlh, float vrh) {
	return Cor(vlh.r * vrh, vlh.g * vrh, vlh.b * vrh);
}

Cor operator+(const Cor& vlh, const Cor& vrh) {
	return Cor(vlh.r + vrh.r, vlh.g + vrh.g, vlh.b + vrh.b);
}

Cor& Cor::operator+=(const Cor& vrh) {
	r += vrh.r;
	g += vrh.g;
	b += vrh.b;

	return *this;
}

Cor& Cor::operator/=(int vrh) {
	r /= vrh;
	g /= vrh;
	b /= vrh;

	return *this;
}

Cor& Cor::operator*=(const Cor& vrh) {
	r *= vrh.r;
	g *= vrh.g;
	b *= vrh.b;

	return *this;
}

bool Cor::operator==(const Cor& vrh) const {
	return r == vrh.r && g == vrh.g && b == vrh.b;
}

bool Cor::operator!=(const Cor& vrh) const {
	return !(*this == vrh);
}