#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2) {
    return p1.first>p2.first;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    priority_queue<int> pq;
	    vector<pair<int,int> > v;
	    for(int i=0;i<n;i++) {
	        int dist,capacity;
	        cin>>dist>>capacity;
	        v.push_back(make_pair(dist,capacity));
	    }
	    int totalDist,fuel;
	    cin>>totalDist>>fuel;
	    sort(v.begin(),v.end(),compare);
	    for(int i=0;i<n;i++) {
	        v[i].first = totalDist - v[i].first;
	    }
	    int prev = 0;
	    int ans = 0;
	    int x = 0;
	    bool flag = true;
	    while(x<n) {
	        if(fuel>=(v[x].first-prev)) {
	            pq.push(v[x].second);
	            fuel -= (v[x].first-prev);
	            prev = v[x].first;
	        }
	        else {
	            if(pq.size()==0) {
	                flag = false;
	                break;
	            }
	            fuel += pq.top();
	            ans++;
	            pq.pop();
	            continue;
	        }
	        x++;
	    }
	    if(!flag) {
	        cout<<-1<<endl;
	        continue;
	    }
	    if(fuel>=totalDist-v[n-1].first) {
	        cout<<ans<<endl;
	        continue;
	    }
	    while(fuel<totalDist-v[n-1].first) {
	        if(pq.empty()) {
	            flag = false;
	            break;
	        }
	        fuel += pq.top();
	        pq.pop();
            ans++;
	    }
	    if(!flag) {
	        cout<<-1<<endl;
	        continue;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}