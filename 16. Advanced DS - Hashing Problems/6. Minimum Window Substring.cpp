#include <iostream>
#include <string>
using namespace std;

string minWindowSubstring(string &str,string &pattern) {
    int strLen = str.length();
    int patLen = pattern.length();
    if(patLen > strLen) {
        return "None";
    }
    int sf[256] = {0};
    int pf[256] = {0};
    for(int i=0;i<patLen;i++) {
        char ch = pattern[i];
        pf[ch] += 1;
    }
    int cnt = 0;
    int min_length = strLen;
    int start = 0;
    int start_index = -1;
    for(int i=0;i<strLen;i++) {
        char ch = str[i];
        sf[ch] += 1;
        if(pf[ch]!=0 && sf[ch] <= pf[ch]) {
            ++cnt;
        }
        if(cnt==patLen) {
            char temp = str[start];
            while(pf[temp]==0 || sf[temp]>pf[temp]) {
                sf[temp]--;
                ++start;
                temp = str[start];
            }
            int win_length = i-start+1;
            if(win_length < min_length) {
                min_length = win_length;
                start_index = start;
            }
        }
    }
    if(start_index==-1) {
        return "None";
    }
    return str.substr(start_index,min_length);
}

int main() {
    string str,pattern;
    getline(cin,str);
    getline(cin,pattern);
    cout<<minWindowSubstring(str,pattern);
    return 0;
}
