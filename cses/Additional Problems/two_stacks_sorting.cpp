// Here are two interesting counter-examples:
// (a)	5,2,7,4,1,6,3
// This permutation is not sortable by two stacks, but it also does not contain a subsequence  with   Thus it is a counter-example to Problem Set 1, No. 1.
// (b)	5,7,2,4,1,6,3
// This permutation is sortable by two stacks, but not if the greedy rule is used. (Given a choice, put the next item on the stack with the smaller topmost item.) The 2 must be placed on the 7, not on the 5, to allow sorting.
// We obtain a linear-time algorithm for testing sortability using a data structure we call a pile of twins. The structure represents all possible legal configurations of the two stacks as sorting proceeds. (A configuration is legal if both stacks are in increasing order from top to bottom.) A twin is a pair of stacks (call them left and right), each of whose elements are in increasing order, top to bottom. A pile of twins is a stack of twins such that all elements of any twin are smaller than those of any twin underneath it, and each twin contains at least one element (on one or the other of its stacks). We begin with an empty pile of twins. We repeat the following step until either we get stuck (the sequence is unsortable) or the input and the pile of twins are empty (the sequence is sortable).
// If the smallest element not on the output is at the front of the input or on top of the one of the stacks of the top twin on the pile, move it to the output;
// if this makes the top twin empty, pop it from the pile. Otherwise, remove the first element, say x from the input. Create a new twin with x in the left stack and nothing on the right stack, and push it on the pile. Repeat the following substep until there is only one twin or the pile, or x is less than the tops of both stacks on the second twin. If x is greater than both tops of the second twin, stop: the sequence is unsortable. Otherwise If x is greater than the top of the left stack of the second twin, flip the second twin (exhange its left and right stacks). Now x is greater than the top of the right stack of the second twin but not that of the right. Fuse the top two twins by catenating their left and right stacks to form a single twin, which replaces the two twins on top of the pile.
// It is straightforward to implement this algorithm so that each substep takes time (Exercise: how?). Each step adds at most one twin to the pile; each substep decreases the number of twins by one, so the total time is linear.
// This algorithm does not actually produce a sequence of moves to do the sorting, but such a sequence can be found in linear additional time. (Exercise: how?)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<pii>> adj(N);
int color[N], nxt[N];
bool visited[N];

void AddEdge(int i, int j, int c) {
  if (i == INT_MAX || j == INT_MAX) {
    return;
  }
  adj[i].push_back({j, c});
  adj[j].push_back({i, c});
}

pii RemoveTop(pii& a) {
  return a.first == a.second ? pii(INT_MAX, INT_MAX) : pii(nxt[a.first], a.second);
}

pii Merge(pii& a, pii& b) {
  if (a.first == INT_MAX) {
    return b;
  }

  if (b.first == INT_MAX) {
    return a;
  }

  nxt[a.second] = b.first;
  return {a.first, b.second};
}

void DFS(int i, int c) {
  if (visited[i]) {
    assert(color[i] == c);
    return;
  }

  visited[i] = true;
  color[i] = c;

  for (pii& p : adj[i]) {
    DFS(p.first, c ^ p.second);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }

  stack<pair<pii, pii>> S;

  for (int target = 1, i = 0; target <= n && i < n;) {
    if (a[i] == target) {
      ++i, ++target;
      continue;
    }

    if (S.empty()) {
      S.push({{a[i], a[i]}, {INT_MAX, INT_MAX}});
      ++i;
      continue;
    }

    if (S.top().first.first == INT_MAX && S.top().second.first == INT_MAX) {
      S.pop();
      continue;
    }

    if (S.top().first.first == target) {
      S.top().first = RemoveTop(S.top().first);
      ++target;
      continue;
    }

    if (S.top().second.first == target) {
      S.top().second = RemoveTop(S.top().second);
      ++target;
      continue;
    }

    pair<pii, pii> new_top = {{a[i], a[i]}, {INT_MAX, INT_MAX}};
    while (!S.empty()) {
      bool less_than_left = a[i] < S.top().first.first;
      bool less_than_right = a[i] < S.top().second.first;

      if (!less_than_left && !less_than_right) {
        printf("IMPOSSIBLE\n");
        return 0;
      }

      if (less_than_left && less_than_right) {
        break;
      }

      if (!less_than_left) {
        swap(S.top().first, S.top().second);
        continue;
      }

      AddEdge(new_top.first.first, S.top().first.first, 0);
      AddEdge(new_top.second.first, S.top().second.first, 0);
      new_top = {Merge(new_top.first, S.top().first), Merge(new_top.second, S.top().second)};
      S.pop();
    }

    AddEdge(new_top.first.first, new_top.second.first, 1);
    S.push(new_top);
    ++i;
  }

  for (int i = 1; i <= n; ++i) {
    DFS(i, color[i]);
  }

  for (int i : a) {
    printf("%d ", 1 + color[i]);
  }
  printf("\n");

  return 0;
}
