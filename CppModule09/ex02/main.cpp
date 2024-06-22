#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try {
        PmergeMe pmm;
        pmm.init_arr(argc, argv);
        pmm.init_vec();
        std::cout << "Before: ";
        pmm.print_vec();
        clock_t vec_t = clock();
        pmm.fordJohnson_vec(2);
        vec_t = clock() - vec_t;
        std::cout << "After:  ";
        pmm.print_vec();
        std::cout << "Time to process a range of " << argc - 1 << " element with std::vector : " << static_cast<float>(vec_t) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;


        pmm.init_deq();
        std::cout << "Before: ";
        pmm.print_deq();
        clock_t deq_t = clock();
        pmm.fordJohnson_deq(2);
        deq_t = clock() - deq_t;
        std::cout << "After:  ";
        pmm.print_deq();
        std::cout << "Time to process a range of " << argc - 1 << " element with std::deque : " << static_cast<float>(deq_t) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}