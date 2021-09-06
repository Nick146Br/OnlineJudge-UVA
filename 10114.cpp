#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef vector <int> vec;
typedef vector <pa> vep;


int main(){
    int mes;
    double pag, carro, emp, n;
    while(cin >> mes >> pag >> carro >> n){
        if(mes < 0)break;
        emp = carro;
        double aux = carro;
        carro+=pag;
        pag = aux/mes;
        int a;
        double b;
        vector <pair<int, double>> v;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            v.push_back({a,b});
        }
        int k =0, i = 0;
        double per = v[0].second;
        carro -= carro*per;
        if(emp > carro){
        k = 1;
        i = 1;
        while(k <= mes){ 
            
            if(i < v.size() && k == v[i].first){
                per = v[i].second;
                i++;  
            }
            carro -= carro*per;
            emp -= pag;
            if(carro >= emp){
                break;
            }
            k++;
               
        }
        }
        if(k == 1)cout << k << " month\n";
        else cout << k << " months\n";
    }
}