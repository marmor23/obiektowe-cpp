#include <iostream>
#include <memory>

class Song
{
	public:
		std::string artist;
		std::string title;
		Song(const std::string &x, const std::string &y)
		{
			artist = x;
			title = y;
			std::cout << "Tworzenie Song(" << artist << ", " << title << ")" << std::endl;
		}
		~Song()
		{
			std::cout << "Niszczenie Song" << std::endl;
		}
};

void info(std::shared_ptr<Song> &ptr)
{
	std::cout << "use_count = " << ptr.use_count() << " unique = " << (ptr.unique() ? "true" : "false") << std::endl;
}

int main()
{
	std::shared_ptr<Song> ptr = std::make_shared<Song>("Black Sabbath", "Children of the Sea");
	info(ptr);
	std::shared_ptr<Song> ptr2 = ptr;
	info(ptr);
	std::shared_ptr<Song> ptr3(ptr2);
	info(ptr);
	std::shared_ptr<Song> ptr4 = std::move(ptr3);
	info(ptr);
	/*
	ptr = nullptr;
	ptr2 = nullptr;
	//ptr3 = nullptr;
	ptr4 = nullptr;
	*/
	std::cout << "Program zakonczyl swoje dzialanie" << std::endl;
	return 0;
}