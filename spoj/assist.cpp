#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> a(1);

vector<int> Update(vector<int>& v){
  int m = v.front();
  vector<int> u;

  int i = 0;
  for(int x: v){
    if(i != 0){
      u.push_back(x);
    }
    i = (i + 1) % m;
  }

  return u;
}

void Initialize(){
  vector<int> v(35001);
  iota(v.begin(), v.end(), 2);

  for(int cnt = 1; !v.empty(); ++cnt, v = Update(v)){
    a.push_back(v.front());
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  if(n == 0){
    exit(0);
  }
  return a[n];
}

int main(){
  Initialize();
  
  while(true){
    printf("%d\n", Solve());
  }
  
  return 0;
}