#pragma once
#include"Area.h"

template <typename T, typename O>
class Criterion
{
public:
	Criterion();
	~Criterion();
	virtual T evaluate(const O&) = 0;
};

class CriterionName : public Criterion<std::string, Area>
{
public:
	std::string evaluate(const Area& a)override { return a.getName(); }
};

class CriterionIsIN : public Criterion<bool, Obec>
{
public:
	bool evaluate(const Obec& t) override { return t.isIn(*area); }
private:
	Area * area; // TODO treba setter
};