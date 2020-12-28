/*
 * @Author: TimeTravel
 * @FilePath: /Example/src/demo/opt_demo.c
 * @Date: 2020-12-28 11:00:21
 * @Description: 
 *      how to use getopt_long, 如何设计自己的命令行参数?   
 *      必要知识:  命令行参数可以分为两类，一类是短选项，一类是长选项，短选项在参数前加一杠"-"，长选项在参数前连续加两杠"--"，
 *                其中-a，-A,-b都表示短选项，--all,--almost-all, --author都表示长选项。
 *                他们两者后面都可选择性添加额外参数
 *      主要涉及:
 *          -extern char *optarg;  
 *          -extern int optind, opterr, optopt;
 *          -getopt
 *          -getopt_long
 *          -getopt_long_only
 */

#include <unistd.h>  
#include <getopt.h>
#include <stdio.h>


// struct option 
// {  
//      const char *name;       /*选项的名称*/
//      int         has_arg;    /*该项是否带有参数*/
//      int        *flag;       /*if flag=NULL, return val; if flag!=NULL, return 0*/
//      int         val;        /*表示指定函数找到该选项时的返回值，或者当flag非空时指定flag指向的数据的值val*/
// }; 

//  形式如“a:b::cd:“，分别表示程序支持的命令行短选项有-a、-b、-c、-d，冒号含义如下：
//     (1)只有一个字符，不带冒号——只表示选项， 如-c 
//     (2)一个字符，后接一个冒号——表示选项后面带一个参数，如-a 100
//     (3)一个字符，后接两个冒号——表示选项后面带一个可选参数，即参数可有可无， 如果带参数，则选项与参数直接不能有空格

// 全局变量：
//     1.optarg：表示当前选项对应的参数值。
//     2.optind：表示的是下一个将被处理到的参数在argv中的下标值。
//     3.opterr：如果opterr = 0，在getopt、getopt_long、getopt_long_only遇到错误将不会输出错误信息到标准输出流。opterr在非0时，向屏幕输出错误。
//     4.optopt：表示没有被未标识的选项。


// 返回值：
//     1.如果短选项找到，那么将返回短选项对应的字符。
//     2.如果长选项找到，如果flag为NULL，返回val。如果flag不为空，返回0
//     3.如果遇到一个选项没有在短字符、长字符里面。或者在长字符里面存在二义性的，返回“？”
//     4.如果解析完所有字符没有找到（一般是输入命令参数格式错误，eg： 连斜杠都没有加的选项），返回“-1”
//     5.如果选项需要参数，忘了添加参数。返回值取决于optstring，如果其第一个字符是“：”，则返回“：”，否则返回“？”。

// 注意：
//     1.longopts的最后一个元素必须是全0填充，否则会报段错误
//     2.短选项中每个选项都是唯一的。而长选项如果简写，也需要保持唯一性。

static const char *g_shortopts = "a:id:vc::f:";
static struct option g_long_options[] = {
            {"add",     required_argument, 0,  0 },
            {"append",  no_argument,       0,  0 },
            {"delete",  required_argument, 0,  0 },
            {"verbose", no_argument,       0,  0 },
            {"create",  required_argument, 0, 'c'},
            {"file",    required_argument, 0,  0 },
            {0,         0,                 0,  0 }      /*end*/
};


void opt_demo(int __argc, char* __argv[])
{
    printf("[%s] \n", __FUNCTION__);
    int ret = 0;
    int index = 0;
    
    while ((ret = getopt_long(__argc, __argv, g_shortopts, g_long_options, &index)) != -1) {
        
        switch (ret)
        {
        // 短选项 处理
        case 'a':
            printf("[%s][%s] \n", __FUNCTION__, optarg);
        // 长选项 处理
        case 0:
            printf("[%s][%s] \n", __FUNCTION__, g_long_options[index].name);
            break;
        default:
            break;
        }
    }
}


