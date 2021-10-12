#pragma once

#define MAX_TOKEN_LENGTH 10240

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>

using namespace std;

enum class wordClass
{
    id,
    digit,
    number,
    myChar,
    string,
    operater,
    delimiter,
    keyword,
    empty
};

enum class states
{
    begin,
    id_1,
    digit_1,
    digit_2,
    digit_3,
    digit_4,
    digit_5,
    digit_6,
    opr_1_1, // >, >>, >=, >>=
    opr_1_2, // >, >>, >=, >>=
    opr_2_1, // <, <<, <=, <<=
    opr_2_2, // <, <<, <=, <<=
    opr_3,   // !, !=
    opr_4,   // =, ==
    opr_5,   // |, ||, |=
    opr_6,   // &, &&, &=
    opr_7,   // +, +=, ++
    opr_8,   // -, -=, --
    opr_9,   // ,*, /*=
    opr_10,  // /, /=, //
    opr_11,  // %, %=
    opr_12,  // ^, ^=
    error_state,
    annotation,
    annotation_end,
    string_start,
    char_start,
    string_escape,
    char_escape
};

enum class keywordClass : int
{
    not_key_word = -1,
    keyword_auto,
    keyword_double,
    keyword_int,
    keyword_struct,
    keyword_break,
    keyword_else,
    keyword_long,
    keyword_switch,
    keyword_case,
    keyword_enum,
    keyword_register,
    keyword_typedef,
    keyword_char,
    keyword_extern,
    keyword_return,
    keyword_union,
    keyword_const,
    keyword_float,
    keyword_short,
    keyword_unsigned,
    keyword_continue,
    keyword_for,
    keyword_signed,
    keyword_void,
    keyword_default,
    keyword_goto,
    keyword_sizeof,
    keyword_volatile,
    keyword_do,
    keyword_while,
    keyword_static,
    keyword_if,
    keyword_inline,
    keyword_restrict,
    keyword__Alignas,
    keyword__alignof,
    keyword__Atomic,
    keyword__Bool,
    keyword__Complex,
    keyword__Generic,
    keyword__Imaginary,
    keyword__Noreturn,
    keyword__Static_assert,
    keyword__Therad_local
};

class word
{
public:
    wordClass sign = wordClass::empty;
    long long attribute_num = 0;
    double attribute_digit = 0;
    string attribute_char = ""; //id_operator_delimiter_keyword
};

class location
{
public:
    int line;
    int col;
};

class parser
{
public:
    parser(string _filename)
    {
        filename = _filename;
        file.open(filename, ios::in);
        memset(wordCount, 0, sizeof(int) * 6);
        token[0] = 0;
        loc.line = 0;
        loc.col = 0;
    };
    ~parser()
    {
        file.close();
    };
    ostringstream out;
    location loc;
    int lineCount = 1;
    int charCount = 0;
    int wordCount[8];
    int errorCount = 0;
    string filename;
    ifstream file;
    int fileRenew();
    int countLine();
    int countWord();
    int countChar();
    string parseFile();
    states state = states::begin;
    char C;
    char token[MAX_TOKEN_LENGTH];
    int get_char();
    int get_nbc();
    void cat();
    keywordClass iskey;
    bool letter();
    bool digit();
    void retract();
    keywordClass reserve();
    int SToI();
    double SToF();
    word return_id(wordClass id, char *charArray, location loc);
    word return_id(wordClass id, double digit, location loc);
    word return_id(wordClass id, long long number, location loc);
    word return_id(wordClass id, const char charArray[], location loc);
    void printClass(wordClass id);
};

void printClass(wordClass id);