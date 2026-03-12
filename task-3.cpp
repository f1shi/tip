#include <iostream>

class Point2D {
private:
    int x, y;
    static int pointCount;

public:
    // конструктор с параметрами
    Point2D(int x, int y) : x(x), y(y) {
        ++pointCount;
        std::cout << "конструктор с параметрами: (" << x << ", " << y << ")\n";
    }

    // конструктор копирования
    Point2D(const Point2D& other) : x(other.x), y(other.y) {
        ++pointCount;
        std::cout << "конструктор копирования: (" << x << ", " << y << ")\n";
    }

    // деструктор
    ~Point2D() {
        --pointCount;
    }

    static int getPointCount() {
        return pointCount;
    }
};

// инициализация статического поля
int Point2D::pointCount = 0;

// функция, принимающая точку по значению
void func(Point2D p) {
    std::cout << "внутри func, количество точек: " << Point2D::getPointCount() << "\n";
}

int main() {
    std::cout << "начальное количество точек: " << Point2D::getPointCount() << "\n";

    // создание через конструктор с параметрами
    Point2D p1(3, 5);
    std::cout << "после p1, количество: " << Point2D::getPointCount() << "\n";

    // прямая инициализация копией
    Point2D p2(p1);
    std::cout << "после p2(p1), количество: " << Point2D::getPointCount() << "\n";

    // копирование при создании (copy-initialization)
    Point2D p3 = p1;
    std::cout << "после p3 = p1, количество: " << Point2D::getPointCount() << "\n";

    // вызов функции по значению
    std::cout << "до func, количество: " << Point2D::getPointCount() << "\n";
    func(p1);
    std::cout << "после func, количество: " << Point2D::getPointCount() << "\n";

    return 0;
}