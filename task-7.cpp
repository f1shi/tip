#include <iostream>

class Temperature {
private:
    double celsius; //температура всегда хранится в цельсиях
    char scale;     //исходная шкала

public:
    //температура в цельсиях
    explicit Temperature(double c) : celsius(c), scale('C') {}

    //конструктор со шкалой
    Temperature(double value, char s) {
        scale = s;
        switch (s) {
            case 'C':
                celsius = value;
                break;
            case 'F':
                celsius = (value - 32) * 5.0 / 9.0;
                break;
            case 'K':
                celsius = value - 273.15;
                break;
            default:
                celsius = 0;
        }
    }

    //метод для получения температуры в фаренгейтах
    double toFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32;
    }

    //для отладки
    void show() const {
        std::cout << "температура: " << celsius << "°C (исходная шкала: " << scale << ")\n";
    }
};

void printBoilingPoint(Temperature t) {
    std::cout << "температура кипения воды: " << t.toFahrenheit() << "°F\n";
}

int main() {
    std::cout << "явный вызов с температурой в цельсиях\n";
    printBoilingPoint(Temperature(100.0));

    std::cout << "\nсоздание объектов с разными шкалами\n";
    Temperature t1(100.0, 'C');
    Temperature t2(212.0, 'F');   // 212°F = 100°C
    Temperature t3(373.15, 'K');  // 373.15K = 100°C

    std::cout << "t1 (100°C) в фаренгейтах: " << t1.toFahrenheit() << "°F\n";
    std::cout << "t2 (212°F) в фаренгейтах: " << t2.toFahrenheit() << "°F\n";
    std::cout << "t3 (373.15K) в фаренгейтах: " << t3.toFahrenheit() << "°F\n";

    //для проверки внутреннего хранения
    std::cout << "\nвнутреннее хранение в цельсиях\n";
    t1.show();
    t2.show();
    t3.show();

    return 0;
}
