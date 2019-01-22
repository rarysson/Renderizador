#include "renderizador.h"
#include "material.h"



int main() {
	std::vector<Luz> luzes;
	std::vector<Esfera> esferas;

	luzes.push_back(Luz(Vec3(0, 0, 10), Cor(1, 1, 1)));
	esferas.push_back(Esfera(Vec3(0, 0, -10), 3, Cor(1, 1, 1), new Liso()));
	esferas.push_back(Esfera(Vec3(0, 3, -10), 2, Cor(1, 1, 1), new Liso()));

	Cena cena(esferas, luzes);
	Camera cam(Vec3(0, 0, 1), Vec3(0, 0, 0), Vec3(1, 0, 0), Vec3(0, 1, 0));
	Imagem img(600, 600);

	Renderizador mundo(cena, cam, img);

	mundo.renderizar_cena(1, 1);
	mundo.gerar_imagem("ray");
	

	return 0;
}