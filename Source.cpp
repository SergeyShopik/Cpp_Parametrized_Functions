#include<iostream>
#include"Templates.h"

int MAX(int a, int b)
{
    return a > b ? a : b;
}
bool Greater(int a, int b)
{
    return a > b ? true : false;
}

int main()
{
    const size_t size1 = 10, size2 = 3, size = size1 + size2;
    int array1[size1] = { 1, 56, 3, 49, 11, 13, 7, 6, 33, 45 };
    int array2[size2] = { 4,8,10 };
    int array[size];
    bool (*ptr)(int, int) = &Greater;
    //Merge(array1, array2, size1, size2, array);
    Sort(array1, size1 - 1, ptr);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

	return 0;
}