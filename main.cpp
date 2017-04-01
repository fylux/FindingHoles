#include <iostream>
#include "findHole.hpp"

using namespace std;

int main() {
	int matrix[5][5] = {
		1,	0,	0,	1,	0,
		0,	0,	0,	1,	0,
		0,	0,	1,	1,	1,
		0,	0,	0,	0,	0,
		1,	0,	0,	1,	0
	};
	cout << "Result : " << findHole(matrix,5) << endl;

	return 0;
}