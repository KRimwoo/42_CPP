#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <cmath>

class  PmergeMe {

    private:
        size_t _n;

        std::vector<int> _numbers;
        
        std::vector<int> _arr_vec;
        std::vector<std::vector<int> > _a_vec;
        std::vector<std::vector<int> > _b_vec;
        std::vector<int> _remain_vec;

        std::deque<int> _arr_deq;
        std::deque<std::deque<int> > _a_deq;
        std::deque<std::deque<int> > _b_deq;
        std::deque<int> _remain_deq;

        size_t jacobsthalNum(size_t n);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void init_arr(int argc, char **argv);

        void init_vec();
        void fordJohnson_vec(size_t pairSize);
        void make_pair_vec(size_t pairSize);
        void merge_insert_vec();
        void binarySearch_vec(std::vector<std::vector<int> > &merged, size_t b_idx);
        void print_vec();

        void init_deq();
        void fordJohnson_deq(size_t pairSize);
        void make_pair_deq(size_t pairSize);
        void merge_insert_deq();
        void binarySearch_deq(std::deque<std::deque<int> > &merged, size_t b_idx);
        void print_deq();
};

#endif