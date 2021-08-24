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
    int x;
    cin >> x;
    for (int a = 0; a <= 30; a++) {
        for (int b = 0; b <= 30; b++) {
            for (int c = 0; c <= 30; c++) {
                for (int d = 0; d <= 30; d++) {
                    for (int e = 0; e <= 30; e++) {
                        int f = (x - (100 * a + 101 * b + 102 * c + 103 * d + 104 * e)) / 105;
                        if (f >= 0 && f <= 1000000 && 100 * a + 101 * b + 102 * c + 103 * d + 104 * e + 105 * f == x) {
                            cout << 1 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << 0 << endl;

    return 0;
}