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
const int MAX = 2e4;
bitset<MAX + 1> marked;
vector<int> primes;
/// O(MAX log(log(MAX)))
void sieve() {
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MAX; i++)
        if (!marked[i]) {
            primes.push_back(i);
            for (ll j = 1ll * i * i; j <= MAX; j += i) marked[j] = true;
        }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n++;
        if (n % 7 == 0 && n % 2 == 1 && !marked[n + 2]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}