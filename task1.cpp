#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  // Инициализируем и вводим высоту пирамиды
  int N;
  std::cin >> N;

  // Создаём пирамиду
  std::vector<std::vector<int>> pyramid(N);

  //Считываем данные
  for (int i = 0; i < N; i++) {
    pyramid[i].resize(i + 1);
    for (int j = 0; j <= i; j++) {
      std::cin >> pyramid[i][j];
    }
  }
  
  // Алгоритм вывода минимальной суммы на позицию pyramid[0][0]
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      pyramid[i][j] += std::min(pyramid[i + 1][j], pyramid[i + 1][j + 1]);
    }
  }
  
  // Вывод минимальной суммы
  std::cout << "Minimum amount: " << pyramid[0][0] << '\n';

  return 0;
}