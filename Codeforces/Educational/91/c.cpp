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
typedef double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX=1e5+5;
int n,x;
vector<ll> a;

bool ok(int ans){
    ll cnt=0,mn=1e9+1;
    int partes=0;
    forn(i,n){
        mn=min(mn,a[i]);
        cnt++;
        if(cnt*mn>=x){
        //cout<<cnt<<" "<<mn;
        mn=1e9+1,cnt=0,partes++;
        //cout<<" parte: "<<partes<<endl;
        }
    }
    if(partes>=ans)return true;
    else return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin>>t;
    while(t--){
        cin>>n>>x;
        a.clear();
        forn(i,n){
            int v;
            cin>>v;
            a.pb(v);
        }
        sort(rall(a));
        int lo=0,hi=MAX;
        int m=0;
        forn(it,70){
            m=(lo+hi)/2;
            //cout<<m<<endl;
            if(ok(m))lo=m;
            else hi=m;
        }
        cout<<m<<endl;
    }
    return 0;
}
