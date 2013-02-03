
#ifndef IMUST_OJ_TASK_H
#define IMUST_OJ_TASK_H

#include "../judgerlib/logger/Logger.h"
#include "../judgerlib/taskmanager/TaskManager.h"
#include "../judgerlib/sql/DBManager.h"

namespace IMUST
{

class JudgeTask : public ITask
{
public:
    JudgeTask(const TaskInputData & inputData);

    virtual bool run();

    virtual const TaskOutputData & output() const
    {
        return output_;
    }

    virtual const TaskInputData & input() const
    {
        return Input;
    }

public:
    const TaskInputData Input;

private:
    TaskOutputData output_;
};

class JudgeThread
{
public:
    JudgeThread(int id, IMUST::TaskManagerPtr working, IMUST::TaskManagerPtr finish);
    void operator()();

private:
    int id_;
    IMUST::TaskManagerPtr workingTaskMgr_;
    IMUST::TaskManagerPtr finisheTaskMgr_;
};


class JudgeTaskFactory : public TaskFactory
{
public:
    JudgeTaskFactory(){}
    virtual ~JudgeTaskFactory(){}

    virtual ITask* create(const TaskInputData & input);

    virtual void destroy(ITask* pTask);
};


class JudgeDBRunThread
{
public:

    JudgeDBRunThread(IMUST::DBManagerPtr dbm);

    void operator()();

private:
    IMUST::DBManagerPtr dbm_;
};


}   // namespace IMUST


#endif  // IMUST_OJ_TASK_H
