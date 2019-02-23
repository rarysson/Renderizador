#ifndef HEADER_CAMERA
#define HEADER_CAMERA

#include "vec.h"
#include "raio.h"



class Camera {
private:
	Vec3 origem_visao;
	Vec3 destino_visao;
	Vec3 vet_horizontal;
	Vec3 vet_vertical;
public:
	Camera(const Vec3& origem, const Vec3& destino, const Vec3& v_hori, const Vec3& v_vert);

	Raio tracejar_raio(float x, float y) const;
};

#endif