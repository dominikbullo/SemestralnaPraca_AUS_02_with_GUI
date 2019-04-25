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
	bool evaluate(const O& o, const Criterion<T, O>& c) override { c.evaluate(o) == this->alpha_; }
	void setAlpha(T alpha) { this->alpha = alpha }
private:
	T alpha_;
};


class FilterHasName : public Filter_fi<std::string, Area>
{
};