//分配任务到线程池
void XThreadPool::Dispatch (XTask * task,int arg){
    testout("主线程在线程池已经分发")；
    if(!task) return
    int tid = (lastThread+1)&threadCount;//简单的累加得到新的线程ID
    lastThread = tid;
    XThread *t = threads[tid]; //得到最新线程的指针

    t->AddTack(task);
    t->Activate(arg);   
}

//初始化线程池
void XThreadPool::Init(int threadCount){
    testout("主线程正在初始化");
    this->threadCount = threadCount;
    this->lastThread = -1;
    for(int i=0;i<threadCount;i++){
        cout <<"创建线程"<<i<<endl;
        XThread *t = new XThread();
        t->id=u;
        t->start();
        threads.push_back(t);
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}