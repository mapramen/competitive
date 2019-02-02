#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

typedef struct data{
  vector< pii > leftORs;
  vector< pii > rightORs;
  ll ans;
}data;

typedef struct node{
  int leftEnd;
  int rightEnd;
  data ans;
  node* leftChild;
  node* rightChild;
}node;

int a[N], X;
data queryAns;

void InitialiseORVector(vector< pii >& ors, int i){
  ors.clear();
  ors.PB(MP(a[i], (int)(i != 0)));
}

data GetData(int i = 0){
  data d;
  InitialiseORVector(d.leftORs, i);
  InitialiseORVector(d.rightORs, i);
  d.ans = (i == 0) ? 0 : (int)(a[i] >= X);
  return d;
}

ll ComputeAns(vector< pii >& leftORs, vector< pii >& rightORs){
  ll ans = 0;
  for(int i = 0, j = rightORs.size() - 1, s = 0; i < leftORs.size(); ++i){
    for( ; j > -1 && (rightORs[j].first | leftORs[i].first) >= X; s += rightORs[j].second, --j);
    ans += 1ll * leftORs[i].second * s;
  }
  return ans;
}

void CombineORVectors(vector< pii >& a, vector< pii >& b, vector< pii >& c){
  vector< pii > d;

  for(auto p : a){
    d.PB(p);
  }

  int prevPrefixOr = d.back().first;
  for(auto p : b){
    int curPrefixOr = (prevPrefixOr | p.first);
    int count = p.second;
    if(curPrefixOr == prevPrefixOr){
      d.back().second += count;
    }
    else{
      d.PB(MP(curPrefixOr, count));
    }
    prevPrefixOr = curPrefixOr;
  }

  c.clear();
  for(auto p : d){
    c.PB(p);
  }
}

void CombineData(data& a, data& b, data& c){
  c.ans = a.ans + b.ans + ComputeAns(a.leftORs, b.rightORs);
  CombineORVectors(b.leftORs, a.leftORs, c.leftORs);
  CombineORVectors(a.rightORs, b.rightORs, c.rightORs);
}

//----------------------------------------- Segment Tree -----------------------------------------//

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    CombineData(temp->leftChild->ans, temp->rightChild->ans, temp->ans);
  }
  else{
    temp->ans = GetData(leftEnd);
    temp->leftChild = temp->rightChild = NULL;
  }

  return temp;
}

void Update(node *currentNode, int i){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    if(i == currentNode->leftEnd && i == currentNode->rightEnd)
      currentNode->ans = GetData(i);
    else{
      Update(currentNode->leftChild, i);
      Update(currentNode->rightChild, i);
      CombineData(currentNode->leftChild->ans, currentNode->rightChild->ans, currentNode->ans);
    }
  }
}

void Query(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l){
    return ;
  }
  else{
    if(l <= currentNode->leftEnd && currentNode->rightEnd <= r)
      CombineData(queryAns, currentNode->ans, queryAns);
    else{
      Query(currentNode->leftChild, l, r);
      Query(currentNode->rightChild, l, r);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, q;

  scanf("%d%d%d", &n, &q, &X);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  node *root = BuildSegmentTree(1, n);

  while(q--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);

    if(t == 1){
      a[l] = r;
      Update(root, l);
    }
    else{
      queryAns = GetData();
      Query(root, l, r);
      printf("%lld\n", queryAns.ans);
    }
  }

  return 0;
}
