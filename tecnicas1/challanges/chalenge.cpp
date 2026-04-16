// nome, telefone, data de nascimento, endereco, cidade 
#include <iostream>
#include <string>

using namespace std;

int main(){

    std::string nome;
    std::string telefone;
    std::string data_nasc;
    std::string endereco;
    std::string cidade;
    
    std::cout << "Digite seu nome:";
    getline(cin, nome);

    std::cout << "\nDigite seu telefone (dd)12345-6789:";
    getline(cin, telefone);

    std::cout << "\nDigite sua data de nascimente (dd-mm-yyyy):";
    getline(cin, data_nasc);

    std::cout << "\nDigite seu endereco:";
    getline(cin, endereco);

    std::cout << "\nDigite sua cidade:";
    getline(cin, cidade);
    
    std::cout << "Seu nome e: "<< nome <<", telefone: "<< telefone <<", nascido em: "<< data_nasc << std::endl;
    std::cout << "Endereco: "<< endereco <<", cidade: "<<cidade;

    return 0;
}