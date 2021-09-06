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
    string a, b, c;
    int k = 1;
    while(cin >> a >> b>> c){
        if(a == "E" && b == "N" && c == "D")break;
        vector <string> res;
        
        if(a=="?" || b == "?"){
            int pos = 0;
            int flag2 = 0;
            if(b == "?"){
                swap(a,b);
                pos = 1;
            }
            if((b =="A+" && c == "A+") || (b =="A+" && c == "A-") 
            || (b =="A-" && c == "A-") || (b =="B+" && c == "B+") 
            || (b =="B+" && c == "B-") || (b =="B-" && c == "B-")
            || (b=="AB+" && c == "B+") || (b=="AB+" && c == "B-")
            || (b=="AB-" && c == "B-") || (b=="AB+" && c == "A+") 
            || (b=="AB+" && c == "A-") || (b=="AB-" && c == "A-")){
                res.push_back("O-");
                res.push_back("O+");
                res.push_back("AB-");
                res.push_back("AB+");
                res.push_back("B-");
                res.push_back("B+");
                res.push_back("A-");
                res.push_back("A+");
            }
            else if((b=="AB-" && c == "B+") || (b=="AB-" && c == "A+")
            || (b =="A-" && c == "A+") || (b =="B-" && c == "B+")){
                res.push_back("O+");
                res.push_back("AB+");
                res.push_back("B+");
                res.push_back("A+");
            }
            
            else if((b=="A+" && c == "B+") || (b=="A+" && c == "B-")
            || (b=="O+" && c=="B+")  || (b=="O+" && c =="B-") 
            || (b=="A-" && c =="B-") || (b=="O-" && c=="B-") 
            || (b=="A-" && c=="AB-") || (b=="A+" && c=="AB+") 
            || (b=="A+" && c=="AB-")){
                res.push_back("AB-");
                res.push_back("AB+");
                res.push_back("B-");
                res.push_back("B+");
            }
            else if((b=="A-" && c =="B+") || (b=="O-" && c=="B+")
            || (b=="A-" && c=="AB+")){

                res.push_back("AB+");
                res.push_back("B+");

            }
    
            else if((b=="B+" && c == "A+") || (b=="B+" && c == "A-")
            || (b=="O+" && c=="A+") || (b=="O+" && c =="A-") 
            || (b=="B-" && c =="A-") || (b=="O-" && c=="A-") 
            || (b=="B-" && c=="AB-") || (b=="B+" && c=="AB+") 
            || (b=="B+" && c=="AB-")){
                res.push_back("AB-");
                res.push_back("AB+");
                res.push_back("A-");
                res.push_back("A+");
            }
            else if((b=="B-" && c =="A+") || (b=="O-" && c=="A+")
            || (b=="B-" && c=="AB+")){
                res.push_back("AB+");
                res.push_back("A+");
            }
            
            else if((b == "A-" && c == "O-") || (b == "A+" && c == "O-")
            || (b == "A+" && c == "O+") || (b == "B-" && c == "O-") 
            || (b == "B+" && c == "O-") || (b == "B+" && c == "O+") 
            || (b == "O+" && c == "O+") || (b == "O+" && c == "O-") 
            || (b == "O-" && c == "O-")){
                res.push_back("O-");
                res.push_back("O+");
                res.push_back("B-");
                res.push_back("B+");
                res.push_back("A-");
                res.push_back("A+");
            }
            else if((b == "A-" && c == "O+") ||  (b == "B-" && c == "O+")){
                res.push_back("O+");
                res.push_back("B+");
                res.push_back("A+");
            }
            else if((b=="AB+" && c == "AB+") || (b=="AB+" && c == "AB-")
            ||  (b=="AB-" && c == "AB-")){
                res.push_back("AB-");
                res.push_back("AB+");
                res.push_back("B-");
                res.push_back("B+");
                res.push_back("A-");
                res.push_back("A+");
            }
            else if((b=="AB-" && c == "AB+")){
                res.push_back("AB+");
                res.push_back("B+");
                res.push_back("A+");
            }
            else if((b == "O-" && c == "O+")){
                res.push_back("O+");
                res.push_back("B+");
                res.push_back("A+");
            }
            else{
                flag2 = 1;
            }
            cout << "Case " << k << ": ";
            if(pos==0){
                if(flag2){
                    cout << "IMPOSSIBLE " << b << " " << c << "\n";
                }
                else{
                    cout << "{";
                    int flag = 0;
                    for(int i = 0; i < res.size();i++){
                        if(flag)cout << ", ";
                        flag = 1;
                        cout << res[i];
                    }
                    cout << "} " << b << " " << c << "\n";
                }
            }
            else{
                if(flag2){
                    cout << b << " IMPOSSIBLE " << c << "\n";
                }
                else{
                    cout << b << " {";
                    int flag = 0;
                    for(int i = 0; i < res.size();i++){
                        if(flag)cout << ", ";
                        flag = 1;
                        cout << res[i];
                    }
                    cout << "} " << c << "\n";
                }
            }
        }
        
        else{
            int point = 0;
            if((a == "A+" && b == "A+") || (a == "A-" && b == "A+") || (a == "A+" && b == "A-") ||
            (a == "O+" && b == "A+") || (a == "O-" && b == "A+") || (a == "O+" && b == "A-") ||
            (a == "A+" && b == "O+") || (a == "A+" && b == "O-") || (a == "A-" && b == "O+")){
                res.push_back("O-");
                res.push_back("O+");
                res.push_back("A-");
                res.push_back("A+");
            }
            if((a == "A-" && b == "A-") || (a == "O-" && b == "A-") || (a == "A-" && b == "O-")){
                res.push_back("O-");
                res.push_back("A-");
            }
            if((a == "B+" && b == "B+") || (a == "B-" && b == "B+") || (a == "B+" && b == "B-") ||
            (a == "O+" && b == "B+") || (a == "O-" && b == "B+") || (a == "O+" && b == "B-") ||
            (a == "B+" && b == "O+") || (a == "B+" && b == "O-") || (a == "B-" && b == "O+")){
                res.push_back("O-");
                res.push_back("O+"); 
                res.push_back("B-");
                res.push_back("B+");
            }
            if((a == "B-" && b == "B-") || (a == "O-" && b == "B-") || (a == "B-" && b == "O-")){
                res.push_back("O-");
                res.push_back("B-");
            }

            if((a == "A+" && b == "B+") || (a == "A+" && b == "B-") || 
            (a == "A-" && b == "B+")  || (a == "B+" && b == "A+")  || 
            (a == "B+" && b == "A-") || (a == "B-" && b == "A+")){
                res.push_back("O-");
                res.push_back("O+");
                res.push_back("AB-");
                res.push_back("AB+");
                res.push_back("B-");
                res.push_back("B+");
                res.push_back("A-");
                res.push_back("A+");
            }
            if((a== "A-" && b == "B-") || (a == "B-" && b == "A-")){
                res.push_back("O-");
                res.push_back("AB-");
                res.push_back("B-");
                res.push_back("A-");
            }

            if((a=="O+" && b=="O-") || (a=="O-" && b == "O+") 
            || (a=="O+" && b=="O+")){
                res.push_back("O-");
                res.push_back("O+");
            }
            if(a=="O-" && b=="O-"){
                res.push_back("O-");
            }
            if((a=="AB+" && b=="AB-") || (a=="AB-" && b=="AB+")
            || (a=="AB+" && b=="A-")  || (a=="AB+" && b=="A+")
            || (a=="AB-" && b=="A+")  || (a=="AB+" && b=="B-")
            || (a=="AB+" && b=="B+")  || (a=="AB-" && b=="B+")
            || (a=="A-" && b=="AB+")  || (a=="A+" && b=="AB-")
            || (a=="A+" && b=="AB+")  || (a=="B-" && b=="AB+")
            || (a=="B+" && b=="AB+")  || (a=="B+" && b=="AB-")
            || (a=="AB+" && b == "AB+")){
                res.push_back("AB-");
                res.push_back("AB+");
                res.push_back("B-");
                res.push_back("B+");
                res.push_back("A-");
                res.push_back("A+");
            }
            if((a=="AB-" && b=="AB-") || (a=="AB-" && b=="B-")  
            || (a=="AB-" && b=="A-") || (a=="B-"  && b =="AB-") 
            || (a=="A-" && b=="AB-")){
                res.push_back("AB-");
                res.push_back("B-");
                res.push_back("A-");
            }
            if((a=="O+" && b=="AB+") || (a=="O-" && b == "AB+") 
            || (a=="O+" && b=="AB-") || (a=="AB-" && b == "O+")
            || (a=="AB+" && b == "O-") || (a=="AB+" && b == "O+")){
                res.push_back("B-");
                res.push_back("B+");
                res.push_back("A-");
                res.push_back("A+");
            }
            if((a=="O-" && b=="AB-") || (a=="AB-" && b == "O-")){
                res.push_back("B-");
                res.push_back("A-");
            }
            cout << "Case " << k << ": ";
            if(res.size()==1){
                cout << a << " " << b << " " << res[0] << "\n";
            }
            else{
                cout << a << " " << b << " {";
                int flag = 0;
                for(int i = 0; i < res.size();i++){
                    if(flag)cout << ", ";
                    flag = 1;
                    cout << res[i];
                }
                cout << "}\n";
            }
        }
        k++;
        
    }
    return 0;
}