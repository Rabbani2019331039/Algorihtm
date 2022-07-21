#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ALL(v) v.begin(),v.end()
#define endl "\n"
#define in(x) scanf("%d",&x)

#define MAX 2000
#define MOD 1000000007
#define PI 2*acos(0.0)

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int x4[] = {1,0,-1,0};
int y4[] = {0,-1,0,1};
int x8[] = {1,1,0,-1,-1,-1,0,1};
int y8[] = {0,-1,-1,-1,0,1,1,1};

void prntVec(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout<<a[i];
        i+1==a.size()?cout<<endl:cout<<' ';
    }
    // cout<<endl;
}

const ll mod = 1e9+7;

int getParent(vi &parent, int p){
	if(parent[p] == p) return p;
	return parent[p] = getParent(parent,parent[p]);
}

void mergeParent(vi &parent, int u, int v){
	u = getParent(parent,u);
	v = getParent(parent,v);
	parent[u] = v;
}


int kruskalMST(vector<vector<pii>> &graph,vector<pii> &tree, 
	priority_queue<pair<int,pair<int,int>>> &minEdge, vi &parent){
	int cost = 0;
	while(!minEdge.empty()){
		auto edge = minEdge.top();
		int u = getParent(parent, edge.second.first);
		int v = getParent(parent, edge.second.second);

		if(u!=v){
			mergeParent(parent,u,v);
			cost+=-edge.first;
			tree.pb(edge.second);
		}
		minEdge.pop();
	}
	return cost;
}


void solve(){
	int n,m;
	cin>>n>>m;
	vi parent(n);
	for(int i=0; i<n;i++) parent[i] = i;
	priority_queue<pair<int,pair<int,int>>> minEdge;
	vector<vector<pii>> graph(n);
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		a--,b--;
		graph[a].pb({w,b});
		graph[b].pb({w,a});
		minEdge.push({-w,{a,b}});
	}

	vector<pii> tree;
	int cost;
	cost = kruskalMST(graph, tree, minEdge, parent);

	cout<<cost<<endl;
	for(auto i: tree){
		cout<<i.first<<' '<<i.second<<endl;
	}




}


int main(){

	solve();

    return 0;

}
