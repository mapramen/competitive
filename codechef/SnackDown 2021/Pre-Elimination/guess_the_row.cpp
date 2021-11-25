#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tdiiiiv tuple<double,int,int,int,int,vector<int>>
#define N 50
#define M (N / 2)

ll c[N + 1][N + 1];
double p[N + 1][N + 1];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid = uniform_int_distribution<int>();
priority_queue<tdiiiiv> Q;

int Query(int i, int j){
  printf("? %d %d\n", i, j);
  fflush(stdout);

  int x;
  scanf("%d", &x);
  return x;
}

void PrintAns(int i){
  printf("! %d\n", i);
  fflush(stdout);
}

ll Count(int k, int a, int b){
  return k < b || a < b ? 0ll : c[a][b] * c[N - a][k - b];
}

double P(int k, int a, int b){
  return 1.0 * Count(k, a, b) / c[N][k];
}

void Initialise(){
  for(int x = 0; x <= N; ++x){
    c[x][0] = 1;
    for(int y = 1; y <= x; ++y){
      c[x][y] = c[x - 1][y - 1] + c[x - 1][y];
    }
  }

  for(int a = 0; a <= N; ++a){
    for(int b = 0; b <= N; ++b){
      double s = 0;
      for(int k = a; k <= N; ++k){
        s += P(k, a, b);
      }
      p[a][b] = 1.0 * P(M, a, b) / max(1.0, s);
    }
  }
}

double CalculateProbability(int a, int b){
  return p[a][b];
}

void Push(int i, int a, int b, vector<int>& v){
  Q.push({CalculateProbability(a, b), uid(rng), i, a, b, v});
}

void Solve(){
  for(int i = 1; i <= N; ++i){
    vector<int> v;
    for(int j = 1; j <= N; ++j){
      v.push_back(j);
    }
    shuffle(v.begin(), v.end(), rng);
    Push(i, 0, 0, v);
  }

  while(!Q.empty()){
    auto [d, p, i, a, b, v] = Q.top();
    Q.pop();

    if(a == N && b == M){
      PrintAns(i);
      break;
    }

    int j = v.back();
    v.pop_back();

    int z = Query(i, j);
    ++a, b += z;

    Push(i, a, b, v);
  }

  while(!Q.empty()){
    Q.pop();
  }
}

int main(){
  int t, n;
  scanf("%d%d", &t, &n);

  Initialise();
  while(t--){
    Solve();
  }
  
  return 0;
}