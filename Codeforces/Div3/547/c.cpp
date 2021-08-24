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
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
ll n;
bool check(ll x, ll sum[]) {
    bool mark[n + 1];
    memset(mark, 0, sizeof mark);
    int cnt = 0;
    forn(i, n) {
        ll cur = sum[i] + x;
        if (cur >= 1 && cur <= n && !mark[cur]) {
            cnt++;
            mark[cur] = 1;
        } else {
            return false;
        }
    }
    return cnt == n;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin >> n;
    ll q[n];
    forn(i, n - 1) {
        cin >> q[i];
    }
    ll sum[n];
    sum[0] = 0;
    forn(i, n - 1) {
        sum[i + 1] = q[i] + sum[i];
    }
    ll parcial_sum = 0;
    forn(i, n) {
        parcial_sum += sum[i];
    }
    ll x = (n * (n + 1) / 2 - parcial_sum) / n;
    if (!check(x, sum)) {
        cout << -1 << endl;
    } else {
        forn(i, n) {
            cout << sum[i] + x << " ";
        }
        cout << endl;
    }

    return 0;
}