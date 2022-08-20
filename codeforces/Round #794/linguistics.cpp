#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];

int GetCount(char c){
  int cnt = 0;
  for(int i = 0; s[i] != '\0'; ++i){
    cnt += (s[i] == c);
  }
  return cnt;
}

void ComputeSameStart(vector<int>& AB, int& c){
  sort(AB.begin(), AB.end());
  for(int& x: AB){
    int z = min(x, c);
    c -= z, x -= z;
  }
}

void ComputeDifferentStart(vector<int>& BA, int& c){
  sort(BA.begin(), BA.end(), greater<int>());
  for(int& x: BA){
    int z = max(0, min(x - 1, c));
    c -= z;
    if(z != 0){
      x -= (z + 1);
    }
  }
}

bool Check(vector<int> AB, vector<int> BA, vector<int> C, int c, int d){
  ComputeSameStart(AB, c);
  ComputeSameStart(C, c);
  ComputeDifferentStart(BA, c);

  ComputeSameStart(BA, d);
  ComputeSameStart(C, d);
  ComputeDifferentStart(AB, d);

  return c == 0 && d == 0;
}

bool Solve(){
  int a, b, c, d;
  scanf("%d%d%d%d%s", &a, &b, &c, &d, s);

  if(a + c + d != GetCount('A') || b + c + d != GetCount('B')){
    return false;
  }

  int n = strlen(s);
  vector<int> AB, BA, C;

  for(int i = 0, j = 0; i < n; i = j){
    for(j = i + 1; j < n && s[j] != s[j - 1]; ++j);

    int k = j - i;

    if(k == 1){
      continue;
    }

    if(k % 2 == 1){
      C.push_back(k / 2);
      continue;
    }

    if(s[i] == 'A'){
      AB.push_back(k / 2);
    }
    else{
      BA.push_back(k / 2);
    }
  }
  
  return Check(AB, BA, C, c, d) || Check(BA, AB, C, d, c);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}