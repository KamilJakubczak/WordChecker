#include <iostream>
#include <conio.h> // potrzebne do getchar()
#include <fstream> 
#include <windows.h> // potrzebane do exit()
#include <cstdlib> 
#include <string> // potrzebane do exit()
using namespace std;

HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
bool sprawdzenie(string prawidlowa, string podana)
{
    
    int dl_prawidlowej = prawidlowa.length();
    int dl_podanej = podana.length();
    int punkty=0;
    for(int i=0;i<=dl_prawidlowej;i++)
    {
        if(prawidlowa[i]==podana[i])
        {
            SetConsoleTextAttribute(uchwyt, 10);
        cout<<prawidlowa[i];
         punkty++;
        }
        else
        {
            SetConsoleTextAttribute(uchwyt, 14);
            cout <<"-";
            
        }
    }
   //cout<<dl_prawidlowej<<endl;
   //cout<<punkty-1<<endl;
    if(punkty-1==dl_prawidlowej)
    {
      
        //cout<< "true"<<endl;
        return(true) ;
    }
    
    else
    {
        //cout << "false"<<endl;
        return(false);
    }    
    
}


int main()
{
    fstream plik;
    char wybor; // wybor polocenia z menu
    string pytanie, odpowiedz;
for(;;)
{
    system("cls");
    SetConsoleTextAttribute(uchwyt, 7);
    cout << "Witaj w programie szkoleniowym z programowania" << endl;
    cout << "Wybierz co chesz zrobic" << endl;
    cout << "=====================" << endl;
    SetConsoleTextAttribute(uchwyt, 15);
    cout << "1.Dodaj nowa informacje" << endl;
    cout << "2.Sprawdz sowja wiedze" << endl;
    cout << "3.Zakoncz program" << endl;
    cout << "=====================" << endl;
    wybor = getch();
    switch(wybor)
    {
        case '1':
            {
             cout << "Podaj pytanie: " << endl;
             getline(cin,pytanie);
             cout << "Podaj odpowiedz: " << endl;
             getline(cin,odpowiedz);
             plik.open("database.txt", ios::out | ios::app);
             plik << pytanie << ";"<<odpowiedz<<";"<< endl;
            // plik << odpowiedz << endl;
             plik.close();
             
             break;  
            }
        case '2':
            {
             plik.open("database.txt", ios::in);
             if(plik.good()==false) 
             {
                 cout << "Baza danych nie istniej, utworz plik database.txt" << endl;
                 exit(0);
             }
             string linia;
             int nr_lini=0;
             bool test=true;
             string podana_odpowiedz;
             int punkty=0;
             int zdobyte_punkty;
             system("cls");
             cout<<"Wcisnij enter aby rozpoczac"<<endl;
             
                 while(!plik.eof())
                 {
                     getline(plik,linia);
                     SetConsoleTextAttribute(uchwyt, 7);
                     if(test==true)
                        {
                           getchar();
                           system("cls");     
                           cout << linia <<endl;
                           getline(cin,podana_odpowiedz);
                           test=false;  
                        }
                      else 
                      {
                          if(sprawdzenie(linia,podana_odpowiedz)==true)
                          {
                              SetConsoleTextAttribute(uchwyt, 10);
                            //cout<<"\n"<<nr_lini<<endl;
                            punkty++;
                           
                          }
                          else
                          {
                                SetConsoleTextAttribute(uchwyt, 12);
                            cout<< "\nZle"<<endl;
                            SetConsoleTextAttribute(uchwyt, 7);
                             cout << "Prawidlowa odpowiedz to: ";
                             SetConsoleTextAttribute(uchwyt, 10);
                             cout<<linia<<endl;
                          }
                          test=true;
                          
                      }
                      nr_lini++;
                        
                 }
             plik.close();
             SetConsoleTextAttribute(uchwyt, 7);
             cout<<endl;
             cout<<"Zdobyto punktow"<<endl;
             cout<<punkty<<"/"<<nr_lini/2;
             getchar();
             break;
            }
        case '3':
            {
                exit(0);
            }    
    }
    
}
}
