#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef vector <int> vec;
typedef vector <pa> vep;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin >> s){
    int M[8][8] = {0};
    int i = 0, j = 0;
    char c;
    for(int k = 0; k < s.size(); k++){
        if(s[k] == '/'){
            i++;
            j=0;
        }
        else{
            int x = (int) s[k] - 48;
            if(x < 10 && x > -1)
                j += (int) s[k] - 48;
            else{ 
                M[i][j] = 2;
                j++;
            }
        
        }
        
    }
    i = 0; j = 0;
    for(int k = 0; k  < s.size(); k++){
        if(s[k] == '/'){
            i++;
            j=0;
        }
        else if(s[k] == 'p'){
            if(i+1 <= 7 && j+1 <= 7 && M[i+1][j+1] != 2)M[i+1][j+1] = 1;
            if(i+1 <= 7 && j-1 >= 0 && M[i+1][j-1] != 2)M[i+1][j-1] = 1;
            j++;
        }
        else if(s[k] == 'P'){
            if(i-1 >= 0 && j+1 <= 7 && M[i-1][j+1] != 2)M[i-1][j+1] = 1;
            if(i-1 >= 0 && j-1 >= 0 && M[i-1][j-1] != 2)M[i-1][j-1] = 1;
            j++;
        }
        else if(s[k] == 'b' || s[k] == 'B'){
        
            int a = i-1, b = j-1;
            while(a>=0 && b>=0){
                if(M[a][b] == 2)break;
                M[a][b] = 1;
                a--;
                b--;
            }
            a=i-1; b=j+1;
            while(a>=0 && b<=7){
                if(M[a][b] == 2)break;
                M[a][b] = 1;
                a--;
                b++;
            }
            a=i+1; b=j-1;
            while(a<=7 && b>=0){
                if(M[a][b] == 2)break;
                M[a][b] = 1;
                a++;
                b--;
            }
            a=i+1; b=j+1;
            while(a<=7 && b<=7){
                if(M[a][b] == 2)break;
                M[a][b] = 1;
                a++;
                b++;
            }
            j++;
        }
        else if(s[k] == 'R' || s[k] == 'r'){
            
            int a = i-1;
            while(a>=0){
                if(M[a][j] == 2)break;
                M[a][j] = 1;
                a--;
            }
            a = i+1;
            while(a<=7){
                if(M[a][j] == 2)break;
                M[a][j] = 1;
                a++;
            }
            a = j-1;
            while(a>=0){
                if(M[i][a] == 2)break;
                M[i][a] = 1;
                a--;
            }
            a = j+1;
            while(a<=7){
                if(M[i][a] == 2)break;
                M[i][a] = 1;
                a++;
            }
            j++;
        }
        else if(s[k] == 'Q' || s[k] == 'q'){
            
            int a = i-1, b = j-1;
            while(a>=0 && b>=0){
                if(M[a][b] == 2)break;
                M[a][b] = 1;
                a--;
                b--;
            }
            a=i-1; b=j+1;
            while(a>=0 && b<=7){
                if(M[a][b] == 2)break;
                M[a][b] = 1;
                a--;
                b++;
            }
            a=i+1; b=j-1;
            while(a<=7 && b>=0){
                if(M[a][b] == 2)break;
                M[a][b] = 1;
                a++;
                b--;
            }
            a=i+1; b=j+1;
            while(a<=7 && b<=7){
                if(M[a][b] == 2)break;
                M[a][b] = 1;
                a++;
                b++;
            }
            a = i-1;
            while(a>=0){
                if(M[a][j] == 2)break;
                M[a][j] = 1;
                a--;
            }
            a = i+1;
            while(a<=7){
                if(M[a][j] == 2)break;
                M[a][j] = 1;
                a++;
            }
            a = j-1;
            while(a>=0){
                if(M[i][a] == 2)break;
                M[i][a] = 1;
                a--;
            }
            a = j+1;
            while(a<=7){
                if(M[i][a] == 2)break;
                M[i][a] = 1;
                a++;
            }
            j++;
        }
        else if(s[k] == 'n' || s[k] == 'N'){
            int a = i, b = j;
            vep mov = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2,-1}, {-2, 1}, {-2, -1}};
            for(int l = 0; l < mov.size(); l++){
                int x = a+mov[l].first;
                int y = b+mov[l].second;
                if(x <= 7 && x >= 0
                && y <= 7 && y >= 0 && M[x][y] != 2){
                    M[x][y] = 1;
                }  
            }
            j++;
        }
        else if(s[k] == 'k' || s[k] == 'K'){
            int a = i, b = j;
            vep mov = {{1, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, 1}, {0, -1}};
            for(int l = 0; l < mov.size(); l++){
                int x = a+mov[l].first;
                int y = b+mov[l].second;
                if(x <= 7 && x >= 0
                && y <= 7 && y >= 0 && M[x][y] != 2){
                    M[x][y] = 1;
                }  
            }
            j++;
        }
        else{
            j+=(int)s[k] - 48;
        }
    
    }
    int cont = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(M[i][j] == 0)cont++;
        }
    }
    cout << cont << "\n";
    }
}