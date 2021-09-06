/*E - BABEL*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 999999999999999999
#define MAXT 10001
main(){
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m, l; 
    string a, b, d;
    while(cin >> l){
        if(l==0)break;
        vector <string> s;
        string ini, fim;
        cin >> ini >> fim;
        s.push_back(ini);
        s.push_back(fim);
        map<string , vector<pair<string, string>>> adj;
        map <string, map<char,long long>> dist;
        while(l--){
            cin >> a >> b >> d;
            s.push_back(a);
            s.push_back(b);
            adj[a].push_back({b, d});
            dist[a][d[0]] = MAX;
            adj[b].push_back({a, d});
            dist[b][d[0]] = MAX;
        }
        priority_queue<pair<long long, tuple <string, string, string>>> q; 
        q.push({0,{"1", ini, "qualquer"}});
        dist[ini]['1'] = 0;
        while(!q.empty()){
            string a, ant, palavra;
            long long tam = q.top().first;
            tie(palavra, a, ant) = q.top().second;
            q.pop();
            for(auto x: adj[a]){
                string b = x.first, word = x.second; 
                long long w = x.second.length();
                if(b == ant || (palavra[0] == word[0]))continue;
                if(dist[a][palavra[0]] + w < dist[b][word[0]]){
                    dist[b][word[0]] = dist[a][palavra[0]] + w;
                    q.push({-dist[b][word[0]],{word, b, a}});
                }
            }
        }
        long long dist_min = MAX;
        for(auto x: dist[fim]){
            //cout << x.first << "\n";
            dist_min = min(dist_min, x.second);
        }
        if(dist_min == MAX)printf("impossivel\n");
        else printf("%lld\n", dist_min); 
    }
}