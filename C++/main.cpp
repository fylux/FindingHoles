#include <iostream>
#include "findHole.hpp"

#define V 5

using namespace std;

int main() {
	int matrix[V][V] = {
		1,	0,	0,	1,	0,
		0,	0,	0,	1,	0,
		0,	0,	1,	1,	1,
		0,	0,	0,	0,	0,
		1,	0,	0,	1,	0
	};
	cout << "Result : " << findHole(matrix,V) << endl;

	return 0;
}