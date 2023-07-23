#include"Stack.h"

void test1()
{
    ST ps;
    STInit(&ps);

    STPush(&ps, 1);
    printf("%d ", STTop(&ps));
    STPop(&ps);

    STPush(&ps, 2);
    STPush(&ps, 3);
    printf("%d ", STTop(&ps));
    STPop(&ps);

    STPush(&ps, 4);
    STPush(&ps, 5);
    printf("%d ", STTop(&ps));
    STPop(&ps);

    while (!STEmpty(&ps))
    {
        printf("%d ", STTop(&ps));
        STPop(&ps);
    }


    STDestroy(&ps);

}

//错误解题
//bool isValid(char* s) {
//    ST ps;
//    STInit(&ps);
//
//    int i = 0;
//    STPush(&ps, s[i]);
//    i++;
//    int tmp = 0;
//
//    while (s[i])
//    {
//        if((&ps)->top != 0)
//            tmp = STTop(&ps);
//
//        switch (s[i])
//        {
//            //case '{':
//            //case '[':
//            //case '(':
//            //    break;
//            case '}':
//                if (tmp == '{')
//                    STPop(&ps);
//                break;
//            case ']':
//                if (tmp == '[')
//                    STPop(&ps);
//                break;
//            case ')':
//                if (tmp == '(')
//                    STPop(&ps);
//                break;
//            default:
//                STPush(&ps, s[i]);
//                break;
//        }
//        i++;
//    }
//
//    if ((&ps)->top)
//        return false;
//    else
//        return true;
//}

int main()
{
    //test1();

    //char arr[] = "(){}";

    //bool tmp = isValid(&arr);
    //printf("%d ", tmp);

    return 0;
}