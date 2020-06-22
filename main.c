#include <stdio.h>
//MrHaddis
//https://github.com/MrHaddis/PAT1017

int main() {
    //这里肯定是不能用 int long 来接收数字
    //1000位长度的数字 肯定是超过正常定义的大小
    char number[1000];
    int b;
    int resultQ, resultR;
    scanf("%s %d", number, &b);
    resultQ = (number[0] - '0') / b;
    resultR = (number[0] - '0') % b;
    //排除0  和个位数的情况
    if (resultQ != 0 || number[1] == '\0') {
        printf("%d", resultQ);
    }
    for (int i = 1; i < 1000; ++i) {
        if (number[i] != '\0') {
            //取余数*10+后一位 对b算除法
            resultQ = (resultR * 10 + (number[i] - '0')) / b;
            printf("%d", resultQ);
            //计算余数
            resultR = ((resultR * 10 + number[i] - '0')) % b;
        } else {
            break;
        }
    }
    printf(" %d", resultR);
    return 0;
}
