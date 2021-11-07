#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define sz size()
#define eps 0.000001
#define oo 2000000007
#define endl '\n'
#define bg begin()
#define nd end()
#define up upper_bound
#define lw lower_bound
#define debug(x) #x << " = " << x << "; "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,rta,tmp;
	cin>>n;
   set<int, greater<int> > ns;
	for(int i=0;i<n;i++){
		cin>>tmp;
		ns.insert(tmp);
	}
	for(int i=1;i<n;i++){
		cin>>tmp;
		ns.erase(tmp);
	}
	rta=*ns.begin();
	cout<<rta<<endl;
	
}