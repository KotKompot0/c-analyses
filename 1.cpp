#include <iostream>
using namespace std;

void fillArr (int **doubleArr, int sizeArr1);
void showArr (int **doubleArr, int sizeArr1);
void updateArr (int **doubleArr, int sizeArr1);

int main (){
    const int sizeArr1 = 5;
    int **doubleArr = new int * [sizeArr1];
    for (int i = 0; i < sizeArr1; i++){
        doubleArr[i] = new int [sizeArr1];
    }

    fillArr(doubleArr, sizeArr1);
    cout << "Your Array now looks like: " << endl;
    showArr(doubleArr, sizeArr1);
    updateArr(doubleArr, sizeArr1);
    cout << "Your update Array now looks like: " << endl;
    showArr(doubleArr, sizeArr1);

    for (int i = 0; i < sizeArr1; i++){
        delete [] doubleArr[i];
    }
    delete [] doubleArr;

    return 0;
}

void fillArr(int **doubleArr, int sizeArr1){
    srand(time(0));
    for (int i = 0; i < sizeArr1; i++){
        for (int j = 0; j < sizeArr1; j++){
            doubleArr[i][j] = 10 + rand() % 90;
        }
    }
}

void showArr(int **doubleArr, int sizeArr1){
    cout << endl;
    for (int i = 0; i < sizeArr1; i++){
        cout << " | ";
        for (int j = 0; j < sizeArr1; j++){
            cout << doubleArr[i][j] << " ";
        }
        cout << " | " << endl;
    }
}

void updateArr (int **doubleArr, int sizeArr1){
    for (int i = 0; i < sizeArr1; i++){
        int maxValue = 0;
        int temp = doubleArr[i][0];
        int *ptrElem = &doubleArr[i][0];
        for (int j = 0; j < sizeArr1; j++){
            if (maxValue < doubleArr[i][j]){
                maxValue = doubleArr[i][j];
                ptrElem = &doubleArr[i][j];
            }
        }
        doubleArr[i][0] = *ptrElem;
        *ptrElem = temp;
    }
}