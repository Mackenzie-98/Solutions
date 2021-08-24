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
    string s, t;
    cin >> s >> t;
    vector<string> v;
    for(int i = 0; i < sz(s) - sz(t) + 1; i++) {
        v.pb(s.substr(i, sz(t)));
    }
    int ans = sz(s);
    for(auto x : v) {
        int cnt = 0;
        forn(i, sz(x)) {
            if(x[i] != t[i])cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
