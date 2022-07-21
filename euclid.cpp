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

int euclid(int a,int b){
	if(b==0) return a;
	return euclid(b, a%b);
}

pair<int, pii> xeuclid(int a, int b){
	if(b==0) return {a,{1,0}};
	auto res = xeuclid(b,a%b);
	int gcd = res.first;
	int x = res.second.second;
	int y = res.second.first - (a/b)*res.second.second;
	return {gcd,{x,y}};
}


void solve(){
	auto res = xeuclid(50, 30);
	cout<<res.first<<endl;
	cout<<res.second.first<<" "<<res.second.second;

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
