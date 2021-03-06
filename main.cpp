#include <iostream>
#include <ctime>
#include "estrutura.h"

using namespace std;

Celula *popularControleDuplicados(Celula *lista, int n) {
  srand(time(NULL));
  
  for (int i = 0; i < n; i++) {
    lista = inserirListaControleDuplicados(rand() % 100, lista);
  }
  return lista;
}

Celula *popularSemControleDuplicados(Celula *lista, int n) {
  srand(time(NULL));
  
  for (int i = 0; i < n; i++) {
    lista = inserirListaSemControleDuplicados(rand() % 100, lista);
  }
  return lista;
}

int main() {

  Celula *lista1 = NULL;
  Celula *lista2 = NULL;

  // questao 1
  lista1 = popularSemControleDuplicados(lista1, 20);
  lista2 = popularControleDuplicados(lista2, 7);


  cout << "Lista 1" << endl;
  exibirLista(lista1);

  cout << "Lista 2" << endl;
  exibirLista(lista2);

  int numero;
  cout << "Qual o número que você deseja apagar da lista? ";
  cin >> numero;
  
  
  lista1 = excluirOcorrenciasLista(numero, lista1);
  
  cout << "Lista após exclusão" << endl;
  exibirLista(lista1);

 
  verificarPresenca(lista1, lista2);

 
  Celula *lista3 = unirListas(lista2, lista1);

  cout << "Exibindo a uniao da lista2 com a lista1" << endl;
  exibirLista(lista3);

  lista1 = excluirparesLista(lista1);
  cout << "Lista após exclusão dos pares" << endl;
  exibirLista(lista1);

  cout << "A Media da lista é " << media(lista1) << endl;

  exibirListametade(lista1);
  return 1;
}
