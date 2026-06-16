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

  // Создаём копию пирамиды, чтобы восстановить путь
  std::vector<std::vector<int>> original_pyramid = pyramid;
  
  // Алгоритм вывода минимальной суммы на позицию pyramid[0][0]
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      pyramid[i][j] += std::min(pyramid[i + 1][j], pyramid[i + 1][j + 1]);
    }
  }

  // Восстановление пути
  std::vector<int> route; // Место хранения пути
  int j = 0;

  for (int i = 0; i < N - 1; i++) {
    route.push_back(original_pyramid[i][j]);
    if (pyramid[i + 1][j] <= pyramid[i + 1][j + 1]) {
      // Если левое меньше, индекс j не меняется
    } else {
      // Если правое меньше, индекс j меняется на j + 1
      j++;
    }
  }
  // Не забываем последнее число
  route.push_back(original_pyramid[N - 1][j]);
  
  // Вывод минимальной суммы
  std::cout << pyramid[0][0] << '\n';

  //Вывод маршрута через пробел
  for (int i = 0; i < N; i++) {
    std::cout << route[i] << " ";
  }

  return 0;
}