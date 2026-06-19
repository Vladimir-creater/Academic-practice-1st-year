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

  encrypted = " " + encrypted;

  // Находим обратную перестановку
  std::vector<int> inverse_Permutation(count_of_characters + 1);
  for (int i = 1; i <= count_of_characters; i++) {
    inverse_Permutation[Permutation[i]] = i;
  }
  
  // Делаем обратную перестановку k раз
  std::string current = encrypted;
  for (int i = 0; i < count_of_permutation; i++) {
    std::string next(count_of_characters + 1, ' ');
    for (int j = 1; j <= count_of_characters; j++) {
      next[j] = current[inverse_Permutation[j]];
    }
    current = next;
  }

  // Выводим результат
  for (int i = 1; i <= count_of_characters; i++) {
    std::cout << current[i];
  }
  std::cout << '\n';

  return 0;
}