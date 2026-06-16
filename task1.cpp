#include <iostream>
#include <vector>
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
  // Отметка вывода
  std::cout << "Pyramid loaded:" << '\n';
  // Вывод данных для проверки корректности ввода
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << pyramid[i][j] << " ";
    }
    std::cout << '\n';
  }

  return 0;
}