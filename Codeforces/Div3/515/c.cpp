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
const int MAXN = 1e6;
int ft[MAXN + 1];
void upd(int i0, int v) {
    for (int i = i0 + 1; i <= MAXN; i += i & -i) ft[i] += v;
}
int get(int i0) {
    int r = 0;
    for (int i = i0; i; i -= i & -i) r += ft[i];
    return r;
}
int get_sum(int i0, int i1) {
    return get(i1) - get(i0);
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    memset(ft, 0, sizeof ft);
    int t;
    cin >> t;
    int r = 3e5;
    int l = 3e5 - 1;
    map<int, int> mp;
    while (t--) {
        char op;
        int id;
        cin >> op >> id;
        if (op == 'L') {
            upd(l, 1);
            mp[id] = l;
            l--;
        } else if (op == 'R') {
            upd(r, 1);
            mp[id] = r;
            r++;
        } else {
            int left = get_sum(l, mp[id]);
            int right = get_sum(mp[id] + 1, r + 1);
            cout << min(left, right) << endl;
        }
    }
    return 0;
}