#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 70001
#define B 10
#define M 45

vector<string> phoneNos;
int T[B][M * N], C[M * N], nxt = 0, ansS[N], ansL[N];

void Insert(string s, int phoneIndex){
  for(int i = 0, k = 0; k < s.size(); ++k){
    int j = s[k] - '0';
    if(T[j][i] == 0)
      T[j][i] = ++nxt;
    i = T[j][i];
    if(C[i] == -1 || C[i] == phoneIndex)
      continue;
    else{
      if(C[i])
        C[i] = -1;
      else
        C[i] = phoneIndex;
    }
  }
}

void InsertPhoneNo(string s, int phoneIndex){
  for(int i = 0; i < B - 1; ++i)
    Insert(string(s, i), phoneIndex);
}

int main(){
  int n;

  cin >> n;
  C[0] = -1;
  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;
    phoneNos.PB(s);
    InsertPhoneNo(s, i + 1);
    ansL[i] = B;
  }

  for(int x = 0; x < n; ++x){
    for(int i = 0; i < B - 1; ++i){
      int cur = 0;
      for(int j = i, len = 1; j < B - 1; ++j, ++len){
        cur = T[phoneNos[x][j] - '0'][cur];
        if(C[cur] == x + 1){
          if(len < ansL[x])
            ansL[x] = len, ansS[x] = i;
        }
      }
    }
  }

  for(int i = 0; i < n; ++i)
    cout << string(phoneNos[i], ansS[i], ansL[i]) << '\n';

  return 0;
}
