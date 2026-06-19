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
    // Если первый тип операции, записываем данные о снеге на улице
    if (type == 1) {
      int street, snow_mm;
      std::cin >> street >> snow_mm;
      snow[street] += snow_mm;

    // Если второй тип операции, выводим сумму снега от улицы street_from до улицы street_to включительно
    } else if (type == 2) {
      int street_from, street_to;
      std::cin >> street_from >> street_to;
      int sum = 0;
      for (int i = street_from; i <= street_to; i++) {
        sum += snow[i];
      }

      std::cout << sum << '\n';
    }
  }

  return 0;
}