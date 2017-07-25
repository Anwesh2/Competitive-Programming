#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

string s, t;

vector<pii> v;

int main(){ _
	cin >> s >> t;
	
	int n = s.length();
	int m = t.length();
	
	for(int i = 0; i < n; i++){
		bool ok = true;
		for(int j = 0; j < m; j++){
			if(i+j >= n){
				ok = false;
			}
			else{
				if(s[i+j] != t[j]) ok = false;
			}	
		}
		if(ok)
			v.pb(mp(i, i+m-1));
	}
	
	int cnt = 0;
//	tr(v);
	for(int i = 0; i < v.size(); i++){
		cnt++;
		pii p = v[i];
		i++;
		while(i < v.size()){
			if(v[i].fi <= p.se) i++;
			else{
				break;
			}
		}
		i--;
	}
	
	cout << cnt << endl;
	
	return 0;
}