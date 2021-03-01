#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

double dp[105][105][105];

void set_dp() {
    for(int i=0;i<105;i++) {
        for(int j=0;j<105;j++) {
            for(int k=0;k<105;k++) {
                dp[i][j][k] = -1.0;
            }
        }
    }
}

//calculating the probabilty of rock surviving
double f1(int r,int p,int s) {
    if(r==0 || s==0) {
        return 0.0;
    }
    // if p is zero then there will be no one to destroy rock
    if(p==0) {
        return 1.0;
    }
    if(dp[r][p][s]!=-1.0) {
        return dp[r][p][s];
    }
    double tot = r*p + p*s + s*r;
    double ans1 = f1(r-1,p,s)*((r*p)/tot);
    double ans2 = f1(r,p-1,s)*((p*s)/tot);
    double ans3 = f1(r,p,s-1)*((r*s)/tot);
    return dp[r][p][s] = ans1+ans2+ans3;
}

//calculating probability of scissor surviving
double f2(int r,int p,int s) {
    if(s==0 || p==0) {
        return 0.0;
    }
    if(r==0) {
        return 1.0;
    }
    if(dp[r][p][s]!=-1.0) {
        return dp[r][p][s];
    }
    double tot = r*p + p*s + s*r;
    double ans1 = f2(r-1,p,s)*((r*p)/tot);
    double ans2 = f2(r,p-1,s)*((p*s)/tot);
    double ans3 = f2(r,p,s-1)*((r*s)/tot);
    return ans1+ans2+ans3;
}

//calculating the probability of paper surviing
double f3(int r,int p,int s) {
    if(p==0 || r==0) {
        return 0.0;
    }
    if(s==0) {
        return 1.0;
    }
    if(dp[r][p][s]!=-1.0) {
        return dp[r][p][s];
    }
    double tot = r*p + p*s + s*r;
    double ans1 = f3(r-1,p,s)*((r*p)/tot);
    double ans2 = f3(r,p-1,s)*((p*s)/tot);
    double ans3 = f3(r,p,s-1)*((r*s)/tot);
    return ans1+ans2+ans3;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int r,s,p;
        cin>>r>>s>>p;
        set_dp();
        double ans1 = f1(r,p,s);
        set_dp();
        double ans2 = f2(r,p,s);
        set_dp();
        double ans3 = f3(r,p,s);
        cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }
    return 0;
}
