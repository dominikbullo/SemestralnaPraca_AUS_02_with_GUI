#pragma once
#include"Area.h"

template <typename T, typename O>
class Criterion
{
public:
	Criterion();
	~Criterion();
	virtual O evaluate(const T& t);
};

class CriterionName : public Criterion<Area, std::string>
{
public:
	std::string evaluate(const Area& a) override { return a.getName(); }
};

class CriterionIsIN : public Criterion<Obec, bool>
{
public:
	bool evaluate(const Obec& t) override { return t.isIn(*area); }
private:
	Area * area; // TODO treba setter
};