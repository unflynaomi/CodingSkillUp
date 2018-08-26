#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <typeinfo>
using namespace std;
/*阿里妈妈广告直通车是一个基于关键词(比如，“连衣裙”，“手机”)的竞价营销平台，商家在后台可以设置参与竞价的关键词。已知历史上所有关键词，和它的受欢迎程度(提前量化为1-99的数字，数值越大越受欢迎)。现在希望提供一个功能：当商家完成关键词录入之后，按热度倒序排列的相似关键词。
 假设：
 1. 当且仅当文字完全一致而顺序不同的关键词相似，比如“连衣裙”和“衣裙连”相似；
 2. 关键词采用GBK编码，内存可以放下所有历史关键词，需要对历史关键词做预处理，加快检索过程；
 请使用标准输入输出(System.in , System.out)；已禁用图形、文件、网络、系统相关的操作，如java.lang.Process , javax.swing.JFrame , Runtime.getRuntime；不要自定义包名称，否则会报错，即不要添加package answer之类的语句；您可以写很多个类，但是必须有一个类名为Main，并且为public属性，并且Main为唯一的public class，Main类的里面必须包含一个名字为'main'的静态方法（函数），这个方法是程序的入口
 时间限制: 3S (C/C++以外的语言为: 5 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
 输入:
 输入包含两个参数：历史关键词列表和查询关键词；历史关键词列表的每一项被空格分割为两段，左半部分为真正的关键词，右半部分为受欢迎程度；
 输出:
 输出相似关键词列表，每一项被空格分割为两段，左半部分为真正的关键词，右半部分为受欢迎程度；
 输入范例:
 历史关键词列表范例：
 连衣裙 99
 衣裙连 10
 苹果 80
 手机 90
 
 查询关键词范例：
 连衣裙
 输出范例:
 连衣裙 99
 衣裙连 10
 */
void print(int num){
    
    cout<<num<<" "<<endl;
}

bool compare(int a,int b)
{
    return a<b;   //升序排列，如果改为return a>b，则为降序
    
}

//template <class T1, class T2, class Pred = std::less<T2> >
//struct sort_pair_second {
//    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
//        Pred p;
//        return p(left.second, right.second);
//    }
//};
bool judge(const pair<string,int> a, const pair<string ,int> b) {
    return a.second>b.second;
}
int get_gbk_sum(string str){
     int len=(int)str.size();
    int sum=0;
    for (int i=0; i<len; i++) {
        sum+=(int)str[i];
    }
    return sum;
}

int main()
{

    vector<pair<string,int>> data2;
    vector<pair<int ,int>> data1;

//    string name;
//    int price;
//    while (scanf("%*s %d",&name,&price)!=EOF) {
//        data2.push_back(make_pair(name, price));
//    }
//    string user_name;
//    cin>>user_name;
    //我控制台不能输入中文，注释部分是实现从控制台输入，用在线编辑器测试的，用的时候把下面的注释掉
    string user_name="连衣裙";
    string user_name2="衣连裙";

    data2.push_back(make_pair<string,int>("连衣裙", 99));
    data2.push_back(make_pair<string,int>("衣连裙", 10));
    data2.push_back(make_pair<string,int>("苹果", 80));
    data2.push_back(make_pair<string,int>("手机", 90));
    //注释到这里就行了
    
//    cout<<name1<<endl;
//    regex r("*连*衣*裙*");  regex_match(data2[i].first, r)
    
    sort(data2.begin(),data2.end(), judge);
    for(auto i=0;i<data2.size();i++){
        
        if (get_gbk_sum(data2[i].first)==get_gbk_sum(user_name)) {
            cout<<data2[i].first<<" "<<data2[i].second<<endl;
        }
    }
    
}
/*
    这题我总结下，思路有5种：1、就是我发的这种 ，大致就是我用了一个pair的vector进行存储，然后拿到你要搜索的关键字，
    用gbk编码格式编译，得到其字符的encode码，相同的汉字对应的码号是一样的，类似ASCII码中A-33，B-34，然后，去搜原来的存储空间，变成查找问题了，这里可以优化速度，我没有优化，我想测试其他的方式；2、用正则匹配去做，但是存在字个数不同需要控制的情况；3、走偏路，把查找的字符串全部组合罗列一个数组然后去匹配，这种也是没办法的办法。4、用Python的dict做，dict和顺序是无关的，只和出现的字和出现字数相关，比如你输入: 今天天气真的好好啊 那么dict[今] = 1, dict[天] = 2,.....。之后无论你输入 天气真的好好啊今天，都能算出来很相似。但是奈何人家不用Python。5、JAVA的今天没做完，不好说能不能整出来，理论上也是可以的，就是效率不知道咋样，弄出来给个结论。

*/
