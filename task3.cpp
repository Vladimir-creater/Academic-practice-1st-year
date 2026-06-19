#include <iostream>
#include <vector>

int main() {
  // Объявление кол-во улиц и кол-во запросов
  int num_of_streets, num_of_requests;
  std::cin >> num_of_streets >> num_of_requests;

  // Создаём список запросов
  std::vector<std::vector<int>> queries;

  // Сохраняем все запросы и взависимости от типа выводим информацию для проверки корректности считывания вводных данных
  for (int i = 0; i < num_of_requests; i++) {
    int type;
    std::cin >> type;

    if (type == 1) {
      int street, snow;
      std::cin >> street >> snow;
      queries.push_back({type, street, snow});
      std::cout << "Update: street " << street << ",snow " << snow << "mm" << '\n';
    } else if (type == 2) {
      int street_from, street_to;
      std::cin >> street_from >> street_to;
      queries.push_back({type, street_from, street_to});
      std::cout << "Give inf: street from " << street_from << " to " << street_to << '\n';
    }
  }

  return 0;
}