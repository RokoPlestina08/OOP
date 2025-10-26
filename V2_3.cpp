#include <iostream>
#include <iomanip>

int** CreateMatrix(int m, int n) {
	int** Matrix = new int* [m]();
	for (int i = 0; i < m ; ++i) {
		int* Stupac = new int[n]();
		for (int j = 0; j < n; ++j) {
			std::cout << "Unesi clan [" << i << "][" << j << "]" << std::endl;
			std::cin >> Stupac[j];
		}
		Matrix[i] = &Stupac[0];
	}
	return Matrix;
}

int** GenerateMatrix(int m, int n, int a, int b) {
	int** Matrix = new int* [m]();
	for (int i = 0; i < m; ++i) {
		int* Stupac = new int[n]();
		for (int j = 0; j < n; ++j) {
			if (a < b) {
				Stupac[j] = a;
				++a;
			}
			else {
				Stupac[j] = b;
			}
		}
		Matrix[i] = &Stupac[0];
	}
	return Matrix;
}

int** MatrixResult(int m1, int n1, int** Matrix1, int m2, int n2, int** Matrix2, char operation) {
	if (operation == '+' || operation == '-') {
		if ((m1 == m2) && (n1 == n2)) {
			int** MatrixResult = new int* [m1]();
			for (int i = 0; i < m1; ++i) {
				int* StupacResult = new int[n1]();
				for (int j = 0; j < n1; ++j) {
					if (operation == '+')
						StupacResult[j] = Matrix1[i][j] + Matrix2[i][j];
					else
						StupacResult[j] = Matrix1[i][j] - Matrix2[i][j];
				}
				MatrixResult[i] = &StupacResult[0];
			}
			return MatrixResult;
		}
	}
	if (operation == '*') {
		if(n1 == m2) {
			int** MatrixResult = new int* [m1]();
			for (int i = 0; i < m1; ++i) {
				int* StupacResult = new int[n2]();
				for (int j = 0; j < n2; ++j) {
					StupacResult[j] = 0;
					for (int k = 0; k < m1; ++k) {
						StupacResult[j] += Matrix1[i][k] * Matrix2[k][j];
					}
				}
				MatrixResult[i] = &StupacResult[0];
			}
			return MatrixResult;
		}
	}
}

int** TransponMatrix(int m, int n, int** Matrix) {
	int** NewMatrix = new int* [n]();
	for (int i = 0; i < n; ++i) {
		int* Stupac = new int[m]();
		for (int j = 0; j < m; ++j) {
			Stupac[j] = Matrix[j][i];
		}
		NewMatrix[i] = &Stupac[0];
	}
	return NewMatrix;
}

void PrintMatrix(int m, int n, int** Matrix) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			float Num = Matrix[i][j];
			std::cout << std::setprecision(4) << std::fixed << Num << " ";
		}
		std::cout << std::endl;
	}
}

void main() {
	int m, n;
	std::cout << "Unesi m (broj redaka)" << std::endl;
	std::cin >> m;
	std::cout << "Unesi n (broj stupaca)" << std::endl;
	std::cin >> n;
	int **Matrix = CreateMatrix(n, m);
	std::cout << "-------------" << std::endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << Matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------" << std::endl;
	int** Matrix2 = GenerateMatrix(n, m, 9, 18);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << Matrix2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------" << std::endl;
	int** MatrixRes = MatrixResult(n, m, Matrix, n, m, Matrix2, '*');
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << MatrixRes[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------" << std::endl;
	int** TMatrix = TransponMatrix(n, m, Matrix);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << TMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------" << std::endl;
	PrintMatrix(m, n, Matrix);
}