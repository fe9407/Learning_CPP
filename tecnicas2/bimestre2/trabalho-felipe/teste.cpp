#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct netflixtitles
{
    string id;          // 1
    string type;        // 2
    string title;       // 3
    string director;    // 4
    string cast;        // 5
    string country;     // 6
    string date_added;  // 7
    string release_year;// 8
    string rating;      // 9
    string duration;    // 10
    string listed_in;   // 11
    string description; // 12
};
typedef struct netflixtitles netflixtitles;

// Função auxiliar para ler um campo respeitando as aspas
string lerCampoCSV(stringstream &ss) {
    string campo;

    // Se o stream estiver vazio, retorna vazio
    if (ss.peek() == EOF) return "";

    // Verifica se o próximo caractere é uma aspa dupla
    if (ss.peek() == '"') {
        ss.get(); // Remove a aspa de abertura do stream
        getline(ss, campo, '"'); // Lê tudo até a aspa de fechamento

        // Se o próximo caractere for a vírgula que separa os campos, consome ela
        if (ss.peek() == ',') {
            ss.get();
        }
    } else {
        // Se não começa com aspas, lê normalmente até a vírgula
        getline(ss, campo, ',');
    }

    return campo;
}

int main()
{
    string linha;
    int contadorMovies = 0, contadorTVshows = 0, totalRegistros = 0;

    netflixtitles titles1;

    ifstream arquivo("netflix_titles_novo.csv", ios::in);

    if(!arquivo.is_open())
    {
        cerr << "Erro ao abrir ao arquivo" << endl;
        return 1;
    }

    int contador = 0;
    while(getline(arquivo, linha))
    {
        //cout << "linha: " << linha << "\n\n";
        /*
        if(linha == "show_id,type,title,director,cast,country,date_added,release_year,rating,duration,listed_in,description"){
            contador--;
            cout << "contador --\n\n";
        }
        */
        stringstream ss(linha);

        // Criamos um vetor local simples de strings, sem usar 'new'
        string campos[12];

        // Preenche os 12 campos usando a nova função inteligente
        for(int i = 0; i < 12; i++)
        {
            campos[i] = lerCampoCSV(ss);
        }

        titles1.id = campos[0];
        titles1.type = campos[1];
        titles1.title = campos[2];
        titles1.director = campos[3];
        titles1.cast = campos[4];
        titles1.country = campos[5];
        titles1.date_added = campos[6];
        titles1.release_year = campos[7];
        titles1.rating = campos[8];
        titles1.duration = campos[9];
        titles1.listed_in = campos[10];
        titles1.description = campos[11];

        // Atualiza os contadores baseados no tipo
        if(titles1.type == "Movie") contadorMovies++;
        if(titles1.type == "TV Show") contadorTVshows++;

        totalRegistros++;
        contador++;
    }
    arquivo.close();

    cout << "Teste string: \n";
    cout << "id: " << titles1.id << endl;
    cout << "type: " << titles1.type << endl;
    cout << "title: " << titles1.title << endl;
    cout << "director: " << titles1.director << endl;
    cout << "cast: " << titles1.cast << endl;
    cout << "country: " << titles1.country << endl;
    cout << "date added: " << titles1.date_added << endl;
    cout << "relese year: " << titles1.release_year << endl;
    cout << "rating: " << titles1.rating << endl;
    cout << "duration: " << titles1.duration << endl;
    cout << "listed in: " << titles1.listed_in << endl;
    cout << "description: " << titles1.description << endl;

    cout << "\n Registros carregados: " << totalRegistros << '\n';
    cout << "+---------------------------------------+" << '\n';
    cout << "| QTD Movies: " << contadorMovies << " | ";
    cout << "QTD TV Shows: " << contadorTVshows << " |" << '\n';
    cout << "+---------------------------------------+" << '\n';

    cout << "\nPressione ENTER para encerrar o programa...";
    cin.get();

    return 0;
}
