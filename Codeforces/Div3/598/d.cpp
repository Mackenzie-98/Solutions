#include <bits/stdc++.h>
using namespace std;
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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll pre[n];
        pre[0] = (s[0] == '1' ? 1ll : 0ll);
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = 0;
            }
        }
        ll cnt = 0;
        ll carry = 0;
        forn(i, sz(s)) {
            if (i != 0 && s[i] == '0') {
                cnt = min(pre[i - 1] + cnt, k);
                swap(s[i], s[i - min(cnt, k)]);
                k -= cnt;
                if (k <= 0) {
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}