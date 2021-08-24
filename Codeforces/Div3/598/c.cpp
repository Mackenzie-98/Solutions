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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> platforms;
    int all = 0;
    forn(i, m) {
        int x;
        cin >> x;
        all += x;
        platforms.pb(x);
    }
    int rec[n];
    int label = 1;
    int cnt = 0;
    memset(rec, 0, sizeof rec);
    for (int i = n - all; i < n; i++) {
        rec[i] = label;
        cnt++;
        if (cnt == platforms[label - 1]) {
            label++;
            cnt = 0;
        }
    }
    // for (auto x : rec) cout << x << " ";
    // cout << endl;
    int ind = 0;
    int cur = d - 1;
    int size = platforms[ind++];
    int p = n - all;
    bool ok = 1;
    while (cur <= n - 1) {
        if (!rec[cur]) {
            if (ind > m) {
                ok = 0;
                break;
            }
            for (int i = cur; i < cur + size; i++) {
                swap(rec[i], rec[p++]);
            }
            cur = cur + size - 1;
            size = platforms[ind++];
        }
        cur += d;
    }
    if (!ok)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (auto x : rec) cout << x << " ";
        cout << endl;
    }
    return 0;
}