CXX=g++
DEPS = camera.h cena.h cor.h esfera.h imagem.h intersecao.h luz.h material.h raio.h renderizador.h util.h vec.h
OBJ = camera.o cena.o cor.o esfera.o imagem.o intersecao.o luz.o material.o raio.o renderizador.o util.o vec.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $<

ray: main.cpp $(OBJ)
	$(CXX) -o $@ $^

clean:
	rm $(OBJ) ray
