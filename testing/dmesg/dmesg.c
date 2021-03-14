#include "memalign.h"

#include<linux/security.h>
#include<linux/sysctl.h>
static unsigned long long count = 0;
int task_create_hook(unsigned long clone_flags)
  {
  	printk("[+geek] call task_create(). count=%llu\n", ++count);	
  	return 0;
  }
  
  static struct security_operations geek_ops = {
  	.name = "geek",
  	.task_create = task_create_hook,
  };
  
static __init int geek_init(void)
  {
  	printk("[+geek] loading...\n");	
  	if(register_security(&geek_ops)){
  		printk("[+geek] register faild\n");	
  	}
  	return 0;
  }
  
security_initcall(geek_init);
