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
int n,m;
int arr[21];
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif

    cin>>n>>m;
    vector<string> v(n);
    forn(i,n)cin>>v[i];
    int lim=n*m;
    for(int mask=0; mask<(int)(1<<lim); mask++) {
        bool ok2=true;
        forn(j,lim) {
            if(mask&(1<<j)) {
                if(v[j/m][j%m]!='.') {
                    ok2=false;
                    break;
                }
            }
        }
        if(ok2) {
            //cout<<"Mask: "<<mask<<endl;
            bool ok1=true;
            for(int i=0; i<n&&ok1; i++) {
                for(int j=0; j<m&&ok1; j++) {
                    //cout<<"CurPosition: "<<i<<" "<<j<<endl;
                    if(v[i][j]!='.') {
                        int sum=0;
                        for(int k=-1; k<=1&&ok1; k++) {
                            for(int w=-1; w<=1&&ok1; w++) {
                                if((k==0&&w==0)||(i+k)>=n||(i+k)<0||(j+w)>=m||(j+w)<0||v[i+k][j+w]!='.')continue;
                                if((mask&(1<<((i+k)*m+(j+w)))))sum++;
                                //cout<<i+k<<" "<<j+w<<" "<<sum<<" "<<(1<<((i+k)*m+(j+w)))<<endl;
                            }
                        }

                        if(sum!=(v[i][j]-'0'))ok1=false;
                    }
                }
            }
            if(ok1) {
                int bits=__builtin_popcount(mask);
                arr[bits]++;
                //cout<<mask<<" "<<bits<<endl;
            }

        }
    }
    bool ok=false;
    forn(i,20) {
        if(arr[i]!=0) {
            cout<<arr[i]<<" "<<i<<endl;
            ok=true;
            break;
        }
    }
    if(!ok)cout<<0<<endl;
    return 0;
}
