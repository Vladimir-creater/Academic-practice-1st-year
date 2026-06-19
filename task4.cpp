#include <iostream>
#include <vector>
#include <string>

int main() {
  // Объявляем и считываем количество символов и перестановок
  int count_of_characters, count_of_permutation;
  std::cin >> count_of_characters >> count_of_permutation;

  // Считываем перестановку
  std::vector<int> Permutation(count_of_characters + 1);
  for (int i = 1; i <= count_of_characters; i++) {
    std::cin >> Permutation[i];
  }

  // Объявляем и считываем зашифрованное слово
  std::string encrypted;
  std::cin >> encrypted;

  // Выводим результат для проверки корректности ввода
  for (int i = 0; i <= count_of_characters; i++) {
    std::cout << Permutation[i] << " ";
  }
  std::cout << '\n';
  std::cout << encrypted << '\n';

}