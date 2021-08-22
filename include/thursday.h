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

int join(void) {
    output("Main thread: " + std::this_thread::get_id() + "started");
    
}

void joinDetachThreads(void) {
	
}