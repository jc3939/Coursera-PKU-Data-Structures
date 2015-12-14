#include <cstdio>
#include <cstring>

const int maxn = 1000000 + 10;
char p[maxn];
int n, next[maxn];

void get_next()
{
    int k = -1, j = 0;
    next[0] = -1;
    while(j < n)
    {
        if(k == -1 || p[k] == p[j])
        {
            k++;
            j++;
            next[j] = k;
        }
        else k = next[k];
    }
}

int main(void)
{
    //freopen("1358in.txt", "r", stdin);
    int kase = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        memset(next, 0, sizeof(next));
        scanf("%s", p);
        getchar();
        get_next();
        
        printf("Test case #%d\n", ++kase);
        for(int i = 2; i <= n; ++i)
        {
            if(next[i] == 0) continue;
            int cir = i - next[i];
            if(i % cir == 0)
                printf("%d %d\n", i, i / cir);
        }
        puts("");
    }

    return 0;
}