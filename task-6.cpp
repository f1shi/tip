#include <iostream>
#include <string>

class Logger {
private:
    std::string logFile;
    int verbosityLevel;
    bool isInitialized;

public:
    // главный конструктор с тремя параметрами
    Logger(const std::string& file, int level, bool init)
        : logFile(file), verbosityLevel(level), isInitialized(init) {
        std::cout << "конструктор с 3 параметрами: ";
        std::cout << "логгер настроен: файл " << logFile
                  << ", уровень " << verbosityLevel << "\n";
    }

    // конструктор с двумя параметрами (делегирует тройному)
    Logger(const std::string& file, int level)
        : Logger(file, level, true) {
        std::cout << "конструктор с 2 параметрами (делегировал тройному)\n";
    }

    // конструктор с одним параметром (делегирует конструктору с двумя)
    Logger(const std::string& file)
        : Logger(file, 1) {
        std::cout << "конструктор с 1 параметром (делегировал конструктору с двумя)\n";
    }

    // конструктор по умолчанию (делегирует конструктору с одним)
    Logger()
        : Logger("log.txt") {
        std::cout << "конструктор по умолчанию (делегировал конструктору с одним)\n";
    }

    // метод для демонстрации состояния
    void showInfo() const {
        std::cout << "текущее состояние: файл=" << logFile
                  << ", уровень=" << verbosityLevel
                  << ", инициализирован=" << (isInitialized ? "да" : "нет") << "\n";
    }
};

int main() {
    std::cout << "=== создание логгера с тремя параметрами ===\n";
    Logger logger1("app.log", 3, true);
    logger1.showInfo();
    std::cout << "\n";

    std::cout << "=== создание логгера с двумя параметрами ===\n";
    Logger logger2("system.log", 2);
    logger2.showInfo();
    std::cout << "\n";

    std::cout << "=== создание логгера с одним параметром ===\n";
    Logger logger3("debug.log");
    logger3.showInfo();
    std::cout << "\n";

    std::cout << "=== создание логгера по умолчанию ===\n";
    Logger logger4;
    logger4.showInfo();
    std::cout << "\n";

    return 0;
}