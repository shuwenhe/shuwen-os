#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char tmpname[L_tmpnam]; // #define	L_tmpnam	1024	/* XXX must be == PATH_MAX */
    char *filename;
    FILE *tmpfp;
    
    filename = tmpnam(tmpname); // char	*tmpnam(char *); 返回文件名
    printf("filename = %s\n",filename);

    tmpfp = tmpfile(); // FILE	*tmpfile(void);
    if (tmpfp)
        printf("Opened a temporary file OK!\nm");
    else
        perror("tmpfile");
    exit(0);
}