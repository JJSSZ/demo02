#ifndef __demo02_h_
#define __demo02_h_

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

typedef int sldatatype;

typedef struct seqlist
{
    sldatatype* a;
    int size;
    int capacity;
}sl;

void sequence_list_init(sl* ps);                                 //初始化一个顺序表***
void sequence_list_push_back(sl* ps,sldatatype x);               //在顺序表尾部插入一个数据***
void sequence_list_pop_back(sl* ps);                             //在顺序表尾部删除一个数据***
void sequence_list_push_front(sl* ps,sldatatype x);              //在顺序表头部插入一个数据***
void sequence_list_pop_front(sl* ps);                            //在顺序表头部删除一个数据***
void sequence_list_print(sl* ps);                                //打印顺序表的内容***
void sequence_list_destory(sl* ps);                              //释放顺序表内存***
void sequence_list_check_capacity(sl* ps);                       //检查顺序表容量是否足够***
void sequence_list_push_set(sl* ps,int pos,sldatatype x);        //在指顺序表的定位置插入一个数据***
void sequence_list_pop_reset(sl* ps,int pos);                    //删除顺序表指定位置的数据***
void sequence_list_delete_data(sl* ps,sldatatype x);             //删除顺序表中指定的数据x***
void sequence_list_disrepeat(sl* ps);                            //去除顺序表中重复的值***
void sequence_list_add(sl* ps1,sl* ps2);                         //把第二个顺序表加到第一个上面***
void sequence_list_combine(sl* ps1,sl* ps2);                     //二个顺序表求并集***
void sequence_list_diff(sl* ps1,sl* ps2);                        //二个顺序表求差集***
void sequence_list_mutual(sl* ps1,sl* ps2);                      //二个顺序表求交集



int sequence_list_find(sl* ps,sldatatype x);                     //查找数据x在顺序表中的位置***








#endif