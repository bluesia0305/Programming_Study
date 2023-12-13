#include <iostream>

__forceinline int Addition(int a, int b, bool print = false)
{
	if (print) printf("a: %i, b: %i\n", a, b);
	return a + b;
}

__forceinline float Addition(float a, int b, bool print = false)
{
	if (print) printf("a: %f, b: %i\n", a, b);
	return a + b;
}

__forceinline float Addition(int a, float b, bool print = false)
{
	if (print) printf("a: %i, b: %f\n", a, b);
	return a + b;
}

__forceinline float Addition(float a, float b, bool print = false)
{
	if (print) printf("a: %f, b: %f\n", a, b);
	return a + b;
}

int main()
{
	printf("%i\n\n", Addition(1, 2));
	printf("%i\n\n", Addition(1, 2, true));

	printf("%f\n\n", Addition(1.5f, 2));
	printf("%f\n\n", Addition(1.5f, 2, true));

	printf("%f\n\n", Addition(1, 2.8f));
	printf("%f\n\n", Addition(1, 2.8f, true));

	printf("%f\n\n", Addition(1.1f, 2.1f));
	printf("%f\n\n", Addition(1.1f, 2.1f, true));
	return 0;
}