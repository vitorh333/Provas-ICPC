#include <bits/stdc++.h>
using namespace std;
    
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n; cin >> n;
 
    while(n--){
        string target; cin >> target;
        string temp = s;
 
        while(temp.size() < target.size()){
            temp += s;
        }
        if (target == temp){
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
 
    }
    return 0;
}
  
