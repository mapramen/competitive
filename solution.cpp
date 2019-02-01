#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const long double EPS = 1e-10;
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
int INF = 2147483645;
lli INFINF = 9223372036854775807;
int debug = 0;

using namespace std;

void print(int a[],int s,int e){for(int i=s;i<=e;i++)cout<<a[i]<<" ";cout<<"\n";}
void print(vector<int> &v,int s,int e){for(int i=s;i<=e;i++)cout<<v[i]<<" ";cout<<"\n";}
void print(vector<int> &v){for(int x:v)cout<<x<<" ";cout<<"\n";}

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*b;x%=m;return x;}

typedef bool (*comp)(pair<pair<int,int>,int> , pair<pair<int,int>,int> );

int T,R,C;
int H[55][55];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
bool vis[55][55];

bool compare (pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	return a.second > b.second;
}

int main()
{
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>R>>C;
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                cin>>H[i][j];
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                vis[i][j] = false;
        priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int> > ,comp> Q(compare);
        for(int j=1;j<=C;++j)
            Q.push({{1,j},H[1][j]});
        for(int j=1;j<=C;++j)
            Q.push({{R,j},H[R][j]});
        for(int j=2;j<R;++j)
            Q.push({{j,1},H[j][1]});
        for(int j=2;j<R;++j)
            Q.push({{j,C},H[j][C]});
        int res = 0;
        while(!Q.empty()){
            auto it1 = Q.top();
            cout << it1.F.F << ' ' << it1.F.S << ' ' << it1.S << '\n';
            while(!Q.empty()){
                auto it2 = Q.top();
                cout << it2.F.F << ' ' << it2.F.S << ' ' << it2.S << '\n';
                if(it2.S > it1.S){
                    break;
                }
                Q.pop();
                if(vis[it2.F.F][it2.F.S]++){
                    continue;
                }
                res+=it1.S-it2.S;
                for(int i=0;i<4;i++){
                    int cx =it2.F.F + dx[i];
                    int cy =it2.F.S + dy[i];
                    if(cx>=1 && cx<=R && cy>=1 && cy<=C){
                        Q.push({{cx,cy},H[cx][cy]});
                    }
                }
            }
            cout << '\n';
        }
        cout<<"Case #"<<t<<": "<<res<<"\n";
        cout << '\n';
    }

    return 0;
}
