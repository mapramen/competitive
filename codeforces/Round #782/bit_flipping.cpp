#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Flip(string& s, vector<int>& f, int k){
  for(int i = 0; i < s.size(); ++i){
    if(i != k){
      s[i] ^= ('0' ^ '1');
    }
  }
  ++f[k];
}

bool Print(int n, string s, vector<int> f){
  int k = 0;
  for(int& x: f){
    k += x;
  }

  for(int i = 0; i < n; ++i){
    if((k - f[i]) % 2 == 0){
      continue;
    }
    s[i] ^= ('0' ^ '1');
  }

  printf("%s\n", s.c_str());
  for(int& x: f){
    printf("%d ", x);
  }
  printf("\n");

  return true;
}

bool Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  string s;
  cin >> s;
  string t = string(s);

  vector<int> f(n);

  if(s.front() == '0' && k % 2 == 1){
    int i = 0;
    for( ; i < n - 1 && s[i] == '0'; ++i);
    Flip(s, f, i);
    --k;
  }

  if(s.front() == '1' && k % 2 == 1){
    Flip(s, f, 0);
    --k;
  }

  for(int i = 0; i < n && k >= 2; ++i){
    if(s[i] == '1'){
      continue;
    }

    int j = i + 1;
    for( ; j < n - 1 && s[j] == '1'; ++j);
    if(j < n){
      ++f[i], ++f[j];
      k -= 2;
    }

    i = j;
  }

  f[0] += k;

  return Print(n, t, f);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}