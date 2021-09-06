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
    int t;
    string s;
    cin >> t;
    getline(cin, s);
    getline(cin, s);
    int flag = 0;
    while(t--){
        if(flag)cout << "\n";
        flag = 1;
        vector <string> v;
        map <string, string> mp;
        while(1){
            getline(cin, s);
            if(s.empty())break;
            v.push_back(s);
            string a;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != ' ')a.push_back(s[i]);
            }
            sort(a.begin(), a.end());
            mp[s] = a;
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1;j < v.size();j++){
                if(mp[v[i]] == mp[v[j]]){
                    cout << v[i] << " = " << v[j] << "\n";
                } 
            }
        }
        
    }
    return 0;
}