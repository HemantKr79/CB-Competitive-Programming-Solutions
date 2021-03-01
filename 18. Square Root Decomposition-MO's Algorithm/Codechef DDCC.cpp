#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define int long long

vector<int> freq(1000001,0);
int cost = 0;

struct query {
    int l,r,block_id,q_no;
    bool operator < (query &q) {
        if(block_id==q.block_id) {
            return r < q.r;
        }
        return block_id < q.block_id;
    }
};

void add(int element) {
    cost -= freq[element]*freq[element]*element;
    freq[element] += 1;
    cost += freq[element]*freq[element]*element;
}

void remove(int element) {
    cost -= freq[element]*freq[element]*element;
    freq[element] -= 1;
    cost += freq[element]*freq[element]*element;
}

void resolve(int &curr_l,int &curr_r,int l,int r,vector<int> &arr) {
    while(curr_l < l) {
        remove(arr[curr_l]);
        ++curr_l;
    }
    while(curr_l > l) {
        --curr_l;
        add(arr[curr_l]);
    }
    while(curr_r < r) {
        ++curr_r;
        add(arr[curr_r]);
    }
    while(curr_r > r) {
        remove(arr[curr_r]);
        --curr_r;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,d;
	cin>>n>>d;
	int rn = sqrt(n);
	vector<int> c(n);
	for(int i=0;i<n;i++) {
	    cin>>c[i];
	}
	vector<int> ans(d);
	vector<query> q(d);
	for(int i=0;i<d;i++) {
	    cin>>q[i].l;
	    cin>>q[i].r;
	    q[i].l -= 1;
	    q[i].r -= 1;
	    q[i].block_id = q[i].l/rn;
	    q[i].q_no = i;
	}
	sort(q.begin(),q.end());
	int curr_l = q[0].l;
	int curr_r = q[0].r;
	for(int i=curr_l;i<=curr_r;i++) {
	    add(c[i]);
	}
	ans[q[0].q_no] = cost;
	for(int i=1;i<d;i++) {
	    resolve(curr_l,curr_r,q[i].l,q[i].r,c);
	    ans[q[i].q_no] = cost;
	}
	for(int i=0;i<d;i++) {
	    cout<<ans[i]<<endl;
	}
	return 0;
}
