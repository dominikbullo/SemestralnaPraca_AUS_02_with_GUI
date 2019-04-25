#include "Filter.h"

template<typename T, typename O>
Filter<T, O>::Filter()
{
}

template<typename T, typename O>
Filter<T, O>::~Filter()
{
}

template<typename T, typename O>
bool Filter<T, O>::evaluate(const O & o, const Criterion<T, O>& c)
{
	return false;
}
