#include <iostream>
#include <vector>

int main() {
  // Вводим N - число вершин, M - число рёбер
  int N, M;
  std::cin >> N >> M;

  // Создаём список смежности
  std::vector<std::vector<int>> adj(N + 1);

  // Считываем рёбра и строим граф
  for (int i = 0; i < M; i++) {
    int u, v;
    std::cin >> u >> v;

    // Граф не направленный, поэтому добавляем ребро в обе стороны
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Выводим список смежности для проверки
  std::cout << "Adjancy list: " << '\n';
  for (int v = 1; v <= N; v++) {
    std::cout << v << ": ";
    for (int neighbor : adj[v]) {
      std::cout << neighbor << " ";
    }
    std::cout << '\n';
  }

  return 0;
}