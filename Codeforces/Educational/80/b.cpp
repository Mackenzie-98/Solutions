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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    // for (ll A = 2; A <= 9; A++) {
    //     for (ll B = 1; B <= 99; B++) {
    //         // ll A, B;
    //         // while (cin >> A >> B) {
    //         ll cnt = 0;
    //         for (int i = 1; i <= A; i++) {
    //             for (int j = 1; j <= B; j++) {
    //                 ll a = i, b = j;
    //                 ll N = stoll(to_string(a) + to_string(b));
    //                 //cout << a * b + a + b << " " << N << endl;
    //                 if (a * b + a + b == N) {
    //                     //cout << a * b + a + b << " " << N << endl;
    //                     cnt++;
    //                 }
    //             }
    //         }
    //         cout << A << " " << B << " " << cnt << endl;
    //     }
    // }
    // }
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        string nine;
        string num = to_string(b);
        int k = sz(to_string(b));
        forn(i, sz(num)) {
            nine += '9';
        }
        cout << a * (sz(num) - (b >= stoll(nine) ? 0 : 1)) << endl;
    }
    return 0;
}