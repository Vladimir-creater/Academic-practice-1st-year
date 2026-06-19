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

  // Находим обратную перестановку
  std::vector<int> inverse_Permutation(count_of_characters + 1);
  for (int i = 1; i <= count_of_characters; i++) {
    inverse_Permutation[Permutation[i]] = i;
  }

  // Выводим обратную перестановку для проверки
  for (int i = 1; i <= count_of_characters; i++) {
    std::cout << inverse_Permutation[i] << " ";
  }
  std::cout << '\n';

}