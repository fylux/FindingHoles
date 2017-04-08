#ifndef __FIND_HOLE__
#define __FIND_HOLE__

#include <algorithm>

template <size_t rows, size_t cols>
int isHole(int (&matrix)[rows][cols], int p) {
	for (int i = 0; i < 5; i++)
		if (matrix[i][p] == 0 && i != p)
			return 0;

	for (int i = 0; i < 5; i++)
		if (matrix[p][i] == 1)
			return 0;

	return 1;
}

template <size_t rows, size_t cols>
int findHole(int (&matrix)[rows][cols], int n) {
	if ( n <= 1 ) return 0-matrix[0][0];

	int c1 = 0; //Hole Candidate 1
	int c2 = 1; //Hole Candidate 2
	
	while (c2 < n && c1 < n) {
		if ( (matrix[c1][c2] && matrix[c2][c1]) || (!matrix[c1][c2] && !matrix[c2][c1]) ) {
			c1=std::max(c1,c2)+1;
			c2=c1+1;
		}
		else if (matrix[c1][c2] && !matrix[c2][c1])
			c1 = std::max(c1,c2)+1;
		
		else if (!matrix[c1][c2] && matrix[c2][c1])
			c2 = std::max(c1,c2)+1;
	}

	if (c1 < n && isHole(matrix,c1))
		return c1;

	if (c2 < n && isHole(matrix,c2))
		return c2;

	return -1;
}



#endif