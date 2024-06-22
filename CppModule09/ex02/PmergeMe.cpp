#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->_n = other._n;
        this->_numbers = other._numbers;

        this->_arr_vec = other._arr_vec;
        this->_a_vec = other._a_vec;
        this->_b_vec = other._b_vec;
        this->_remain_vec = other._remain_vec;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::init_arr(int argc, char **argv) {
    std::set<int> set;

    if (argc < 2) {
        throw std::runtime_error("Error: not enough arguments");
    }
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j]; j++) {
            if (!isdigit(argv[i][j]) && argv[i][j] != '-') {
                throw std::runtime_error("Error: invalid argument");
            }
        }
        long long num_long = std::stoll(argv[i]);
        if (num_long > 2147483647 || num_long < 0) {
            throw std::runtime_error("Error: invalid argument");
        }
        int num = std::stoi(argv[i]);
        set.insert(num);
        _numbers.push_back(num);
        if (set.size() != _numbers.size()) {
            throw std::runtime_error("Error: duplicate argument");
        }
    }
    _n = _numbers.size();
}

void PmergeMe::init_vec() {
    for (unsigned int i = 0; i < _n; i++) {
        _arr_vec.push_back(_numbers[i]);
    }
}

void PmergeMe::fordJohnson_vec(size_t pairSize) {
    size_t idx = 0;
    while ((idx + 1) * pairSize <= _n)
    {
        std::vector<int>::iterator a = _arr_vec.begin() + idx * pairSize;
        std::vector<int>::iterator b = a + (pairSize / 2);
        std::vector<int>::iterator nxt = b + (pairSize / 2);
        if (*a < *b)
            std::rotate(a, b, nxt);
        idx++;
    }
    if (pairSize > _n / 2)
    {
        make_pair_vec(pairSize);
        merge_insert_vec();
        return;
    }

    fordJohnson_vec(pairSize * 2);
    make_pair_vec(pairSize);
    merge_insert_vec();
}

void PmergeMe::make_pair_vec(size_t pairSize) {
    size_t r_size = _n % pairSize;
    size_t i = 0;

    while (i + pairSize <= _n) {
        size_t j = 0;
        std::vector<int> tmp_a;
        std::vector<int> tmp_b;

        while (j < pairSize / 2) {
            tmp_a.push_back(_arr_vec[i + j]);
            j++;
        }
        _a_vec.push_back(tmp_a);

        j = 0;
        while (j < pairSize / 2) {
            tmp_b.push_back(_arr_vec[i + j + pairSize / 2]);
            j++;
        }
        _b_vec.push_back(tmp_b);

        i += pairSize;
    }

    if (r_size) {
        std::vector<int> tmp;
        size_t j = 0;
        while (pairSize / 2 <= r_size && j < pairSize / 2) {
            tmp.push_back(_arr_vec[i + j]);
            j++;
        }
        if (!tmp.empty())
            _b_vec.push_back(tmp);
        while (i + j < _n) {
            _remain_vec.push_back(_arr_vec[i + j]);
            j++;
        }
    }

}

size_t PmergeMe::jacobsthalNum(size_t n) {
    return ((pow(2, n) - pow(-1, n)) / 3);
}

void PmergeMe::merge_insert_vec() 
{
    std::vector<std::vector<int> > merged;
    std::vector<size_t> jacobsthalArr;
    for (size_t i = 2; jacobsthalNum(i) <= _a_vec.size(); i++) {
        jacobsthalArr.push_back(jacobsthalNum(i));
    }

    merged.push_back(_b_vec[0]);

    for (size_t i = 0; i < _a_vec.size(); i++) {
        merged.push_back(_a_vec[i]);
    }

    size_t i = 1;
    while (i < jacobsthalArr.size()) {
        size_t j = 0;
        
        while (jacobsthalArr[i - 1] < jacobsthalArr[i] - j) {
            binarySearch_vec(merged, jacobsthalArr[i] - j - 1);
            j++;
        }
        i++;
    }

    size_t j = 0;
    while (jacobsthalArr[i - 1] < _b_vec.size() - j) {
        binarySearch_vec(merged, _b_vec.size() - j - 1);
        j++;
    }

    _arr_vec.clear();
    for (size_t m_idx = 0; m_idx < merged.size(); m_idx++) {
        for (size_t el_idx = 0; el_idx < merged[m_idx].size(); el_idx++) {
            _arr_vec.push_back(merged[m_idx][el_idx]);
        }
    }
    for (size_t r = 0; r < _remain_vec.size(); r++) {
        _arr_vec.push_back(_remain_vec[r]);
    }
    _a_vec.clear();
    _b_vec.clear();
    _remain_vec.clear();
}

