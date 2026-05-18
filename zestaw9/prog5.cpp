#include <iostream>
#include <memory>

std::weak_ptr<int> wptr;

void info()
{
    std::shared_ptr<int> sptr;
	std::cout << "wptr.use_count() == " << wptr.use_count() << "; ";
    sptr = wptr.lock();
	if (sptr)
        std::cout << "wartosc sptr = " << *sptr << std::endl;
    else
        std::cout << "weak_ptr wygasl!" << std::endl;
}

int main()
{
	int i;
	for (i = 0; i < 5; i++)
	{
        std::shared_ptr<int> sptr = std::make_shared<int>(i);
        wptr = sptr;
        info();
    }
    info();
	return 0;
}