//	Author:NIE
#include <iostream>
#include <vector>
using namespace std;

#define rep(n) for(int i=1;i<=(n);i++)
typedef long long ll;
const ll INF=0x7f7f7f7f;

const ll MAX_N=1000005;
vector<pair<ll,ll> > a;
ll mark[MAX_N];
ll imain(){
	a.clear();
	int N;
	cin>>N;
	a.push_back(make_pair(1,1));
	rep(N){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		a.push_back(make_pair(x,y));
	}
	mark[N+1]=0;
	for(ll i=N;i>=1;i--){
		mark[i]=max(mark[i+1],a[i].second);
	}
	ll sum=0;
	rep(N){
		ll dlt=mark[i+1]-a[i].first;
		if(dlt>0){
			sum+=dlt;
		}
	}
	return sum;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	int T, kase = 0;
	cin>>T;
	while(T--){
		cout<< "Case #" << ++kase << ": " << imain()<<'\n';
	}
}