void PmergeMe::binarySearch_vec(std::vector<std::vector<int> > &merged, size_t b_idx)
{
    if (b_idx == 0)
        return ;
    int right_idx = b_idx;
    if (b_idx >= _a_vec.size())
        right_idx = _a_vec.size() - 1;

    int left = 0;
    int mid = 0;
    int right;
    int insertValue = this->_b_vec[b_idx][0];

    std::vector<std::vector<int> >::iterator it = std::find(merged.begin(), merged.end(), this->_a_vec[right_idx]);
    right = std::distance(merged.begin(), it);

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (merged[mid][0] < insertValue) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    merged.insert(merged.begin() + left, this->_b_vec[b_idx]);
}

void PmergeMe::print_vec() {
    for (size_t i = 0; i < _arr_vec.size(); i++) {
        std::cout << _arr_vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::init_deq() {
    for (unsigned int i = 0; i < _n; i++) {
        _arr_deq.push_back(_numbers[i]);
    }
}

void PmergeMe::fordJohnson_deq(size_t pairSize) {
    size_t idx = 0;
    while ((idx + 1) * pairSize <= _n)
    {
        std::deque<int>::iterator a = _arr_deq.begin() + idx * pairSize;
        std::deque<int>::iterator b = a + (pairSize / 2);
        std::deque<int>::iterator nxt = b + (pairSize / 2);
        if (*a < *b)
            std::rotate(a, b, nxt);
        idx++;
    }
    if (pairSize > _n / 2)
    {
        make_pair_deq(pairSize);
        merge_insert_deq();
        return;
    }

    fordJohnson_deq(pairSize * 2);
    make_pair_deq(pairSize);
    merge_insert_deq();
}

void PmergeMe::make_pair_deq(size_t pairSize) {
    size_t r_size = _n % pairSize;
    size_t i = 0;

    while (i + pairSize <= _n) {
        size_t j = 0;
        std::deque<int> tmp_a;
        std::deque<int> tmp_b;

        while (j < pairSize / 2) {
            tmp_a.push_back(_arr_deq[i + j]);
            j++;
        }
        _a_deq.push_back(tmp_a);

        j = 0;
        while (j < pairSize / 2) {
            tmp_b.push_back(_arr_deq[i + j + pairSize / 2]);
            j++;
        }
        _b_deq.push_back(tmp_b);

        i += pairSize;
    }

    if (r_size) {
        std::deque<int> tmp;
        size_t j = 0;
        while (pairSize / 2 <= r_size && j < pairSize / 2) {
            tmp.push_back(_arr_deq[i + j]);
            j++;
        }
        if (!tmp.empty())
            _b_deq.push_back(tmp);
        while (i + j < _n) {
            _remain_deq.push_back(_arr_deq[i + j]);
            j++;
        }
    }

}

void PmergeMe::merge_insert_deq() 
{
    std::deque<std::deque<int> > merged;
    std::vector<size_t> jacobsthalArr;
    for (size_t i = 2; jacobsthalNum(i) <= _a_deq.size(); i++) {
        jacobsthalArr.push_back(jacobsthalNum(i));
    }

    merged.push_back(_b_deq[0]);

    for (size_t i = 0; i < _a_deq.size(); i++) {
        merged.push_back(_a_deq[i]);
    }

    size_t i = 1;
    while (i < jacobsthalArr.size()) {
        size_t j = 0;
        
        while (jacobsthalArr[i - 1] < jacobsthalArr[i] - j) {
            binarySearch_deq(merged, jacobsthalArr[i] - j - 1);
            j++;
        }
        i++;
    }

    size_t j = 0;
    while (jacobsthalArr[i - 1] < _b_deq.size() - j) {
        binarySearch_deq(merged, _b_deq.size() - j - 1);
        j++;
    }

    _arr_deq.clear();
    for (size_t m_idx = 0; m_idx < merged.size(); m_idx++) {
        for (size_t el_idx = 0; el_idx < merged[m_idx].size(); el_idx++) {
            _arr_deq.push_back(merged[m_idx][el_idx]);
        }
    }
    for (size_t r = 0; r < _remain_deq.size(); r++) {
        _arr_deq.push_back(_remain_deq[r]);
    }
    _a_deq.clear();
    _b_deq.clear();
    _remain_deq.clear();
}

void PmergeMe::binarySearch_deq(std::deque<std::deque<int> > &merged, size_t b_idx)
{
    if (b_idx == 0)
        return ;
    int right_idx = b_idx;
    if (b_idx >= _a_deq.size())
        right_idx = _a_deq.size() - 1;

    int left = 0;
    int mid = 0;
    int right;
    int insertValue = this->_b_deq[b_idx][0];

    std::deque<std::deque<int> >::iterator it = std::find(merged.begin(), merged.end(), this->_a_deq[right_idx]);
    right = std::distance(merged.begin(), it);

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (merged[mid][0] < insertValue) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    merged.insert(merged.begin() + left, this->_b_deq[b_idx]);
}

void PmergeMe::print_deq() {
    for (size_t i = 0; i < _arr_deq.size(); i++) {
        std::cout << _arr_deq[i] << " ";
    }
    std::cout << std::endl;
}