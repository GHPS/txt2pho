 PREPROC 0.2.4 USER MANUAL

(c) Thomas Portele, IKP, University of Bonn, 10.2.1998
1. GENERAL INFORMATION

PREPROC was written by Thomas Portele as a flexible text preprocessing tool for speech synthesis applications. PREPROC reads input from a text file, performs some conversions and writes the result to a text file.

The conversions are done in three steps. In the first step a rule set is used to determine whether a conversion should be applied to a token (any string between spaces is a token). In the second step, a token can be replaced by another token due to an exchange table (this is mainly used for abbreviations). In the third step conversion functions are applied to tokens marked in the first step as to be processed.

The rule set and the abbreviation list are loaded on run time (and can be changed by special tags in the input stream). The conversion functions, however, are hard-coded, and new functions must be compiled in the program.

PREPROC currently reads from stdin and writes to stdout. Two parameters must appear in a call. The first one is the name of the rule set, the second one the name of the abbreviation list (if no second parameter is given, no token replacements are performed).
2. INPUT

The input stream is separated into tokens. A token is every sequence of non-space characters between spaces. A space is NEWLINE, TAB and SPACE. Zero characters work like EOF markers. Tokens are separated by SPACE in the output of the input routine. The input class PPInput can be called with a list of characters which will be treated as separate tokens. Currently, only brackets are treated this way. A sequence "a(b)c" will thus become "a ( b ) c". The input is read with a lookahead of one token.
3. RULES

The rule file is line-oriented. Every rule occupies one line. The rule format is given below. The rules are processed from top to bottom; more specific rules should precede more general ones.

A rule file can be exchanged by another rule file when the sequence {UsePreprocRules:<name_of_new_rule_file>} is found in the input, where <name_of_new_rule_file> must be the name of the new rule file. Thus, application-oriented preprocessing (e.g. letter heads) is possible.

A line with length 0 or with a leading '#' is treated as a comment.
4. RULE FORMAT

A rule file consists of two parts. The first part is the character set definition. A character set is defined by a line in the format

<character_in_rule_string>: <characters_in_input_string>*

where <character_in_rule_string> is treated in the rules as a class identifier that can be any character of <characters_in_input_string>. Example:

Z: 0123456789

After the keyword "Rules:" at the beginning of a line the rules start. They have the general format

<target> <context> AS <function>

<target> is a string of <character_in_rule_string> with these modifiers:

* implies one to n occurences of the preceding <character_in_rule_string>

[X] implies one to n occurences of the <character_in_rule_string>s between the square brackets

<context> can be one or more <context_constraints>.
A <context_constraint> has the form

BEFORE|AFTER <string_of_character_in_rule_string>|<tokenlist> IN <word_scope>

where BEFORE|AFTER indicates where the context should be found relative to the token. The context can be either a string of <character_in_rule_string> or a sequence of tokens between ' and separated by , , e.g. 'dem,den'. IN <word_scope> is optional; <word_scope> is a number followed by the keyword WORDS. This indicate how many words are investigated. More than one word can only be used with AFTER. If IN <word_scope> is missing, one word is the default value.

<function> is the name of a function (see 6.)

Examples can be found in the file "Rules.lst"
5. ABBREVIATIONS

The abbreviation list file is line-oriented. It has the general format <target sequence>TAB<new sequence>NEWLINE. A target is every character from the beginning of a line to the TAB (0x09) character. The new sequence is every character (including SPACE) from the TAB to the end of the line.

A token is matched with each target in the list. It is replaced by the new sequence.
6. REPLACEMENT FUNCTIONS

The replacement functions are coded in the source code file PPFuncts.cc. They have the format "char* FUNCTION_NAME(char* in)" and replace the input in the parameter "in" with appropriate output. If "in" is not returned, it should be deleted.

The functions must be defined in the header file PPFuncts.h.

The functions must be called in the method "call" defined in PPFnclst.cc using the EXECUTE(FUNCTION_NAME) macro with FUNCTION_NAME the name of the function.

Currently, the following functions for German are implemented:

extern char* single_numbers(char* in) ; 
 extern char* numeral(char* in) ; 
 extern char* phone_number_prefix(char* in) ; 
 extern char* international_phone_prefix(char* in) ; 
 extern char* phone_number(char* in) ; 
 extern char* money_post(char* in) ; 
 extern char* money_pre(char* in) ; 
 extern char* money_no_change(char* in) ; 
 extern char* time(char* in) ; 
 extern char* time_before_Uhr(char* in) ; 
 extern char* ordinal_fem(char* in) ; 
 extern char* ordinal_neutr(char* in) ; 
 extern char* ordinal_dativ(char* in) ; 
 extern char* short_date(char* in) ; 
 extern char* short_date_flex(char* in) ; 
 extern char* full_date(char* in) ; 
 extern char* full_date_flex(char* in) ; 
 extern char* version(char* in) ; 
 extern char* real_number(char* in) ; 
 extern char* real_number_with_point(char* in) ; 
 extern char* email(char* in) ; 
 extern char* http_address(char* in) ; 
 extern char* computer_address(char* in) ; 
 extern char* unit(char* in) ; 
 extern char* divide(char* in) ; 
 extern char* equals(char* in) ; 
 extern char* minus(char* in) ; 
 extern char* plus(char* in) ; 
 extern char* sign(char* in) ; 
 extern char* percent(char* in) ; 
 extern char* ando(char* in) ; 
 extern char* dollar(char* in) ; 
 extern char* at(char* in) ; 
 extern char* bracket(char* in) ; 
 extern char* colon_numbers(char* in) ; 
 extern char* arithmetic(char* in) ; 
 extern char* short_date_before_point(char* in) ; 
 extern char* short_date_flex_before_point(char* in) ; 
 extern char* full_date_before_point(char* in) ; 
 extern char* full_date_flex_before_point(char* in) ; 
 extern char* word_before_point(char* in) ; 
 extern char* numeral_before_point(char* in) ; 
 extern char* real_number_before_point(char* in) ; 
 extern char* colon_numbers_before_point(char* in) ;

7. OUTPUT

The output is written token by token to the output file (currently stdout).
