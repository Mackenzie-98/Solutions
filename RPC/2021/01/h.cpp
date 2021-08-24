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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for(auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if(sizeof...(v)) cerr << ", "; _print(v...);}

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};
vector<Vertex> trie[31];

void add_string(string const& s, vector<Vertex> &trie) {
    int v = 0;
    for(char ch : s) {
        int c = ch - 'a';
        if(trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}

bool buscar(string const& s, vector<Vertex> &trie) {
    int v = 0;
    for(auto ch : s) {
        int c = ch - 'a';
        if(trie[v].next[c] == -1)return false;
        v = trie[v].next[c];
    }
    return true;
}

int main() {
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    /*string a="hola";
    string b="holi";
    string c="hoca";
    debug(1);

    add_string(a,trie[0]);
    add_string(b,trie[0]);
    add_string(c,trie[0]);
    debug(2);
    cout<<buscar("hola",trie[0])<<endl;
    debug(3);*/
    int t;
    cin >> t;
    while(t--) {
        int p, r;
        cin >> p >> r;
        int aa[p + 1];
        forn(i, 31) {
            trie[i].clear();
            Vertex x;
            trie[i].pb(x);
        }
        forn(i, p) {
            int c;
            cin >> c;
            aa[i] = c;
            forn(j, c) {
                string s;
                cin >> s;
                add_string(s, trie[i]);
            }
        }
        bool mp[p+1];
        forn(w, r) {
            int n;
            cin >> n;
            int ans = 0;
            memset(mp,0,sizeof mp);
            forn(z, n) {
                string s;
                cin >> s;
                bool ok = false;
                int ind=-1;
                forn(i, p) {
                    bool cur = buscar(s, trie[i]);
                    if(!cur)continue;
                    if((ok && cur)||(cur&&mp[i]))goto done;
                    ok |= cur;
                    ind=i;
                }
                if(ok&&!mp[ind])ans++,mp[ind]=true;
                //debug(s,ind,ok,ans);
done:;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
