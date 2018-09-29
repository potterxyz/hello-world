//
//  main.cpp
//  Stack
//
//  Created by MacBook on 2018/9/25.
//  Copyright © 2018 MacBook. All rights reserved.
//

#include "Stack.h"
#include <stdio.h>
int main(){
    SeqStack N,O;
    initStack(N);
    initStack(O);
    int i=0,result=0,topOptPriority,tokenPriority;
    char ch,ch1,right,left;
    /*while(scanf("%c",&in[i])!=EOF){
        i++;
    }*/
    const char in[100]="5+3+2#";
    Push(O,'#');
    
    
    topOptPriority=isp(in[1]); //栈外元素的优先级
    printf("%d\n",topOptPriority);
    Pop(O,ch);
    tokenPriority=icp(ch);
    printf("%d\n",tokenPriority);
    
    
    
    
    
    for(i=0;i<6;i++)
    {
        if(in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'||in[i]=='#')
        {
            if(O.elem[O.top]=='#'&&i==5)
            {
                //result=Pop(N,N.top);
                break;
            }
            else
            {
                ch=O.elem[O.top];
                printf("~~~\n");
                topOptPriority=isp(ch);
                tokenPriority=icp(in[i]);
                if(tokenPriority>topOptPriority)
                {
                    printf("!!!\n");
                    Push(O,in[i]);
                }
                else
                {
                    //ch1=Pop(O);
                    //right=Pop(N);
                    //left=Pop(N);
                    Push(N,DoOperator(ch1,right,left));
                    printf("@@@\n");
                }
            }
        }
        else if(in[i]=='(')
        {
            Push(O,in[i]);
        }
        else if(in[i]==')')
        {
            while(O.elem[O.top]!='('){
                //ch1=Pop(O);   //一直在执行退栈，直到栈顶字符为'('
                //right=Pop(N);
                //left=Pop(N);
                Push(N,DoOperator(ch1,right,left));
            }
           // Pop(O);
        }
        else
        {
            Push(N,in[i]);
            printf("###\n");
        }
    }
    printf("%d\n",result);
    return 0;
}












