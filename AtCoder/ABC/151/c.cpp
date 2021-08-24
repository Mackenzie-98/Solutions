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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    bool mark[n + 2];
    memset(mark, 0, sizeof mark);
    int ac = 0, wa = 0;
    forn(i, m) {
        int v;
        string c;
        cin >> v >> c;
        if (mark[v])
            continue;
        else {
            if (c == "WA") {
                mp[v]++;
            } else {
                mark[v] = 1;
                wa += mp[v];
                ac++;
            }
        }
    }
    cout << ac << " " << wa << endl;
    return 0;
}