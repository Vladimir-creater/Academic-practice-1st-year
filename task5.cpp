#include <iostream>
#include <vector>

int main() {
  // Записываем высоту и ширину матрицы
  int height, width;
  std::cin >> height >> width;

  // Записываем матрицу
  std::vector<std::vector<int>> matrix(height, std::vector<int>(width));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cin >> matrix[i][j];
    }
  }

  // Выводим матрицу для проверки корректности ввода
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << '\n';
  }

  return 0;
}