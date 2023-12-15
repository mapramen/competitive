#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

set<string> rock = {"Kamen", "Rock", "Pierre", "Stein", "Ko", "Koe", "Sasso", "Roccia", "Guu", "Kamien", "Piedra"};
set<string> scissor = {"Nuzky", "Scissors", "Ciseaux", "Schere", "Ollo", "Olloo", "Forbice", "Choki", "Nozyce", "Tijera"};
set<string> paper = {"Papir", "Paper", "Feuille", "Papier", "Papir", "Carta", "Rete", "Paa", "Papier", "Papel"};

string ReadPlayerName() {
  string language, name;
  cin >> language >> name;
  return name;
}

int ReadMove(string hand) {
  if (rock.find(hand) != rock.end()) {
    return 0;
  }

  if (paper.find(hand) != paper.end()) {
    return 1;
  }

  if (scissor.find(hand) != scissor.end()) {
    return 2;
  }

  assert(false);
}

void PrintPlayerPoints(string name, int points) {
  cout << name << ": " << points << " " << (points == 1 ? "point" : "points") << '\n';
}

void Solve() {
  string player1 = ReadPlayerName();
  string player2 = ReadPlayerName();

  int player1_points = 0, player2_points = 0;
  string hand;

  while (true) {
    cin >> hand;

    if (hand == "-" || hand == ".") {
      break;
    }

    int player1_move = ReadMove(hand);

    cin >> hand;
    int player2_move = ReadMove(hand);

    if (player1_move == player2_move) {
      continue;
    }

    if ((player1_move + 1) % 3 == player2_move) {
      player2_points++;
    } else {
      player1_points++;
    }
  }

  PrintPlayerPoints(player1, player1_points);
  PrintPlayerPoints(player2, player2_points);

  if (player1_points == player2_points) {
    printf("TIED GAME\n");
  } else {
    string winner = player1_points > player2_points ? player1 : player2;
    printf("WINNER: %s\n", winner.c_str());
  }

  if (hand == ".") {
    exit(0);
  }

  printf("\n");
}

int main() {
  for (int g = 1;; ++g) {
    printf("Game #%d:\n", g);
    Solve();
  }
  return 0;
}