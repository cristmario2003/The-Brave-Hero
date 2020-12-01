#include <bits/stdc++.h>
using namespace std;
struct Carl{short viata,putere,aparare,viteza,noroc,abilitate1,abilitate2;};
struct Bestie{short viata,putere,aparare,viteza,noroc;};
Carl carl;
Bestie bestie;
bool ok;
short dodge,NumarTure;
int main()
{
    srand(time(0));

    carl.viata = rand() % 31 + 65; cout<<"Viata lui Carl este: "<<carl.viata<<'\n';
    carl.putere = rand() % 11 + 60; cout<<"Puterea lui Carl este: "<<carl.putere<<'\n';
    carl.aparare = rand() % 11 + 40; cout<<"Apararea lui Carl este: "<<carl.aparare<<'\n';
    carl.viteza = rand() % 11 + 40; cout<<"Viteza lui Carl este: "<<carl.viteza<<'\n';
    carl.noroc = rand() % 21 + 10; cout<<"Norocul lui Carl este: "<<carl.noroc<<'\n';

    cout<<'\n'<<'\n'<<'\n';

    bestie.viata = rand() % 26 + 55; cout<<"Viata bestiei este: "<<bestie.viata<<'\n';
    bestie.putere = rand() % 31 + 50; cout<<"Puterea bestiei este: "<<bestie.putere<<'\n';
    bestie.aparare = rand() % 21 + 35; cout<<"Apararea bestiei este: "<<bestie.aparare<<'\n';
    bestie.viteza = rand() % 21 + 40; cout<<"Viteza bestiei este: "<<bestie.viteza<<'\n';
    bestie.noroc = rand() % 16 + 25; cout<<"Norocul bestiei este: "<<bestie.noroc<<'\n';

    cout<<'\n'<<'\n'<<'\n';

    if(carl.viteza > bestie.viteza) { ok = 1; cout<<"Carl are primul atac."<<'\n'<<'\n'; } /// Carl are primul atac
    else if(bestie.viteza > carl.viteza) { ok = 0; cout<<"Bestia are primul atac."<<'\n'<<'\n'; }/// Bestia incepe
    else{
         if(carl.noroc >= bestie.noroc) { ok = 1; cout<<"Carl are primul atac."<<'\n'<<'\n'; } /// O sa presupun ca incepe Carl si daca au norocul egal
         else { ok = 0 ; cout<<"Bestia are primul atac."<<'\n'<<'\n'; }
    }
    while(carl.viata > 0 && bestie.viata > 0 && NumarTure < 20)
    {
        NumarTure++;
        cout<<"Inceputul turului cu numarul "<<NumarTure<<":"<<'\n';
        if(ok == 1)
        {
            cout<<"    Este randul lui Carl sa atace."<<'\n';
            dodge = rand() % 100 + 1;
            if(dodge <= bestie.noroc) cout<<"    Bestia are noroc si se fereste de atac."<<'\n'; /// Bestie a avut noroc sa dea dodge
            else{
                carl.abilitate1 = rand() % 100 + 1;
                if(carl.abilitate1 <= 10) /// Atacul lui Carl se dubleaza pentru urmatorul atac
                    {
                     cout<<"    Carl foloseste forta dragonului si isi dubleaza puterea pentru urmatorul atac."<<'\n';
                     if(carl.putere * 2 - bestie.aparare <= 0) cout<<"    Atacul lui Carl nu ii provoaca daune bestiei."<<'\n';
                        else if(carl.putere * 2 - bestie.aparare >= 100){ bestie.viata -= 100; cout<<"    Atacul lui Carl ii provoaca bestiei daune in valoare de 100."<<'\n'; }
                            else { bestie.viata = bestie.viata - (carl.putere * 2 - bestie.aparare); cout<<"    Atacul lui Carl ii provoaca bestiei daune in valoare de "<<carl.putere * 2 - bestie.aparare<<"."<<'\n'; }
                    }
                else{
                    if(carl.putere - bestie.aparare <= 0) cout<<"    Atacul lui Carl nu ii provoaca daune bestiei."<<'\n';
                        else if(carl.putere - bestie.aparare >= 100){ bestie.viata -= 100; cout<<"    Atacul lui Carl ii provoaca bestiei daune in valoare de 100."<<'\n'; }
                            else { bestie.viata = bestie.viata - (carl.putere - bestie.aparare); cout<<"    Atacul lui Carl ii provoaca bestiei daune in valoare de "<<carl.putere - bestie.aparare<<"."<<'\n'; }
                }
            }
            cout<<"    Bestia ramane cu "<<bestie.viata<<" puncte de viata la finalul turului."<<'\n';
            ok = 0; /// Urmatorul atac o sa fie al bestiei
        }
        else{
            cout<<"    Este randul bestiei sa atace."<<'\n';
            dodge = rand() % 100 + 1;
            if(dodge <= carl.noroc)  cout<<"    Carl are noroc si se fereste de atac."<<'\n';
            else{
                carl.abilitate2 = rand() % 100 + 1;
                if(carl.abilitate2 <= 20) /// Atacul bestiei se injumatateste pentru urmatorul atac
                    {
                     cout<<"    Carl foloseste scutul fermecat si injumatateste daunele urmatorului atac."<<'\n';
                     if(bestie.putere / 2 - carl.aparare <= 0) cout<<"    Atacul bestiei nu ii provoaca daune lui Carl."<<'\n';
                        else if(bestie.putere / 2 - carl.aparare >= 100){ carl.viata -= 100; cout<<"    Atacul bestiei ii provoaca lui Carl daune in valoare de 100."<<'\n'; }
                            else { carl.viata = carl.viata - (bestie.putere / 2 - carl.aparare); cout<<"    Atacul bestiei ii provoaca lui Carl daune in valoare de "<<bestie.putere / 2 - carl.aparare<<"."<<'\n'; }
                    }
                else{
                    if(bestie.putere - carl.aparare <= 0) cout<<"    Atacul bestiei nu ii provoaca daune lui Carl."<<'\n';
                        else if(bestie.putere - carl.aparare >= 100){ carl.viata -= 100; cout<<"    Atacul bestiei ii provoaca lui Carl daune in valoare de 100."<<'\n'; }
                            else { carl.viata = carl.viata - (bestie.putere - carl.aparare); cout<<"    Atacul bestiei ii provoaca lui Carl daune in valoare de "<<bestie.putere - carl.aparare<<"."<<'\n'; }
                }
            }
            cout<<"    Carl ramane cu "<<carl.viata<<" puncte de viata la finalul turului."<<'\n';
            ok = 1; /// Urmatorul atac o sa fie al lui Carl

        }
        cout<<'\n';
    }
    if(carl.viata <= 0) cout<<"Bestia l-a infrant pe Carl dupa "<<NumarTure<<" ture, ramanand cu "<<bestie.viata<<" puncte de viata."<<'\n';
        else if(bestie.viata <= 0) cout<<"Carl a infrant bestia dupa "<<NumarTure<<" ture, ramanand cu "<<carl.viata<<" puncte de viata."<<'\n';
            else if(NumarTure == 20) cout<<"Cele 20 de ture s-au terminat si Carl a ramas cu "<<carl.viata<<" puncte de viata si bestia cu "<<bestie.viata<<" puncte de viata."<<'\n';
}
