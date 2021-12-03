#include <iostream>
#include <fstream>

using namespace std;

void firstQ(int* dataArr) {
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

int thirdQ() {
	ifstream textFile;
	//textFile.open("debug_values.txt");
	textFile.open("instructions.txt");
	int xPos = 0;
	int yPos = 0;
	int aim = 0;

	for (int i = 0; i < 1000; i++) {
		char data[9] = { 0,0,0,0,0,0,0,0,0 };
		textFile >> data;
		char data2[9] = { 0,0,0,0,0,0,0,0,0 };
		switch (data[0])
		{
		case 'f':
			textFile >> data2;
			xPos += (data2[0] - 0x30);
			yPos += (data2[0] - 0x30) * aim;
			break;
		case 'u':
			textFile >> data2;
			aim -= (data2[0] - 0x30);
			break;
		case 'd':
			textFile >> data2;
			aim += (data2[0] - 0x30);
			break;
		}
	}
	textFile.close();
	cout << "xPos: " << xPos << endl;
	cout << "yPos: " << yPos << endl;

	return xPos * yPos;
}

int fourthQ() {
	ifstream textFile;
	//textFile.open("debug_values.txt");
	textFile.open("binary.txt");
	uint16_t binArr[1000];
	for (int i = 0; i < 1000; i++) {
		uint16_t toBinary = 0;
		for (int j = 0; j < 12; j++) {
			char a;
			textFile >> a;
			toBinary |= ((a - 0x30) << (15 - j));
		}
		binArr[i] = toBinary;
	}
	textFile.close();
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 16; j++) {
			cout << ((binArr[i] & (0x8000 >> j)) >> (15 - j));
		}
		cout << endl;
	}
	uint16_t gamma = 0;
	for (int i = 0; i < 12; i++) {
		int counter = 0;
		for (int j = 0; j < 1000; j++) {
			counter += (binArr[j] & (1 << (15 - i))) != 0;
		}
		gamma |= ((counter > 500) << (15 - i));
	}
	gamma = gamma >> 4;
	uint16_t epsilon = (~gamma) & 0xFFF;

	for (int j = 0; j < 16; j++) {
		cout << ((gamma & (0x8000 >> j)) >> (15 - j));
	}
	cout << endl;

	cout << "Gamma: " << gamma << endl;
	cout << "Epsilon: " << epsilon << endl;

	return gamma * epsilon;
}

int main() {
	int dataArr[2000];
	int instructionArr[1000];
	//firstQ(dataArr);
	//secondQ(dataArr);
	//cout << "total: " << thirdQ();
	cout << "Power Consumption: " << fourthQ();
}