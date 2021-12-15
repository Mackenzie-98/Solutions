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



int main() {

    fastIO;
   int n;
   cin>>n;
   int ma=0;
   while(n--){
   	int c,p,px,j;
   	cin>>c>>p;
   	vector<pair<ll,ll>> cs(c);
   	
   	while(c--){
   		
   	cin>>px>>j;	
   	if(px>p)continue;
   	
   	if(j>ma)ma=j;
   	
   	}
   	cout<<ma<<endl;
   	ma=0;
   }
    


    return 0;
}