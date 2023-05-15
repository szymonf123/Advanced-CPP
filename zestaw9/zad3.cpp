#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Song {
public:
    std::wstring artist;
    std::wstring title;

    Song(std::wstring a, std::wstring t){
        artist = a;
        title = t;
        std::wcout << "Konstruktor " << artist << " - " << title << std::endl;
    }

    ~Song(){
        std::wcout << "Destruktor " << artist << " - " << title << std::endl;
    }
};

std::unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title) {
    return std::make_unique<Song>(artist, title);
}

void MakeSongs() {
    std::vector<std::unique_ptr<Song>> songs;
    songs.push_back(SongFactory(L"Michael Jackson", L"Beat It"));
    songs.push_back(SongFactory(L"One Direction", L"One Way Or Another"));
    songs.push_back(SongFactory(L"Dead Or Alive", L"You Spin Me Round"));

    for (auto& i : songs){
        std::wcout << i->artist << " - " << i->title << std::endl;
    }
}

main(){
    std::cout << "Main start\n";
    MakeSongs();
    std::cout << "Main end\n";
}