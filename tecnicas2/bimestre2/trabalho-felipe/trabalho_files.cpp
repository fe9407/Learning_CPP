#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct netflixtitles
{
    string type;
    string title;
    string director;
    string cast;
    string country;
    string date_added;
    int release_year;
    string rating;
    string duration;
    string listed_in;
    string description;
};
typedef struct netflixtitles netflixtitles;

int main()
{
    ifstream tabela("netflix_titles.csv", ios::in);

    string escrita;
    netflixtitles titles1;
    int teste=0;
    int contadorLinhas=0, contadorMovies=0, contadorTVshows=0;

    while(getline(tabela, escrita, ','))
    {
        cout << escrita << ",";

        //if(escrita == "s") contadorLinhas++;

        //contadorLinhas++;
        teste++;
        //cout << "\n\nValor de teste: " << teste;
        //cin.get();
    }

    while(getline(tabela, escrita)) contadorLinhas++;

    cout << "\n\nregistros carregados: " << contadorLinhas;
    //cout << "\nmovies: " << contadorMovies << " | TV shows: " << contadorTVshows;
    return 0;
}
