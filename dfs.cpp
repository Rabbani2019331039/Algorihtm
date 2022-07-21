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


void dfs(vii &adj, int s, vb &visit){
	visit[s] = 1;
	for(auto v : adj[s]){
		if(!visit[v])
			dfs(adj,v,visit);
	}
}


int dfs_timer = 0;
void dfs(vii &adj, int s, vb &visit, vector<pii> &timeStamp){
	visit[s] = 1;
	timeStamp[s].first = dfs_timer++; 
	for(auto v : adj[s]){
		if(!visit[v])
			dfs(adj, v, visit, timeStamp);
	}
	timeStamp[s].second = dfs_timer++;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vii adj(n);
	vb visit(n);
	vector<pii> timeStamp(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(adj, 0, visit, timeStamp);
	for(auto i: timeStamp){
		cout<<i.first<<' '<<i.second<<endl;
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
