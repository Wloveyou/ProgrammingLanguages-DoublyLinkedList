#include <iostream> 
#include <glm/glm.hpp> 
using namespace std; 
 
// Функция для заполнения матрицы случайными числами 
void fill_random(glm::mat4& matrix) { 
    // Инициализируем генератор случайных чисел 
    srand(time(NULL)); 
    // Заполняем матрицу случайными числами в диапазоне от 0 до 99 
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            matrix[i][j] = rand() % 100; 
        } 
    } 
} 
 
// Функция для заполнения матрицы с клавиатуры 
void fill_keyboard(glm::mat4& matrix) { 
    // Запрашиваем у пользователя ввод элементов матрицы 
    cout << "Введите элементы матрицы:" << endl; 
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            cin >> matrix[i][j]; 
        } 
    } 
} 
 
// Функция для вывода матрицы на экран 
void print_matrix(const glm::mat4& matrix) { 
    // Выводим элементы матрицы в виде таблицы 
    cout << "Матрица:" << endl; 
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            cout << matrix[i][j] << "\t"; 
        } 
        cout << endl; 
    } 
} 
 
// Функция для замены максимального элемента каждой строки номером столбца, в котором он находится 
void replace_max(glm::mat4& matrix) { 
    // Проходим по каждой строке матрицы 
    for (int i = 0; i < 4; i++) { 
        // Инициализируем максимальный элемент и его индекс 
        float max = matrix[i][0]; 
        int max_index = 0; 
        // Ищем максимальный элемент и его индекс в строке 
        for (int j = 1; j < 4; j++) { 
            if (matrix[i][j] > max) { 
                max = matrix[i][j]; 
                max_index = j; 
            } 
        } 
        // Заменяем максимальный элемент номером столбца 
        matrix[i][max_index] = max_index; 
    } 
} 
 
// Функция для вставки после всех строк, содержащих минимальный элемент матрицы, строки 2, 4, 6, ... 
void insert_row(glm::mat4& matrix) { 
    // Инициализируем минимальный элемент матрицы 
    float min = matrix[0][0]; 
    // Ищем минимальный элемент матрицы 
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            if (matrix[i][j] < min) { 
                min = matrix[i][j]; 
            } 
        } 
    } 
    // Считаем количество строк, содержащих минимальный элемент 
    int count = 0; 
    for (int i = 0; i < 4; i++) { 
        bool found = false; 
        for (int j = 0; j < 4; j++) { 
            if (matrix[i][j] == min) { 
                found = true; 
                break; 
            } 
        } 
        if (found) { 
            count++; 
        } 
    } 
    // Создаем новую матрицу с увеличенным количеством строк 
    glm::mat4x3 new_matrix; // Матрица 4x3 
    // Копируем элементы из старой матрицы в новую, вставляя новые строки 
    int k = 0; // Индекс для новой матрицы 
    for (int i = 0; i < 4; i++) { 
        // Копируем текущую строку из старой матрицы 
        for (int j = 0; j < 4; j++) { 
            new_matrix[k][j] = matrix[i][j]; 
        } 
        k++; 
        // Проверяем, содержит ли текущая строка минимальный элемент 
        bool found = false; 
        for (int j = 0; j < 4; j++) { 
            if (matrix[i][j] == min) { 
                found = true; 
                break; 
            } 
        } 
        // Если содержит, то вставляем новую строку 2, 4, 6, ... 
        if (found) { 
            for (int j = 0; j < 4; j++) { 
                new_matrix[k][j] = (j + 1) * 2; 
            } 
            k++; 
        } 
    } 
    // Присваиваем указателю на старую матрицу адрес новой матрицы 
    matrix = new_matrix; 
} 
 
// Главная функция программы 
int main() { 
    // Создаем матрицу 4x4 
    glm::mat4 matrix; 
    // Заполняем матрицу 
    int choice; 
    cout << "Выберите способ заполнения матрицы:" << endl; 
    cout << "1 - случайными числами" << endl; 
    cout << "2 - с клавиатуры" << endl; 
    cin >> choice; 
    switch (choice) { 
        case 1: 
        fill_random(matrix); 
            break; 
        case 2: 
            fill_keyboard(matrix); 
            break;
