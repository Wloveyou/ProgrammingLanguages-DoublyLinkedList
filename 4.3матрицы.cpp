#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// Класс для работы с матрицами
class Matrix {
    // Поле для хранения элементов матрицы
    std::vector<std::vector<int>> data;
public:
    // Конструктор, принимающий размеры матрицы
    Matrix(int n, int m) {
        // Инициализируем матрицу нулями
        data.resize(n, std::vector<int>(m, 0));
    }

    // Метод для заполнения матрицы случайными числами
    void fillRandom() {
        // Создаем генератор случайных чисел
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);

        // Проходим по всем элементам матрицы
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                // Присваиваем элементу случайное значение
                data[i][j] = dis(gen);
            }
        }
    }

    // Метод для заполнения матрицы с клавиатуры
    void fillKeyboard() {
        // Проходим по всем элементам матрицы
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                // Считываем элемент с клавиатуры
                std::cin >> data[i][j];
            }
        }
    }

    // Метод для вывода матрицы на экран
    void print() {
        // Проходим по всем элементам матрицы
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                // Выводим элемент с пробелом
                std::cout << data[i][j] << " ";
            }
            // Переходим на новую строку
            std::cout << "\n";
        }
    }

    // Метод для замены максимального элемента каждой строки номером столбца, в котором он находится
    void replaceMax() {
        // Проходим по всем строкам матрицы
        for (int i = 0; i < data.size(); i++) {
            // Находим индекс максимального элемента в строке
            int maxIndex = std::max_element(data[i].begin(), data[i].end()) - data[i].begin();
            // Заменяем максимальный элемент индексом
            data[i][maxIndex] = maxIndex;
        }
    }

    // Метод для вставки после всех строк, содержащих минимальный элемент массива, строки 2, 4, 6, ...
    void insertRow() {
        // Находим минимальный элемент во всей матрице
        int min = data[0][0];
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                if (data[i][j] < min) {
                    min = data[i][j];
                }
            }
        }

        // Создаем вектор для вставки
        std::vector<int> row(data[0].size());
        for (int i = 0; i < row.size(); i++) {
            row[i] = (i + 1) * 2;
        }

        // Проходим по всем строкам матрицы в обратном порядке
        for (int i = data.size() - 1; i >= 0; i--) {
            // Проверяем, есть ли в строке минимальный элемент
            bool hasMin = false;
            for (int j = 0; j < data[i].size(); j++) {
                if (data[i][j] == min) {
                    hasMin = true;
                    break;
                }
            }
            // Если есть, то вставляем после нее вектор
            if (hasMin) {
                data.insert(data.begin() + i + 1, row);
            }
        }
    }
};

int main() {
    // Считываем размеры матрицы
    int n, m;
    std::cout << "Введите размеры матрицы: ";
    std::cin >> n >> m;

    // Создаем объект класса Matrix
    Matrix matrix(n, m);

    // Спрашиваем пользователя, как он хочет заполнить матрицу
    char choice;
    std::cout << "Как вы хотите заполнить матрицу? (r - случайными числами, k - с клавиатуры): ";
    std::cin >> choice;

    // Вызываем соответствующий метод
    if (choice == 'r') {
        matrix.fillRandom();
    }
    else if (choice == 'k') {
        matrix.fillKeyboard();
    }
    else {
        std::cout << "Неверный выбор\n";
        return 0;
    }

    // Выводим исходную матрицу
    std::cout << "Исходная матрица:\n";
    matrix.print();// Вызываем метод для замены максимальных элементов
    matrix.replaceMax();

    // Выводим измененную матрицу
    std::cout << "Матрица после замены максимальных элементов:\n";
    matrix.print();

    // Вызываем метод для вставки строк
    matrix.insertRow();

    // Выводим конечную матрицу
    std::cout << "Матрица после вставки строк:\n";
    matrix.print();

    return 0;
}
