#include <bits/stdc++.h>
using namespace std;
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
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool mark[26];
    memset(mark, 0, sizeof mark);
    forn(i, k) {
        char x;
        cin >> x;
        mark[x - 'a'] = 1;
    }
    vector<ll> prod;
    int cnt = 0;
    for (int i = 0; i < sz(s); i++) {
        if (mark[s[i] - 'a']) {
            cnt++;
        } else {
            prod.pb(cnt);
            cnt = 0;
        }
    }
    prod.pb(cnt);
    ll ans = 0;
    for (auto x : prod) {
        ans += x * (x + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}