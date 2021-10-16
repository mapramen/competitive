#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000005

char S[N];
int a[N];

string ReadString(){
  scanf("%s", S);
  return string(S);
}

vector<int> ZFunction(string s){
  int n = s.size();
  vector<int> z(n + 1);

  for(int i = 1, l = 0, r = 0; i < n; ++i){
    if (i <= r){
      z[i] = min (r - i + 1, z[i - l]);
    }

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
      ++z[i];
    }
            
    if (i + z[i] - 1 > r){
      l = i, r = i + z[i] - 1;
    }
  }
  
  return z;
}

vector<int> PrefixFunction(string s){
  int n = s.length();
  vector<int> pi(n);

  for(int i = 1; i < n; ++i){
    int j = pi[i - 1];
    
    while (j > 0 && s[i] != s[j]){
      j = pi[j - 1];
    }

    if(s[i] == s[j]){
      j++;
    }
    
    pi[i] = j;
  }
  
  return pi;
}

ll Solve(){
  string s1 = ReadString();
  string s2 = ReadString();
  string x = ReadString();

  vector<int> z = ZFunction(s2 + "$" + x);
  vector<int> pi = PrefixFunction(s1 + "$" + x);

  int n = s1.size(), m = x.size();
  for(int i = 0; i <= n; ++i){
    a[i] = -1;
  }

  for(int i = n, j = s2.size() + 1, k = 0; k <= m; ++i, ++j, ++k){
    int p = pi[i];
    a[p] = max(a[p], z[j]);
  }

  ll ans = 0;
  for(int i = n; i != -1; --i){
    int ansx = a[i];
    if(ansx == -1){
      continue;
    }
    
    int p = pi[i - 1];
    a[p] = max(a[p], ansx);

    ans += (1 + ansx);
    a[i] = -1;
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