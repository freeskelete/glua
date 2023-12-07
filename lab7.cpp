#include <fstream>
#include <iostream>

const int N = 12;
int matrix[N][N];
int n;

namespace first {

	void readMatrix() {
		std::ifstream file("input.txt");
		file >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				file >> matrix[i][j];
			}
		}
	}


	void writeMatrix() {
		std::ofstream file("output.txt");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				file << matrix[i][j] << " ";
			}
			file << std::endl;
		}
	}

	bool isequals() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++)
			{
				bool flag = false;
				for (int I = 0; I < n; I++) {
					if (matrix[I][i] != matrix[I][j]) {
						flag = true;
					}
				}
				if (!flag) {
					return true;
				}
			}
		}
		return false;
	}

	bool isprime(int num) {
		int len_dividers = 0;
		for (int i = 1; i <= std::sqrt(num); i++) {
			if (num % i == 0) {
				if (num != num / i) {
					len_dividers += 2;
				}
				else {
					len_dividers += 1;
				}
				
			}
		}
		if (len_dividers == 1 && num > 1) {
			return true;
		}
		return false;
	}

	bool isabsolute() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isprime(abs(matrix[i][j]))) {
					return true;
				}
			}
		}
		return false;
	}

	bool abssum(int j) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += abs(matrix[i][j]);
		}
		return sum;
	}

	void editMatrix() {
		if (isequals() && isabsolute()) {
			std::cout << 1;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (abssum(i) < abssum(j)) {
						std::swap(matrix[i], matrix[j]);
					} 
				}
			}
		}
	}
}



int main() {
	first::readMatrix();
	first::editMatrix();
	first::writeMatrix();
}
