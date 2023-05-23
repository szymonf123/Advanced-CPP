#include <iostream>
#include <ctime>
#include <algorithm>
#include <execution>
#include <vector>

main() {
    std::vector<int> heap;
    for (int i = 0; i < 1'000'000; i++)
        heap.push_back(100000 - i);

    std::cout << "is_heap\n";
    clock_t start = clock();
    bool answer = std::is_heap(std::execution::par, heap.begin(), heap.end());
    clock_t stop = clock();
    double duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;

    start = clock();
    answer = std::is_heap(std::execution::seq, heap.begin(), heap.end());
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;


    std::cout << "is_sorted\n";
    start = clock();
    answer = std::is_sorted(std::execution::par, heap.begin(), heap.end(), std::greater<int>());
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;

    start = clock();
    answer = std::is_sorted(std::execution::seq, heap.begin(), heap.end(), std::greater<int>());
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;


    std::cout << "count_if\n";
    start = clock();
    int result = std::count_if(std::execution::par, heap.begin(), heap.end(), [&heap](int& i){return i % 3 == 0;});
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;

    start = clock();
    result = std::count_if(std::execution::seq, heap.begin(), heap.end(), [&heap](int& i){return i % 3 == 0;});
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;


    std::cout << "count\n";
    start = clock();
    result = std::count(std::execution::par, heap.begin(), heap.end(), 0);
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;

    start = clock();
    result = std::count(std::execution::seq, heap.begin(), heap.end(), 0);
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;


    std::cout << "sort\n";
    start = clock();
    std::sort(std::execution::par, heap.begin(), heap.end(), std::greater<int>());
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;

    start = clock();
    std::sort(std::execution::seq, heap.begin(), heap.end(), std::greater<int>());
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;
}
