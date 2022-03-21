#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 30001

char s[21];
int T[N];
map<string,int> M;

void Reset(){
  M.clear();
  for(int i = 1; i < N; ++i){
    T[i] = 0;
  }
}

void Update(int i){
  for( ; i < N; i += (i & -i)){
    ++T[i];
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

string ReadWord(){
  scanf("%s", s);
  return string(s);
}

vector<int> ReadSentence(int n){
  vector<int> v(n);
  
  for(int i = 1; i <= n; ++i){
    string s = ReadWord();
    auto it = M.find(s);
    if(it != M.end()){
      v[i - 1] = it->second;
    }
    else{
      M[s] = i;
      v[i - 1] = i;
    }
  }

  return v;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  Reset();
  ReadSentence(n);

  vector<int> a = ReadSentence(n);
  reverse(a.begin(), a.end());

  ll ans = 0;
  for(int x: a){
    ans += Query(x - 1);
    Update(x);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}