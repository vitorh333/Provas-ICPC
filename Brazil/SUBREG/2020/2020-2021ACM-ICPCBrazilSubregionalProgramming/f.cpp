#include "bits/stdc++.h"
using namespace std;
 
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
 
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s; cin >> s;
    int n = (int) s.size();
 
    int gamesLeft = 0;
    int gamesRight = 0;
    int pontosLeft = 0;
    int pontosRight = 0;
 
    int currSaque = 0;
    bool isOver = false;
    for (int i = 0; i < n; i++){
        //cout << "Pontos Left, PontosRight: " << pontosLeft << " " << pontosRight << '\n';
        //cout << "Games left, gamesRight: " << gamesLeft << " " << gamesRight << '\n';
        char q = s[i];
        if (isOver && q != 'Q') continue;
        if (q == 'S'){
            if (currSaque == 0){
                pontosLeft++;
                currSaque  = 0;
            }else {
                pontosRight++;
                currSaque = 1;
            }
        }else if (q == 'R'){
            if (currSaque == 0){
                pontosRight++;
                currSaque = 1;
            }else {
                pontosLeft++;
                currSaque = 0;
            }
        }else {
            //cout << "Resultados em q: " << '\n';
            //cout << "Pleft,Pright,Gleft,GRight: " << pontosLeft << " " << pontosRight << " " << gamesLeft << " " << gamesRight << '\n';
            if (isOver){
                
                if (gamesLeft > gamesRight){
                    cout << gamesLeft << " (winner) - " << gamesRight << '\n';
                }else {
                    cout << gamesLeft << " - " << gamesRight << " (winner)";  
                }
                /*
                cout << gamesLeft << " ";
                if (gamesLeft > gamesRight){
                    cout << "(winner) - ";
                }
                cout << gamesRight << " ";
                if (gamesRight > gamesLeft){
                    cout << "(winner)";
                }
                continue;
                */
                continue;
            }
            if (currSaque == 0){
                cout << gamesLeft << " (" << pontosLeft << "*) - " << gamesRight << " (" << pontosRight << ")" << '\n';
            }else {
                cout << gamesLeft << " (" << pontosLeft << ") - " << gamesRight << " (" << pontosRight << "*)" << '\n';
            }
        }
        if (pontosLeft == 10 && pontosRight != 10){
            pontosLeft = 0;
            pontosRight = 0;
            gamesLeft++;
        }else if (pontosLeft != 10 && pontosRight == 10){
            //cout << "entrou aqui em: " << i << '\n';
            pontosLeft = 0;
            pontosRight = 0;
            gamesRight++;
        }else if (pontosLeft >= 5 && pontosLeft - pontosRight >= 2){
            pontosLeft = 0;
            pontosRight = 0;
            gamesLeft++;
        }else if (pontosRight >= 5 && pontosRight - pontosLeft >= 2){
            //cout << "entrou aqui em: " << i << '\n';
            pontosLeft = 0;
            pontosRight = 0;
            gamesRight++;
        }
 
        if (gamesRight == 2 || gamesLeft == 2){
            isOver = true;
        }
        //cout << "pontos left, pontos right: " << pontosLeft << " " << pontosRight << '\n';
        //cout << "games left, games right: " << gamesLeft << " " << gamesRight << '\n';
        
    }
}
