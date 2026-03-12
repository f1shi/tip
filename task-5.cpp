#include <iostream>

class Rectangle {
private:
    const double width;
    const double height;
    const double area;
    const double perimeter;

public:
    //конструктор с параметрами
    Rectangle(double w, double h)
        : width(w), height(h), area(w * h), perimeter(2 * (w + h)) {
        std::cout << "создан прямоугольник: " << width << " x " << height << "\n";
    }

    //конструктор копирования
    Rectangle(const Rectangle& other)
        : width(other.width), height(other.height),
          area(other.area), perimeter(other.perimeter) {
        std::cout << "скопирован прямоугольник: " << width << " x " << height << "\n";
    }

    //геттеры
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double getArea() const { return area; }
    double getPerimeter() const { return perimeter; }

    //вывод информации
    void displayInfo() const {
        std::cout << "ширина: " << width << ", высота: " << height
                  << ", площадь: " << area << ", периметр: " << perimeter << "\n";
    }
};

int main() {
    Rectangle r1(5.0, 3.0);
    Rectangle r2(2.5, 4.0);
    Rectangle r3(r1); //копирование

    std::cout << "\nинформация о прямоугольниках\n";
    r1.displayInfo();
    r2.displayInfo();
    r3.displayInfo();

    return 0;

}
