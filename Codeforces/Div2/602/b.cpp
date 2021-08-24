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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        bool mark[n + 1];
        memset(mark, 0, sizeof mark);
        forn(i, n) cin >> arr[i];
        int cur = 1;
        bool ok = 1;
        vector<int> ans;
        forn(i, n) {
            if (!mark[arr[i]]) {
                ans.pb(arr[i]);
                mark[arr[i]] = 1;
            } else {
                while (mark[cur]) {
                    cur++;
                }
                if (cur >= arr[i]) {
                    ok = 0;
                    break;
                }
                ans.pb(cur);
                mark[cur] = 1;
                cur++;
            }
        }
        if (ok) {
            for (auto &x : ans) cout << x << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}