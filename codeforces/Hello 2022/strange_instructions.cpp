#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int oneOperations = 0, middleZeroDeleteOperations = 0, endZeroDeleteOperartions = 0;
priority_queue<pii,vector<pii>,greater<pii>> Q;

void Reset(){
  oneOperations = 0, middleZeroDeleteOperations = 0, endZeroDeleteOperartions = 0;
  while(!Q.empty()){
    Q.pop();
  }
}

void AddZeroOperation(int isEnd, int zeros){
  if(zeros == 0){
    return;
  }

  if(zeros > 1){
    Q.push({isEnd, zeros});
    return;
  }
  
  if(isEnd == 0){
    ++middleZeroDeleteOperations;
  }
  else{
    ++endZeroDeleteOperartions;
  }
}

ll Calculate(string s, int op, int a, int b, int c){
  int n = s.size();

  Reset();

  for(int i = 1; i < n; ++i){
    oneOperations += (s[i] == '1' && s[i - 1] == '1');
  }

  for(int i = 0; i < n; ++i){
    if(s[i] == '1'){
      continue;
    }

    int j = i;
    for( ; j < n && s[j] == '0'; ++j);
    AddZeroOperation(i == 0 || j == n, j - i);
    i = j - 1;
  }

  ll ans = 0, ansx = 0;
  for( ; true; op ^= 1){
    if(op == 0){
      if(oneOperations == 0){
        break;
      }
      ansx += b;
      --oneOperations;
    }
    else{
      if(oneOperations == 0 && !Q.empty()){
        ans = max(ans, ansx + a);
      }

      if(oneOperations == 0 || Q.empty()){
        if(middleZeroDeleteOperations != 0){
          --middleZeroDeleteOperations, ++oneOperations;
          ansx -= c;
        }
        else if(endZeroDeleteOperartions != 0){
          --endZeroDeleteOperartions;
          ansx -= c;
        }
        else{
          break;
        }
      }
      else{
        auto [isEnd, zeros] = Q.top();
        Q.pop();

        ansx += a;
        AddZeroOperation(isEnd, zeros - 1);
      }
    }

    ans = max(ans, ansx);
  }

  return ans;
}

ll Solve(){
  int n, a, b, c;
  string s;

  cin >> n >> a >> b >> c >> s;

  return max(Calculate(s, 0, a, b, c), Calculate(s, 1, a, b, c));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}