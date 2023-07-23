#define _CRT_SECURE_NO_WARNINGS 1

//leetcode:	20. ÓÐÐ§µÄÀ¨ºÅ
//bool isValid(char* s) {
//    if (strlen(s) % 2 == 1)
//        return false;
//    ST ps;
//    STInit(&ps);
//
//    while (*s)
//    {
//        if (*s == '(' || *s == '[' || *s == '{')
//        {
//            STPush(&ps, *s);
//        }
//        else
//        {
//            if (ps.top == 0)
//            {
//                STDestroy(&ps);
//                return false;
//            }
//            char top = STTop(&ps);
//            STPop(&ps);
//
//            if ((*s == ')' && top != '(')
//                || (*s == '}' && top != '{')
//                || (*s == ']' && top != '['))
//            {
//                return false;
//            }
//        }
//        ++s;
//    }
//
//    if (ps.top)
//    {
//        STDestroy(&ps);
//        return false;
//    }
//    else
//    {
//        STDestroy(&ps);
//        return true;
//    }
