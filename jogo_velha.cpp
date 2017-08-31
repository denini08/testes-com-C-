#include <iostream>

using namespace std;

class Jogo_velha{
	public:
		Jogo_velha(){
			for(int i = 0; i <3 ; i++){
				for(int j = 0; j < 3; j++){
					matrix[i][j] = 0;
				}
			}
		}
		int getposicao(int x, int y){
			return matrix[x][y];
		}
		int setposicao(int x, int y,  int jogador){
			if(matrix[x][y] != 0 ){ //caso a posicao já foi jogada
				matrix[x][y] = jogador;
				return 0; 
			}
			else{
				return -1; //caso erro
			}
		}
	private:
		int matrix[3][3];
};



int main(const int argc, const char **argv){
	
	return 0;
}