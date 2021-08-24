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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool flag = s[0] == '1';
        string ans = "";
        set<char> st;
        forn(i, sz(s)) {
            st.insert(s[i]);
            if (flag)
                ans += "10";
            else
                ans += "01";
        }
        if (sz(st) == 1) {
            forn(i, sz(s)) cout << s[0];
            cout << endl;
        } else
            cout << ans << endl;
    }
    return 0;
}