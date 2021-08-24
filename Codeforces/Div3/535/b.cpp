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
ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}
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
    map<int, int> mp;
    forn(i, n) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    sort(arr, arr + n);
    int x = arr[n - 1];
    int y = arr[n - 2];
    for (int i = n - 2; i >= 0; i--) {
        if (mp[arr[i]] == 2 || x % arr[i] != 0) {
            y = arr[i];
            break;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}