#pragma once

template<typename T>
inline const T max(const T&, const T&);

template<class Type>
void Merge(Type* array1, Type* array2, size_t size1, size_t size2, Type* resarray);

template<class Type>
void Sort(Type* array, size_t size, bool(*cmp)(Type, Type));

template<typename T>
const T max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template<class Type>
void Merge(Type* array1, Type* array2, size_t size1, size_t size2, Type* resarray)
{
    int ia1 = 0, ia2 = 0, ires = 0;
    do
    {
        if (ia1 == size1) {
            resarray[ires++] = array2[ia2++];
            continue;
        }
        else if (ia2 == size2)
        {
            resarray[ires++] = array1[ia1++];
            continue;
        }
        if (array1[ia1] < array2[ia2])
            resarray[ires++] = array1[ia1++];
        else
            resarray[ires++] = array2[ia2++];

    } while (ia1 < size1 || ia2 < size2);

}

template<typename Type>
void Sort(Type* array, size_t size, bool (*cmp) (Type, Type))
{
    int i = 0, j = size;
    int p = array[size / 2];

    do
    {
        while (cmp(array[i], p))
        {
            i++;
        }

        while (cmp(p, array[j]))
        {
            j--;
        }

        if (i <= j)
        {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }

    } while (i <= j);

    if (j > 0)
    {
        Sort(array, j, cmp);
    }

    if (size > i)
    {
        Sort(array + i, size - i, cmp);
    }
}

template<typename Type>
bool Lesser(Type a, Type b)
{
    if (a > b)
    {
        return true;
    }

    return false;
}

template<typename Type>
bool Greater(Type a, Type b)
{
    if (a < b)
    {
        return true;
    }

    return false;
}