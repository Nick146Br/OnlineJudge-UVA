#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef vector <int> vec;
typedef vector <pa> vep;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    int p = 1;
    cin.ignore();
    while(t--){
        
        string s;
        getline(cin, s);
        string a;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')a.push_back(s[i]);
        }   
        int num = sqrt(a.size());
        if(num*num != a.size()){
            cout << "Case #" << p << ":\n";
            cout << "No magic :(\n";
        }else{
            int M[101][101];
            int k = 0;
            for(int i = 0; i < num; i++){
                for(int j = 0; j < num; j++){
                    M[i][j] = a[k++];
                }
            }
            string x, y, z;
            for(int i = 0; i < num; i++){
                for(int j = 0; j < num; j++){
                    x.push_back(M[j][i]);
                }
            }
            for(int i = num-1; i >= 0; i--){
                for(int j = num-1; j >= 0; j--){
                    y.push_back(M[i][j]);
                }
            }
            for(int i = num-1; i >= 0; i--){
                for(int j = num-1; j >= 0; j--){
                    z.push_back(M[j][i]);
                }
            }
            if(x == a && y == a && a == z){
                cout << "Case #" << p << ":\n";
                cout << num << "\n";
            }
            else{
                cout << "Case #" << p << ":\n";
                cout << "No magic :(\n";
            }

        }
        p++;
    }
    return 0;
}