#include<iostream>
#include<queue>
#include<chrono>
#include<math.h>
#include<string.h>
#include "papancatur.h"
using namespace std;
using namespace std::chrono;

int pathFinding(PapanCatur* p){
	int dp[p->size][p->size];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	
	// Bottom-up dynamic programming
	for (int i = 0; i < p->size; i++)
		for (int j = 0; j < p->size; j++)
			if (p->data[i][j] > 0)
				for (int moves = 0; moves <= p->data[i][j]; moves++){
					
					// Movements can vary diagonally
					int nextI = i + moves;
					int nextJ = j + p->data[i][j] - moves;
					
					// Is index array not out-of-bounds?
					if ((nextI < p->size) && (nextJ < p->size))
						dp[nextI][nextJ] += dp[i][j];
					
				}
			
	return dp[p->size - 1][p->size - 1];		
}

int main(){
	// Reads input where size is unknown
	queue<int> input;
	int temp;
	while (cin >> temp)
		input.push(temp);
	
	// Moves input to PapanCatur p
	PapanCatur * p = new PapanCatur(sqrt(input.size()));
	int i = 0;
	while (!input.empty()){
		p->data[i / p->size][i % p->size] = input.front();
		input.pop();
		i++;
	}
	
	// Calls DP function, also prints execution time in ms
	auto start = high_resolution_clock::now();
	cout << pathFinding(p) << endl;
	auto stop = high_resolution_clock::now();
	
	cout << duration_cast<milliseconds>(stop - start).count() << "ms" << endl;
	
}