//
//  producer_consumer.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-20.
//

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;                 // Shared buffer
const int bufferSize = 10;              // Maximum buffer size
std::mutex mtx_consumer;                         // Mutex for buffer access
std::condition_variable bufferNotEmpty; // Condition variable for buffer not empty
std::condition_variable bufferNotFull;  // Condition variable for buffer not full

void producer() {
    for (int i = 0; i < 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx_consumer);

        // Wait until buffer is not full
        bufferNotFull.wait(lock, [] { return buffer.size() < bufferSize; });

        // Produce data and add to the buffer
        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;

        lock.unlock();

        // Notify consumers that buffer is not empty
        bufferNotEmpty.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx_consumer);

        // Wait until buffer is not empty
        bufferNotEmpty.wait(lock, [] { return !buffer.empty(); });

        // Consume data from the buffer
        int data = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << data << std::endl;

        lock.unlock();

        // Notify producers that buffer is not full
        bufferNotFull.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int mainp() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout<<"finished..."<<std::endl;
    return 0;
}

