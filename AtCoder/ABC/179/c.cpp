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
double eps = 1e-9;
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n;
    cin>>n;
    int x=(int)ceil(sqrt(n));
    int ans=0;
    for(int i=0; i<n; i++) {
        int c=n-i;
        int div=0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if(j*j==i)div++;
                else div+=2;
            }
        }
        if(c>=0&&i+c==n)ans+=div;
    }
    cout<<ans<<endl;

    return 0;
}

