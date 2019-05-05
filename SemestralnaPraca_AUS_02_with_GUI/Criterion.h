#pragma once
#include"Area.h"

template <typename T, typename O>
class Criterion
{
public:
	//Criterion() {};
	//~Criterion() {};
	virtual T evaluate(const O& o) const = 0;
};

class CriterionName : public Criterion<std::string, Area>
{
public:
	//CriterionName() {};
	std::string evaluate(const Area& a) const override {
		return a.getName();
		//return "test";
	}
};

class CriterionIsIN : public Criterion<bool, Obec>
{
public:
	bool evaluate(const Obec& t)const override {
		//return t.isIn(*area); 
		return true;
	}
private:
	// TODO treba setter
	Area * area;
};