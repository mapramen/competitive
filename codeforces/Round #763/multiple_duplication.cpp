#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 26

char s[N];
set<int> S[B];
int leftChild[N], rightChild[N], parent[N], startTime[N], finishTime[N], startTimeToVertex[N], inorderIndex[N], timer = 0;
bool marker[N];
vector<int> inorder;

int T1[N], T2[N];

void Update(int T[], int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Update(int T[], int l, int r, int x){
  Update(T, l, x);
  Update(T, r + 1, -x);
}

int Query(int T[], int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void InorderDFS(int i, int p){
  if(i == 0){
    return;
  }

  parent[i] = p;
  
  InorderDFS(leftChild[i], i);
  
  inorder.push_back(i);
  inorderIndex[i] = inorder.size() - 1;

  InorderDFS(rightChild[i], i);
}

void PreOrderDFS(int i){
  if(i == 0){
    return;
  }

  startTime[i] = ++timer;
  startTimeToVertex[timer] = i;

  PreOrderDFS(leftChild[i]);
  PreOrderDFS(rightChild[i]);

  finishTime[i] = timer;
}

void InsertChar(int i, char c){
  S[c - 'a'].insert(i);
}

char GetNextChar(int i, char c){
  int k = -1, xk = INT_MAX;
  
  for(int j = 0; j < B; ++j){
    if(S[j].empty() || 'a' + j == c){
      continue;
    }

    auto jt = S[j].upper_bound(i);
    if(jt == S[j].end()){
      continue;
    }

    int xj = *jt;
    if(xj < xk){
      xk = xj, k = j;
    }
  }

  return 'a' + k;
}

int main(){
  int n, m;
  scanf("%d%d%s", &n, &m, s);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &leftChild[i], &rightChild[i]);
  }

  InorderDFS(1, 0);
  PreOrderDFS(1);

  for(int i = 1; i <= n; ++i){
    Update(T1, startTime[i], finishTime[i], 1);
  }

  for(int k = 0; k < n; ++k){
    int i = inorder[k];
    InsertChar(2 * k, s[i - 1]);
  }

  for(int k = 0; k < n; ++k){
    int i = inorder[k];
    int d = Query(T1, startTime[i]);

    if(d == 0 || d > m || Query(T2, startTime[i]) > 0){
      continue;
    }

    char c = GetNextChar(2 * k, s[i - 1]);

    if(c < s[i - 1]){
      Update(T2, startTime[i], finishTime[i], 1);
      continue;
    }

    for(int j = i; j != 0 && !marker[j]; j = parent[j]){
      Update(T1, startTime[j], finishTime[j], -1);
      InsertChar(2 * inorderIndex[j] + 1, s[j - 1]);
      --m;
      marker[j] = true;
    }
  }

  while(true){
    int k = -1, xk = INT_MAX;
    for(int i = 0; i < B; ++i){
      if(S[i].empty()){
        continue;
      }

      int xi = *(S[i].begin());
      if(xi < xk){
        xk = xi, k = i;
      }
    }

    if(k == -1){
      break;
    }

    putchar('a' + k);
    S[k].erase(xk);
  }
  putchar('\n');

  return 0;
}