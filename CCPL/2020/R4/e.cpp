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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAX = 1e5;
bool mark[MAX];
void sieve() {
    mark[0] = mark[1] = 1;
    for (ll i = 2; i * i <= MAX; i++) {
        for (ll j = i * i; j <= MAX; j += i) {
            if (!mark[j]) mark[j] = 1;
        }
    }
}
ull binpow(ull a, int n) {
    if (n == 0) return 1;
    if (n & 1)
        return a * binpow(a * a, n / 2);
    else
        return binpow(a * a, n / 2);
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    ull limx = ULLONG_MAX;
    ull limn = (ull)(sqrt(sqrt(limx)) - 1);
    sieve();
    set<ull> ans;
    forn(i, limn) {
        int x = (int)(log(limx) / log(i + 1));
        for (int j = 4; j <= x; j++) {
            if (mark[j]) {
                ans.insert(binpow(i + 1, j));
            }
        }
    }
    ans.erase(0);
    ans.insert(1);
    for (auto x : ans) cout << x << endl;
    return 0;
}