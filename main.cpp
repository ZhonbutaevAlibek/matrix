#include<iostream>
#include <fstream>
#include<ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int** Array; //указатель на массив указателей (динамический двумерный массив)
	int N, M;
mark:
	cout << "Введите количество строк матрицы: ";
	cin >> N;
	cout << "Введите количество столбцов матрицы: ";
	cin >> M;

	//проверка ввода
	if (N <= 0 || M <= 0) {
		cout << "Значения должны быть больше нуля!" << endl;
		goto mark;
	}

	Array = new int* [N]; //Выделяется память под одномерный массив,
						  //каждый элемент которого, является указателем

	for (int i = 0; i < N; i++)
		Array[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Array[i][j] = rand() % 21 - 10; //заполнение матрицы рандомными числами от -10 до 10
		}
	}


	string title;
	string format = ".csv";

	cout << "\nВведите название файла для записи матрицы: ";
	cin >> title;

	title = title + format;
	ofstream fail;
	fail.open(title, ios::_Nocreate | ios::out);

	//если файл не найден
	if (!fail.is_open()) {
		cout << "\n ---->  Указанный файл не найден! :(" << endl;
		cout << "Матрица:" << endl;
		// вывод матрицы
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << "Arr[" << i << "][" << j << "]=" << Array[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else {   //если файл открыт, то запись матрицы в файл
		cout << "\nМатрица:" << endl;
		// вывод матрицы
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << "Arr[" << i << "][" << j << "]=" << Array[i][j] << "\t";
			}
			cout << endl;
		}
		// запись матрицы в файл
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				fail << Array[i][j];
				fail << ",";
			}
			fail << "\n";
		}
		cout << "\n ---->  Матрица успешно записана в файл :)" << endl;
	}

	fail.close();

	for (int i = 0; i < N; i++)
		delete Array[i];	// Удаление строк массива
	delete[]Array;		// Удаление массива указателей


	cout << endl;
	system("pause");
	return 0;
}
