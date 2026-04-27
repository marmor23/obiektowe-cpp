#include <iostream>
#include <exception>
#include <map>

class Kolor
{
	public:
		int r, g, b;
		Kolor()
		{
			r = 0;
			g = 0;
			b = 0;
		}
		Kolor(int rx, int gx, int bx)
		{
			r = rx;
			g = gx;
			b = bx;
		}
};

class polwyjatek
{
	public:
		Kolor nieznanyKolor()
		{
			throw std::invalid_argument("Kolor o podanej nazwie nie instnieje!");
		}
};

class poldomyslny
{
	public:
		Kolor nieznanyKolor()
		{
			return Kolor();
		}
};

template<int r, int g, int b>
class poldomyslnymod
{
	public:
		Kolor nieznanyKolor()
		{
			return Kolor(r, g, b);
		}
};

template <typename polityka = polwyjatek>
class FabrykaKolorow
{
	std::map<std::string, Kolor> colmap;
	polityka pol;
	public:
		FabrykaKolorow()
		{
			colmap["czarny"] = Kolor(0, 0, 0);
			colmap["bialy"] = Kolor(255, 255, 255);
			colmap["czerwony"] = Kolor(255, 0, 0);
			colmap["zielony"] = Kolor(0, 255, 0);
			colmap["niebieski"] = Kolor(0, 0, 255);
			colmap["zolty"] = Kolor(255, 255, 0);
			colmap["magenta"] = Kolor(255, 0, 255);
			colmap["turkusowy"] = Kolor(0, 255, 255);
		}
		Kolor zwrocKolor(std::string nazwa)
		{
			if (colmap.find(nazwa) == colmap.end())
				return pol.nieznanyKolor();
			return colmap[nazwa];
		}
};

std::ostream& operator<<(std::ostream &os, Kolor k)
{
	os << "Kolor" << "(" << k.r << ", " << k.g << ", " << k.b << ")";
	return os;
}

int main()
{
	FabrykaKolorow fab;
	FabrykaKolorow<poldomyslny> fabdef;
	FabrykaKolorow<poldomyslnymod<33, 66, 88>> fabmod;
	try
	{
		std::cout << "Niebieski: " << fab.zwrocKolor("niebieski") << std::endl;
		std::cout << "Czarny: " << fab.zwrocKolor("czarny") << std::endl;
		std::cout << "Magenta: " << fab.zwrocKolor("magenta") << std::endl;
		std::cout << "Nieistniejacy: " << fab.zwrocKolor("nieistniejacy") << std::endl;
	}
	catch (std::invalid_argument e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Niebieski: " << fabdef.zwrocKolor("niebieski") << std::endl;
		std::cout << "Czarny: " << fabdef.zwrocKolor("czarny") << std::endl;
		std::cout << "Magenta: " << fabdef.zwrocKolor("magenta") << std::endl;
		std::cout << "Nieistniejacy: " << fabdef.zwrocKolor("nieistniejacy") << std::endl;
	}
	catch (std::invalid_argument e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Niebieski: " << fabmod.zwrocKolor("niebieski") << std::endl;
		std::cout << "Czarny: " << fabmod.zwrocKolor("czarny") << std::endl;
		std::cout << "Magenta: " << fabmod.zwrocKolor("magenta") << std::endl;
		std::cout << "Nieistniejacy: " << fabmod.zwrocKolor("nieistniejacy") << std::endl;
	}
	catch (std::invalid_argument e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}