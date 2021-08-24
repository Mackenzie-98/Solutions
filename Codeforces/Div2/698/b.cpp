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
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 03
    fastIO;
#endif
    int t;
    cin>>t;
    while(t--) {
        int q,d;
        cin>>q>>d;
        forn(i,q) {
            int x;
            cin>>x;
            if(d==1)cout<<"YES"<<endl;
            else {
                int w=0;
                bool ok=false;
                while(w<=9&&x-w*d>=0&&!ok)   {
                    int aux=x-w*d;
                    while(aux>0){
                        int di=aux%10;
                        aux/=10;
                        if(di==d){
                            ok=true;
                            goto done;
                        }
                    }
                    w++;
                }
done:;
                if(ok||x>=d*10)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
