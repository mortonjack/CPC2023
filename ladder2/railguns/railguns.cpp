#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

class Cache {
  private:
    unordered_map<int, unordered_map<int, unordered_set<int>>> m_explored;
  public:
    bool unexplored(int i, int j, int t) {
      if (m_explored[i][j].find(t) != m_explored[i][j].end()) {
        return false;
      }
      m_explored[i][j].insert(t);
      return true;
    }
};

class Shots {
  private:
    unordered_map<int, unordered_map<int, unordered_set<int>>> shots;
  public:
    void add_shot(int t, int d, int coord) {
      shots[t][d].insert(coord);
    }
    bool is_shot(int t, int i, int j) {
      if (shots.count(t)) {
        if (shots[t].count(1)) {
          if (shots[t][1].find(i) != shots[t][1].end()) return true;
        }
        if (shots[t].count(2)) {
          if (shots[t][2].find(j) != shots[t][2].end()) return true;
        }
      }
      return false;
    }
};

class Pos {
  public:
    int time;
    int row;
    int col;
    Pos(int t, int r, int c): time(t), row(r), col(c) {}
    
    bool operator>(const Pos& other) const {
        if (time != other.time) return time < other.time;
        return row+col < other.row+other.col;
    }
    bool operator<(const Pos& other) const {
        if (time != other.time) return time > other.time;
        return row+col > other.row+other.col;
    }
    bool operator==(const Pos& other) const {
        return time == other.time && row == other.row && col == other.col;
    }
    bool operator>=(const Pos& other) const {
        if (time != other.time) return time <= other.time;
        return row+col <= other.row+other.col;
    }
    bool operator<=(const Pos& other) const {
        if (time != other.time) return time >= other.time;
        return row+col >= other.row+other.col;
    }
};

int play(int n, int m, Shots& shots) {
  Cache cache;
  priority_queue<Pos> q;
  q.emplace(0, 0, 0);
  while (!q.empty()) {
    Pos pos = q.top(); q.pop();
    if (pos.row == n && pos.col == m) return pos.time;

    if (!shots.is_shot(pos.time+1, pos.row, pos.col) 
    && cache.unexplored(pos.time+1, pos.row, pos.col)) {
      q.emplace(pos.time+1, pos.row, pos.col);
    }

    if (pos.row != n 
    && !shots.is_shot(pos.time+1, pos.row+1, pos.col) 
    && cache.unexplored(pos.time+1, pos.row+1, pos.col)) {
      q.emplace(pos.time+1, pos.row+1, pos.col);
    }
    if (pos.row != 0
    && !shots.is_shot(pos.time+1, pos.row-1, pos.col) 
    && cache.unexplored(pos.time+1, pos.row-1, pos.col)) {
      q.emplace(pos.time+1, pos.row-1, pos.col);
    }
    if (pos.col != m 
    && !shots.is_shot(pos.time+1, pos.row, pos.col+1) 
    && cache.unexplored(pos.time+1, pos.row, pos.col+1)) {
      q.emplace(pos.time+1, pos.row, pos.col+1);
    }
    if (pos.col != 0 
    && !shots.is_shot(pos.time+1, pos.row, pos.col-1) 
    && cache.unexplored(pos.time+1, pos.row, pos.col-1)) {
      q.emplace(pos.time+1, pos.row, pos.col-1);
    }
  }
  return -1;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, r;
    cin >> n >> m >> r;
    Shots shots;
    for (int j = 0; j < r; j++) {
      int t, d, coord;
      cin >> t >> d >> coord;
      shots.add_shot(t, d, coord);
    }
    cout << play(n, m, shots) << '\n';
  }
  return 0;
}