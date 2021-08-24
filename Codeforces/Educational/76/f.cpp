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
    int n;
    cin >> n;
    int arr[n];
    forn(i, n) cin >> arr[i];
    vector<int> middle1, middle2;
    for (int i = 0; i < (1 << 15); i++) {
        middle1.pb(i);
    }
    for (int i = 0; i < (1 << 15); i++) {
        middle2.pb(__builtin_popcount((1 << 15) + i));
    }
    sort(all(middle2));
    for (int i = 0; i < sz(middle1); i++) {
        int v = __builtin_popcount(middle1[i] ^ arr[0]);
        int ind = lower_bound(all(middle2), v);
    }
    return 0;
}