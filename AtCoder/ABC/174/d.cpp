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
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n, k;
    cin >> n >> k;
    priority_queue<double> q;
    forn(i, n) {
        int a;
        cin >> a;
        q.push(a);
    }
    while(k--) {
        double x = q.top();
        cout<<x<<" ";
        q.pop();
        x /= 2.0;
        cout<<x<<endl;
        q.push(x), q.push(x);
    }
    double mx = 0;
    while(!q.empty()) {
        double x = q.top();
        //cout << x << endl;
        q.pop();
        mx = max(mx, x);
    }
    cout << (ll)ceil(mx) << endl;
    return 0;
}
