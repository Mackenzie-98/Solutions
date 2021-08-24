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
        int n;
        cin >> n >> s;
        // cout << "h1" << endl;
        int sz = n;
        for (int i = n - 1; i >= 0; i--) {
            if ((s[i] - '0') % 2 == 0) {
                s.pop_back();
                sz--;
            } else {
                break;
            }
        }
        int sum = 0;
        int pos = -1;
        for (int i = 0; i < sz(s); i++) {
            int ch = (s[i] - '0');
            sum += ch;
            if (pos == -1 && ch & 1 && !(sz(s) >= 2 && i == 0 && s[i + 1] == '0')) pos = i;
        }
        // cout << "h2" << endl;
        if ((sum & 1) && pos != -1) {
            char x = s[pos];
            s.erase(s.begin() + pos);
            sum -= (x - '0');
        }
        // cout << "h3" << endl;
        if (sz(s) != 0 && (sum % 2 == 0) && (s[0] != '0') && (s[sz(s) - 1] - '0') & 1) {
            cout << s << endl;
        } else
            cout << -1 << endl;
    }
    return 0;
}