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
    ll n;
    cin >> n;
    ll d = 0;
    cout << 1 << endl;
    cout.flush();
    cin >> d;
    cout << endl;
    if(d == 0) {
        cout << "! 1" << endl;
        cout.flush();
    } else {
        ll lo = (1 << d), hi = (1 << (d + 1)) - 1;
        ll disA = 0, disB = 0;
        cout << lo << endl;
        cout.flush();
        cin >> disA;
        cout << endl;
        cout << hi << endl;
        cout.flush();
        cin >> disB;
        cout << endl;
        while(disA && disB) {
            ll m = (lo + hi) / 2;
            if(disA < disB) {
                hi = m;
                cout << hi << endl;
                cout.flush();
                cin >> disB;
                cout << endl;
            } else {
                lo = m+((lo + hi)%2);
                cout<<lo<<endl;
                cout.flush();
                cin >> disA;
                cout << endl;
            }
        }
        if(disA == 0) {
            cout << "! " << lo << endl;
            cout.flush();
        } else {
            cout << "! " << hi << endl;
            cout.flush();
        }
    }
    return 0;
}
