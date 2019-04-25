#pragma once
#include "Criterion.h"
#include"Area.h"


template <typename T, typename O>
class Filter
{
public:
	Filter();
	~Filter();
	virtual bool evaluate(const O& o, const Criterion<T, O>& c);
};

template <typename T, typename O>
class Filter_fi : public Filter<T, O>
{
public:
	// FIXME Severity	Code	Description	Project	File	Line	Suppression State
	// Error	C2662	'O Criterion<Area,O>::evaluate(const T &)' : cannot convert 'this' pointer from 'const Criterion<Area,std::string>' to 'Criterion<Area,std::string> &'	

	bool evaluate(const O& o, const Criterion<T, O>& c) override { return c.evaluate(o) = alpha; }
private:
	T alpha; // TODO treba setter
};

class FilterHasName : public Filter_fi<Area, std::string> {};