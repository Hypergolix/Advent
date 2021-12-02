#include <iostream>
#include <fstream>

using namespace std;

void firstQ(int* dataArr ) {
	ifstream textFile;
	//textFile.open("debug_values.txt");
	textFile.open("values.txt");
	for (int i = 0; i < 2000; i++) {
		char data[5] = { 0,0,0,0,0 };
		textFile >> data;
		int nrOfDigits = 5;
		for (int j = 4; j > -1; j--) {
			if (data[j] == 0) {
				nrOfDigits--;
			}
			else {
				break;
			}
		}
		dataArr[i] = 0;
		int digit = 1;
		for (int j = (nrOfDigits - 1); j > -1; j--) {
			dataArr[i] += (data[j] - 0x30) * digit;
			digit *= 10;
		}
	}
	/*
	for (int i = 0; i < 2000; i++) {
		cout << dataArr[i] << endl;
	}
	*/
	textFile.close();

	int increased = 0;
	for (int i = 1; i < 2000; i++) {
		if (dataArr[i] > dataArr[i - 1]) {
			increased++;
		}
	}
	cout << increased << endl;
}

void secondQ(int* arr) {
	int counter = 0;
	for (int i = 0; i < (2000 - 3); i++) {
		counter += (arr[i + 1] + arr[i + 2] + arr[i + 3] > arr[i] + arr[i + 1] + arr[i + 2]);
	}
	cout << counter << endl;
}

int main() {
	int dataArr[2000];
	firstQ(dataArr);
	secondQ(dataArr);

}