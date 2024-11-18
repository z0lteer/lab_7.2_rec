#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void CreateRow(int** a, const int rowNo, const int cols, const int Low, const int High, int colNo) {
    // ���������� ������ �������� � ����� ���������� ������
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    // ������� ��� ���������� �������� � �����
    if (colNo < cols - 1)
        CreateRow(a, rowNo, cols, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rows, const int cols, const int Low, const int High, int rowNo) {
    // ������ ������ ��� ���������� �����
    CreateRow(a, rowNo, cols, Low, High, 0);
    // ������� ��� ���������� �����
    if (rowNo < rows - 1)
        CreateRows(a, rows, cols, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int cols, int colNo) {
    // ��������� ������ �������� �����
    cout << setw(4) << a[rowNo][colNo];
    // ������� ��� ���������� �������� � �����
    if (colNo < cols - 1)
        PrintRow(a, rowNo, cols, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rows, const int cols, int rowNo) {
    // ������ ������ ��� ��������� �����
    PrintRow(a, rowNo, cols, 0);
    // ������� ��� ���������� �����
    if (rowNo < rows - 1)
        PrintRows(a, rows, cols, rowNo + 1);
}

void FindMinMaxInRow(int* row, const int cols, int colNo, int& minIndex, int& maxIndex) {
    // ��������� ������� ���������� �� ������������� ��������
    if (row[colNo] < row[minIndex])
        minIndex = colNo;
    if (row[colNo] > row[maxIndex])
        maxIndex = colNo;
    // ������� ��� ���������� ��������
    if (colNo < cols - 1)
        FindMinMaxInRow(row, cols, colNo + 1, minIndex, maxIndex);
}

void SwapMaxMinInRow(int* row, const int cols) {
    int minIndex = 0;
    int maxIndex = 0;
    // ����������� ������� ���������� �� ������������� �������� � �����
    FindMinMaxInRow(row, cols, 1, minIndex, maxIndex);
    // ����� ������ ���������� �� ������������� ��������
    int temp = row[minIndex];
    row[minIndex] = row[maxIndex];
    row[maxIndex] = temp;
}

void ProcessRows(int** a, const int rows, const int cols, int rowNo) {
    // ������ ������� ��� ����� ���������� � ������������� �������� � �����
    SwapMaxMinInRow(a[rowNo], cols);
    // ������� ��� ���������� �����
    if (rowNo < rows - 1)
        ProcessRows(a, rows, cols, rowNo + 1);
}

int main() {
    srand((unsigned)time(NULL));
    int rows, cols;
    cout << "rows = "; cin >> rows;
    cout << "cols = "; cin >> cols;

    // ��������� �������� �������
    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];

    int Low = -9, High = 9;
    // ���������� ������� ����������� ����������
    CreateRows(a, rows, cols, Low, High, 0);
    cout << "Original matrix:" << endl;
    PrintRows(a, rows, cols, 0);

    // ����� ������ ������������� � ���������� �������� � ������� �����
    ProcessRows(a, rows, cols, 0);
    cout << "Modified matrix:" << endl;
    PrintRows(a, rows, cols, 0);

    // �������� ���'��
    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
