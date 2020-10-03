struct task_struct
{
    volatile long state; // -1 unrunnable, 0 runnable, > 0 stopped
    pid_t pid;
    pid_t tgid;
}
