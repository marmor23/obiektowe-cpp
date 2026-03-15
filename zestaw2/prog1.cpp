#include <iostream>

class samochod
{
	public:
		std::string firma;
		std::string model;
		int rokprodukcji;
		virtual void opis()
		{
			std::cout << "Zwykla klasa samochod nie posiada opisu" << std::endl;
		}
};

class Fiat126 : public samochod
{
	public:
		Fiat126() {}
		Fiat126(std::string firmax, std::string modelx, int rokprodukcjix)
		{
			firma = firmax;
			model = modelx;
			rokprodukcji = rokprodukcjix;
		}
		void opis()
		{
			std::cout << firma << " " << model << " " << rokprodukcji << std::endl;
		}
};	

class Peugeot206 : public samochod
{
	public:
		Peugeot206() {}
		Peugeot206(std::string firmax, std::string modelx, int rokprodukcjix)
		{
			firma = firmax;
			model = modelx;
			rokprodukcji = rokprodukcjix;
		}
		void opis()
		{
			std::cout << firma << " " << model << " " << rokprodukcji << std::endl;
		}
};

class Porsche911 : public samochod
{
	public:
		Porsche911() {}
		Porsche911(std::string firmax, std::string modelx, int rokprodukcjix)
		{
			firma = firmax;
			model = modelx;
			rokprodukcji = rokprodukcjix;
		}
		void opis()
		{
			std::cout << firma << " " << model << " " << rokprodukcji << std::endl;
		}
};

template<typename t>
void opissamochodu(t tab, int siz)
{
	int i;
	for (i = 0; i < siz; i++)
		tab[i].opis();
}

int main()
{
	// polimorfizm statyczny
	Peugeot206 samochody[3];
	samochody[0] = Peugeot206("Peugeot", "206", 2004);
	samochody[1] = Peugeot206("Peugeot", "206", 2005);
	samochody[2] = Peugeot206("Peugeot", "206", 2006);
	opissamochodu<Peugeot206 *>(samochody, 3);
	
	// polimorfizm dynamiczny
	samochod *samochodytab[3];
	int i;
	samochodytab[0] = new Fiat126("Fiat", "126p", 1978);
	samochodytab[1] = new Peugeot206("Peugeot", "206", 2005);
	samochodytab[2] = new Porsche911("Porsche", "911", 2019);
	for (i = 0; i < 3; i++)
		samochodytab[i]->opis();
	return 0;
}