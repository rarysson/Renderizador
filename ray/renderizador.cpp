#include "renderizador.h"



Renderizador::Renderizador(const Cena& cen, const Camera& cam, const Imagem& i) :
cena {cen}, camera {cam}, img {i} {
	for (int j = 0; j < img.altura; ++j) {
		std::vector<Cor> v;

		for (int i = 0; i < img.largura; ++i) {
			v.push_back(Cor());
		}

		buffer_pixel.push_back(v);
	}
}

void Renderizador::gerar_imagem(const std::string& nome_arquivo) {
	std::string nome = nome_arquivo + ".ppm";
	std::ofstream imagem(nome);

	imagem << "P3\n" << img.largura << " " << img.altura << "\n255\n";

	for (int j = 0; j < img.altura; ++j) {
		for (int i = 0; i < img.largura; ++i) {
			imagem << static_cast<int>(255.99f * buffer_pixel[i][j].r) << ' ' 
					<< static_cast<int>(255.99f * buffer_pixel[i][j].g) << ' ' 
					<< static_cast<int>(255.99f * buffer_pixel[i][j].b) << '\n';
		}
	}

	imagem.close();
}

void Renderizador::renderizar_cena(int numero_amostras, int profundidade_dispersao) {

	for (int j = 0; j < img.altura; ++j) {

		for (int i = 0; i < img.largura; ++i) {
			float alfa = (2.0f * j) / (img.largura - 1.0f) - 1.0f;
			float beta = (-2.0f * ((i - (img.altura - 1.0f)) / (img.altura - 1.0f)) - 1.0f);

			Raio r = camera.tracejar_raio(alfa, beta);
			Cor c;			

			for (int k = 0; k < numero_amostras; ++k) {
				ObjIntersecao obj = cena.tracejar_raio(r);

				if (obj.interceptou) {
					c += cena.determinar_cor_objeto(obj, r, profundidade_dispersao);
				} else {
					c = Cor(0.5f, 0.5f, 0.5f);
					break;
				}
			}

			c /= numero_amostras;
			c.saturar();
			buffer_pixel[j][i] = c;
		}
	}
}