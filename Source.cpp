#include <iostream>
#include <cstdarg>
#include <string.h>


using namespace std;

int sum(int k, ...) {
	va_list list;

	va_start(list, k);

	int sum = 0;

	for (int i = 0; i < k; i++) {
		sum += va_arg(list, int);
	}

	va_end(list);

	return sum;
}

char* conStrs(int size, ...) {
	va_list list;
	va_start(list, size);

	char* result = new char[1023];
	result[0] = NULL;

	for (int i = 0; i < size; i++) {
		strcat_s(result, 1024, va_arg(list, char*));

		if (i == 0)
		{
			strcat_s(result, 1024, ":\\");
		}
		else if (i != size - 1) {
			strcat_s(result, 1024, "\\");
		}
	}

	va_end(list);

	return result;
}

int main()
{
	cout << conStrs(5, "C",  "Program files", "Adobe", "bin", "adobe.exe");
	return 0;
}

