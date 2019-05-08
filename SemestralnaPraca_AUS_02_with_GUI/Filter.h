#pragma once
#include "Kriterium.h"
#include"Area.h"


template <typename T, typename O>
class Filter
{
public:
	virtual bool evaluate(O& o, Kriterium<T, O>& c) = 0;
};

template <typename T, typename O>
class Filter_FI : public Filter<T, O>
{
public:
	bool evaluate(O& o, Kriterium<T, O>& c) override { T result = c.evaluate(o); return result >= this->alpha_ && result <= this->beta_; }
	void setAlpha(T alpha) { this->alpha_ = alpha; }
	void setBeta(T beta) { this->beta_ = beta; }
private:
	T alpha_;
	T beta_;
};

template <typename T, typename O>
class Filter_fi : public Filter<T, O>
{
public:
	bool evaluate(O& o, Kriterium<T, O>& c) override { return (c.evaluate(o) == this->alpha_); }
	void setAlpha(T alpha) { this->alpha_ = alpha; }
private:
	T alpha_;
};


class FilterHasName : public Filter_fi<std::string, Area> {};
class FilterVolici : public Filter_FI<int, Area> {};
class FilterUcast : public Filter_FI<double, Area> {};