#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array {
  // attributes
  T *data;
  size_t n;
public:
  //constructors
  dynamic_array(int n) {
    std::cout << "integer constrctor is called" << std::endl;
    this->n = n;
    data = new T[n];
  }  
  // copy constructor
  dynamic_array(const dynamic_array<T> &other) {
    std::cout << "copy constructor is called" << std::endl;
    n = other.n;
    for (int i = 1; i < n; i++) {
      data[i] = other[i];
    }
  }
  // destructor
  ~dynamic_array(){
    delete [] data;
    std::cout << "\nDestructor freezing data!" << std::endl;
  }
  //methods
  T &operator[](int index) {
    return data[index];
  }

  const T &operator[](int index) const {
    return data[index];
  }  

  T &at(int index) {
    if (index < n) {
      return data[index];
    }
    throw "Index out of range";
  }

  size_t size() {
    return n;
  }

  T *begin() {
    return data;
  }

  const T *begin() const {
    return data;
  }

  T *end() {
    return data + n;
  }

  const T *end() const {
    return data + n;
  }
};

int main() {
  
  dynamic_array < int> arr{5};
  std::cout << arr.at(4) << std::endl;
  std::cout << arr.size()<< std::endl;
  for (auto v : arr) {
    std::cout << v << " ";
  }
  return 0;
}