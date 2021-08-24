#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        forn(i,n)cin>>arr[i];
        bool ok=0;
        forn(i,n){
            for(int j=i+1;j<n;j++){
                if(abs(arr[i]-arr[j])==1){
                    ok=1;
                    break;
                }
            }
        }
        if(ok)cout<<2<<endl;
        else cout<<1<<endl;

    }

    return 0;
}