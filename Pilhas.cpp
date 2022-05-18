#include <iostream>
#include <locale.h>
#include <iomanip>

using namespace std;

struct Lista
{
	int pront;
	string nome;
	double salario;
	Lista *ant;
};

Lista* init()
{
	return NULL;
}

int isEmpty(Lista* lista)
{
	return (lista == NULL);
}

Lista* insert(Lista* lista, int pront, string nome, double salario)
{
	Lista* novo = new Lista();
	Lista* aux = lista;
	
	while(aux != NULL && aux->pront != pront){
		aux = aux->ant;
	}
	
	if(aux == NULL){
		novo->pront = pront;
		novo->nome = nome;
		novo->salario = salario;
		novo->ant = lista;
		
		cout << endl << "Funcion�rio Cadastrado" << endl;
	} else{
		cout << endl << "Prontu�rio j� existente." << endl;
		return aux = lista;
	}

	return novo;	
}

int count(Lista* lista)
{
	int k = 0;
	Lista* aux;
	aux = lista;
	
	while(aux != NULL){
		++k;
		aux = aux->ant;
	}
	
	return k;
}

void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	
	while(aux != NULL){
		cout << "Prontu�rio: " << aux->pront << ", Nome: " << aux->nome << ", Sal�rio: R$" << fixed << setprecision(2) << aux->salario << endl;
		
		aux = aux->ant;
	}
	
}

Lista* find(Lista* lista, int pront)
{
	Lista* aux;
	aux = lista;
	
	while(aux != NULL && aux->pront != pront){
		aux = aux->ant;
	}
	
	return aux;
}

Lista* remove(Lista* lista, int pront)
{
	Lista* aux;
	Lista* anterior = NULL;
	
	aux = lista;
	while(aux != NULL && aux->pront != pront){
		anterior = aux;
		aux = aux->ant;
	}
	
	if(aux == NULL){
		cout << endl << "Funcion�rio inexistente." << endl;
		
		return lista;
	}
	
	if(anterior == NULL){
		cout << endl << "Funcion�rio exclu�do." << endl;
		return lista = aux->ant;
	} else {
		anterior->ant = aux->ant;
		cout << endl << "Funcion�rio exclu�do." << endl;
	}
	
	return lista;
}

double total(Lista* lista)
{
	Lista* aux = lista;
	double total = 0;
	
	while(aux != NULL){
		total += aux->salario;
		aux = aux->ant;
	}
	
	return total;
}

int menu()
{
	int key;
	
	cout << "0. Sair" << endl;
	cout << "1. Incluir" << endl;
	cout << "2. Excluir" << endl;
	cout << "3. Pesquisar" << endl;
	cout << "4. Listar" << endl;
	
	cin >> key;
	
	return key;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	int key;
	int pront;
	string nome;
	double salario;
	double totalSalario;
	
	Lista* funcionarios;
	Lista* buscado;
	funcionarios = init();
	
	key = menu();
	
	while(key != 0){
		switch(key){
			case 1:
				cout << endl << "Insira um Prontu�rio: ";
				cin >> pront;
				cout << "Insira um Nome: ";
				cin >> nome;
				cout << "Insira um Sal�rio: ";
				cin >> salario;
				
				funcionarios = insert(funcionarios, pront, nome, salario);
				
				cout << "Quantidade atual: " << count(funcionarios) << endl << endl;
				
				key = menu();
				break;
			case 2:
				cout << endl << "Insira o prontu�rio do funcion�rio que deseja excluir: ";
				cin >> pront;
				
				funcionarios = remove(funcionarios, pront);
				
				cout << "Quantidade atual " << count(funcionarios) << endl << endl;
				
				key = menu();
				break;
			case 3:
				cout << endl << "Insira o prontu�rio para pesquisa: ";
				cin >> pront;
				
				buscado = find(funcionarios, pront);
				if(buscado == NULL){
					cout << endl << "Funcion�rio n�o encontrado." << endl << endl;
				}else{
					cout << endl << "Prontu�rio: " << buscado->pront << ", Nome: " << buscado->nome << ", Sal�rio: R$" << fixed << setprecision(2) << buscado->salario << endl << endl;
				}
				
				key = menu();
				break;
			case 4:
				cout << endl;
				print(funcionarios);
				cout << endl;
				
				totalSalario = total(funcionarios);
				cout << "Total de sal�rios: R$" << fixed << setprecision(2) << totalSalario << endl << endl;
				 
				key = menu();
				break;
		}
	}
	
	return 0;
}