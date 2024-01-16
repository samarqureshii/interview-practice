//Background: In operating systems, an interrupt is a signal to the processor emitted by hardware or software indicating an event that needs immediate attention. An important aspect of handling interrupts in programs, especially in Unix/Linux-based systems, is managing signal interrupts. Signals like SIGINT (for interrupt, typically sent by pressing Ctrl+C) or SIGTERM (for terminate) are common and need to be handled gracefully in applications.


#include <iostream>
#include <csignal>
#include <unistd.h>
#include <atomic>
using namespace std;
// A flag to control the main loop
atomic<bool> keepRunning(true);

// Signal handler function
void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    // Set the flag to false to stop the main loop
    keepRunning = false;
}

int main() {
    // Register the signal handler
    signal(SIGINT, signalHandler);

    // Main program loop
    while(keepRunning) {
        cout << "Program running... Press Ctrl+C to stop" << endl;
        sleep(1);  // Sleep for demonstration purposes
    }

    cout << "Program exiting..." << std::endl;
    return 0;
}

