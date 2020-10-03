/*
 *  shuwen-os/ipc/sem.c
 *
 *  Copyright (C) 2007, 2012 Shuwen He <1201220707@pku.edu.cn>
 */

struct sem
{
    /* data */
    int semval; // current value
    struct pid *sempid;
};
