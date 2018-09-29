//
//  Header.h
//  Stack
//
//  Created by MacBook on 2018/9/25.
//  Copyright © 2018 MacBook. All rights reserved.
//

//
//  SeqStack.hpp
//  blabla
//
//  Created by MacBook on 2018/9/24.
//  Copyright © 2018年 MacBook. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define initSize 100
#define increment 20
typedef char SElemType;
typedef int AElemType;
typedef struct{
    SElemType *elem;
    AElemType *number;
    int maxSize,top;
}SeqStack;
void initStack(SeqStack& S){  //初始化
    S.elem=(SElemType*)malloc(initSize*sizeof(SElemType));
    S.maxSize=initSize; S.top=-1;
}
bool stackEmpty(SeqStack& S){    //判断栈空
    return S.top==-1;
}
bool stackFull(SeqStack& S){  //判断栈满
    return S.top==S.maxSize-1;
}

void overFlow(SeqStack& S){       //栈满处理
    int newSize=S.maxSize+increment;
    SElemType *newS=(SElemType *)malloc(newSize*sizeof(SElemType));
    for(int i=0;i<S.top;i++)
        newS[i]=S.elem[i];
    free(S.elem);
    S.elem=newS;
    S.maxSize=newSize;
}
void Push(SeqStack& S,SElemType x){    //若栈不满，则新元素进栈
    if(stackFull(S))overFlow(S);
    S.top++;
    S.elem[S.top]=x;
}
bool Pop(SeqStack &S,SElemType &x)
{
    if(stackEmpty(S))return false;
    x=S.elem[S.top];S.top--;
    return true;
}
int isp(char op){
    if(op=='+'||op=='-') return 3;
    else if(op=='#') return 0;
    else if(op=='(') return 1;
    else if(op=='*'||op=='/') return 5;
    else if(op==')') return 6;
    else return 0;
}
int icp(char op){
    if(op=='+'||op=='-') return 2;
    else if(op=='#') return 0;
    else if(op=='(') return 6;
    else if(op=='*'||op=='/') return 4;
    else if(op==')') return 1;
    else return 0;
}

char DoOperator(char op,char right,char left){     //从操作数栈OPND中取两个操作数，根据操作符op形成运算指令并计算
    char result;
    right=right-'0';
    left=left-'0';
    switch(op){
        case'+':result=left+right;break;
        case'-':result=left-right;break;
        case'*':result=left*right;break;
        case'/':result=left/right;break;
    }
    return result;
}

bool getTop(SeqStack &S,SElemType &x)
{
    if(stackEmpty(S))return false;
    x=S.elem[S.top];
    return true;
}
















