#include<iostream>
using namespace std;

#define ll long long

int main() {
	ll t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		pair<ll,ll> *p = new pair<ll,ll>[n];
		//p[i].first stores the cost and p[i].second stores the liters
		for(ll i=0;i<n;i++) {
			cin>>p[i].first;
		}
		for(ll i=0;i<n;i++) {
			cin>>p[i].second;
		}
		ll total_cost = p[0].first*p[0].second;
		ll fuel = p[0].second;
		ll x = 0;
		ll lowest_cost = p[0].first;
		while(x<n) {
			lowest_cost = min(lowest_cost,p[x].first);
			if(fuel>=p[x].second) {
				fuel -= p[x].second;
			}
			else {
				total_cost += (p[x].second-fuel)*lowest_cost;
				fuel += (p[x].second-fuel);
				continue;				
			}
			x++;
		}
		cout<<total_cost<<endl;
	}
	return 0;
}