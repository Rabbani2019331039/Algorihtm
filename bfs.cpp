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
const int inf = INT_MAX;


// adj : adjacency list
// s : source node
// d : distance from the source (array)
// p : parent (array)
// visit : visit array
void bfs(vii &adj, int s, vi &d, vi &p , vb &visit){
	int n = adj.size();

	visit[s] = 1;
	d[s] = 0;

	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v: adj[u]){
			if(!visit[v]){
				visit[v] = 1;
				d[v] = d[u] + 1;
				p[v] = u;
				q.push(v);
			}
		}
	}
}

void bfs(vii &adj, int s, vi &dis, vb &visit){
	int n = adj.size();

	visit[s] = 1;
	dis[s] = 0;

	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v: adj[u]){
			if(!visit[v]){
				visit[v] = 1;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
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
	vii adj(n);
	vi p(n,-1), d(n,inf);
	vb visit(n,0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bfs(adj, 0, d, p, visit);

	//path printing
	int to = 3;
	printPath(p,3);

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
