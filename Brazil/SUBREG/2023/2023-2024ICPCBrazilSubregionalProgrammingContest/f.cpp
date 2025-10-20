#include <bits/stdc++.h>
using namespace std;
    
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int d,c,r; cin >> d >> c >> r;
    vector<int> vi(c);
    vector<int> vr(r);
    for (int &y : vi) cin >> y;
    for (int &y : vr) cin >> y;
 
    int leftc = 0;
    int leftr = 0;
    
    int ans = 0;
    bool valid = true;
    while(valid){
        if (leftc < c){
            if (vi[leftc] <= d){
                ans++;
                d -= vi[leftc];
                leftc++;  
            }else {
                if (leftr < r){
                    ans++;
                    d += vr[leftr];
                    leftr++;
                }else {
                    valid = false;
                    break;
                }
            }
        }else {
            if (leftr >= r){
                valid = false;
                break;
            }else {
                ans++;
                leftr++;
            }
        }        
    }
 
    
    cout << ans << '\n';
 
    return 0;
}
