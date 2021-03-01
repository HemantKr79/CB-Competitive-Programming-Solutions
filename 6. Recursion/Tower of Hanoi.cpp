#include <iostream>
using namespace std;

void move(int n,char scr,char helper,char dest) {
    if(n==0) {
        return;
    }
    move(n-1,scr,dest,helper);
    cout<<"Move disk "<<n<<" from "<<scr<<" to "<<dest<<endl;
    move(n-1,helper,scr,dest);
}

int main() {
    int n;
    cin>>n;
    move(n,'A','B','C');
    return 0;
}
