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



// ll n,k,m;
// ll a,b,c,d;

void dfs(vii &grph, vb &visited, int src, vi &path){
	visited[src] = 1;
	path.pb(src);
	if(path.size() == grph.size()) return;
	for(auto v: grph[src]){	
		if(!visited[v]){
			// path.pb(v);
			dfs(grph, visited, v, path);
		}
		if(path.size() == grph.size()) return;
	}
	path.pop_back();
	visited[src] = 0;
}

void solve(){
	//input graph
	int n,m;
	cin>>n>>m;
	vii grph(n);
	vb visited(n,0);
	vi path;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		grph[u].push_back(v);
		grph[v].push_back(u);
	}

	//finding hamilton path
	for(int i=0;i<n;i++){
		dfs(grph, visited, i, path);
		if(path.size()==grph.size()) break;
	}

	// output hamilton path
	if(path.size() != grph.size()) cout<< -1<< endl;
	else{
		for(auto x: path) cout<<x<<' ';
			cout<<endl;
	}
}


int main(){
    
    solve();

    return 0;

}
