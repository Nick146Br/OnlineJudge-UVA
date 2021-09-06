#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef vector <int> vec;
typedef vector <pa> vep;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    int pl, x, die, a, b;
    cin >> pl >> x >> die;
    vec v(pl+1, 1), d;
    int M[101] = {0};

    for(int i = 1; i <= 100; i++){
        M[i] = i;
    }
    for(int i = 1; i <= x; i++){
        cin >> a >> b;
        M[a] = b;
    }
    int k;
    for(int i = 0; i < die; i++){
        cin >> k;
        d.push_back(k);
    }
    int j = 1;
    for(int i = 0; i < d.size(); i++){
        v[j] = v[j]+d[i];
        if(v[j] >= 100){
            v[j] = 100;
            break;
        }
        
        v[j] = M[v[j]];
        if(v[j] >= 100){
            v[j] = 100;
            break;
        }
        
        j++;
        if(j == pl+1)j = 1;
    }
    for(int i = 1; i <= pl; i++){
        cout << "Position of player "<< i << " is "<< v[i] << ".\n";
    }
    }
}