#include "hasher.h"

std::mutex report_mutex;

void hasher::operator()(size_t i, const std::vector<std::string>& data,
                        std::vector<std::string>& result)
{
    std::string                 hash_result;
    std::lock_guard<std::mutex> locked(report_mutex); // ???
    std::cout << "Thread " << i << " use data " << data[i] << std::endl;
    hash_result = md5(data[i]);
    std::cout << "hash result vector =  " << hash_result << std::endl;
    // std::lock_guard<std::mutex> locked(report_mutex);
    // result.push_back(hash_result);
    result[i] = hash_result;
}
