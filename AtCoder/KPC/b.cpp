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
bool cmp(const pii a, const pii b) {
    return a.S < b.S;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    vector<pii> segments;
    forn(i, n) {
        int x, l;
        cin >> x >> l;
        segments.pb({x - l, x + l});
    }
    sort(all(segments), cmp);
    int ans = 1;
    pii cur = segments[0];
    for (int i = 1; i < n; i++) {
        if (segments[i].F >= cur.S) ans++, cur = segments[i];
    }
    cout << ans << endl;
    return 0;
}