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


int primsMST(vector<vector<pii>> &graph, vector<pii> &tree){
	int src = 0;
	vb visit(graph.size(),0);
	vi vertexTaken;
	vertexTaken.pb(0);
	visit[src] = 1;
	int cost = 0;
	priority_queue<pii> minEdge;
	while(vertexTaken.size()<graph.size()){
		visit[vertexTaken.back()]=1;
		for(auto u: graph[vertexTaken.back()]) minEdge.push({-u.first, u.second});

		pii v = minEdge.top();
		while(visit[v.second]){
			minEdge.pop();
			v = minEdge.top();
		}
		cost+=-v.first;
		tree.pb({vertexTaken.back(), v.second});
		vertexTaken.pb(v.second);
	}
	return cost;

}


void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pii>> graph(n);
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		a--,b--;
		graph[a].pb({w,b});
		graph[b].pb({w,a});
	}

	vector<pii> tree;
	int cost;
	cost = primsMST(graph, tree);

	cout<<cost<<endl;

	for(auto i: tree) cout<<i.first<<' '<<i.second<<endl;




}


int main(){

	solve();

    return 0;

}
