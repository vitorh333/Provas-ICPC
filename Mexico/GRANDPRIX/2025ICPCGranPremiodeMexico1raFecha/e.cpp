#include <bits/stdc++.h>
using namespace std;
    
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    int ans = -1;
    vector<int> v(n);
    for (int &y : v) cin >> y;
    for (int i = 0; i < n; i++){
        if (v[i] >= m) {
            ans = i + 1;
            break;
        }
    }
 
    cout << ans << '\n';
    return 0;
}
