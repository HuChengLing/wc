#include<stdlib.h>
#include<stdio.h>
#include<string>
#include <ctype.h>//为isspace()提供原型
#include <stdbool.h>
#include<iostream>
void signalcount(char *Filename);
void main()
{

	int c = 0, w = 0, l = 0;
	int signline = 0;
	FILE *fp;
	char fileName[80];
	char ch[1024];
	//bool inword = false;//字符在单词中,inward等于ture
	printf("please input fileName:");
	gets_s(fileName);
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		printf("can't open file %s\n", fileName);
		getchar();
		exit(1);
	}
	while (!feof(fp))
	{
		fgets(ch, 1024, fp);
		l++;
		int length = strlen(ch);
		for (int i = 0; i < length; i++)
		{
			//判断是不是空格不是的话在while里面i++执行判断到下一个空格的出现或是结束  
			if (ch[i] != ' ')
			{
				w++;
				//if ((ch[i] > '0'&&ch[i]<'9' || ch[i]>'a'&&ch[i], 'z' || ch[i] > 'A'&&ch[i] < 'Z') && ch[i] != ' ')
					//c++;
				while (ch[i] != ' '&&ch[i] != '\0')
				{

					if ((ch[i] > '0'&&ch[i]<'9' || ch[i]>'a'&&ch[i], 'z' || ch[i] > 'A'&&ch[i] < 'Z') && ch[i] != ' '&&ch[i] != '\n')
						c++;
					i++;

				}
			}


		}
		/*{
			int len = 0, i = 0;
			int signline = 0;
			fgets(ch, sizeof(ch), fp);
			len = strlen(ch);
			for (i = 0; i < len; i++)
			{
				if ((ch[i] == '/'&&ch[i + 1] == '/') || (ch[i] == '/'&&ch[i + 1] == '*'))
				{
					signline++;
					break;
				}
			}
			}


		}*/
		printf("一共有:%d行 %d个单词 %d个字符", l, w, c);
		signalcount(fileName);
		fclose(fp);
		system("pause");
	}
}

void signalcount(char *filename)
{
	int len = 0, i = 0,signline = 0;
	FILE *fp;
	char str[1000];
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf( "请在文件中添加内容\n") ;
		exit(-1);
	}
	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);
		len = strlen(str);
		for (i = 0; i<len; i++)
		{
			if ((str[i] == '/'&&str[i + 1] == '/') || (str[i] == '/'&&str[i + 1] == '*'))
			{
				signline++;
				break;
			}
		}
	}
	fclose(fp);
	printf( "注释行数%d行\n", signline);
}