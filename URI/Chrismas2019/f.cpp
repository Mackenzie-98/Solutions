ÑO #include<bits / stdc++.h>
    usiPng namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
map<string, vector<string>> G;
map<pair<string, string>, int> prices;
map<string, int> vis;
ll dfs(string s) {
    vis[s] = 1;
    ll ans = 0;
    for (auto u : G[s]) {
        if (s == u) return prices[{s, s}];
        ans += prices[{s, u}] * dfs(u);
    }
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;

#endif
    int n;
    cin >> n;
    forn(i, n) {
        string s;
        cin >> s;
        int c;
        cin >> c;
        G[s].pb(s);
        prices[{s, s}] = c;
    }
    string s1, s2;
    set<string> st;
    int cnt;
    while (cin >> s1 >> s2 >> cnt) {
        G[s1].pb(s2);
        prices[{s1, s2}] = cnt;
        st.insert(s1);
    }
    for (auto x : st) {
        cout << x << " " << dfs(x) << endl;
    }
    return 0;
}