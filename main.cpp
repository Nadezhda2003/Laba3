#include <iostream>
#include <Windows.h> 
using std::endl;
using std::cin;
using std::cout;
int n;
HANDLE* hThread;
int markerCount;
CRITICAL_SECTION criticalSection;
struct numsThread {
	int* arr;
	int num;
	HANDLE start;
	HANDLE stop = CreateEvent(NULL, TRUE, FALSE, NULL);
	HANDLE* event = new HANDLE[2];
};
DWORD WINAPI marker(LPVOID _arrF)
{
	numsThread arrF = *(numsThread*)_arrF;
	srand(arrF.num);
	bool check = false;
	int count = 0;
	while(!check) {
		int temp = rand();
		temp = temp % n;
		EnterCriticalSection(&criticalSection);
		if (arrF.arr[temp] == 0) {
			Sleep(5);
			arrF.arr[temp] = arrF.num;
			Sleep(5);
			count += 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arrF.arr[i] == arrF.num) {
			arrF.arr[i] = 0;
		}
	}
	return 0;
}
int main() {
	
}