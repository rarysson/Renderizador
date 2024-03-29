#include "renderizador.h"
#include "material.h"



int main() {
	std::vector<Luz> luzes;
	std::vector<Esfera> esferas;

	luzes.push_back(Luz(Vec3(0, 20, -50), Cor(1, 1, 1)));
	//esferas.push_back(Esfera(Vec3(-2, 0, -5), 2, Cor(1, 0, 0), new Difuso()));
	//esferas.push_back(Esfera(Vec3(2, 2, -5), 2, Cor(0, 1, 0), new Difuso()));
	esferas.push_back(Esfera(Vec3(0, -101, -1), 100, Cor(0, 1, 0), new Opaco()));
	esferas.push_back(Esfera(Vec3(1, 2, -5), 2, Cor(0, 1, 1), new Difuso()));

	Cena cena(esferas, luzes);
	Camera cam(Vec3(0, 0, 1), Vec3(0, 0, 0), Vec3(1, 0, 0), Vec3(0, 1, 0));
	Imagem img(600, 600);

	Renderizador mundo(cena, cam, img);

	mundo.renderizar_cena(1, 5);
	mundo.gerar_imagem("ray");
	

	return 0;
}