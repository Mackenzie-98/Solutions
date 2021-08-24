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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n,m;
    cin>>n>>m;
    int c[n],a[m];
    forn(i,n)cin>>c[i];
    forn(i,m)cin>>a[i];
    int ind1=0,ind2=0;
    int ans=0;
    while(ind1<n&&ind2<m){
        if(c[ind1]<=a[ind2]){
            ind1++,ind2++;
            ans++;
        }else{
            ind1++;
        }
    }
    cout<<ans<<endl;
    return 0;
}