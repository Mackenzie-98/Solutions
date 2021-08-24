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
    for (int n = 1; n <= 200; n++) {
        int a = 0, b = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            int cur = i;
            while (cur != 0) {
                if (cur % 10 != 0)
                    cnt++;
                cur /= 10;
            }
            if (cnt == 1) a++;
            if (cnt == 2) b++;
            if (cnt == 3) c++;
        }
        cout << n << " " << a << " " << b << " " << c << endl;
    }
    return 0;
}