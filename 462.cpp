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
    string s;
    while(getline(cin, s)){
        vector <char> v[4];
        int i = 0;
        string a;
        int points = 0;
        while(i < s.size()){
            a = s.substr(i, 2);
            if(a[1] == 'S')v[0].push_back(a[0]);
            if(a[1] == 'H')v[1].push_back(a[0]);
            if(a[1] == 'D')v[2].push_back(a[0]);
            if(a[1] == 'C')v[3].push_back(a[0]);

            if(a[0] == 'A')points+=4;
            if(a[0] == 'K')points+=3;
            if(a[0] == 'Q')points+=2;
            if(a[0] == 'J')points+=1;

            i+=3;
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < v[i].size(); j++){
                if(v[i][j] == 'K'){
                    if(v[i].size()==1)points-=1;
                }
                if(v[i][j] == 'J'){
                    if(v[i].size()<=3)points-=1;
                }
                if(v[i][j] == 'Q'){
                    if(v[i].size()<=2)points-=1;
                }
            }
        }
        int flag = 1;
        if(points >= 16){
            int stops = 0;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < v[i].size(); j++){
                    if(v[i][j] == 'A'){
                        stops++;
                        break;
                    }
                    if(v[i][j] == 'K' && v[i].size() >= 2){
                        stops++;
                        break;
                    }
                    if(v[i][j] == 'Q' && v[i].size() >= 3){
                        stops++;
                        break;
                    }
                }
            }
            if(stops == 4){
                flag = 0;
                cout << "BID NO-TRUMP\n";
            }
        }
        if(flag){
            for(int i = 0; i < 4; i++){
                if(v[i].size() == 2)points++;
                if(v[i].size() == 1)points+=2;
                if(v[i].size() == 0)points+=2;
            }
            if(points < 14)cout << "PASS\n";
            else{
                char suit;
                int ma = 0;
                for(int i = 0; i < 4; i++){
                    if(v[i].size() > ma){
                        if(i == 0)suit = 'S';
                        if(i == 1)suit = 'H';
                        if(i == 2)suit = 'D';
                        if(i == 3)suit = 'C';
                        ma = v[i].size();
                    }
                }
                cout << "BID " << suit << "\n";
            }
        }
    }
}