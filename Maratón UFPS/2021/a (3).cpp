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

const int MX = 1e6 + 500000;
bool marked[MX+1000];
bool isTwin[MX+1000];
int before[MX+1000];
int after[MX+1000];
vector<int> primes;
/// O(MX log(log(MX)))
void sieve() {
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MX; i++) {
        if (marked[i]) continue;
        primes.push_back(i);
        for (ll j = 1ll*i*i; j <= MX; j += i) marked[j] = true;
    }
}

void init(){
	for(int i = 2; i <= MX; i++){
		marked[i] = 0;
		isTwin[i] = 0;
		before[i] = oo;
		after[i] = oo;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	sieve();
	for(int i = 3; i <= MX-100; i++){
		if(!marked[i] && (!marked[i+2] || !marked[i-2])){
			isTwin[i] = true;
		}else{
			isTwin[i] = false;
		}
	}
	int flag = 3;
	for(int i = 1; i < MX; i++){
		if(isTwin[i]){
			flag = i;
		}	
		before[i] = flag;
	}
	flag = 1000000007;
	for(int i = MX; i >= 1; i--){
		if(isTwin[i]){
			flag = i;
		}	
		after[i] = flag;
	}
	
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		if(abs(n-before[n]) < abs(n-after[n])){
			cout << before[n] << endl;
		}else{
			cout << after[n] << endl;
		}
	}
	
}