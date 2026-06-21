#include <iostream>
#include <algorithm>

int main() {
  // Вводим кол-во запросов
  int num_of_requests;
  std::cin >> num_of_requests;

  // Повторяем цикл по количеству запросов
  for (int i = 0; i < num_of_requests; i++) {

    // Вводим данные
    int a, b, x, y;
    std::cin >> a >> b >> x >> y;

    // Находим кол-во пар для типа В
    int pairs_B = std::min(b, x);
    // Вычисляем кол-во оставшихся модулей типа 1
    int remaining_type1 = x - pairs_B;

    // Находим кол-во пар типа А
    int pairs_A = std::min(a, remaining_type1 + y);

    // Выводим наибольшее кол-во пар
    std::cout << pairs_B + pairs_A;

    // Выводим пробел, если будет ещё один вывод данных
    if (i < num_of_requests - 1) {
      std::cout << " ";
    }
  }
  std::cout << '\n';

  return 0;
}