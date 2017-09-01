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
		if(matrix[x][y] == 0 ){ //caso a posicao nao foi jogada
			matrix[x][y] = jogador;
			return 0; 
		}
		else{
			return -1; //caso erro
		}
	}
	void imprimir(){
		//pregica de fazer :S
	}
 private:
	int matrix[3][3];
};

class Player{
 public:
	Player(string nome_, int numero_){		//numero ? 1 ou 2
		nome = nome_;
		numero = numero_;
	}
	
	int getnumero(){
		return numero;
    }
	string getnome(){
		return nome;
	}
 
 private:
	int numero;
	string nome;
};


int main(const int argc, const char **argv){
	string a, b;
	int x = 3,y = 3, p = 0;
	
	
	cout << "Jogador 1 digite seu nome:" << endl;
	cin >> a ;
	cout << "Jogador 2 digite seu nome:" << endl;
	cin >> b;
	Jogo_velha *obj = new Jogo_velha();
	Player *p1 = new Player(a , 1);
	Player *p2 = new Player(b , 2);
	
	
	while(true){
		loop:
		if(p == 0){
			cout << p1->getnome() << " digite a posicao que deseja jogar:" << endl;
			scanf("%d %d",&x,&y );
			if(x > 2 || x < 0 || y>2 || y < 0){
				cout << "posicao inexistente"<< endl;
				goto loop;
			}
			if(obj->setposicao(x,y,p1->getnumero()) == -1){
				cout << p1->getnome() << " digitou uma posicao ja jogada anteriormente" << endl;
				goto loop;
			} else printf("FOIIIIII\n");
			p++;
			
		}
		else{
			cout << p2->getnome() << " digite a posicao que deseja jogar:" << endl;
			scanf("%d %d",&x,&y );
			if(x > 2 || x < 0 || y>2 || y < 0){
				cout << "posicao inexistente"<< endl;
				goto loop;
			}
			if(obj->setposicao(x,y,p2->getnumero()) == -1){
				cout << p2->getnome() << " digitou uma posicao ja jogada anteriormente" << endl;
				goto loop;
			}
			p--;
			
		}
	}
	return 0;
}




