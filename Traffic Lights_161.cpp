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
    string s;
    bool flag = true;

    while(flag){
        vec sem;
        while(cin >> s){
            if(s=="0" && sem.empty()){
                cin >> s;
                cin >> s; 
                flag = false;
                break;
            }
            else{
                int num = stoi(s);
                if(num == 0)break;
                sem.push_back(num);
            }   
        }
        if(!flag)break;
        sort(sem.begin(), sem.end());
        int tempo = sem[0]-4;
        int flag2 = 0;
        while(1){
            int cont = 0;
            for(int i = 0; i < sem.size(); i++){
                if((tempo % (sem[i]*2)) < sem[i] - 5){
                    cont++;
                }  
            }
            if(cont == sem.size())break;
            tempo++;
            if(tempo > 18000){
                flag2 = 1;
                break;
            }
        }
        if(flag2)cout << "Signals fail to synchronise in 5 hours\n";
        else{
            int hour = hour = tempo/3600;
            tempo = tempo%3600;
            int min = (tempo/60);
            int sec = tempo%60;
            printf("%02d:%02d:%02d\n", hour, min, sec);

        }
        sem.clear();
            
    }
}