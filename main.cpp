#include <iostream>

// оператор сравнения, оператор копирующего присваивания

template< class T >
T * merge(const T * const * a, size_t sa, const size_t * sai, T * c)
{
  size_t size = 0;
  for (size_t i = 0; i < sa; ++i) {
    size += sai[i];
  }
  size_t * sai_cur = new size_t[sa] {};
  size_t j = 0;
  try {
    for (; j < size; ++j) {
      size_t min_index = 0;
      for (size_t i = 1; i < sa; ++i) {
        if (sai_cur[i] < sai[i] && a[i][sai_cur[i]] < a[min_index][sai_cur[min_index]]) {
          min_index = i;
        }
      }
      c[j] = a[min_index][sai_cur[min_index]];
      ++sai_cur[min_index];
    }
  } catch (...) {
    delete[] sai_cur;
    return c + j;
  }
  delete[] sai_cur;
  return c + size;
}
