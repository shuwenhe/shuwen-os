// tst->state
#define TASK_RUNNING 0X0001 // 可执行状态
#define TASK_INTERRUPTIBLE 0x0001 // 受信号signal软中断的到来而被唤醒
#define TASK_UNINTERRUPTIBLE 0X0002 // 进程深度睡眠不受信号signal(软中断)打扰

// tst->exit_state
#define EXIT_ZOMBIE 0X0020 // 僵尸态：进程已经"去世"(exit)而"户口"尚未注销

struct task_struct{
    volatile long state; // 进程当前的运行状态
    pid_t pid;
    pid_t tgid;
    int prio;                 // priority
    int static_prio;          // static priority
    int normal_prio;          // normal priority
    unsigned int rt_priority; // real time priority

    // Memory management 
    struct mm_struct *mm;
    struct mm_struct *active_mm;

    // File management 
}
