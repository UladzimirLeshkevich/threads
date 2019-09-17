#include "hasher.h"
//from branch

void hasher::operator()(size_t i, const std::vector<std::string>& data,
                        std::vector<std::string>& result)
{
    std::string                 hash_result;
    std::cout << "Thread " << i << " use data " << data[i] << std::endl;
    hash_result = md5(data[i]);
    std::cout << "hash result vector =  " << hash_result << std::endl;
    result[i] = hash_result;
}
