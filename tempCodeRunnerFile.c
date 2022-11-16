//C program for Banker's Algorithm 
#include <stdio.h> 
int main() 
{ 
	// P0, P1, P2, P3, P4 are the names of Process

	int n, r, i, j, k; 
	n = 5; // Indicates the Number of processes 
	r = 3; //Indicates the Number of resources 
	int alloc[5][3] = { { 0, 0, 1 }, // P0 // This is Allocation Matrix 
						{ 3, 0, 0 }, // P1 
						{ 1, 0, 1 }, // P2 
						{ 2, 3, 2 }, // P3 
						{ 0, 0, 3 } }; // P4 

	int max[5][3] = { { 7, 6, 3 }, // P0 // MAX Matrix 
					{ 3, 2, 2 }, // P1 
					{ 8, 0, 2 }, // P2 
					{ 2, 1, 2 }, // P3 
					{ 5, 2, 3 } }; // P4 

	int avail[3] = { 2, 3, 2 }; // These are Available Resources 

	int f[n], ans[n], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][r]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < r; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) 
    { 
		for (i = 0; i < n; i++) 
        { 
			if (f[i] == 0) 
            { 
				int flag = 0; 
				for (j = 0; j < r; j++) { 
					if (need[i][j] > avail[j])
                    { 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) 
                { 
					ans[ind++] = i; 
					for (y = 0; y < r; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	printf("Th SAFE Sequence is as follows\n"); 
	for (i = 0; i < n - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[n - 1]); 

	return (0); 

}