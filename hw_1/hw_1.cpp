// hw_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>

void read_array_data(std::ifstream& file, int*& arr, int& size);
void write_array_data(std::ofstream& file, int* arr, int size, bool shift);
void shift_array_left(int* arr, int size);
void shift_array_right(int* arr, int size);

int main() {

	setlocale(LC_ALL, "rus");

	std::ifstream in;
	in.open("in.txt");
	if (!in.is_open()) {
		std::cout << "не удалось открыть файл с данными" << std::endl;
		exit(1);
	}

	int n_size;
	int* n_arr;
	int m_size;
	int* m_arr;
	read_array_data(in, n_arr, n_size);
	read_array_data(in, m_arr, m_size);
	in.close();

	std::ofstream out;
	out.open("out.txt");
	if (!out.is_open()) {
		std::cout << "не удалось открыть файл на запись" << std::endl;
		exit(1);
	}

	write_array_data(out, m_arr, m_size, true);
	write_array_data(out, n_arr, n_size, false);

	out.close();

	delete n_arr;
	delete m_arr;

	return 0;
}

void read_array_data(std::ifstream& file, int*& arr, int& size) {
	file >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		file >> arr[i];
	}
}

void write_array_data(std::ofstream& file, int* arr, int size, bool shift) {
	file << size;
	file << std::endl;
	
	if (shift) {
		shift_array_right(arr, size);
	} else {
		shift_array_left(arr, size);
	}

	for (int i = 0; i < size; ++i) {
		file << arr[i] << " ";
	}

	file << std::endl;
}

void shift_array_left(int* arr, int size) {
	int tmp = arr[0];
	for (int i = 1; i < size; ++i) {
		arr[i - 1] = arr[i];
	}
	arr[size - 1] = tmp;
}

void shift_array_right(int* arr, int size) {
	int tmp = arr[size - 1];
	for (int i = size - 1; i > 0; --i) {
		arr[i] = arr[i - 1];
	}
	arr[0] = tmp;
};

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
