#include "Key.h"


Key::Key(Area * area) : nazov(nazov), pocetVolicov(pocetVolicov), ucast(ucast)
{
}

Key::Key(std::string nazov) : nazov(nazov)
{
}

Key::Key(int pocetVolicov) : pocetVolicov(pocetVolicov)
{
}

Key::Key(float ucast) : ucast(ucast)
{
}
