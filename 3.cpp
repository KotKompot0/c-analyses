#include <iostream>
using namespace std;

int **func1(int NumberOfLines, int NumberOfColumns);
// Выделение памяти
void func2(int **pointer, int NumberOfLines, int NumberOfColumns);
// Заполнение и вывод на экран
void func3(int **pointer, int NumberOfLines, int NumberOfColumns);
// Меняем местами максимальный и первый элемент в строках
void **func4(int **pointer, int NumberOfLines, int NumberOfColumns);
// Освобождение памяти

int main(){
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int n,m;

    cin >> n >> m; //ввести кол-во строк (n) и количество столбцов (m)

    int **a = NULL;
    a = func1(n, m);
    cout << "Исходная матрица: " << endl;
    func2(a, n, m);
    cout << "Конечная матрица: ";
    func3(a, n, m);
    func4(a, n, m);
}

int **func1(int NumberOfLines, int NumberOfColums){
    int **pointer = new int*[NumberOfLines];
    for(int i (0); i < NumberOfLines; i ++){
        pointer[i] = new int[NumberOfColums];
    }
    return pointer;
}

void func2(int **pointer, int NumberOfLines, int NumberOfColumns){
    for(int i(0); i < NumberOfLines; i++){
        for(int j(0); j < NumberOfColumns; j++){
            pointer[i][j] = 10 + rand() % 99;
        }
    }
    for(int i(0); i < NumberOfLines; i++){
        for(int j(0); j < NumberOfColumns; i++){
            cout << pointer[i][j] << " ";
        }
        cout << endl;
    }
}
