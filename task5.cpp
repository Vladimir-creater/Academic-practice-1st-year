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

  // Иннициализируем границы фигуры
  int min_row = height;
  int max_row = -1;
  int min_col = width;
  int max_col = -1;

  // Ищем границы фигуры
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (matrix[i][j] == 1) {
        if (i < min_row) min_row = i;
        if (i > max_row) max_row = i;
        if (j < min_col) min_col = j;
        if (j > max_col) max_col = j;
      }
    }
  }

  // Находим координаты прямоугольника
  int rect_min_row = min_row - 1;
  int rect_min_col = min_col - 1;
  int rect_max_row = max_row + 1;
  int rect_max_col = max_col + 1;

  // Вывод финального результата
  std::cout << rect_min_row << " " << rect_min_col << " " << rect_max_row << " " << rect_max_col << '\n';

  return 0;
}