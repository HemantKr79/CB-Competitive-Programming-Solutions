#include <iostream>
using namespace std;

int string_to_int(string s) {
    int sLen = s.length();
    if(sLen==0) {
        return 0;
    }
    int smallAns = string_to_int(s.substr(0,sLen-1));
    int ans = smallAns*10;
    ans += (s[sLen-1]-'0');
    return ans;
}

int main() {
    string s;
    cin>>s;
    int num = string_to_int(s);
    cout<<num;
    return 0;
}
