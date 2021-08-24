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

int n;
const int MAX=105;
string A[MAX],B[MAX];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin>>n;
    map<string,int> mp;
    forn(i,n)cin>>A[i];
    forn(i,n)cin>>B[i],mp[B[i]]++;
    int ans=0;
    forn(i,n){
        if(mp[A[i]]>0)mp[A[i]]--;
        else ans++;
    }
    cout<<ans<<endl;

    return 0;
}
