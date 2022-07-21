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


// complexity O(v^3)
//the input graph is the adjacency matrix with the associate weight
void floydWarshall(vii &dis){
	int n = dis.size();
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dis[i][k] < inf && dis[k][j] < inf){
					dis[i][j] = min(dis[i][j], dis[i][k]+ dis[k][j]);
				}
			}
		}
	}
}

// for making predecessor matrix
void floydWarshall(vii &dis, vii &par){
	int n = dis.size();
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dis[i][k] < inf && dis[k][j] < inf){
					if(dis[i][j] > dis[i][k] + dis[k][j]){
						dis[i][j] = dis[i][k]+ dis[k][j];
						par[i][j] = par[k][j];
					}
				}
			}
		}
	}
}

// print the shortest path from i tp j
void printAllPairShortestPath(vii &par, int i, int j){
	if(i==j) cout<<i<<" ";
	else if(par[i][j] == -1) cout<<"No path from "<<i<<" to "<<j<<" exist";
	else{
		printAllPairShortestPath(par,i,par[i][j]);
		cout<<j<<" ";
	}
}


// input format
// n : number of nodes
// m : number of edges
// next m line contains 3 int a,b,w denotaing a directed edge from a to b 
// with edge weight w 
void solve(){
	int n,m;
	cin>>n>>m;
	vii w(n,vi(n,inf)), dis(n,vi(n,inf)), par(n,vi(n,-1));
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		w[a][b] = dis[a][b] = c;
		par[a][b] = a;
	}
	for(int i=0;i<n;i++){
		w[i][i] = dis[i][i] = 0; 
	}

	floydWarshall(dis, par);
	printAllPairShortestPath(par,3,0);
	cout<<endl;
	// for(auto i : par){
	// 	for(auto j: i){
	// 		cout<<j<<' ';
	// 	}
	// 	cout<<endl;
	// }
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
