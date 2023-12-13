#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void fillMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    cout << "Выберите способ заполнения массива:" << endl;
    cout << "1. Случайные числа" << endl;
    cout << "2. Ввод с клавиатуры" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        srand(time(0));  // Инициализация генератора случайных чисел
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand() % 100;  // Генерация случайного числа от 0 до 99
            }
        }
    } else if (choice == 2) {
        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    cout << "Массив:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void replaceMaxWithColumn(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int maxElement = matrix[i][0];
        int maxColumn = 0;

        // Находим максимальный элемент и его столбец
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxColumn = j;
            }
        }

        // Заменяем максимальный элемент номером столбца
        matrix[i][maxColumn] = maxColumn;
    }
}

void insertRowsAfterMin(int matrix[MAX_ROWS][MAX_COLS], int& rows, int cols) {
    int minElement = matrix[0][0];

    // Находим минимальный элемент
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
            }
        }
    }

    // Вычисляем количество строк для вставки
    int insertRowsCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == minElement) {
                insertRowsCount++;
                break;
            }
        }
    }

    // Вставляем строки
    int newRows = rows + insertRowsCount;
    int newMatrix[MAX_ROWS][MAX_COLS];

    int newRow = 0;
    for (int i = 0; i < rows; i++) {
        bool insertRow = false;

        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == minElement) {
                insertRow = true;
                break;
            }
        }

        // Копируем текущую строку в новую матрицу
        for (int j = 0; j < cols; j++) {
            newMatrix[newRow][j] = matrix[i][j];
        }
        newRow++;

        // Вставляем дополнительную строку после текущей строки
        if (insertRow) {
            for (int j = 0; j < cols; j++) {
                newMatrix[newRow][j] = j + 1;  // Значение элементов новой строки: 1, 2, 3, ...
            }
            newRow++;
        }
    }

    // Обновляем значения переменных rows и matrix
    rows = newRows;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }
}

int main() {
    int n, m;
    cout << "Введите количество строк и столбцов: ";
    cin >> n >> m;

    int matrix[MAX_ROWS][MAX_COLS];

    fillMatrix(matrix, n, m);
    printMatrix(matrix, n, m);

    replaceMaxWithColumn(matrix, n, m);
    printMatrix(matrix, n, m);

    insertRowsAfterMin(matrix, n, m);
    printMatrix(matrix, n, m);

    return 0;
}
