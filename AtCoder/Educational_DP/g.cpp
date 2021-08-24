#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAX = 1e5 + 5;
vector<int> G[MAX];
int mem[MAX];
int n, m;
int f(int u) {
    int &ans = mem[u];
    if (ans != -1) return ans;
    ans = 0;
    for (auto x : G[u]) {
        ans = max(ans, f(x) + 1);
    }
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    // H ola
    cin >> n >> m;
    memset(mem, -1, sizeof mem);
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
    }
    forn(i, n) { G[0].pb(i + 1); }
    cout << f(0) - 1 << endl;
    return 0;
}