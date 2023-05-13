#include "MaxHeap.h"
MaxHeap::MaxHeap()
{
	array = new Student[capacity]{ };
	size = 0;
}

MaxHeap::~MaxHeap()
{
	delete[] array;
	array = nullptr;
}

void MaxHeap::push(Student s)
{
	array[size++] = s;
	heapify_up(size - 1);
}

bool MaxHeap::isempty()
{
	return size == 0;
}

Student MaxHeap::top()
{
	return array[0];
}

void MaxHeap::pop()
{
	array[0] = array[--size];
	heapify_down(0);
}

int MaxHeap::Size()
{
	return size;
}
