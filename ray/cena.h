#ifndef HEADER_CENA
#define HEADER_CENA

#include "esfera.h"
#include "luz.h"
#include "util.h"
#include "intersecao.h"
#include <vector>




class Cena {
private:
	std::vector<Luz> lista_luzes;
	std::vector<Esfera> lista_esferas;

public:
	Cena(const std::vector<Esfera>& e, const std::vector<Luz>& l); 

	void adicionar_esfera(const Esfera& e);

	void adicionar_luz(const Luz& l);

	ObjIntersecao tracejar_raio(const Raio& raio, const Esfera& esf_inter = Esfera());

	Cor determinar_cor_objeto(ObjIntersecao& obj, const Raio& raio, int profundidade);

private:
	bool objeto_visivel_a_luz(const ObjIntersecao& obj, const Luz& luz);
};

#endif