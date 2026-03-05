#include <iostream>

// Неявный интерфейс: оператор сравнения, оператор копирующего присваивания
// Недостаток явного интерфейса: непонятно что такое C и что нужно вернуть.

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

int main()
{
  size_t size_a = 7;
  size_t size_b = 5;
  size_t size_c = 6;
  size_t sai[] {size_a, size_b, size_c};
  int a[] {1, 2, 3, 4, 5, 6, 7};
  int b[] {15, 56, 77, 81, 100};
  int c[] {13, 21, 51, 54, 71, 100};
  int* arr[]{a, b, c};

  int* res = new int[size_a + size_b + size_c];
  int* end = nullptr;
  try {
    end = merge(arr, 3, sai, res);
  } catch (...) {
    delete[] res;
    return 1;
  }

  for (int* n = res; n < end; n++) {
    std::cout << *n << ' ';
  }
  std::cout << "\n";
  delete[] res;
  return 0;
}
