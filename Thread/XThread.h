#pragma once
#include<list>
#include<mutex>

class Xtask;
struct event_base;
class Xthread{
public:
    void Start();
    void Main();
    void Activate(int arg);
    void AddTack(Xtask *);

    Xthread();
    ~Xthread();
    int id=0;

private:
    event_base *base =0; 
    std::list<Xtask*> taska;
    std::mutex tasks_mutex;
}