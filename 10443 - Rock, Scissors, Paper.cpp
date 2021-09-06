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
    int flag = 0;
    while(t--){
        if(flag)cout << "\n";
        flag = 1;
        int r, c, n;
        cin >> r >> c >> n;
        char M[101][101], Cp[101][101];
    
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> M[i][j];
            }
        }
        vep mov = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(n--){
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    Cp[i][j] = '*';
                }
            }
            int flag2 = 1;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    for(int l = 0; l < mov.size(); l++){
                        int x = i+mov[l].first;
                        int y = j+mov[l].second;
                        if(x>=0 && x < r && y>=0 && y < c){
                            if(M[i][j] == 'R' && M[x][y] == 'S'){
                                Cp[x][y] = 'R';
                                flag2 = 0;
                            }
                            else if(M[i][j] == 'S' && M[x][y] == 'P'){
                                Cp[x][y] = 'S';
                                flag2 = 0;
                            }
                            else if(M[i][j] == 'P' && M[x][y] == 'R'){
                                Cp[x][y] = 'P';
                                flag2 = 0;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(Cp[i][j] != '*')M[i][j] = Cp[i][j];
                }
            }
            if(flag2)break;
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << M[i][j];
            }
            cout << "\n";
        }

    }

}