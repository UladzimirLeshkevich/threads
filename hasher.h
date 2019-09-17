#pragma once
#include "md5.h"
//comment from the my local branch

#include <array>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class hasher
{
public:
    // hasher();
    void operator()(size_t i, const std::vector<std::string>& data,
                    std::vector<std::string>& result);
};
