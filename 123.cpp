#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef vector <int> vec;
typedef vector <pa> vep;

int main(){
    ll n,k,x;
    cin >> n >> k >> x;
    vector<int>v;
    ll a;
    for(ll i=0;i<n;i++){
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(),v.end());
    ll sum=0;
    ll pos;
    ll sum2=0;
    for(int i=0;i<n;i++){
      pos = lower_bound(v.begin(),v.end(),v[i]+x) - v.begin();
      if(abs(v[pos]-v[pos-1])>=x*2){
          sum++;
      }else if(abs(v[pos]-v[pos-1])>x){
        sum2++;
      }
      i = pos-1;
    }
    cout << sum+sum2-k << endl;

}