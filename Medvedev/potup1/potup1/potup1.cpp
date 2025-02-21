#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int N;
    cout << "Введите количество элементов массива: ";
    cin >> N;

    vector<int> a(N);
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < N; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    int k = N;
    cout << "Всего элементов: " << k<< endl;

    int G;
    cout << "Введите искомое число: ";
    cin >> G;

    int left = 0;
    int right = N - 1;
    int o = 0; 
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (G == a[mid]) {
            cout << "Ваш элемент под номером " << mid + 1 << " (индекс: " << mid << ")" << endl;
            found = true;
            break; 
        }
        if (a[mid] > G) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        cout << "Элемент " << G << " не найден в массиве. Итерация номер " << o << endl;
        o++;
    }

    if (!found) {
        cout << "Элемент " << G << " не найден в массиве после " << o << " итераций." << endl;
    }

    return 0;
}
