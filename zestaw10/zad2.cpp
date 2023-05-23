#include <vector>  
#include <algorithm>  
#include <execution>  
#include <mutex>
#include <iostream>
#include <ctime>

template <typename Policy>
void test(Policy policy){
    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    std::mutex output_mutex;

    std::for_each(policy, vec.begin(), vec.end(), [&output, &output_mutex](int& elem) {
        if (elem % 2 == 0) {    
            std::lock_guard lock(output_mutex);       
            output.push_back(elem); 
        } //lock_guard automatycznie zwalnia mutex po wyjsciu z bloku
    }); 

    std::cout << output[0] << " " << output[1] << " " << output[2] << std::endl;
}

main() { 
    clock_t start = clock();
    test<>(std::execution::par);
    clock_t stop = clock();
    double duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;

    start = clock();
    test<>(std::execution::seq);
    stop = clock();
    duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;
}  