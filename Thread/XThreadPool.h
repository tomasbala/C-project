#pragma once
#include<vector>

class XThread;
class Xtask;
class XthreadPool{
public:
    static XThreadPool *Get(){
        static XthreadPool p;
        return &p;
    }
    void Init(int threadCount); //初始化所有线程
    void Dispatch(XTask*,int arg); //分发任务给线程，arg是任务所带的参数
private:
    int threadCount;//统计线程数量
    int lastThread = -1;
    std::vector<XThread *> threads;//所有线程的向量
    XThreadPool() {};
}

