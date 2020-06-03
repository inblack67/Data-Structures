#include<stdio.h>

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void strUpper(char *t){
    while (*t) {
        if(*t >= 'a' && *t <= 'z'){
            *t -= 32;
        }
        t++;
    }
}

void strReverse(char *t){
    char *l = t;
    while (*--l) {
        l++;
    }
    while (t < l) {
        swap(t, l);
        t++;
        l--;
    }
}

int isNumeric(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int customATOI(char *str){
    
    int sign = 1, i = 0, result = 0;
    
    if(str[0] == '-'){
        sign = -1;
        i++;
    }
    
    for(; str[i] && isNumeric(str[i]); i++){
        result = (result * 10) + (str[i] - '0');
    }
    
    return result * sign;
}
    
int main()
{
    char str[] = "12";
    
    printf(" %d\n ", customATOI(str) + 1);
    
//    char t2[] = { 'A', 'M', 'A', 'N' };
//    printf("%s", t);
//    printf("\n");
//    for (int i = 0; i < sizeof(t2)/sizeof(char); i++) {
//        printf("%c", t2[i]);
//    }
//    printf("\n");
//    int size = sizeof(t);
//    printf("%d\n", size);
//    printf(" %s ", t);
//    strUpper(t);
//    printf("\n");
//    printf(" %s ", t);
//    printf(" %s ", t);
//    printf("\n");
//    strReverse(t);
//    printf(" %s ", t);
//    printf("\n");
    
    
    return 0;
}
