#include<iostream>
using namespace std;

bool isPossible(int *books,int mid,int n,int m) {
	int i=0;
	for(int student=1;student<=m;student++) {
		int page_cnt = 0;
		while(i<n && page_cnt+books[i]<=mid) {
			page_cnt += books[i];
			i++;
		}
		if(i==n) {
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		int *books = new int[n];
		int e = 0;
		for(int i=0;i<n;i++) {
			cin>>books[i];
			e += books[i];
		}
		if(m>n) {
		    cout<<-1<<endl;
		    continue;
		}
		int s = books[n-1];
		int ans = e;
		while(s<=e) {
			int mid = (s+e)/2;
			if(isPossible(books,mid,n,m)) {
				e = mid-1;
				ans = min(ans,mid);
			}
			else {
				s = mid+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}