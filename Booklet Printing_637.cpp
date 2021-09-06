#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef vector <int> vec;
typedef vector <pa> vep;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    while(1){
        cin >> t;
        if(t == 0)break;
        cout << "Printing order for " << t << " pages:\n";
    
        vec res1(t/2), res2(t/2);
        for(int i = 1; i <= t/2; i+=2){
            res2[i-1] = i;
            res1[i] = i+1;
        }
        for(int i = t/2 + 1; i <= t; i+=2){
            res2[t - i - 2] = i;
            res1[t - i - 3] = i+1;
            
        }
        
        for(int i = 0; i < front.size(); i++){
    
            cout << "Sheet " << i+1 << ", front: ";
            if(front[i].first == -1)cout << "Blank";
            else cout << front[i].first;
            cout << ", ";
            if(front[i].second == -1)cout << "Blank";
            else cout << front[i].second;
            cout << "\n";
            if(i < back.size()){
                cout << "Sheet " << i+1 << ", back : ";
                if(back[i].first == -1)cout << "Blank";
                else cout << back[i].first;
                cout << ", ";
                if(back[i].second == -1)cout << "Blank";
                else cout << back[i].second;
                cout << "\n";
            }
        }

    }
    return 0;
}