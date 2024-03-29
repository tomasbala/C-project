//启动线程

void Xthread::Start(){
    testout(id<<"threwad At Start()");
    thread th(&XThread::Main,this);
    th.detach();
}


void XThread::Main() {
    cout<<id<<"thread::Main() begin"<<endl;
    //线程启动时要做的事
    cout<<id<<"thread::Main() end"<<endl;
}

void XThread::Activate(int arg){
    testout(id<<"thread At Activate()");
    //从任务列表中获取任务，并初始化
    Xtask *t = NULL;
    tasks_mutex.lock();
    if(tasks.empty()){
        tasks_mutex.unlock();
        return;
    }
    t = tasks.front();
    tasks.pop_front();
    tasks_mutex.unlock();
    t->Init(arg);
}

void XThread::AddTack(XTask *t){
    if(!t) return;
    t->base = this->base;
    tasks_mutex.lock();
    tasks.push_back(t);
    tasks_mutex.unlock();
}
Xthread::XThread(){
} //构造函数
Xthread::~XThread(){

}//析构函数

