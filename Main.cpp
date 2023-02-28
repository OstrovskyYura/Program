#include <iostream>
using namespace std;

class SparseMatrix {
	int size2;
	int size1;
public:
	int** matrix;
	int* vect;
	SparseMatrix(int n)
	{
		size2 = n;
		matrix = new int* [size2];
		for (int i = 0; i < size2; i++) {
			matrix[i] = new int[size2];
		}
		size1 = ((size2 * size2 - 10) / 2);
		vect = new int[size1];
	}
	~SparseMatrix() {
		for (int i = 0; i < size2; i++) 
			delete[] matrix[i];
			delete[] matrix;
			delete[] vect;
	}
	int newIndex(int i, int j) {
		if (i == 0 || i == 1) {
			int n = 0;
			n = n + 1;
			return i * ((size2 - 1) - n) + (j - n);
		}
		if (i % 2 == 0) {
			int n;
			if (i == 6) {
				n = 3;
			}
			else if (i == 8) {
				n = 4;
			}
			else if (i == 4) {
				n = 2;
			}
			else if (i == 2) {
				n = 1;
			}
			n++;
			return i * (size2 - n) + (j - n);
		}
		if (i % 2 != 0) {
			int n;
			if (i == 5) {
				n = 2;
			}
			else if (i == 3) {
				n = 1;
			}
			else if (i == 7) {
				n = 3;
			}
			n++;
			return i * ((size2 - 1) - n) + (j - 1);
		}
	}
	int pack(int i, int j, int value) {
		if (i < j) {
			vect[newIndex(i, j)] = value;
			return value;
		}
		else return 0;
	}
	bool fillMatrix() {
		int k = 1;
		for (int i = 0; i < size2; i++)
			for (int j = 0; j < size2; j++) {
				if (i < j) {
					matrix[i][j] = k++;
				}
				else matrix[i][j] = 0;
			}
		return 1;
	}
	bool fillVect() {
		int k = 1;
		for (int i = 0; i < size2; i++)
			for (int j = 0; j < size2; j++) {
				if (i < j) {
					pack(i, j, k++);
				}
			}
		return 1;
	}
	void printMatrix() {
		for (int i = 0; i < size2; i++) {
			for (int j = 0; j < size2; j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void printVect() {
		cout << endl;
		for (int i = 0; i < size1; i++) {
			cout << vect[i] << "\t";
		}
		cout << endl;
	}
};
int main() {
	SparseMatrix sm(10);
	sm.fillMatrix();
	sm.printMatrix();
	sm.fillVect();
	sm.printVect();
	return 0;
}