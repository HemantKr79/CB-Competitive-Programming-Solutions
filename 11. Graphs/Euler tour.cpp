#include <iostream>
#include<vector>
using namespace std;

#define N 100005

vector<int> gr[N];
int tin[N],tout[N];
int timer;

void euler_tour1(int curr,int par) {
    cout<<curr<<" ";
    tin[curr] = ++timer;
    bool isLeafNode = true;
    for(auto nbr : gr[curr]) {
        if(nbr!=par) {
            euler_tour1(nbr,curr);
            tout[curr] = ++timer;
            isLeafNode = false;
            cout<<curr<<" ";
        }
        if(isLeafNode) {
            tout[curr] = timer;
        }
    }
}

void euler_tour2(int curr,int par) {
    cout<<curr<<" ";
    tin[curr] = ++timer;
    for(auto nbr : gr[curr]) {
        if(nbr!=par) {
            euler_tour2(nbr,curr);
        }
    }
    cout<<curr<<" ";
    tout[curr] = ++timer;
}

void euler_tour3(int curr,int par) {
    cout<<curr<<" ";
    tin[curr] = ++timer;
    for(auto nbr : gr[curr]) {
        if(nbr!=par) {
            euler_tour3(nbr,curr);
        }
    }
    tout[curr] = timer;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    //Euler tour 1 starts
    cout<<"Euler tour 1: ";
    timer = 0;
    euler_tour1(1,0);
    cout<<endl<<"Total time : "<<timer<<endl;
    cout<<"Node"<<"\t"<<"Time in"<<"\t"<<"Time out"<<endl;
    for(int i=1;i<=n;i++) {
        cout<<i<<"\t"<<tin[i]<<"\t"<<tout[i]<<endl;
    }
    //Euler tour 2 starts
    cout<<endl;
    cout<<"Euler tour 2: ";
    timer = 0;
    euler_tour2(1,0);
    cout<<endl<<"Total time : "<<timer<<endl;
    cout<<"Node"<<"\t"<<"Time in"<<"\t"<<"Time out"<<endl;
    for(int i=1;i<=n;i++) {
        cout<<i<<"\t"<<tin[i]<<"\t"<<tout[i]<<endl;
    }
    //Euler tour 3 starts
    cout<<endl;
    cout<<"Euler tour 3: ";
    timer = 0;
    euler_tour3(1,0);
    cout<<endl<<"Total time : "<<timer<<endl;
    cout<<"Node"<<"\t"<<"Time in"<<"\t"<<"Time out"<<endl;
    for(int i=1;i<=n;i++) {
        cout<<i<<"\t"<<tin[i]<<"\t"<<tout[i]<<endl;
    }
    return 0;
}
