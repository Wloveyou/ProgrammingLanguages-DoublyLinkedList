#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция для создания многомерного массива n x m из n целых чисел
int** create_array(int n, int m) {
    // Выделяем память для массива указателей на строки
    int** array = new int*[n];
    // Выделяем память для каждой строки
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    return array;
}

// Функция для заполнения массива случайными числами
void fill_random(int** array, int n, int m) {
    // Инициализируем генератор случайных чисел
    srand(time(NULL));
    // Заполняем массив случайными числами в диапазоне от 0 до 99
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[i][j] = rand() % 100;
        }
    }
}

// Функция для заполнения массива с клавиатуры
void fill_keyboard(int** array, int n, int m) {
    // Запрашиваем у пользователя ввод элементов массива
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> array[i][j];
        }
    }
}

// Функция для вывода массива на экран
void print_array(int** array, int n, int m) {
    // Выводим элементы массива в виде таблицы
    cout << "Массив:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функция для замены максимального элемента каждой строки номером столбца, в котором он находится
void replace_max(int** array, int n, int m) {
    // Проходим по каждой строке массива
    for (int i = 0; i < n; i++) {
        // Инициализируем максимальный элемент и его индекс
        int max = array[i][0];
        int max_index = 0;
        // Ищем максимальный элемент и его индекс в строке
        for (int j = 1; j < m; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
                max_index = j;
            }
        }
        // Заменяем максимальный элемент номером столбца
        array[i][max_index] = max_index;
    }
}

// Функция для вставки после всех строк, содержащих минимальный элемент массива, строки 2, 4, 6, ...
void insert_row(int**& array, int& n, int m) {
    // Инициализируем минимальный элемент массива
    int min = array[0][0];
    // Ищем минимальный элемент массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }
    // Считаем количество строк, содержащих минимальный элемент
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (array[i][j] == min) {
                found = true;
                break;
            }
        }
        if (found) {
            count++;
        }
    }
    // Создаем новый массив с увеличенным количеством строк
    int** new_array = create_array(n + count, m);
    // Копируем элементы из старого массива в новый, вставляя новые строки
    int k = 0; // Индекс для нового массива
    for (int i = 0; i < n; i++) {
        // Копируем текущую строку из старого массива
        for (int j = 0; j < m; j++) {
            new_array[k][j] = array[i][j];
        }
        k++;
        // Проверяем, содержит ли текущая строка минимальный элемент
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (array[i][j] == min) {
                found = true;
                break;
            }
        }
        // Если содержит, то вставляем новую строку 2, 4, 6, ...
        if (found) {
            for (int j = 0; j < m; j++) {
                new_array[k][j] = (j + 1) * 2;
            }
            k++;
        }
    }
    // Освобождаем память из-под старого массива
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
    // Присваиваем указателю на старый массив адрес нового массива
    array = new_array;
    // Обновляем количество строк
    n = n + count;
}

// Главная функция программы
int main() {
    // Задаем размеры массива
    int n = 3;
    int m = 4;
    // Создаем массив
    int** array = create_array(n, m);
    // Заполняем массив
    int choice;
    cout << "Выберите способ заполнения массива:" << endl;
    cout << "1 - случайными числами" << endl;
    cout << "2 - с клавиатуры" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            fill_random(array, n, m);
            break;
        case 2:
            fill_keyboard(array, n, m);
            break;
        default:
            cout << "Неверный выбор" << endl;
            return 0;
    }
    // Выводим массив на экран
    print_array(array, n, m);
    // Заменяем максимальный элемент каждой строки номером столбца, в котором он находится
    replace_max(array, n, m);
    // Выводим массив на экран
    cout << "После замены максимальных элементов:" << endl;
    print_array(array, n, m);
    // Вставляем после всех строк, содержащих минимальный элемент массива, строку 2, 4, 6, ...
    insert_row(array, n, m);
    // Выводим массив на экран
    cout << "После вставки новых строк:" << endl;
    print_array(array, n, m);
    // Освобождаем память из-под массива
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}
