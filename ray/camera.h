#ifndef HEADER_CAMERA
#define HEADER_CAMERA

#include "vec.h"
#include "raio.h"




class Camera {
private:
	Vec3 origem_visao;
	Vec3 destino_visao;
	Vec3 vet_h;
	Vec3 vet_v;
public:
	Camera(const Vec3& o, const Vec3& d, const Vec3& h, const Vec3& v);

	Raio tracejar_raio(float x, float y) const;
};

#endif