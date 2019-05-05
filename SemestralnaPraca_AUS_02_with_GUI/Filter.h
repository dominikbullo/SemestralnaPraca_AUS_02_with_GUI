#pragma once
#include "Criterion.h"
#include"Area.h"


template <typename T, typename O>
class Filter
{
public:
	//Filter();
	//~Filter();
	virtual bool evaluate(O& o, Criterion<T, O>& c) = 0;
};
template <typename T, typename O>
class Filter_FI : public Filter<T, O>
{
public:
	bool evaluate(O& o, Criterion<T, O>& c) override { T result = c.evaluate(o); return result >= alpha && result <= beta; }
private: T alpha; // treba setter
private: T beta; // treba setter
};

template <typename T, typename O>
class Filter_fi : public Filter<T, O>
{
public:
	bool evaluate(O& o, Criterion<T, O>& c) override { return (c.evaluate(o) == this->alpha); }
	void setAlpha(T alpha) { this->alpha = alpha; }
private:
	T alpha;
};


class FilterHasName : public Filter_fi<std::string, Area>
{
};