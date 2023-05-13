#include "MinHeap.h"

MinHeap::MinHeap()
{
	array = new Student[capacity]{ };
	size = 0;
}

MinHeap::~MinHeap()
{
	delete[] array;
	array = nullptr;
}

void MinHeap::push(Student s)
{
	array[size++] = s;
	heapify_up(size - 1);
}

bool MinHeap::isempty()
{
	return size == 0;
}

Student MinHeap::top()
{
	return array[0];
}

void MinHeap::pop()
{
	array[0] = array[--size];
	heapify_down(0);
}

int MinHeap::Size()
{
	return size;
}
