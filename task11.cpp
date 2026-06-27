#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int main() {
  // 1. Загружаем картинку
  cv::Mat image = cv::imread("image.jpg");
  if (image.empty()) {
    std::cout << "ERROR! Image is not found!" << std::endl;
    return -1;
  }

  std::cout << "Image is found!" << std::endl;

  // 2. Переводим в HSV (чтобы не зависеть от яркости)
  cv::Mat hsvImage;
  cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

  // 3. Фильтруем картинку на жёлтые пиксели маской
  cv::Mat mask;
  cv::inRange(hsvImage, cv::Scalar(15, 80, 80),
              cv::Scalar(35, 255, 255), mask);

  // 4. Убираем мелкий шум
  cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
  cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);
  cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, kernel);

  // 5. Находим контуры
  std::vector<std::vector<cv::Point>> contours;
  cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  int count = 0;

  // 6. Проверяем каждый контур
  for (size_t i = 0; i < contours.size(); i++) {
    double area = cv::contourArea(contours[i]);
    
    if (area > 100) {
      count++;
      cv::Rect boundingBox = cv::boundingRect(contours[i]);
      int center_x = boundingBox.x + boundingBox.width / 2;
      int center_y = boundingBox.y + boundingBox.height / 2;
      
      // Красная точка в центре
      cv::circle(image, cv::Point(center_x, center_y), 7, cv::Scalar(0, 0, 255), -1);
      // Синий прямоугольник вокруг объекта
      cv::rectangle(image, boundingBox, cv::Scalar(255, 0, 0), 2);
    }
  }

  // 7. Выводим результат в консоль
  std::cout << "Yellow figures: " << count << std::endl;

  // 8. Сохраняем результат в файлы (НЕ открываем окна)
  cv::imwrite("result.jpg", image);
  cv::imwrite("mask.jpg", mask);

  std::cout << "Result was saved in result.jpg and mask.jpg" << std::endl;

  return 0;
}

// D:\msys64\ucrt64\bin\g++.exe task11.cpp -o task11.exe "-ID:/msys64/ucrt64/include/opencv4" "-LD:/msys64/ucrt64/lib" -lopencv_core -lopencv_imgproc -lopencv_imgcodecs
// .\task11.exe