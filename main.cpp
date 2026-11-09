#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;




    struct Product {
        string nazwa;
        double cena;
     int ilosc;
};
    vector<Product> magazyn;


   int main() {
       int wybor;
       while (true) {
           cout << "--- Wybierz opcje: ----"<<endl;
           cout << "1.Dodaj produkt" << endl;
           cout << "2.Wyswietl magazyn"<<endl;
           cout << "3.Szukaj najdrozszego"<<endl;
           cout <<"4.Wyjdź"<<endl;
           cin >> wybor;

           switch (wybor) {
               case 1: {
                   Product nowy;

                   cout<< "podaj nazwe produkt:  " << endl;
                   cin >> nowy.nazwa;

                   cout << "podaj cene(zł): " << endl;
                   cin >> nowy.cena;

                   cout << "podaj ilosc: "<<endl;
                   cin >> nowy.ilosc;

                   magazyn.push_back(nowy);
                   cout << "Dodano do magazynu!!"<<endl;

                   break;
               }
               case 2: {
                   if (magazyn.empty()) {
                       cout << "Magazyn jest pusty!! dodaj cos do magazynu!"<<endl;
                   }else {
                       cout << "---Zawartosc Magazynu---"<<endl;
                       for (int i = 0; i  <  magazyn.size(); i++ ) {
                           cout << i + 1 << ". " << magazyn[i].nazwa <<
                               " | cena: " << magazyn[i].cena << " zł" <<
                                   " | ilosc: " << magazyn[i].ilosc << " .szt" << endl;
                       }

                   }
                   break;
               }

               case 3:
                   if (magazyn.empty()) {
                       cout << "Magzayn jest pusty!!"<<endl;
                   }else {
                       auto it = max_element(magazyn.begin(), magazyn.end(), [](const Product& a, const Product& b) {
                          return a.cena < b.cena;
                       });

                       cout << "Najdrozszy produkt: " << it->nazwa << endl;
                       cout << "Cena: "<< it->cena << " zł" <<endl;
                   }


                   break;
               case 4:

                   return 0;
               default:
               cout << "Nie poprawna wartość!! wybierz z zakresu (1-4)!!"<<endl;
                   break;
           }
       }
   }