#include <iostream>

using namespace std;

const int n = 1000;

int main(){
    string s1; // = "abcde1234567890abcde"; // Caso a capacidade de armazenamento seja maior que a padrão ele pede mais espaço para o sistema operacional
    //Ex: abcde1234567890abcde = 20 caracteres, 15 na call stack, 5 na hyp
    cout << "Tamanho inicial da variavel s1 (em bytes): " << sizeof(s1);
    cout << "\ncapacidade inicial da string (QTD de caracteres): " << s1.capacity();
    for(int i = 0; i < n; i++){
        //incrementar a string caracter a caracter
        s1 += 'a';
        if(s1.size()%10 == 0){
            cout << "\nTamanho da variavel s1: " << s1.size();
            cout << "\ncapacidade da string (QTD de caracteres): " << s1.capacity();
        }
    }

    return 0;
}
