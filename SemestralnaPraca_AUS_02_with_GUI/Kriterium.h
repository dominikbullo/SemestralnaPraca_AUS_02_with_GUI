#pragma once
#include"Area.h"

template <typename T, typename O>
class Kriterium
{
public:
	virtual T evaluate(const O& o) const = 0;
};

class KriteriumNazov : public Kriterium<std::string, Area>
{
public:
	std::string evaluate(const Area& a) const override { return a.getName(); }
};

class KriteriumPrislusnostObce : public Kriterium<bool, Obec>
{
public:
	bool evaluate(const Obec& o) const override { return o.isIn(*area); }
	void setArea(Area* area) { this->area = area; }
private:
	Area * area;
};

class KriteriumVolici : public Kriterium<int, Area>
{
public:
	int evaluate(const Area& a) const override { return a.getPocetVolicov(kolo); }
	void setArea(Area* area) { this->area = area; }
	void setKolo(int kolo) { this->kolo = kolo; }
private:
	Area * area;
	int kolo;
};

class KriteriumVydaneObalky : public Kriterium<int, Area>
{
public:
	int evaluate(const Area& a) const override { return a.getPocetVydanychObalok(kolo); }
	void setArea(Area* area) { this->area = area; }
	void setKolo(int kolo) { this->kolo = kolo; }
private:
	Area * area;
	int kolo;
};


class KriteriumUcast : public Kriterium<double, Area>
{
public:
	double evaluate(const Area& a) const override { return a.getUcastVolicov(kolo); }
	void setArea(Area* area) { this->area = area; }
	void setKolo(int kolo) { this->kolo = kolo; }

private:
	Area * area;
	int kolo;
};

class KriteriumOdovzdaneObalky : public Kriterium<double, Area>
{
public:
	double evaluate(const Area& a) const override { return a.getPocetOdovzdanychObalok(kolo); }
	void setArea(Area* area) { this->area = area; }
	void setKolo(int kolo) { this->kolo = kolo; }
private:
	Area * area;
	int kolo;
};