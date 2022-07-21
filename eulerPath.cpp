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

bool isEulerPathFound(vi &deg){
	int odd=0;
	for(int i=0;i<deg.size();i++){
		if(deg[i]%2) odd++;
	}

	if(odd ==2 || odd ==0) return true;
	return false;
}

void eulerPath(vector<set<int>> &grph, int src, vi &path, vii &adjMat){
    if(grph[src].empty()) return;
	for(auto v: grph[src]){
		if(adjMat[src][v]){
			adjMat[src][v]--;
			adjMat[v][src]--;
			eulerPath(grph, v, path, adjMat);
		}
	}
	path.pb(src);
}



void solve(){

	//input graph
	int n,m;
	cin>>n>>m;
	vector<set<int>> grph(n);
	vii adjMat(n, vi(n,0));
	vi deg(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		grph[u].insert(v);
		grph[v].insert(u);
		adjMat[u][v]++;
		adjMat[v][u]++;
		deg[u]++; deg[v]++;
	}

	//finding source
	int src = 0;
	for(int i=0;i<deg.size();i++)
		if(deg[i]%2){
			src =i; break;
		}

	//finding euler path
	cout<<"src: "<<src<<endl;
	vi path;
	if(isEulerPathFound(deg)){
		eulerPath(grph,src,path, adjMat);
		for(auto &x: path){
			cout<<x<<' ';
		}
		cout<<endl;
	}
	else cout<<-1<<endl;


}


int main(){

    solve();
    return 0;
}
