#include <iostream>

using namespace std;

void array_rand_numbers(int* x, int n) {
    //Заполнение массива случайными числами
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        x[i] = rand() % 10 + 1;
}

void array_print(int* x, int n) {
    //Вывод массива в консоль
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    cout << endl;
}

// Функция array_partition выполняет разделение массива x на две части относительно опорного элемента.
// Возвращает индекс, разделяющий массив на две части.
int array_partition(int* x, int low, int high) {
    int pivot = x[low]; // Выбираем первый элемент в качестве опорного
    int i = low - 1;
    int j = high + 1;

    // Цикл разделения массива
    while (true) {
        // Поиск элемента больше или равного опорному справа от него
        do {
            i++;
        } while (x[i] < pivot);

        // Поиск элемента меньше или равного опорному слева от него
        do {
            j--;
        } while (x[j] > pivot);

        // Если индексы пересеклись, возвращаем индекс j
        if (i >= j)
            return j;

        // Обмен элементов, чтобы части массива были относительно опорного элемента
        swap(x[i], x[j]);
    }
}

// Рекурсивная функция array_sort сортирует массив x в заданном диапазоне (low - high)
void array_sort(int* x, int low, int high) {
    if (low < high) {
        // Выполняем разделение массива и рекурсивно сортируем две полученные половины
        int pi = array_partition(x, low, high);
        array_sort(x, low, pi);  // Сортируем левую часть от опорного элемента
        array_sort(x, pi + 1, high);  // Сортируем правую часть от опорного элемента
    }
}

int main() {
    system("chcp 65001");
    int n;
    cout << "Введите количество элементов массива n: " << endl;
    cin >> n;
    int* x = new int[n];
    array_rand_numbers(x, n);
    array_print(x, n);
    array_sort(x, 0, n - 1);
    array_print(x, n);
    //cout << "Емкостная сложность = " << n/2+3;
    return 0;
}
