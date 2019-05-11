#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include"nsga2.h"
#define numpop 5 
using namespace std;

int main(){
    srand(time(NULL));
    vector <Individuo> populacao;
    
    for(int i=0;i<numpop;i++){
        Individuo a;
        a.num = floatrand();
        a.id=i;
        a.np=0;
        a.rank=0;
        a.x = funcao1(a.num);
        a.y = funcao2(a.num);
        populacao.push_back(a);
    }
    vector< vector<Individuo> > Fronteiras;

    fast_non_dominated_sort(populacao,Fronteiras);

    //sort(populacao.begin(),populacao.end(),meuSort);

    for(int i=0;i<numpop;i++){
        printf("%.3lf - ( %.2lf | %.2lf ) - id %d - sp - %ld\n",populacao[i].num,populacao[i].x,populacao[i].y,populacao[i].id,populacao[i].sp.size());
    }

    cout<<"aasdasdas"<<Fronteiras.size()<<endl;    


    for(int i=0;i<Fronteiras.size();i++){
        cout<<"Fronteira "<<i<<endl;
        for(int j=0;j<Fronteiras[i].size();j++){
            cout<<"id - "<<Fronteiras[i][j].id<<" rank - "<<Fronteiras[i][j].rank<<"  - num= "<<Fronteiras[i][j].num<<endl;
        }
    }

return 0;
}



//g++ nsga2.cpp main.cpp -o a