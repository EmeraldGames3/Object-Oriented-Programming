#include "MyContainer.h"

template <typename T>
MyContainer<T>::MyContainer() : data{0}{}

template <typename T>
MyContainer<T>::~MyContainer() = default;

template class MyContainer<int>; // explicit template instantiation for int
template class MyContainer<float>; // explicit template instantiation for int
template class MyContainer<double>; // explicit template instantiation for int
