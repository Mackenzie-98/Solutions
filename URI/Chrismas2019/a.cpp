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
    int n, m, p;
    while (cin >> n >> m >> p) {
        vector<pii> points;
        map<pair<int, int>, bool> mp;
        forn(i, p) {
            int x, y;
            cin >> x >> y;
            points.pb({x, y});
            mp[{x, y}] = 1;
        }
        bool ok = 1;
        for (int i = 0; i < p - 1; i++) {
            for (int j = i + 1; j < p; j++) {
                bool ok1 = 0, ok2 = 0, ok3 = 0;
                int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
                x1 = min(points[i].F, points[j].F);
                x2 = max(points[i].F, points[j].F);
                y1 = min(points[i].S, points[j].S);
                y2 = max(points[i].S, points[j].S);
                ok1 = x1 == x2;
                ok2 = y1 == y2;
                if (!ok1 && !ok2) {
                    for (int a = y1; a <= y2; a++) {
                        for (int b = x1; b <= x2; b++) {
                            pair<int, int> pi = {b, a};
                            if (pi != points[i] && pi != points[j]) {
                                if (mp[{pi.F, pi.S}]) {
                                    ok3 = 1;
                                    goto done1;
                                }
                            }
                        }
                    }
                    // for (int k = x1; k < x2; k++) {
                    //     if (mp[{k, y2}] || mp[{x2 - (k - x1), y1}]) {
                    //         ok3 = 1;
                    //         break;
                    //     }
                    // }
                    // for (int k = y1; k < y2; k++) {
                    //     if (mp[{x2, k}] || mp[{x1, y2 - (k - y1)}]) {
                    //         ok3 = 1;
                    //         break;
                    //     }
                    // }
                }
            done1:;
                if (!ok1 && !ok2 && !ok3) {
                    //cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
                    ok = 0;
                    goto done;
                }
            }
        }
    done:;
        if (ok)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}