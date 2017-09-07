#include <iostream>
#include <stdlib.h>

using namespace std;

struct Pixel {
	int r, g, b;
};

class Imagem{
 private:	

 	void getpixeis(FILE *arq){
		char tipo[2];
		struct Pixel **aux = NULL;

		fscanf(arq, "%s %d %d\n\n", tipo, &this->largura, &this->altura);
		aux = (struct Pixel **) malloc(sizeof(struct Pixel *)*(this->altura));
		for (int i = 0; i < this->altura; i++) {
			aux[i] = (struct Pixel *) malloc(sizeof(struct Pixel)*(this->largura));
		}
		for (int y = 0; y < this->altura; y++) {
			for (int x = 0; x < this->largura; x++) {
				fscanf(arq, "%d %d %d ", &aux[y][x].r, &aux[y][x].g, &aux[y][x].b);
			}
		}
		this->pixeis = aux;
	}



 	struct Pixel **pixeis;
	int altura, largura;


 public:
 	Imagem(FILE *arq){
 		getpixeis(arq);
 	}
 	struct Pixel getonepixel(int x, int y){
 		return this->pixeis[y][x];
 	}
 	struct Pixel **getAllpixel(){
 		return this->pixeis;
 	}
	int getaltura(){
		return this->altura;
	}
	int getlargura(){
		return this->largura;
	}
};


void save_ppm(struct Pixel **pixel, int heigth, int width, char *nomeArq) {
	
	FILE *arq = fopen(nomeArq, "w");
	
	fprintf(arq, "P3\n%i %i\n255\n", width, heigth);
	
	for (int y = 0; y < heigth; y++) {
		for (int x = 0; x < width; x++) {
			fprintf(arq, "%i %i %i ", pixel[y][x].r - 10, pixel[y][x].g - 10, pixel[y][x].b - 10); //quando somamos o rgb do pixel e dividimos por 3 temos o seu valor negativo  
		}
		fprintf(arq, "\n");
	}
	
	fclose(arq);
}

int main(const int argc, const char **argv){
	char nomeArq[] = "saida.ppm";
	int x, y;
	FILE *arq = NULL;
	if(argc < 2) printf("faltando nome do arquivo de entrada\n argv\n");
	if(arq = fopen(argv[1],"r")){
		Imagem *img = new Imagem(arq);
		save_ppm(img->getAllpixel(), img->getaltura(), img->getlargura(), nomeArq);
	}
	else printf("arquivo invalido\n");
}