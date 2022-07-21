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
const ll inf = INT_MAX; 
int sz = 100;


//basic implementation

//finds the shortest path while checking negative cycle exists or not
// returns ture : negative cycle exists
// returns false : negative cycle  dosn't exists

// relaxs the garphs n (number of vertices) times, if the graph still can be 
// relaxed then it has negative cycle

// Complexity : O(VE) in case of E = V^2 => O(V^3)
bool bellmanFord_basic(vector<vector<pll>> &adj, vl &dis, int s){
	dis[s] = 0;

	// relaxing all edges n times
	for(int k=0;k<adj.size();k++){ 
		for(int i=0;i<adj.size();i++){
			for(auto v: adj[i]){
				if(dis[v.first] > dis[i] + v.second){
					dis[v.first] = max(-inf, dis[i] + v.second);
				}
			}
		}
	}
	
	// checking further relaxation is possible or not
	for(int i=0;i<adj.size();i++){
		for(auto v: adj[i]){
			if(dis[v.first] > dis[i] + v.second) return true; //negative cycle found
		}
	}
	return false;
}

//printing the shortest path
bool bellmanFord(vector<vector<pll>> &adj, vl &dis, vl &par, int s){
	dis[s] = 0;

	// relaxing all edges n times
	for(int k=0;k<adj.size();k++){ 
		for(int i=0;i<adj.size();i++){
			for(auto v: adj[i]){
				if(dis[v.first] > dis[i] + v.second){
					dis[v.first] = max(-inf, dis[i] + v.second);
					par[v.first] = i;
				}
			}
		}
	}
	
	// checking further relaxation is possible or not
	for(int i=0;i<adj.size();i++){
		for(auto v: adj[i]){
			if(dis[v.first] > dis[i] + v.second) return true; //negative cycle found
		}
	}

	return false;
}

void printPath(vi &par, int to){
	vi path;
	for(int i = to; i != -1;i = par[i]){
		path.pb(i);
	}
	reverse(ALL(path));
	for(auto i : path) cout<<i<<' ';
		cout<<endl;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pll>> adj(n);
	vl parents(n,-1), dis(n,inf);
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].pb({b,w});
	}

	int des = 4;
	if(bellmanFord(adj,dis,parents,0)) 
		cout<<"Negative cycle detected"<<endl;
	else{
		cout<<"No negative cycle"<<endl;
		vl path;
		for(int i=des; i!=-1;i = parents[i]){
			path.pb(i);
		}
		reverse(ALL(path));
		for(auto i: path){
			cout<<i<<' ';
		}
		cout<<endl;
		cout<<"cost: "<<dis[des]<<endl;

	}

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
