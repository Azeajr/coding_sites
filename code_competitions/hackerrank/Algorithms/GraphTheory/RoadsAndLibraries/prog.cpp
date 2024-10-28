#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

class DSU {
  int *parent;
  int *rank;
  int size;

public:
  DSU(int n) {
    size = n;
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; i++) {
      parent[i] = -1;
      rank[i] = 1;
    }
  }

  int find(int i) {
    if (parent[i] == -1) {
      return i;
    }
    return parent[i] = find(parent[i]);
  }

  void unite(int x, int y) {
    int s1 = find(x);
    int s2 = find(y);

    if (s1 != s2) {
      if (rank[s1] < rank[s2]) {
        parent[s1] = s2;
        rank[s2] += rank[s1];
      } else {
        parent[s2] = s1;
        rank[s1] += rank[s2];
      }
    }
  }
  // friend ostream &operator<<(ostream &os, const DSU &dsu);
};

// ostream &operator<<(ostream &os, const DSU &dsu) {
//   for (int i = 0; i < dsu.size; i++) {
//     os << dsu.parent[i] << ":" << dsu.rank[i] << endl;
//   }
//   return os;
// }

class Graph {
  vector<vector<int>> edgeList;
  int V;
  DSU *s;
  int trees;
  int treeCost;

public:
  Graph(int V, int treeCost) {
    this->V = V;
    trees = -1;
    this->treeCost = treeCost;
  }

  void addEdge(int x, int y, int w) { edgeList.push_back({w, x, y}); }

  long kruskals_mst() {
    sort(edgeList.begin(), edgeList.end());

    s = new DSU(V);

    long ans = 0;
    for (auto edge : edgeList) {
      int w = edge[0];
      int x = edge[1];
      int y = edge[2];

      if (s->find(x) != s->find(y)) {
        s->unite(x, y);
        ans += w;
      }
    }
    trees = 0;
    for (int i = 0; i < V; i++) {
      if (s->find(i) == i) {
        trees++;
      }
    }
    delete s;
    return ans + trees * treeCost;
  }
};

long roadsAndLibraries(int n, int c_lib, int c_road,
                       vector<vector<int>> cities) {
  if (c_lib <= c_road) {
    return n * c_lib;
  } else {
    Graph roadsAndLibraries(n, c_lib);
    for (auto city : cities) {
      roadsAndLibraries.addEdge(city[0], city[1], c_road);
    }

    return roadsAndLibraries.kruskals_mst();
  }
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int c_lib = stoi(first_multiple_input[2]);

    int c_road = stoi(first_multiple_input[3]);

    vector<vector<int>> cities(m);

    for (int i = 0; i < m; i++) {
      cities[i].resize(2);

      string cities_row_temp_temp;
      getline(cin, cities_row_temp_temp);

      vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

      for (int j = 0; j < 2; j++) {
        int cities_row_item = stoi(cities_row_temp[j]);

        cities[i][j] = cities_row_item;
      }
    }

    long result = roadsAndLibraries(n, c_lib, c_road, cities);

    cout << result << "\n";
    // fout << result << "\n";
  }

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
