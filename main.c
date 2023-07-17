#include "sequence_list.h"
#include "windows.h"

void list_text1()
{
    sl sl1,sl2;
    sequence_list_init(&sl1);

    sequence_list_push_back(&sl1,1);
    sequence_list_push_back(&sl1,2);
    sequence_list_push_back(&sl1,3);
    sequence_list_push_back(&sl1,4);
    sequence_list_push_back(&sl1,5);
    sequence_list_push_back(&sl1,5);
    sequence_list_push_back(&sl1,5);

    sequence_list_push_front(&sl1,6);
    sequence_list_push_front(&sl1,6);
    sequence_list_push_front(&sl1,6);
    sequence_list_push_front(&sl1,6);
    sequence_list_push_front(&sl1,7);
    sequence_list_push_front(&sl1,8);
    sequence_list_push_front(&sl1,9);
    sequence_list_push_front(&sl1,9);
    sequence_list_push_front(&sl1,9);
    sequence_list_push_front(&sl1,9);
    sequence_list_push_front(&sl1,9);

    sequence_list_push_set(&sl1,4,10);
    sequence_list_push_set(&sl1,6,20);
    sequence_list_push_set(&sl1,7,30);
    sequence_list_push_set(&sl1,9,40);

    sequence_list_init(&sl2);
    
    sequence_list_push_back(&sl2,-1);
    sequence_list_push_back(&sl2,-2);
    sequence_list_push_back(&sl2,-3);
    sequence_list_push_back(&sl2,-4);
    sequence_list_push_back(&sl2,-5);
    sequence_list_push_back(&sl2,-5);
    sequence_list_push_back(&sl2,-5);
    
    // sequence_list_pop_front(&sl1);

    // sequence_list_pop_back(&sl1);

    // sequence_list_pop_reset(&sl1,5);

    // sequence_list_delete_data(&sl1,7);

    // sequence_list_disrepeat(&sl1);

    sequence_list_add(&sl1,&sl2);

    // sequence_list_diff(&sl1,&sl2);

    sequence_list_mutual(&sl1,&sl2);


    
    sequence_list_print(&sl1);
    sequence_list_print(&sl2);
    sequence_list_destory(&sl1);
}



int main(int argc, char const *argv[])
{
    list_text1();
    system("pause");
    return 0;
}
