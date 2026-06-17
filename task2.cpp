#include <iostream>
#include <vector>

// Функция DFS для обхода компоненты связности
void dfs(int v, std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
  visited[v] = true; // Помечаем вершину как посещённую

  // Проходим по соседям текущей вершины
  for (int u : adj[v]) {
    if (!visited[u]) { // Если сосед не посещён
      dfs(u, adj, visited); // Рекурсивно вызываем DFS
    }
  }
}

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
  
  // Массив для отслеживания посещённых вершин
  std::vector<bool> visited(N + 1, false);

  // Считываем количество компонент связности
  int components = 0;

  for (int v = 1; v <= N; v++) {
    if (!visited[v]) {
      // Нашли новую компоненту связности
      dfs(v, adj, visited);
      components++;
    }
  }

  // Выводим результат
  std::cout << components - 1 << '\n';

  return 0;
}