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
    string cur="7";
    forn(i,12){
        cout<<cur<<endl;
        ll x=stoll(cur);
        vector<ll> div;
        for(ll j=1;j*j<=x;j++){
            if(x%j==0){
                if(j*j==x)div.pb(j);
                else{
                    div.pb(j);
                    div.pb(x/j);
                }
            }

        }
        sort(all(div));
        for(auto x:div)cout<<x<<" ";
        cout<<endl;
        cur+="7";
    }
    return 0;
}
