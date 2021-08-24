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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n, q;
    cin >> n >> q;
    set<pii> lava;
    int blocks = 0;
    forn(i, q) {
        int x, y;
        cin >> x >> y;
        pii p1, p2, p3;
        p1 = {x == 2 ? 1 : 2, y - 1};
        p2 = {x == 2 ? 1 : 2, y};
        p3 = {x == 2 ? 1 : 2, y + 1};
        if (!lava.count({x, y})) {
            lava.insert({x, y});
            if (lava.count(p1)) blocks++;
            if (lava.count(p2)) blocks++;
            if (lava.count(p3)) blocks++;
        } else {
            lava.erase({x, y});
            if (lava.count(p1)) blocks--;
            if (lava.count(p2)) blocks--;
            if (lava.count(p3)) blocks--;
        }
        if (blocks == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}