#include <bits/stdc++.h>
using namespace std;
    
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<long long> v(n);
    for (long long &y : v) cin >> y;
    vector<long long> pref(n);
    pref[0] = v[0];
 
    for (int i = 1; i < n; i++){
        pref[i] = v[i] + pref[i - 1];
    }
    /* cout << "soma indo:" << '\n';
    for (int i = 0; i < n; i++) cout << pref[i] << " ";
    cout << '\n';
    */
    vector<long long> suf(n);
    map<long long,long long> freq;
    suf[n - 1] = v[n - 1];
    freq[v[n - 1]]++;
    for (int i = n - 2; i >= 0; i--){
        suf[i] = v[i] + suf[i + 1];
        freq[suf[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++){
        if (freq.count(pref[i])){
            if (freq[pref[i]] == 0){
                ans++;
            }else {
                freq[pref[i]]--;
            }
        }else {
            ans++;
        
        }
    }
  /*  cout << "soma voltando: " << '\n';
    for (int i = n - 1; i >= 0; i--) cout << suf[i] << " ";
    */ 
    cout << ans << '\n';
 
 
    return 0;
}
 
