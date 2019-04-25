#include "Criterion.h"

template<typename T, typename O>
Criterion<T, O>::Criterion()
{
}

template<typename T, typename O>
Criterion<T, O>::~Criterion()
{
}

template<typename T, typename O>
O Criterion<T, O>::evaluate(const T & t)
{
	return O();
}

