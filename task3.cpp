#include <iostream>
#include <vector>

int main() {
  // Объявление кол-во улиц и кол-во запросов
  int num_of_streets, num_of_requests;
  std::cin >> num_of_streets >> num_of_requests;

  //Массив с данными о количестве снега на улицах
  std::vector<int> snow(num_of_streets + 1, 0);

  // Обработка входных данных
  for (int i = 0; i < num_of_requests; i++) {
    int type;
    std::cin >> type;

    if (type == 1) {
      int street, snow_mm;
      std::cin >> street >> snow_mm;
      snow[street] += snow_mm;
    } else if (type == 2) {
      int street_from, street_to;
      std::cin >> street_from >> street_to;
      // Пока ничего
      std::cout << "Being developed" << '\n';
    }
  }

  // Выводим значения в списке snow для проверки обработки входных данных
  for (int i = 0; i <= num_of_streets; i++) {
    std::cout << i << ": " << snow[i] << '\n';
  }

  return 0;
}