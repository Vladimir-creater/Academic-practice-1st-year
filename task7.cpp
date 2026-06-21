#include <iostream>
#include <string>

int main() {
  // Вводим номер из базы
  std::string car_num;
  std::cin >> car_num;

  // Проверка на размер номера
  if (car_num.length() != 6) {
    std::cout << "No" << '\n';
    return 0;
  }

  // Проверка первого символа
  if (!(car_num[0] >= 'A' && car_num[0] <= 'Z')) {
    std::cout << "No" << '\n';
    return 0;
  }

  // Проверка 2, 3 и 4 символа
  for (int i = 1; i <= 3; i++) {
    if (!(car_num[i] >= '0' && car_num[i] <= '9')) {
      std::cout << "No" << '\n';
    }
  }
  
  // Проверка двух оставшихся символов
  for (int i = 4; i <= 5; i++) {
    if (!(car_num[i] >= 'A' && car_num[i] <= 'Z')) {
      std::cout << "No" << '\n';
      return 0;
    }
  }

  // Если номер прошёл все проверки => он верный
  std::cout << "Yes" << '\n';

  return 0;
}