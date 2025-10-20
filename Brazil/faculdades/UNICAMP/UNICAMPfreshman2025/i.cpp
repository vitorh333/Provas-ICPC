#include <bits/stdc++.h>
using namespace std;
    
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin >> n >> k;
    vector<pair<int,int>> info;
 
    while(n--){
        int a,b; cin >> a >> b;
        info.push_back({a,b});
 
    }
    sort(info.begin(),info.end());
    
    for (int i = 0; i < (int) info.size(); i++){
        if (k >= info[i].first) k += info[i].second; else
            break;
    }
 
    cout << k << '\n';
 
    return 0;
}
