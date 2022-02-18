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
  sort(a.begin(), a.end());
  return a;
}

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0){
    exit(0);
  }

  vector<int> a = ReadArray(n);
  vector<int> b = ReadArray(m);

  return a.front() < b[1];
}

int main(){
  while(true){
    printf("%s\n", Solve() ? "Y" : "N");
  }
  return 0;
}