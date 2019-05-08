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
	bool evaluate(O& o, Kriterium<T, O>& c) override { T result = c.evaluate(o); 	return result >= alpha && result <= beta; }
	void setAlpha(T alpha) { this->alpha = alpha; }
	void setBeta(T beta) { this->beta = beta; }
private:
	T alpha;
	T beta;
};

template <typename T, typename O>
class Filter_fi : public Filter<T, O>
{
public:
	bool evaluate(O& o, Kriterium<T, O>& c) override { return (c.evaluate(o) == this->alpha); }
	void setAlpha(T alpha) { this->alpha = alpha; }
private:
	T alpha;
};


class FilterHasName : public Filter_fi<std::string, Area> {};
class FilterVolici : public Filter_FI<int, Area> {};
class FilterUcast : public Filter_FI<int, Area> {};