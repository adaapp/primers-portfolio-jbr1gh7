#include<thread>
#include <boost/lexical_cast.hpp>

int thread1Time = 5;
int thread2Time = 10;

void sleepTimer(int seconds = 5) {
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

//creates a thread and sleeps it for the pre-defined duration
void timer1() {
    output("\nThread 1: " + boost::lexical_cast<std::string>(std::this_thread::get_id()) + " started");
    sleepTimer(thread1Time);
    output("\nThread 1: " + boost::lexical_cast<std::string>(std::this_thread::get_id()) + " ended");
}

void timer2() {
    output("\nThread 2: " + boost::lexical_cast<std::string>(std::this_thread::get_id()) + " started");
    sleepTimer(thread2Time);
    output("\nThread 2: " + boost::lexical_cast<std::string>(std::this_thread::get_id()) + " ended");
}

void joinThreads(void) {
    //define the two threads in parallel
    std::thread thread1(timer1);
    std::thread thread2(timer2);

    output("\nMain thread: " + boost::lexical_cast<std::string>(std::this_thread::get_id()) + " started");

    thread1.join();
    thread2.join();

    output("\nMain thread: " + boost::lexical_cast<std::string>(std::this_thread::get_id()) + " ended");
}

void detachThreads(void) {
    std::thread thread1(timer1);
    std::thread thread2(timer2);

    output("\nMain thread: " + boost::lexical_cast<std::string>(std::this_thread::get_id()) + " started");

    thread1.detach();
    thread2.detach();

    output("\nMain thread: " + boost::lexical_cast<std::string>(std::this_thread::get_id()) + " ended");
}

void joinDetachThreads(void) {
	joinThreads();
    detachThreads();
}