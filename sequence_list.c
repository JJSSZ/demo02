#include "sequence_list.h"

/****初始化一个顺序表****/
void sequence_list_init(sl* ps)
{
    ps->a = NULL;
    ps->capacity = 0;
    ps->size = 0;
}

/****检查顺序表容量是否足够****/
void sequence_list_check_capacity(sl* ps)
{
    if(ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 8 : ps->capacity + 8;
        sldatatype* tem = (sldatatype* )realloc(ps->a,newcapacity*sizeof(sldatatype));
        if(tem == NULL)
        {
            exit(-1);
        }
        ps->a = tem;
        ps->capacity = newcapacity;
    }
}

/****打印顺序表的内容****/
void sequence_list_print(sl* ps)
{
    for(int i = 0;i < ps->size;i++)
    {
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}

/****在顺序表尾部插入一个数据x****/
void sequence_list_push_back(sl* ps,sldatatype x)
{
    sequence_list_push_set(ps,ps->size,x);
}

/****删除顺序表尾部的一个数据****/
void sequence_list_pop_back(sl* ps)
{
    sequence_list_pop_reset(ps,ps->size - 1);
}

/****释放顺序表内存****/
void sequence_list_destory(sl* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->capacity = 0;
    ps->size = 0;
}

/****在顺序表头部插入一个数据****/
void sequence_list_push_front(sl* ps,sldatatype x)
{
    sequence_list_push_set(ps,0,x);
}

/****删除顺序表头部一个数据****/
void sequence_list_pop_front(sl* ps)
{

    sequence_list_pop_reset(ps,0);
}

/****查找数据x在顺序表中的位置****/
int sequence_list_find(sl* ps,sldatatype x)
{
    for (int i = 0; i < ps->size; i++)
    {
        if(ps->a[i] == x)
        {
            return i;
        }
    }
    return NULL;
}

/****在指定的位置（pos）插入一个数据x****/
void sequence_list_push_set(sl* ps,int pos,sldatatype x)
{
    assert (pos <= ps->size && pos >= 0);
    sequence_list_check_capacity(ps);
    int end = ps->size - 1;
    while(end >= pos)
    {
        ps->a[end + 1] = ps->a[end];
        -- end;
    }
    ps->a[pos] = x;
    ps->size ++;
}

/****删除指定位置（pos）的数据****/
void sequence_list_pop_reset(sl* ps,int pos)
{
    assert (pos < ps->size + 1 && pos > 0);
    int begin = pos ;
    while (begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin];
        ++ begin;
    }
    ps->size --;
}

/****删除顺序表中的指定数据x****/
void sequence_list_delete_data(sl* ps,sldatatype x)
{
    int k,i = 0;
    while (i <= ps->size)
    {
        k = sequence_list_find(ps,x) + 1;
        if (k != 0)
        {
            sequence_list_pop_reset(ps,k);
        }
        i++;
    }
}

/****去除顺序表中重复的元素****/
void sequence_list_disrepeat(sl* ps)
{
    if (ps->size == 0)
    {
        return ;
    }
    int k;
    sl* dst = ps;

    for(int j = 0; j < dst->size - 1; j++)
    {
        dst = ps;
        k = j + 1;
        for(int i = j + 1; i < dst->size; i++)
        {
            if(dst->a[i] != ps->a[j] )
            {
                ps->a[k++] = dst->a[i];
            }
        }
        ps->size = k;
    }
    ps = dst;
}

/****把第二个顺序表加到第一个上面****/
void sequence_list_add(sl* ps1,sl* ps2)
{
    for (int i = 0; i < ps2->size; i++)
    {
        sequence_list_push_back(ps1,ps2->a[i]);
    }
}

/****二个顺序表求并集****/
void sequence_list_combine(sl* ps1,sl* ps2)
{
    sequence_list_add(ps1,ps2);
    sequence_list_disrepeat(ps1); 
}

/****二个顺序表求差集****/
void sequence_list_diff(sl* ps1,sl* ps2)
{ 
    for(int i = 0; i < ps1->size; i++)
    {
        for(int j = 0;j < ps2->size; j++)
        {
            if (ps1->a[i] == ps2->a[j])
            {
                sequence_list_pop_reset( ps1, i + 1);
            }
        }
    }
    
}

/*二个顺序表求交集*/
void sequence_list_mutual(sl* ps1,sl* ps2)
{
    int pos;
    for(int i = 0; i < ps1->size; i++)
    {
        for (int j = 0; j < ps2->size; j++)
        {
            pos = sequence_list_find(ps1,ps2->a[j]);
            if (pos == NULL)
            {
                sequence_list_pop_reset( ps2, j );
            }
            else
            {
                break;
            }
        }
    }
}















