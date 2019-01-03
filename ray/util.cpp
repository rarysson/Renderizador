#include "util.h"



int ut::int_aleatorio(int inicio, int fim) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(inicio, fim);

	return dist(gen);
}

float ut::float_aleatorio(float inicio, float fim) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(inicio, fim);

	return dist(gen);
}