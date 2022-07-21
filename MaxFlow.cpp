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


int n,m;
// vi findPath(int src, int dst, vi &path, vii &capacity, vb& visited){
// 	if(src == dst){
// 		path.pb(src);
// 		return path;
// 	}
// 	visited[src] = 1;
// 	path.pb(src);
// 	for(int i=0;i<n;i++){
// 		if(capacity[src][i] && !visited[i]){
// 			findPath(i,dst,path, capacity, visited);
// 		}
// 	}
// 	path.pop_back();
// 	visited[src] = 0;
// 	// return path;
// }

int visited[1001];
int parent[1001];

void dfs(int src, int dst, vii &capacity){
	visited[src] = 1;
	for(int i=0;i<n;i++){
		if(visited[i] || capacity[src][i]==0) continue;
		parent[i] = src;
		if(visited[dst]) return;
		dfs(i,dst,capacity);
	}
}

vi findPath(int dst){
	vi path;
	if(!visited[dst]) return path;

	while(dst!=-1){
		path.pb(dst);
		dst = parent[dst];
	}

	reverse(ALL(path));
	return path;
}

int findFlow(int src, int sink, vii &capacity){

	int flow = 0;

	while(true){
		vi flowPath;
		int minCap = INT_MAX;
		memset(visited, 0 , sizeof(visited));
		memset(parent, -1, sizeof(parent));
		dfs(src, sink, capacity);
		flowPath = findPath(sink);
		if(flowPath.empty()) return flow;

		for(int i=0;i<flowPath.size()-1;i++){
			minCap = min(minCap, capacity[flowPath[i]][flowPath[i+1]]);
		}
		flow += minCap;
		for(int i=0;i<flowPath.size()-1;i++){
			capacity[flowPath[i]][flowPath[i+1]] -= minCap;
			capacity[flowPath[i+1]][flowPath[i]] += minCap;
		}
	}

	return flow;
}



void solve(){
	int src, sink;
	cin>>n>>m;
	vii capacity(n, vi(n,0));
	for(int i=0;i<m;i++){
		int a,b,w; cin>>a>>b>>w;
		capacity[a][b] += w; 
	}
	cin>>src>>sink;

	// findPath(src,sink,path,capacity,visited);
	// for(auto i: path){
	// 	cout<< i<<' ';
	// }
	// cout<<endl;


	int flow = findFlow(src, sink, capacity);
	cout<<flow<<endl;

}


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t=1,cas=1;

    // cin>>t;

    while(t--){
        // cout<<"Case "<<cas++<<":\n";
        solve();
        // if(t) cout<<endl;
    }

    return 0;

}
