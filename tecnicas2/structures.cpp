#include <iostream>
#include <string>

using namespace std;

//tipos de stl: int, float, double, char
/*
  Variaveis declaradas estaticamente são armazenadas na call stack
  int n = 10;

 */

//struct = tipos personalizados de dados (Não implementados na stl);
//struct é um tipo abstrado de dados
//
//definição da struct

struct Endereco {
  string cidade;
  string estado;
};
typedef struct Endereco Endereco;

struct Produto {
  int codigo;
  string descricao;
  float preco;
  Endereco origem;
};
typedef struct Produto Produto;

void cadastraPeca(Produto &peca){
    //parametro é recebido por referencia
    //altera o valor por origem
    cout << "Informe o código da peça: ";
    cin >> peca.codigo;
    cin.ignore();

    cout << "Informe a descrição da peça: ";
    getline(cin, peca.descricao);

    cout << "Informe o preco da peca: ";
    cin >> peca.preco;
    cin.ignore();

    cout << "Informe a cidade de origem da peca: ";
    getline(cin, peca.origem.cidade);

    cout << "Informe o estado de origem da peca: ";
    getline(cin, peca.origem.estado);
}

//sub-algoritimo de uma peça
void printPeca(Produto peca){//Recebe o parametro por cópia (Sem o "&")
    cout << "Codigo: " << peca.codigo << endl;
    cout << "Descricao: " << peca.descricao << endl;
    cout << "Preco: " << peca.preco << endl;
    cout << "Cidade de origem: " << peca.origem.cidade << endl;
    cout << "Estado de origem: " << peca.origem.estado << endl << '\n';
}

const int n = 2;

int main(){
  cout << "Tamanho do tipo int: " << sizeof(int) << endl;
  cout << "Tamanho do tipo Endereco: " << sizeof(Endereco) << endl;
  cout << "Tamanho do tipo Produto: " << sizeof(Produto) << endl;

  Produto backup;
  Produto estoque[n];
  backup = estoque[0];
  /*
  estoque[0].codigo = 100;
  estoque[0].descricao = "Pistao";
  estoque[0].origem.cidade = "Affalterbach";
  estoque[0].origem.estado = "Descobrir";
  estoque[0].preco = 100.00;
  */
  //Operações permitidas com struct
  /*
    Somente atribuir uma struct á outra;
  */
  backup = estoque[0];

  //Operações não permitidas
  /*
    Não podemos realizar soma (+), subtração (-), multiplicação (*), divisão (/);
    estoque[0] + estoque[1] -> não permitido!
    estoque[0] / estoque[1] -> não permitido!

    total = estoque[0].preco + estoque[1].preco .... -> Valido!
    estoque[0].origem = estoque[1].origem; -> Valido!
  */

  for(int i=0;i<n;i++){
      cout << "\nCadastrando peca " << i+1 << '\n';
      cadastraPeca(estoque[i]);
  }

  cout << "\nRelatorio do estoque\n\n";
  for(int i=0;i<n;i++){
      cout << "Peca " << i+1 << '\n';
      printPeca(estoque[i]);
  }

  return 0;
}
