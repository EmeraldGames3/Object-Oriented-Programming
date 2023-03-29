#include "DependancyStructuredMatrix.h"

template class DSM<int>;
template class DSM<float>;
template class DSM<double>;

template<typename Type>
DSM<Type>::DSM(int elementCount) : elementCount(elementCount){
    matrix = nullptr;
    elementNames = nullptr;
}