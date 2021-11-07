#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N];
int a[N], minPrime[N], nxt[N];
vector<vector<int>> V(N);
stack<int> S;

void Add(int i){
  int x = a[i];
  
  while(x > 1){
    int p = minPrime[x];
    V[p].push_back(i);
    x /= p;
  }
}

void Delete(int i){
  int x = a[i];
  
  int j = i;
  while(x > 1){
    int p = minPrime[x];
    
    if(V[p].empty()){
      j = -1;
    }
    else{
      j = min(j, V[p].back());
      V[p].pop_back();
    }

    x /= p;
  }

  nxt[i] = j;
}

void InitialiseNext(int n){
  for(int i = 1; i <= n; ++i){
    nxt[i] = i;
  }

  for(int x = 2; x < N; ++x){
    minPrime[x] = x;
  }

  for(int p = 2; p * p < N; ++p){
    if(minPrime[p] != p){
      continue;
    }

    for(int x = p * p; x < N; x += p){
      minPrime[x] = p;
    }
  }

  for(int i = 1; i <= n; ++i){
    if(s[i - 1] == '*'){
      Add(i);
    }
    else{
      Delete(i);
    }
  }
}

ll CalculateAns(int n){
  ll ans = 0;
  
  for(int i = n; i != 0; --i){
    int x = nxt[i];
    while(!S.empty() && nxt[S.top()] >= x){
      S.pop();
    }
    
    if(nxt[i] == i){
      int j = S.empty() ? n + 1 : S.top();
      ans += (j - i);
    }
    
    S.push(i);
  }

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  scanf("%s", s);

  InitialiseNext(n);

  printf("%lld\n", CalculateAns(n)); 
  
  return 0;
}