#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define ft first
#define sd second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}
const int MX=100;
vector<int> luckys;
bool mark[MX+1];

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int acum=1;
    for(int i=1; i<=MX; i++) {
        if(!mark[i]) {
            luckys.pb(i);
            for(int j=i+acum; j<=MX; j+=(j-i)/acum) {
                debug(i,j);
                mark[j]=true;
            }
            acum++;
        }
    }
    for(int i=0; i<10; i++)cout<<luckys[i]<<endl;
    return 0;
}
