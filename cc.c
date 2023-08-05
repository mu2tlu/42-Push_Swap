/// eğer 0 -0 +0 değilse ve atoi 0 dönüyorsa demekki gerçekten 0 değil

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%d\n",atoi("-+12321q"));
    printf("%d\n",atoi("+-231a"));
    printf("%d\n",atoi("--231a"));
    printf("%d\n",atoi("--231a"));
}
