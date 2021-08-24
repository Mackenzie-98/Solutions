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
        int n;
        string s;
        cin >> n >> s;
        pii cur = {0, 0};
        map<pii, int> pos;
        pos[cur] = 1;
        int mn = 1e9;
        int x = -1, y = -1;
        forn(i, n) {
            if (s[i] == 'L') cur.F--;
            if (s[i] == 'R') cur.F++;
            if (s[i] == 'U') cur.S++;
            if (s[i] == 'D') cur.S--;
            if (pos[cur] != 0) {
                int dis = abs(i - pos[cur]);
                if (dis < mn) {
                    mn = dis;
                    x = pos[cur];
                    y = i + 1;
                }
            }
            pos[cur] = i + 2;
        }
        if (x == -1 || y == -1)
            cout << -1 << endl;
        else
            cout << x << " " << y << endl;
    }
    return 0;
}