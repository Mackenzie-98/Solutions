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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    vector<ull> a(n);
    forn(i, n) cin >> a[i];
    vector<ull> suffix(n, 0), prefix(n, 0);
    prefix[0] = ~a[0];
    suffix[n - 1] = ~a[n - 1];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] & (~a[i]);
        suffix[n - i - 1] = suffix[n - i] & (~a[n - i - 1]);
    }
    ull mx = 0;
    int ind = 0;
    ll flag = 0;
    for (ll i = 0; i < 32; i++) {
        flag += (1ll << i);
    }
    forn(i, n) {
        ull cur = (i == 0 ? flag : prefix[i - 1]) & (a[i]) & (i == n - 1 ? flag : suffix[i + 1]);
        if (cur > mx) {
            mx = cur;
            ind = i;
        }
    }
    cout << a[ind] << " ";
    forn(i, n) {
        if (i != ind) cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}