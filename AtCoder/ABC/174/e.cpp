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

const int MAX = 2e5 + 5;
int A[MAX];
int n, k;

int check(int x) {
    int cnt = 0;
    forn(i, n) {
        if(A[i] > x)cnt += A[i] / x;
    }
    return cnt;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin >> n >> k;
    forn(i, n)cin >> A[i];
    int lo = 1, hi = 1e9;
    forn(it, 70) {
        int m = (lo + hi) / 2;
        //cout << m << endl;
        if(check(m) <= k)hi = m;
        else lo = m;
    }
    cout << hi << endl;
    return 0;
}
