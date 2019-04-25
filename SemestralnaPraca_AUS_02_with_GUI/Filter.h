#pragma once
#include "Criterion.h"
#include"Area.h"


template <typename T, typename O>
class Filter
{
public:
	Filter();
	~Filter();
	virtual bool evaluate(const O& o, const Criterion<T, O>& c) = 0;
};

template <typename T, typename O>
class Filter_fi : public Filter<T, O>
{
public:
	bool evaluate(const O& o, const Criterion<T, O>& c) override {
		return true;
		//c.evaluate(o) = alpha; }
	}
private:
	T alpha;
	// TODO treba setter
};

class FilterHasName : public Filter_fi<Area, std::string> {};