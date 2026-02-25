#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int square(int x) {
	int result = 0;

	result = x * x;

	return result;
}

static void docalc(int val) {
	printf("Square of %d = %d\n", val, square(val));

	if (val < 1000) {
		int t = 0;

		t = val * val * val;

		printf("value of cube is %d\n", t);
	}
}

int main(int argc, char *argv[]) {
	static int key = 50;
	static char mbuf[111234];

	pid_t pid;

	pid = getpid();

	printf("pid = %d\n", pid);
	char *p;

	p = malloc(1024);

	docalc(key);

	return 0;
}
