#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){ // argc程序参数个数；argv参数自身的字符串数组
	int arg;

	for(arg = 0; arg < argc; arg++){
		if (argv[arg][0] == '-') // 0检查首字母是否是短横线来发现选项
			printf("option:%s\n",argv[arg]+1);
		else
			printf("argument %d: %s\n", arg, argv[arg]); // arg参数个数
	}
	exit(0);
}
