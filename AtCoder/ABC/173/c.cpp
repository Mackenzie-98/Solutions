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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int h, w, k;
    cin >> h >> w >> k;
    char mat[h + 1][w + 1];
    forn(i, h) {
        string cad;
        cin >> cad;
        forn(j, w) {
            mat[i][j] = cad[j];
        }
    }
    int ans = 0;
    for(int mask1 = 0; mask1 < (1 << h); mask1++) {
        for(int mask2 = 0; mask2 < (1 << w); mask2++) {
            int cnt = 0;
            forn(i, h) {
                forn(j, w) {
                    bool bit1 = (mask1 & (1 << i));
                    bool bit2 = (mask2 & (1 << j));
                    if(!(bit1 || bit2) && mat[i][j] == '#')cnt++;
                }
            }
            if(cnt == k)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
