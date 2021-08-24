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
    int n;
    cin >> n;
    vector<int> s(n);
    int sum = 0;
    forn(i, n) cin >> s[i], sum += s[i];
    if (sum % 10 != 0)
        cout << sum << endl;
    else {
        sort(all(s));
        forn(i, n) {
            if ((sum - s[i]) % 10 != 0) {
                sum -= s[i];
                break;
            }
        }
        if (sum % 10 != 0)
            cout << sum << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}