#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt"); // ����������� ����� ������ �� �����
ofstream out("output.txt"); // ����������� ������ ������ � ����

void sort(int* arr, int n) // ���-����� ����������
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 2; j < n; j += 2) //���������� �� ������� ��-�� ���� � ����� 2
                if (arr[j - 1] > arr[j]) //���� ���������� ��-� ������ ��������
                    swap(arr[j - 1], arr[j]);
        }
        else
        {
            for (int j = 1; j < n; j += 2) //���������� � ������� ��-�� ���� � ����� 2
                if (arr[j - 1] > arr[j]) //���� ���������� ��-� ������ ��������
                    swap(arr[j - 1], arr[j]);
        }
    }
}

void print(int** arr, int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            out << arr[i][j] << " ";
        out << endl;
    }
}

int main()
{
    int n;
    in >> n; 

    int** arr = new int* [n]; 
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> arr[i][j];
        }
    }

    int t = 2; //�������� ����������� � ��������� > 1 ��-��

    for (int k = n - 2; k >= 0; k--)
    {
        int* arr_1 = new int[t];
        int* arr_2 = new int[t];

        for (int m = 0; m < t; m++) //��������� ��������� � ������ � ������� �����
        {
            arr_1[m] = arr[k + m][m];
            arr_2[m] = arr[m][k + m];
        }

        sort(arr_1, t);
        sort(arr_2, t);

        for (int m = 0; m < t; m++) //������ ���������� 
        {
            arr[k + m][m] = arr_1[m];
            arr[m][k + m] = arr_2[m];
        }

        t++;
    }

    print(arr, n);
    return 0;
}