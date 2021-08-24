#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
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
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n, m, q;
    cin >> n >> m >> q;
    pair<int, int> x, y;
    map<int, int> f, c;
    map<pii, bool> par;
    map<int, vector<int>> mp1;
    map<int, vector<int>> mp2;
    x = {0, 0}, y = {0, 0};
    forn(i, q) {
        int h, w;
        cin >> h >> w;
        f[h]++;
        c[w]++;
        par[{h, w}]=1;
        //debug(h, w, f[h], c[w], x.F, y.S);
        if(f[h] >= x.S) {
            x = {h, f[h]};
            mp1[x.S].pb(x.F);
        }
        if(c[w] >= y.S) {
            y = {w, c[w]};
            mp2[y.S].pb(y.F);
        }
    }
    int ans = 0;
    for(auto p:mp1[x.S]){
        for(auto k:mp2[y.S]){
            ans=max(ans,f[p] + c[k] - par[{p, k}]);
            if(!par[{p,k}])goto done;
        }
    }
    done:;
    cout << ans << endl;
    return 0;
}
