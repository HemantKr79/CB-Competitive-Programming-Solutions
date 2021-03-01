#include <iostream>
using namespace std;

int nums[100005],mob[100005],prime_cnt[100005];
#define N 100000

void cal_mob() {
    for(int i=0;i<=N;i++) {
        nums[i] = 1;
        prime_cnt[i] = 0;
    }
    mob[0] = 1;
    for(int i=2;i<=N;i++) {
        if(prime_cnt[i]!=0) {
            continue;
        }
        for(int j=i;j<=N;j+=i) {
            nums[j] *= i;
            prime_cnt[j]++;
        }
    }
    for(int i=1;i<=N;i++) {
        if(nums[i]==i) {
            if(prime_cnt[i]%2==0) {
                mob[i] = 1;
            }
            else {
                mob[i] = -1;
            }
        }
        else {
            mob[i] = 0;
        }
    }
}

int main() {
    cal_mob();
    for(int i=1;i<=30;i++) {
        cout<<mob[i]<<" ";
    }
    return 0;
}
