struct process_struct
{
    /* Process management */
    volatile long state; // -1 unrunnable, 0 runnable, > 0 stopped
    pid_t pid;
    pid_t tgid;
    int prio;                 // priority
    int static_prio;          // static priority
    int normal_prio;          // normal priority
    unsigned int rt_priority; // real time priority

    /* Memory management */
    struct mm_struct *mm;
    struct mm_struct *active_mm;

    /* File management */
}
