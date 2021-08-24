#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define ft first
#define sd second
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
const int MX = 1e6;
bool marked[MX+1];
vector<int> primes;

ll lcm(ll a,ll b) {
    return a*(b/__gcd(a,b));
}

void sieve() {
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MX; i++) {
        if (marked[i]) continue;
        primes.push_back(i);
        for (ll j = 1ll*i*i; j <= MX; j += i) marked[j] = true;
    }
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
    sieve();
    int t;
    cin>>t;
    while(t--) {
        int d;
        cin>>d;
        vector<int> div;
        ll a=1,b=0,c=0,e=0;
        int ind1=lower_bound(all(primes),1+d)-primes.begin();
        int ind2=lower_bound(all(primes),primes[ind1]+d)-primes.begin();
        b=lcm(a,primes[ind1]);
        c=lcm(b,primes[ind2]);
        e=lcm(b,c);
        cout<<e<<endl;
        /*for(int j=1; j*j<=e; j++) {
            if(e%j==0) {
                if(j*j==e)div.pb(j);
                else div.pb(j),div.pb(e/j);
            }
        }
        sort(all(div));
        for(auto x:div)cout<<x<<" ";
        cout<<endl;*/
    }

    return 0;
}
