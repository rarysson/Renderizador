#ifndef HEADER_VEC
#define HEADER_VEC

#include <cmath>



struct Vec3 {
public:
	float x = 0;
	float y = 0;
	float z = 0;

public:
	Vec3();

	Vec3(float x_, float y_, float z_);

	float produto_escalar(const Vec3& v) const;

	friend Vec3 operator+(const Vec3& vlh, const Vec3& vrh);

	friend Vec3 operator+(const Vec3& vlh, float vrh);

	friend Vec3 operator-(const Vec3& vlh, const Vec3& vrh);

	Vec3 operator*(float v) const;

	friend Vec3 operator*(float vlh, const Vec3& vrh);

	friend Vec3 operator/(const Vec3& vlh, float vrh);

	friend bool operator==(const Vec3& vlh, const Vec3& vrh);

	Vec3 normalizar() const;

	float modulo() const;
};

#endif