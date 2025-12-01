#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <unistd.h>
using namespace std;

int shared_data = 0;
int readercount = 0;

mutex rc_mutex;
mutex db_mutex;

void reader(int id)
{
    while (true)
    {
        rc_mutex.lock();
        {
            readercount++;
            if (readercount == 1)
            {
                db_mutex.lock();
            }
        }
        rc_mutex.unlock();

        cout << "Reader " << id << " reads " << shared_data << endl;

        rc_mutex.lock();
        {
            readercount--;
            if (readercount == 0)
            {
                db_mutex.unlock();
            }
        }
        rc_mutex.unlock();

        sleep(1);
    }
}

void writer(int id)
{
    while (true)
    {
        db_mutex.lock();
        {
            shared_data++;
            cout << "Writer " << id << " writes " << shared_data << endl;
        }
        db_mutex.unlock();

        sleep(2);
    }
}

int main()
{
    int r, w;

    cout << "Enter number of readers: ";
    cin >> r;

    cout << "Enter number of writers: ";
    cin >> w;

    vector<thread> threads;

    for (int i = 1; i <= r; i++)
    {
        threads.emplace_back(reader, i);
    }

    for (int i = 1; i <= w; i++)
    {
        threads.emplace_back(writer, i);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}
