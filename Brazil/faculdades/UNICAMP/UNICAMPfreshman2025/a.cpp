#include <bits/stdc++.h>
using namespace std;
    
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long p,r,g,x; cin >> p >> r >> g >> x;
    long long ney = 0;
 
    if (g * x <= r){
        ney += g * x * p;
    }else {
        ney += r * p;
    }
 
    cout << ney << '\n';
    return 0;
}
    
    
