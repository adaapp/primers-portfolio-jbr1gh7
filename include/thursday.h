#include<thread>

int thread1Time = 5;
int thread2Time = 10;

void sleepTimer(int seconds = 5) {
	std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
    output("I am back awake!");
}

void timer1() {
    output("\nThread 1: " + std::this_thread::get_id() + " started");
    sleepTimer(thread1Time);
    output("\nThread 1: " + std::this_thread::get_id() + " ended");
}

void timer2() {
    output("\nThread 2: " + std::this_thread::get_id() + " started");
    sleepTimer(thread2Time);
    output("\nThread 2: " + std::this_thread::get_id() + " ended");
}

int joinThreads(void) {
    std::thread thread1(timer1);
    std::thread thread2(timer2);

    output("\nMain thread: " + std::this_thread::get_id() + "started");

    thread1.join();
    thread2.join();
}

void joinDetachThreads(void) {
	joinThreads();
}