#include <cstdio>
#include <cctype>
using namespace std;
int main()
{
	int ch;
	bool in_title, in_word, new_line;
	in_title = true;
	in_word = false;
	new_line = false;
	int count = 0;
	while ((ch = getchar()) != EOF)
	{
		// 换行了，这个词肯定结束了，看下一字符这句话有没有结束
		if (ch == '\n')
		{
			if (in_word)
				count++;
			in_word = false;
			new_line = true;
			continue;
		}
		// 圣经的一句话又开始了，上一句话统计
		// 圣经一句话开始的标志：换行后紧接数字
		if (new_line && isdigit(ch))
		{
			new_line = false;
			in_title = true;
			printf("%d\n", count);
			count = 0;
		}
		// 换行后紧接数字是title要直接输出，碰到空格就要真的开始计数了
		if (in_title)
		{
			putchar(ch);
			if (isspace(ch))
				in_title = false;
			continue;
		}
		// 碰到空格意味着词的结束
		if (in_word && isspace(ch))
		{
			in_word = false;
			count++;
		}
		// 在不是title且不在词内的情况下碰到数字和字母意味着词的开始，不然有个标点你也算成词了
		else if (isalnum(ch))
			in_word = true;
	}
	// 输出最后一句的count
	printf("%d\n", count);
	return 0;
}
/*
// 直接按词来的
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int count;
    string temp;
    bool flag = false;
    while (cin >> temp)
    {
        if (temp[0] == '1' || temp[0] == '2')
        {
            if (flag)
                cout << count << endl;
            count = 0;
            cout << temp << " ";
            flag = true;
        }
        else if (isalpha(temp[0]))
            count++;
    }
    // 补上最后一行话的词数
    cout << count << endl;
    return 0;
}
*/
/*
1:1 10
1:2 31
1:3 11
1:4 22
1:5 19
1:6 19
1:7 26
1:8 20
1:9 25
1:10 27
1:11 30
1:12 35
1:13 11
1:14 41
1:15 21
1:16 33
1:17 15
1:18 26
1:19 11
1:20 25
1:21 33
1:22 29
1:23 11
1:24 34
1:25 36
1:26 50
1:27 21
1:28 49
1:29 33
1:30 37
1:31 24
2:1 13
2:2 31
2:3 31

*/