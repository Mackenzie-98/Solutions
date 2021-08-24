#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef  long long ll;
typedef long long ld;

class droga {
public:
	string name;
	int pr, fr, ti;
	droga(int pri, int fre, int tie, string nom) {
		pr = pri;
		fr = fre;
		ti = tie;
		name = nom;
	}
};

bool operator<(const droga& d1, const droga& d2) {
	bool td1ma = d1.ti > d2.ti;
	bool pd1ma = d1.pr > d2.pr;
	return (d1.ti == d2.ti) ? pd1ma : td1ma;
}

int main() {
	// violinista forever xd
	ios::sync_with_stdio(0),cin.tie(0);

	int t,n,k,f;
	string nombre;
	cin>>t;
	while(t--){
		priority_queue<droga> cola;
		cin>>n>>k;
		for (int i = 0; i < n; i++) {
			cin >> nombre >> f;
			cola.push(droga(i, f, f, nombre));
		}
		for (int i = 0; i < k; i++) {
			droga rta = cola.top();
			cola.pop();
			cout << rta.ti << ' ' << rta.name << endl;
			cola.push(droga(rta.pr, rta.fr, rta.ti+rta.fr, rta.name));
		}

	}
	return 0;
}
