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
        int n;
        cin>>n;
        vector<int> v(n);
        vector<pii> mnl(n),mnr(n);
        forn(i,n)cin>>v[i];
        mnl[0]={v[0],0},mnr[n-1]={v[n-1],n-1};
        for(int i=1;i<n;i++){
            if(v[i]<mnl[i-1].F)mnl[i]={v[i],i};
            else mnl[i]=mnl[i-1];
            if(v[n-i-1]<mnr[n-i].F)mnr[n-i-1]={v[n-i-1],n-i-1};
            else mnr[n-i-1]=mnr[n-i];
        }
        for(int i=1;i<n-1;i++){
            if(mnl[i].F<v[i]&&mnr[i].F<v[i]){
                cout<<"YES"<<endl;
                cout<<mnl[i].S+1<<" "<<i+1<<" "<<mnr[i].S+1<<endl;
                goto done;
            }
        }
        cout<<"NO"<<endl;
        done:;
    }
    return 0;
}
