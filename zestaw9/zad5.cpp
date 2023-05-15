#include <iostream>
#include <memory>

class Song;

std::shared_ptr<Song> iptr2;

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

void test(){
    std::shared_ptr<Song> iptr(new Song(L"Michael Jackson", L"Beat It"));
    iptr2 = iptr;
}
main(){
    std::wcout << "Poczatek funkcji test()\n";
    test();
    std::wcout << "Koniec funkcji test()\n";
}