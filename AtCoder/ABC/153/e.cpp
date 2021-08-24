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
const int MAX_N = 1e3 + 5;
const int MAX_H = 1e4 + 5;
ll h, n;
pll v[MAX_H];
ll memo[MAX_N][MAX_H];
ll cost(int i, ll x) {
    //cout << i << " " << x << endl;
    if (x <= 0) return 0;
    if (i >= n) return 1e9;
    ll &ans = memo[i][x];
    if (ans != -1) return ans;
    ans = 0;
    ans = min(cost(i, x - v[i].F) + v[i].S, min(cost(i + 1, x - v[i].F) + v[i].S, cost(i + 1, x)));
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    memset(memo, -1, sizeof memo);
    cin >> h >> n;
    forn(i, n) cin >> v[i].F >> v[i].S;
    cout << cost(0, h) << endl;
    // int mn = 1e9;
    // pll best = {0, 0};
    // forn(i, n) {
    //     if (v[i].S - v[i].F < mn) {
    //         mn = v[i].S - v[i].F;
    //         best = v[i];
    //     }
    // }
    // ll cost = best.S * (h / best.F);
    // cout << h % best.F << endl;
    // cout << cost << endl;
    // if (h % best.F != 0) {
    //     int mnc = 1e9;
    //     forn(i, n) {
    //         if (v[i].F >= h % best.F && v[i].S < mnc) {
    //             mnc = v[i].S;
    //         }
    //     }
    //     cost += mnc;
    // }
    // //h = h - best.F * (h / best.F);

    // cout << cost << endl;
    return 0;
}