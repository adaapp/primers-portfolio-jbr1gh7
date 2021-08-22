#include<thread>

void sleepTimer(int seconds = 5) {
	std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
    output("I am back awake!");
}


void joinDetachThreads(void) {
	std::cout << " - joinDetachThreads: not yet implemented\n\n";
}