#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<string> split_string(string);

class Graph {
    ll v;
    map<ll,list<ll> > l;
    void dfs_helper(ll src,map<ll,bool > &visited,ll &cnt) {
        ++cnt;
        visited[src] = true;
        for(auto neighbour : l[src]) {
            if(!visited[neighbour]) {
                dfs_helper(neighbour,visited,cnt);
            }
        }
    }
    public:
    Graph(ll v) {
        this->v = v;
        list<ll> tmp;
        for(ll i=0;i<v;i++) {
            l.insert(make_pair(i,tmp));
        }
    }
    void addEdge(ll x,ll y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    ll dfs() {
        map<ll,bool> visited;
        for(auto p : l) {
            visited[p.first] = false;
        }
        vector<ll> connected_components;
        for(auto p : visited) {
            if(!p.second) {
                ll cnt = 0;
                dfs_helper(p.first,visited,cnt);
                connected_components.push_back(cnt);
            }
        }
        ll ans = 0;
        for(auto item : connected_components) {
            ans += (((ll)item)*(item-1))/2;
        }
        return ans;
    }
};

// Complete the journeyToMoon function below.
ll journeyToMoon(ll n, vector<vector<ll> > astronaut) {
    Graph g(n);
    for(auto item : astronaut) {
        ll x = item[0];
        ll y = item[1];
        g.addEdge(x,y);
    }
    ll total = (((ll)n)*(n-1))/2;
    ll ans = g.dfs();
    ll a = total - ans;
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    ll n = stoi(np[0]);

    ll p = stoi(np[1]);

    vector<vector<ll>> astronaut(p);
    for (ll i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (ll j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ll result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
