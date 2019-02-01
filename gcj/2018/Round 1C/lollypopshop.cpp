#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200

int c[N];
bool sold[N];
vector<int> v;

void OutputLollipop(){
  int x = INT_MAX;

  for(auto i : v){
    ++c[i];
    if(!sold[i]){
      x = min(x, c[i]);
    }
  }

  vector<int> a;
  for(auto i : v){
    if(!sold[i] && c[i] == x){
      a.PB(i);
    }
  }

  if(a.size() == 0){
    printf("-1\n");
  }
  else{
    int k = rand() % a.size();
    printf("%d\n", a[k]);
    sold[a[k]] = 1;
  }

  fflush(stdout);
}

void Solve(){
  int n;

  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    c[i] = 0;
    sold[i] = 0;
  }

  while(n--){
    int d;

    v.clear();

    scanf("%d", &d);
    for(int x = 0; x < d; ++x){
      int i;
      scanf("%d", &i);
      v.PB(i);
    }

    OutputLollipop();
    fflush(stdout);
  }
  fflush(stdout);
}

int main(){
  int t;

  scanf("%d", &t);

  srand(time(NULL));
  for(int k = 1; k <= t; ++k)
    Solve();

  return 0;
}
