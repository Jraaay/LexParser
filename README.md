# LexParser

这是一个 C 语言的词法分析器

## 题目

> 词法分析程序的设计与实现

> 实验内容:设计并实现 C 语言的词法分析程序,要求实现如下功能。

-   [x] 可以识别出用 C 语言编写的源程序中的每个单词符号,并以记号的形式输出每个单词符号。
-   [x] 可以识别并跳过源程序中的注释。
-   [x] 可以统计源程序中的语句行数、各类单词的个数、以及字符总数,并输出统计结果。
-   [x] 检査源程序中存在的词法错误,并报告错误所在的位置。
-   [x] 对源程序中岀现的错误进行适当的恢复,使词法分析可以继续进行,对源程序进行一次扫描,即可检査并报告源程序中存在的所有词法错误。

## 用法
```
.\LexParser.exe <file_to_parse_name> [outfile_name]
```

## 支持情况

-   [x] 标识符

|     |     |     |     |        |
| :-: | :-: | :-: | :-: | :----: |
| a-z | A-Z | 0-9 | \_  | 关键词 |

-   [x] 注释

|          |          |
| :------: | :------: |
| 单行注释 | 多行注释 |

-   [x] 运算符

|     |      |     |     |
| :-: | :--: | :-: | :-: |
|  >  |  >>  | >=  | >>= |
|  >  |  >>  | >=  | >>= |
|  <  |  <<  | <=  | <<= |
|  <  |  <<  | <=  | <<= |
|  !  |  !=  |  =  | ==  |
|  /  |  /=  | \*  | \*= |
|  %  |  %=  |  ^  | ^=  |
| \|  | \|\| | \|= |  ?  |
|  &  |  &&  | &=  |
|  +  |  +=  | ++  |
|  -  |  -=  | --  |

-   [x] 常量

|        |      |        |      |
| :----: | :--: | ------ | ---- |
| 浮点数 | 整数 | 字符串 | 字符 |

-   [x] 分界符

|     |     |     |     |     |
| :-: | :-: | :-: | :-: | :-: |
|  ;  |  ,  |  :  |  .  |  #  |
| [ ] | ( ) | { } | < > |
