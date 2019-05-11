#include<bits/stdc++.h>
#include<stdlib.h>
#include"nsga2.h"
using namespace std;


void teste(int a){
    cout<<"asdasdas "<<a<<endl;
}

double funcao1(double n){
    return sin(3.1415926*n);
}

double funcao2(double n){
    return cos(3.1415926*n);
}

double floatrand(){
    double HI=1.0,LO=0.0;
    
    double r = (rand() / (double)RAND_MAX * HI) + LO;
    return r;
}

bool meuSort(Individuo a,Individuo b){
    return a.num < b.num;
}

void fast_non_dominated_sort(vector<Individuo> &Po, vector< vector<Individuo> > &Fronteiras){
    vector<Individuo> f1;
    int numF;
    for(int i=0;i<Po.size();i++){
        Individuo p=Po[i];

        for(int j=0;j<Po.size();j++){
            Individuo q=Po[j];
            if(p.num < q.num ){
                Po[j].sp.push_back(q);
                //p.sp.push_back(q);
                
            }
            else if( q.num < p.num){
                Po[j].np++;
                //p.np++;
            }
        }
        if (p.np == 0){
            //p.rank=1;
            Po[i].rank=1;
            f1.push_back(p);
        }
    }

    Fronteiras.push_back(f1);
    numF = 0;
    cout<<"qntf = "<<Fronteiras.size()<<" tam f0 = "<<Fronteiras[0].size()<<endl;


    while (!Fronteiras[numF].empty()){
        vector<Individuo> fn;
        
        for(int i = 0;i<Fronteiras[numF].size();i++){  //for each p e Fi
            Individuo p = Fronteiras[numF][i];
            
            for(int j=0;j<p.sp.size();j++){
                
                Individuo q=p.sp[j];
                Fronteiras[numF][i].sp[j].np--;
                //q.np--;
                
                if(Fronteiras[numF][i].sp[j].np == 0){
                    //q.rank=numF+1;
                    Fronteiras[numF][i].sp[j].rank = numF+1;
                    //Fronteiras[numF][i].rank= numF+1;
                    cout<<"+1"<<endl;
                    fn.push_back(Fronteiras[numF][i].sp[j]);
                }
            } 
        }
        numF++;
        Fronteiras.push_back(fn);
    }
}
