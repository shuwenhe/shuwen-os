#include <stdio.h>
#include <string.h>

int next[32] = {-999};

void get_next(char *T, int *next)
{
    int k = -1, j = 0;
    next[j] = k;

    while (j < strlen(T)){
        if ((k == -1) || (T[j] == T[k])){
            ++k;
            ++j;
            next[j] = k;
        }else
				  k = next[k];
    }
}

int index_kmp(char *S, char *T, int pos)
{
    int i = pos, j = 0;

    while((i < strlen(S)) && (j < strlen(T)) ){
        if ((j == -1) || S[i] == T[j]){
					i++;
					j++;
        }else
					j = next[j];
    }

    if (strlen(T) == j)
        return i - strlen(T);
    else
        return -1;
}

void print_next(int next[], int n)
{
   int i;

   for (i = 0; i < n; i++)
       printf("next[%d] = %d\n", i, next[i]);
}

int main(void)
{
    char *s = "ababcabcacbab";
    char *t = "abcac";
    int pos = 0;
    int index;

    printf("kmp\n");
    get_next(t, next);
    print_next(next, strlen(t));

    index = index_kmp(s, t, pos);
    printf("index = %d\n", index);
}
