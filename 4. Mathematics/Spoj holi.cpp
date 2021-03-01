#include <iostream>
#include <list>
using namespace std;

class Graph {
    public:
    int V;
    list< pair<int,int> > *l;
    Graph(int v) {
        V = v;
        l = new list< pair<int,int> >[v];
    }
    void addEdge(int s,int d,int cost) {
        l[s].push_back(make_pair(d,cost));
        l[d].push_back(make_pair(s,cost));
    }
    int dfs_helper(int sv,bool visited[],int count[],int &ans) {
        visited[sv] = true;
        count[sv] = 1;
        for(auto neighbour : l[sv]) {
            int neighbourVertex = neighbour.first;
            int weight = neighbour.second;
            if(!visited[neighbourVertex]) {
                count[sv] += dfs_helper(neighbourVertex,visited,count,ans);
                int x = count[neighbourVertex];
                int y = V - x;
                ans += 2*min(x,y)*weight;
            }
        }
        return count[sv];
    }
    void dfs() {
        bool *visited = new bool[V];
        int *count = new int[V];
        for(int i=0;i<V;i++) {
            visited[i] = false;
            count[i] = 0;
        }
        int ans = 0;
        dfs_helper(0,visited,count,ans);
        cout<<ans;
        return;
    }
};

int main() {
    int t;
    cin>>t;
    int test = 1;
    while(t--) {
        int n;
        cin>>n;
        Graph g(n);
        for(int i=1;i<n;i++) {
            int s,e,w;
            cin>>s>>e>>w;
            g.addEdge(s-1,e-1,w);
        }
        cout<<"Case #"<<test<<": ";
        g.dfs();
        test++;
        cout<<endl;
    }
    return 0;
}
