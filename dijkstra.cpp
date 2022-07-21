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
const int inf = 1000000000;

void dijkstra(vector<vector<pii>> &adj, int s, vi &dis, vi &par){
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0,s});
	while(!q.empty()){
		pii u = q.top();
		q.pop();
		for(auto v: adj[u.second]){
			if(dis[v.first]>dis[u.second]+v.second){
				dis[v.first] = dis[u.second]+v.second;
				par[v.first] = u.second;
				q.push({dis[v.first], v.first});
			}
		}
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pii>> adj(n);
	vi dis(n, inf), par(n,-1);
	for(int i=0; i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].pb({b,c});
	}
	dijkstra(adj, 0, dis, par);
	for(auto i: dis){
		cout<<i<<' ';
	}
	cout<<endl;
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
