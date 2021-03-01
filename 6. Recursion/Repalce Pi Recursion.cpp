#include <iostream>
#include <string>
using namespace std;

string replace_pi(string s) {
    if(s.length()==0) {
        return s;
    }
    if(s[0]=='p') {
        if(s.length()>1 && s[1]=='i') {
            string smallOutput = replace_pi(s.substr(2));
            return "3.14"+smallOutput;
        }
    }
    return s.substr(0,1)+replace_pi(s.substr(1));
}

int main() {
    string s;
    cin>>s;
    string out = replace_pi(s);
    cout<<out;
}
