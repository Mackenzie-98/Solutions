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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll suma = 0;
        if( n % 2 == 1 && (n % 10 != 5))cout << "deficient" << endl;
        else {
            for(ll i = 1; i * i <= n; i++) {
                    if(n % i == 0) {
                        if(i * i == n)suma += i;
                        else {
                            if(i == 1)suma += i;
                            else suma += i, suma += n / i;
                        }
                    }
                    if(suma > n)break;
                }
                if(suma < n)cout << "deficient" << endl;
                else if(suma == n)cout << "perfect" << endl;
                else cout << "abundant" << endl;
            }
    }
    return 0;
}
