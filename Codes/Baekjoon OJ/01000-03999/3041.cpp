#include <iostream>
#include <cmath>

int dispersion_degree(char puzzle[][4]);
int dispersion(char puzzle[][4], int i, int l);

int main(void) {
	char puzzle[4][4];
	
	for(int i=0; i<4; i++)
		for(int l=0; l<4; l++)
			std::cin>>puzzle[i][l];
			
	std::cout<<dispersion_degree(puzzle);
	
	return 0;
}

int dispersion_degree(char puzzle[][4]) {
	int count=0;
	
	
	for(int i=0; i<4; i++)
		for(int l=0; l<4; l++)
			if(puzzle[i][l]!='.')
				count += dispersion(puzzle, i, l);
	
	return count;
}

int dispersion(char puzzle[][4], int y, int x) {
	char s_puzzle[4][4]={{'A', 'B', 'C', 'D'},
						{'E', 'F', 'G', 'H'},
						{'I', 'J', 'K', 'L'},
						{'M', 'N', 'O', '.'}};
	int disp;
						
	for(int i=0; i<4; i++)
		for(int l=0; l<4; l++)
			if(s_puzzle[i][l] == puzzle[y][x])
				disp = abs(x-l) + abs(y-i);
		
	return disp;
}