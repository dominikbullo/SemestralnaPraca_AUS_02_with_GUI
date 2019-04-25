#include "Filter.h"



Filter::Filter()
{
}

template<typename T, typename O>
Filter<T, O>::~Filter()
{
}

template<typename T, typename O>
O Filter<T, O>::evaluate(const T & t)
{
	return O();
}
