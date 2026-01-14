#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

#if 0
std::mutex mtx;
int counter = 0;
void worker() {
    for (int i = 0; i < 10000000; ++i) {
        mtx.lock();
        ++counter;
        mtx.unlock();
    }
}
#else
std::atomic<int> counter(0);
void worker() {
    for (int i = 0; i < 10000000; ++i) {
        ++counter;
    }
}
#endif

void demo() {
    auto start = std::chrono::steady_clock::now();
    std::thread t1(worker);
    std::thread t2(worker);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "counter = " << counter << ", time = " << duration.count() << std::endl;
}

int main() {
    demo();
    return 0;
}
