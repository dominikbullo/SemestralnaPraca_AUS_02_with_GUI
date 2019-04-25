#pragma once
#include"Area.h"

template <typename T, typename O>
class Filter
{
public:
	Filter();
	~Filter();
	virtual O evaluate(const T& t);
};

template <typename T, typename O>
class Filter_fi : public Filter<T, O>
{
public:
	bool evaluate(const O& o, const Criterion<T, O>& c) override { return c.evaluate(o) = alpha; }
private: T alpha; // TODO treba setter
};