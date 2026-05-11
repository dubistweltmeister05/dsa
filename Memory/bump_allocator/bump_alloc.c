#define _GNU_SOURCE // includes all definitions in X/Open and POSIX standards. thread: https://stackoverflow.com/a/5724485/31525551

#include "bump_alloc.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

void *HEAP = NULL;

int bump_reset(void) {
	if (HEAP == NULL) return -1;
	int status = brk(HEAP); // brk() returns 0 if the brk() method frees the HEAP successfully
	if (status == 0) HEAP = NULL;
	return status;
}

void *bump_alloc(size_t size) {
	if (size == 0) { // err handler for size
		fprintf(stderr, "bump_alloc(): invalid size specified. returning NULL\n");
		return NULL;
	}
	void* mem = sbrk(size); // returns the program break. 
	if (mem == (void *)-1) { // returns (void *)-1 in case of error
		fprintf(stderr, "bump_alloc(): sbrk() failed. returning NULL\n");
		return NULL;
	}
	if (HEAP == NULL) HEAP = mem; // if HEAP hasn't been used yet then stores the starting address of the
	// heap managed by this allocator
	return mem;
}


int main(void) {
	char* data = "this is a text string to see whether the allocator works or not";
	size_t size = strlen(data) + 1;
	char* cpy = bump_alloc(size);
	if (cpy == NULL) {
		fprintf(stderr, "bump_alloc(): failed\n");
		return 1;
	}

	memcpy(cpy, data, size);
	printf("copied data > \n'%s'\n", cpy);
	printf("ptr > '%p'\n", cpy);
	printf("ptr > '%p'\n", HEAP);

	if (bump_reset() != 0) {
		fprintf(stdout, "bump_reset(): error in HEAP freeing\n"); 
		/*
		fun fact: after using brk() you can't use any methods in glibc, including but not limited to printf() fprintf() and what not. the reason being is that brk() basically manipulates the program break 
		and glibc internals touch the heap through malloc() and other methods. now think: if the HEAP was
		manipulated previously and glibc internals don't know about it then what will happen when someone tries to mess with that manipulated memory?
		yep.
		*/
	}
	return 0;
}
