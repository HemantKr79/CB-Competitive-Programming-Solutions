#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v({4 , 8, 15, 16, 23, 42});
    vector<int> a(4);
    for(int i=0;i<4;i++) {
        cout<<"? "<<i+1<<" "<<i+2<<endl;
        cin>>a[i];
    }
    do {
        bool isCorrect = true;
        for(int i=0;i<4;i++) {
            if(v[i]*v[i+1]!=a[i]) {
                isCorrect = false;
                break;
            }
        }
        if(isCorrect) {
            cout<<"! ";
            for(int i=0;i<6;i++) {
                cout<<v[i]<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    while(next_permutation(v.begin(),v.end()));
    return 0;
}
