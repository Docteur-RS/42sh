#ifndef PARSER_42SH_H_
# define PARSER_42SH_H_

void		char_print(char);
void		string_print(char *);
char		*string_espacewords(char *, char *, char *, unsigned int);
int		string_espacewords_length(char *, char *, char *, unsigned int);
unsigned int	string_length(char *);
char		*string_copy(char *);
char		*string_copy_define(char *, char *);
char		*string_search_define(char *, char  *);
int		string_compare(char *, char *, int);
char		*string_search(char *, char *);
char		*string_replace(char *, char *, char *, char *);
char		*parser_eliminate_keywords_with_spaces(char *);
char		*parser_add_spaces(char *, unsigned int);
char		*parser_add_spaces_word(char);
int		parser_step1(char *);
char		**parser_start(char *);
int		parser_spaces_tabulations_count_less(char *);
char		*parser_spaces_tabulations_create_less(char *, int, int);
char		*parser_add_spaces_before_after(char *);
char		*command_copy_special_command(char *);
char		*commands_copy_special(char *, char *);
void		parser_free_char_star_star(char **);
char		**commands_keywords_extract_create(char *);
int		commands_keywords_extract_count(char *);
void		aff_struct(char **);
int		command_analyse(char **);
void		command_delete_caracter_alone(char **);
int		command_line_is_a_command(char *);
int		command_analyse_message(char);
int		commands_keywords_write(char *, char **);

#endif /* !PARSER_42SH_H_ */
