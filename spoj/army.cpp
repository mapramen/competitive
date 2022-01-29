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
  reverse(a.begin(), a.end());
  return a;
}

string Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a = ReadArray(n);
  vector<int> b = ReadArray(m);

  while(!a.empty() && !b.empty()){
    if(a.back() < b.back()){
      a.pop_back();
    }
    else{
      b.pop_back();
    }
  }

  if(!a.empty()){
    return "Godzilla";
  }

  if(!b.empty()){
    return "MechaGodzilla";
  }

  return "uncertain";
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}