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
const int MAX = 1e6+1;
int prime[MAX + 1];
void sieve() {
    for (int i = 2; i <= MAX; i++) if (!prime[i]) {
            prime[i] = i;
            for (ll j = 1ll * i * i; j <= MAX; j += i) {
                if (!prime[j]) prime[j] = i;
            }
        }
}
void fact(int n, map<int, int> &f) {
    while (n > 1) {
        f[prime[n]]++;
        n /= prime[n];
    }
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
    sieve();
    int n;
    cin >> n;
    vector<int> v(n);
    int g ;
    cin >> g;
    v[0] = g;
    forn(i, n - 1)cin >> v[i + 1], g = __gcd(g, v[i + 1]);
    bool ok = 1;
    map<int, bool> mp;
    for(int i = 0; i < n && ok; i++) {
        map<int, int> factores;
        fact(v[i], factores);
        for(auto x : factores) {
            if(mp[x.F]) {
                ok = 0;
                break;
            }
            mp[x.F] = 1;
        }
    }
    if(ok)cout << "pairwise coprime" << endl;
    else if(g == 1)cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    return 0;
}
