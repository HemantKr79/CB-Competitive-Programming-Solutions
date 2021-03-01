#include <iostream>
#include<set>
#include<map>
using namespace std;

class person_compare {
    public:
    bool operator()(pair<string,int> p1,pair<string,int> p2) {
        return p1.second<p2.second;
    }
};

int main() {
    int friends,no_of_transactions;
    cin>>friends>>no_of_transactions;
    map<string,int> net;
    string from,to;
    int amount;
    while(no_of_transactions--) {
        cin>>from>>to>>amount;
        if(net.count(from)==0) {
            net[from] = 0;
        }
        if(net.count(to)==0) {
            net[to] = 0;
        }
        net[from] -= amount;
        net[to] += amount;
    }
    multiset<pair<string,int> , person_compare> m;
    for(auto item : net) {
        if(item.second!=0) {
            m.insert(item);
        }
    }
    int cnt = 0;
    while(!m.empty()) {
        auto low = m.begin();
        auto high = prev(m.end());
        string debiter = low->first;
        int debit_amount = low->second;
        string crediter = high->first;
        int credit_amount = high->second;
        int settlement_amount = min(-debit_amount,credit_amount);
        m.erase(low);
        m.erase(high);
        debit_amount += settlement_amount;
        credit_amount -= settlement_amount;
        cout<<debiter<<" will pay "<<settlement_amount<<" to "<<crediter<<endl;
        ++cnt;
        if(debit_amount!=0) {
            m.insert(make_pair(debiter,debit_amount));
        }
        if(credit_amount!=0) {
            m.insert(make_pair(crediter,credit_amount));
        }
    }
    cout<<cnt;
    return 0;
}
