#include <iostream>
#include <memory>

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

main(){
    std::unique_ptr<Song> song = std::make_unique<Song>(L"Wham!", L"Last christmas");
    //jedna specjalizacja umozliwia przekazanie argumentow do konstruktora

    std::unique_ptr<int[]> ints = std::make_unique<int[]>(20);
    //tutaj nie przekazujemy argumentow do konstruktora, bo nie tworzymy zadnego obiektu, ale mozemy podac rozmiar tablicy
}