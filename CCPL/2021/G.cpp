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
const double eps=1e-7;
vector<string> split(const string &s/*, char c*/) {
    vector<string> v;
    stringstream ss(s);
    string sub;
    while (ss >> sub) v.pb(sub);
    //while (getline(ss, sub, c)) v.pb(sub);
    return v;
}
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    vector<ll> v;
    for(ll i=0; i<=31625; i++) {
        v.pb(i*i);
    }
    string s;
    while(getline(cin,s)) {
        vector<string> ve=split(s);
        if(sz(ve)==1) {
            ll n=stoll(ve[0]);
            if(n>=0) {
                int ind=lower_bound(all(v),n)-v.begin();
                double bb=v[ind]-n;
                if(abs(sqrt(bb)-(ll)sqrt(bb))<eps) {
                    cout<<ind<<" "<<(ll)(sqrt(v[ind]-n))<<endl;
                } else {
                    cout<<"h"<<endl;
                    if(n&1)cout<<"Spinster Number."<<endl;
                    else cout<<"Bachelor Number."<<endl;
                }
            } else {
                int ind=lower_bound(all(v),abs(n))-v.begin();
                double bb=v[ind]-abs(n);
                if(abs(sqrt(bb)-(ll)sqrt(bb))<eps) {
                    cout<<(ll)(sqrt(v[ind]-abs(n)))<<" "<<ind<<endl;
                } else {
                    if(n&1)cout<<"Spinster Number."<<endl;
                    else cout<<"Bachelor Number."<<endl;
                }
            }
        } else {
            ll n1=stoll(ve[0]), n2=stoll(ve[1]);
            int ans=0;
            for(int i=n1; i<=n2; i++) {
                int ind=lower_bound(all(v),i)-v.begin();
                double bb=v[ind]-i;
                if(abs(sqrt(bb)-(ll)sqrt(v[ind]-i))<eps) ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
