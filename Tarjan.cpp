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


void tarjan(int u, int &depth, vi &entry, vi &low, stack<int> &stk, vb &onStk, vii &adj, vi &scc){
	entry[u] = low[u] = depth++;
	stk.push(u);
	onStk[u] = 1;
	for(auto v: adj[u]){
		if(entry[v] == -1){
			tarjan(v, depth, entry, low, stk, onStk, adj, scc);
			low[u] = min(low[u], low[v]);
		}
		else if(onStk[v]){
			low[u] = min(low[u],entry[v]);
		}
	}

	if(low[u] == entry[u]){
		int w = -1;
		do{
			w = stk.top();
			stk.pop();
			onStk[w] = 0;
			scc.pb(w);
		}while(w!=u);

		for(auto i: scc) cout<<i<<' ';
			cout<<endl;
		scc.clear();
	}
}




void solve(){
	int n,m;
	cin>>n>>m;
	vii adj(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
	}

	vi low(n,-1), entry(n,-1), scc;
	vb onStk(n,0);
	int depth = 0;
	stack<int> stk;
	tarjan(0, depth, entry, low, stk, onStk, adj, scc);

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
