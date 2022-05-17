#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ReadArray(int n){
  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  return a;
}

int Calculate(vector<int> a){
  int skip_ans = 0, ans = 0;
  for(int x: a){
    int cur_ans = skip_ans + x;
    skip_ans = max(skip_ans, ans);
    ans = cur_ans;
  }
  return max(skip_ans, ans);
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0){
    exit(0);
  }

  vector<int> a(n);
  for(int& x: a){
    x = Calculate(ReadArray(m));
  }

  return Calculate(a);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}