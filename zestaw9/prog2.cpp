#include <iostream>
#include <memory>
#include <vector>

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

std::unique_ptr<Song> SongFactory(const std::string &artist, const std::string &title)
{
	return std::make_unique<Song>(artist, title);
}

int main()
{
	std::vector<std::unique_ptr<Song>> songvec;
	auto song = SongFactory("aa", "bb");
	songvec.push_back(SongFactory("cc", "dd"));
	songvec.push_back(SongFactory("ee", "ff"));
	songvec.push_back(SongFactory("gg", "hh"));
	songvec.push_back(SongFactory("xx", "vv"));
	songvec.push_back(SongFactory("yy", "zz"));
	for (auto &s : songvec)
		std::cout << "Song: Artist = " << s->artist << " Title = " << s->title << std::endl;
	return 0;
}