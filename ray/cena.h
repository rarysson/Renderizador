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

	/*void gerar_cena_aleatoria(int quantidade_esferas, int quantidade_luzes) {
		for (int i = 0; i < quantidade_esferas; ++i) {
			Esfera e
		}
	}*/

	ObjIntersecao tracejar_raio(const Raio& raio);

	Cor determinar_cor_objeto(const ObjIntersecao& obj);

private:
	bool objeto_visivel_a_luz(const Vec3& ponto, const Luz& luz);
};

#endif