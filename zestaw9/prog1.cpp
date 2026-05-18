#include <iostream>
#include <memory>

int main()
{
	void *ptr;
	std::unique_ptr<void *> uptr;
	std::shared_ptr<void *> sptr;
	std::weak_ptr<void *> wptr;
	std::cout << "sizeof(ptr) = " << sizeof(ptr) << std::endl;
	std::cout << "sizeof(unique_ptr) = " << sizeof(uptr) << std::endl;
	std::cout << "sizeof(shared_ptr) = " << sizeof(sptr) << std::endl;
	std::cout << "sizeof(weak_ptr) = " << sizeof(wptr) << std::endl;
	return 0;
}