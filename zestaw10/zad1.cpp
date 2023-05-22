#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>
#include <ctime>

main(){
    std::vector<int> a, b, c;
    for (int i = 0; i < 10000; i++)
        a.push_back(10000 - i);
    b = a;
    c = a;

    std::clock_t start = std::clock();
    std::cout << "Sekwencyjnie\n";
    std::sort(std::execution::seq, a.begin(), a.end());
    std::clock_t stop = std::clock();
    double duration = static_cast<double>(stop - start);
    std::cout << duration << std::endl;

    std::cout << "\nRownolegle\n";
    start = std::clock();
    std::sort(std::execution::par, b.begin(), b.end());
    stop = std::clock();
    duration = static_cast<double>(stop - start);
    std::cout << duration << std::endl;

    std::cout << "\nRownolegle niesekwencyjnie\n";
    start = std::clock();
    std::sort(std::execution::par_unseq, c.begin(), c.end());
    stop = std::clock();
    duration = static_cast<double>(stop - start);
    std::cout << duration << std::endl;
}