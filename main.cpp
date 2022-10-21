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
}
int main() {
}