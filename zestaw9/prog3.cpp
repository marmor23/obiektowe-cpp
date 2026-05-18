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

int main()
{
	// template<class T, class... Args> unique_ptr<T> make_unique(Args&&... args);
	auto clsptr = std::make_unique<Song>("Deep Purple", "Perfect Strangers");
	// template<class T> unique_ptr<T> make_unique(std::size_t size);
	auto tabptr = std::make_unique<int[]>(10);
	return 0;
}