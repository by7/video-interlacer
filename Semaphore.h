#include <mutex>
#include <condition_variable>

class Semaphore
{
private:
    std::mutex mutex_;
    std::condition_variable condition_;
    int turnid = 1; // Initialized as getNext()'s turn
public:
    void notify(int id) {
        std::unique_lock<decltype(mutex_)> lock(mutex_);
        if(turnid==1) turnid = 0;
        else turnid = 1;
        //switch between 0 and 1
        condition_.notify_one();
    }
    void wait(int id) {
        std::unique_lock<decltype(mutex_)> lock(mutex_);
        while(turnid != id)
            condition_.wait(lock);
        turnid = id;
    }
};
