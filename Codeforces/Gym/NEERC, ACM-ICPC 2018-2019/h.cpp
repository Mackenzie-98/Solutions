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

int main() {
    fastIO;
    freopen("holes.in", "r", stdin);
    freopen("holes.out", "w", stdout);
    int h;
    cin>>h;
    if(h==0)cout<<"1"<<endl;
    else if(h==1)cout<<"0"<<endl;
    else {
        string ans(h/2,'8');
        if(h&1)ans="4"+ans;
        cout<<ans<<endl;
    }
    return 0;
}
