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
        int n, s, k;
        cin >> n >> s >> k;
        map<int, bool> mp;
        forn(i, k) {
            int a;
            cin >> a;
            mp[a] = 1;
        }
        int left = 0, right = 0;
        bool ok1 = 0, ok2 = 0;
        for (int i = s; i >= max(n - k - 5, 1); i--) {
            if (!mp[i]) {
                ok1 = 1;
                break;
            } else {
                left++;
            }
        }
        for (int i = s; i <= min(s + k + 5, n); i++) {
            if (!mp[i]) {
                ok2 = 1;
                break;
            } else
                right++;
        }
        if (!ok1) left = 2e9;
        if (!ok2) right = 2e9;
        //cout << left << " " << right << endl;
        cout << min(left, right) << endl;
    }
    return 0;
}