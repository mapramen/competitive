#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

set<string> final_positions;
set<pii> visited;

vector<int> winning_masks = {
    0b111000000,
    0b000111000,
    0b000000111,
    0b100100100,
    0b010010010,
    0b001001001,
    0b100010001,
    0b001010100,
};

bool IsWinningMask(int mask) {
  for (int winning_mask : winning_masks) {
    if ((mask & winning_mask) == winning_mask) {
      return true;
    }
  }
  return false;
}

string ToFinalPositionString(int xmask, int omask) {
  string s = "";
  for (int i = 0; i < 9; i++) {
    if ((xmask & (1 << i)) != 0) {
      s += 'X';
    } else if ((omask & (1 << i)) != 0) {
      s += 'O';
    } else {
      s += '.';
    }
  }
  return s;
}

void Search(int xmask, int omask, int move_number) {
  if (visited.find({xmask, omask}) != visited.end()) {
    return;
  }

  if (move_number == 10 || IsWinningMask(xmask) || IsWinningMask(omask)) {
    final_positions.insert(ToFinalPositionString(xmask, omask));
    return;
  }

  for (int i = 0; i < 9; i++) {
    if ((xmask & (1 << i)) != 0 || (omask & (1 << i)) != 0) {
      continue;
    }
    if (move_number % 2 == 1) {
      Search(xmask | (1 << i), omask, move_number + 1);
    } else {
      Search(xmask, omask | (1 << i), move_number + 1);
    }
  }
}

void Precompute() {
  Search(0, 0, 1);
}

bool Solve() {
  string s;
  cin >> s;

  if (s == "end") {
    exit(0);
  }

  return final_positions.find(s) != final_positions.end();
}

int main() {
  Precompute();
  while (true) {
    printf("%s\n", Solve() ? "valid" : "invalid");
  }
  return 0;
}