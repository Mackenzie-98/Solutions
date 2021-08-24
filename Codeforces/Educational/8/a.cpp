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
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool mark[26];
        memset(mark, 0, sizeof mark);
        int cnt = 1;
        string ans = "";
        for (int i = 1; i < sz(s); i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else {
                if (cnt % 2) ans += s[i - 1];
                cnt = 1;
            }
        }
        if (cnt % 2) ans += s[sz(s) - 1];
        sort(all(ans));
        auto x = unique(all(ans));
        ans.resize(distance(ans.begin(), x));
        cout << ans << endl;
    }
    return 0;
}