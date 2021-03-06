#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1001000;
const ll MOD = 1e9 + 7;

int n, m;
ll f[N+N];
ll res;

int main(){
	f[0] = 1;
	for(int i = 1; i < N+N; i++){
		f[i] = (f[i-1] * i) % MOD;
	}
	
	sd2(n,m);
	res = 1;
	
	for(int i = n; i >= 1; i--){
		int mul = min(n - i + 1, m);
		res = (res * f[mul]) % MOD;
	}
	
	for(int i = m; i > 1; i--){
		int mul = min(m - i + 1, n);
		res = (res * f[mul]) % MOD;
	}
	
	cout << res << endl;
	return 0;
}
