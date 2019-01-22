#include "vec.h"



Vec3::Vec3() {}

Vec3::Vec3(float x_, float y_, float z_) : 
	x {x_}, y {y_}, z {z_} {}

float Vec3::produto_escalar(const Vec3& v) const {
	return (x * v.x) + (y * v.y) + (z * v.z);
}

Vec3 operator+(const Vec3& vlh, const Vec3& vrh) {
	return Vec3(vlh.x + vrh.x, vlh.y + vrh.y, vlh.z + vrh.z);
}

Vec3 operator+(const Vec3 & vlh, int vrh) {
	return Vec3(vlh.x + vrh, vlh.y + vrh, vlh.z + vrh);
}

Vec3 operator-(const Vec3& vlh, const Vec3& vrh) {
	return Vec3(vlh.x - vrh.x, vlh.y - vrh.y, vlh.z - vrh.z);
}

Vec3 Vec3::operator*(float v) const {
	return Vec3(x * v, y * v, z * v);
}

Vec3 operator*(float vlh, const Vec3& vrh) {
	return Vec3(vrh.x * vlh, vrh.y * vlh, vrh.z * vlh);
}

Vec3 operator/(const Vec3& vlh, float vrh) {
	return Vec3(vlh.x / vrh, vlh.y / vrh, vlh.z / vrh);
}

bool operator==(const Vec3& vlh, const Vec3& vrh) {
	return (vlh.x == vrh.x) && (vlh.y == vrh.y) && (vlh.z == vrh.z);
}

Vec3 Vec3::normalizar() const {
	return (*this) / modulo();
}

float Vec3::modulo() const {
	return std::sqrtf(this->produto_escalar(*this));
}