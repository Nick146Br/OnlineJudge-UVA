#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef vector <int> vec;
typedef vector <pa> vep;


int main(){
    int h, u, d, f;
    while(cin >> h >> u >> d >> f){
        if(h ==0)break;
        double per = (double)f/100;
        double c = u*per;
        int i = u, k = 1;
        if(i > h){
            cout << "success on day " << k << "\n";
        }
        else if(i - d < 0){
            cout << "failure on day " << k << "\n";
        }
        else{
            double x = (double)i;
            x-=d;
            k = 1;
            // double dist = c*k
            while(x >= 0 && x <= h){
                
                if(u-c*k > 0)x += u-c*k;

                if(x > h){
                    k++;
                    break;
                }
                x -= d;   
                k++;
            }
            if(x<0)cout << "failure on day " << k << "\n";
            else cout << "success on day " << k << "\n";
        }


    }
}