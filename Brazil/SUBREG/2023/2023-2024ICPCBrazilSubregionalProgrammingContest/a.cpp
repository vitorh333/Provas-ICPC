#include <bits/stdc++.h>
using namespace std;
    
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,h; cin >> n >> h;
    vector<int> v(n);
 
    for (int &y : v) cin >> y;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (v[i] <= h) ans++;
    }
    cout << ans << '\n';
    return 0;
}
  
