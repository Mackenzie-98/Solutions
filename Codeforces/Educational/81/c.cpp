/**
 * @author: Mackenzie
**/
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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        map<char, int> mpt;
        map<char, vector<int>> pos;
        forn(i, sz(t)) mpt[t[i]]++;
        forn(i, sz(s)) {
            if (mpt[s[i]]) {
                pos[s[i]].pb(i);
            }
        }
        int last = -1;
        map<char, int> cur;
        int ans = 0;
        int ind = 0;
        bool ok = 1;
        forn(i, sz(t)) {
            if (sz(pos[t[i]]) == 0) {
                ok = 0;
                break;
            }
            int aux = lower_bound(all(pos[t[i]]), last + 1) - pos[t[i]].begin();
            if (aux >= sz(pos[t[i]])) {
                last = -1;
                cur.clear();
                ans++;
                aux = 0;
            }
            ind = pos[t[i]][aux];
            //cout << t[i] << " " << ind << " " << last << endl;
            if (ind > last) {
                last = ind;
                cur[t[i]]++;
            } else {
                last = -1;
                cur.clear();
                ans++;
            }
        }
        if (ok)
            cout << ans + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}