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
ll mod = 1e9 + 7;
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    ll A[n];
    ll sum = 0;
    forn(i, n) cin >> A[i];
    sort(A, A + n);
    forn(i, n) cout << A[i] << " ";
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << (A[i] ^ A[j]) << endl;
            sum = (sum % mod + (A[i] ^ A[j]) % mod) % mod;
        }
    }
    cout << sum << endl;
    return 0;
}