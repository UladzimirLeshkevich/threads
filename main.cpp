#include "hasher.h"

int main()
{
    hasher h;

    // unsigned                 nthreads = std::thread::hardware_concurrency();
    unsigned nthreads = 5;

    std::vector<std::string> input_data(nthreads);
    input_data[0] = "11111";
    input_data[1] = "22222";
    input_data[2] = "33333";
    input_data[3] = "44444";
    input_data[4] = "55555";

    std::vector<std::string> result_data(nthreads);

    for (auto& it : input_data)
    {
        std::cout << it << std::endl;
    }

    //something like threads pool
    std::vector<std::thread> threads(nthreads);

    // for (unsigned i = 0; i < nthreads; ++i)
    for (unsigned i = 0; i < nthreads; ++i)
    {
        std::cout << "i= " << i << std::endl;
        threads[i] =
            (std::thread(h, i, std::ref(input_data), std::ref(result_data)));

        //        threads.push_back(
        //            std::thread(h, i, std::ref(input_data),
        //            std::ref(result_data)));
    }
    for (auto& t : threads)
        t.join();

    // result
    std::cout << std::endl;
    std::cout << "result vector" << std::endl;
    for (auto& it : result_data)
    {
        std::cout << it << std::endl;
    }

    input_data[0] = "66666";
    input_data[1] = "77777";
    input_data[2] = "88888";
    input_data[3] = "99999";
    input_data[4] = "12121";

    for (auto& it : input_data)
    {
        std::cout << it << std::endl;
    }

    for (unsigned i = 0; i < nthreads; ++i)
    {
        threads[i] =
            (std::thread(h, i, std::ref(input_data), std::ref(result_data)));
    }
    for (auto& t : threads)
        t.join();

    // result 2
    std::cout << std::endl;
    std::cout << "result vector2 " << std::endl;
    for (auto& it : result_data)
    {
        std::cout << it << std::endl;
    }

    return 0;
}
