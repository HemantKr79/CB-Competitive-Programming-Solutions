#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second==p2.second) {
        return p1.first>p2.first;
    }
    return p1.second<p2.second;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        pair<int,int> *activities = new pair<int,int>[n];
        for(int i=0;i<n;i++) {
            cin>>activities[i].first;
            cin>>activities[i].second;
        }
        sort(activities,activities+n,compare);
        int ans = 0;
        int activity_end_time = 0;
        for(int i=0;i<n;i++) {
            if(activities[i].first>=activity_end_time) {
                ans++;
                activity_end_time = activities[i].second;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
