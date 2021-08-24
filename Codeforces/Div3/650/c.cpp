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
        int n,k;
        string s;
        cin>>n>>k>>s;
        int cnt=s[0]=='0',ans=0;
        for(int i=1;i<n;i++){
            if(s[i]=='0'&&s[i]==s[i-1])cnt++;
            else{
                int segment=cnt;
                if(cnt!=i)segment-=2*k;
                else segment-=k;
                ans+=max(0,(segment+k)/(k+1));
                cnt=s[i]=='0';
            }
        }
        if(s[n-1]=='0'){
            int segment=cnt;
            if(segment!=n)segment-=k;
            ans+=max(0,(segment+k)/(k+1));
        }
        cout<<ans<<endl;

    }
    return 0;
}
