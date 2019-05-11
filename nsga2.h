#include<bits/stdc++.h>
using namespace std;


typedef struct individuo{
    int id,rank;
    double num,x,y;
    double np;
    vector<struct individuo> sp;
}Individuo;


void teste(int a);
double funcao1(double n);
double funcao2(double n);
double floatrand();
bool meuSort(Individuo a,Individuo b);
void fast_non_dominated_sort(vector<Individuo> &Po,vector< vector<Individuo> > &Fronteiras);