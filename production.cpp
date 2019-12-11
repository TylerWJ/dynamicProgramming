/*
 * production.cpp
 *
 *  Created on: Nov 23, 2019
 *      Author: Tyler Jones
 */


#include "production.h"

Production::Production(){
	// TODO Auto-generated constructor stub
}

Production::~Production(){
	// TODO Auto-generated destructor stub
}

void Production::production(int arr[8][8])
{
	cout << "The starting array: " << endl;
	printArray(arr);
	cout << endl << endl;

	int sumArr[8][8];

	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (i == 0){ //first row - remains the same
				sumArr[i][j] = arr[i][j];
			}
			else if(j == 0){ //the far left row
				sumArr[i][j] = arr[i][j] + max(sumArr[i-1][j], sumArr[i-1][j+1]);
			}
			else if(j == 7){ //the far right row
				sumArr[i][j] = arr[i][j] + max(sumArr[i-1][j-1], sumArr[i-1][j]);
			}
			else{ //every other row
				sumArr[i][j] = arr[i][j] + max(sumArr[i-1][j], max(sumArr[i-1][j-1], sumArr[i-1][j+1]));
			}
		}
	}

	cout << "Array with max sums: " << endl;
	printArray(sumArr);

	int theMax = 0;
	int yMax = 0;
	int xMax = 0;

	for(int i = 0; i < 8; i++)
	{
		theMax = max(theMax, sumArr[7][i]);
		if(theMax == sumArr[7][i]){
			yMax = 7;
			xMax = i;
		}
	}

	int totalGems = theMax;

	cout << endl << "Path: " << endl;
	cout << "Row: " << yMax+1 << " Vault: " << xMax+1 << endl;

	int arkenstoneVault = xMax + 1;

	for(int i = 6; i >= 0; i--){
		theMax = 0;
		yMax--;
		if(xMax == 7){ //far right row only compares 2 values
			theMax = max(sumArr[yMax][xMax-1], sumArr[yMax][xMax]);
		}
		else if(xMax == 0){ //far left row only compares 2 values
			theMax = max(sumArr[yMax][xMax], sumArr[yMax][xMax+1]);;
		}
		else{ //compares 3 values
			theMax = max(sumArr[yMax][xMax-1], max(sumArr[yMax][xMax], sumArr[yMax][xMax+1]));
		}
		if(theMax == sumArr[yMax][xMax-1]){ //update the vault
			xMax = xMax-1;
		}
		else if(theMax == sumArr[yMax][xMax+1]){ //update the vault
			xMax = xMax + 1;
		}
		cout << "Row: " << yMax+1 << " Vault: " << xMax+1 << endl;
	}

	cout << endl << "Starting Row: " << yMax+1 << "		Starting Vault: " << xMax+1 << endl << endl;
	cout << "Total gems collected: " << totalGems << endl << endl;
	cout << "The vault that holds the Arkenstone is Vault " << arkenstoneVault << endl << endl;
}

void Production::printArray(int arr[8][8])
{
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
}
