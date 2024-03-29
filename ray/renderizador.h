#ifndef HEADER_RENDERIZADOR
#define HEADER_RENDERIZADOR

#include "cena.h"
#include "camera.h"
#include "imagem.h"
#include "intersecao.h"

#include <vector>
#include <string>
#include <fstream>




class Renderizador {
private:
	Cena cena;
	Camera camera;
	Imagem img;
	std::vector<std::vector<Cor>> buffer_pixel;

public:
	Renderizador(const Cena& cen, const Camera& cam, const Imagem& i);

	void gerar_imagem(const std::string& nome_arquivo);

	void renderizar_cena(int numero_amostras, int profundidade_dispersao);
};

#endif