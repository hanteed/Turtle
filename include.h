#ifndef INCLUDE_H
# define INCLUDE_H

char *my_strdup(const char * src);
char *my_strpbrk(char *s1, char *s2);
char * my_strcpy(char * dest, const char * src);
char * my_strdupin(const char * src);
int parse_modif_name(char file[]);
int unzip_file(char *str);
int parse_file_content(char file[]);
int delete_content(char file[]);
int parse_file_links(char file[]);
int edit_link(char file[]);
int parse_creator_name(char file[]);
int parse_modif_name(char file[]);
int parse_creation_date(char file[]);
int parse_modification_date(char file[]);
int edit_modif_name(char file[]);
int find_malwares(int ac, char *av[]);
int check_response_code(char * id, int timeout);
char *get_file_id(char * id, char * API_KEY, char **av);
void titleascii();
void turtleascii();
char * get_api_key(char * API_KEY);
int get_report(char * id);
int menu_choice(int ac, char **av);
void display_menu();
void ascii_display();
int my_strlen(const char *str);
int edit_creator_name(char file[]);
int edit_police_ascii(char file[]);
int edit_police_hAnsi(char file[]);
void delete_pictures();
char *old_image_name(char file[], char *new);
void edit_image();
char *new_picture_name(char *str, char *str2);
char *my_strMin2Maj(char *str);
char *my_strMaj2Min(char *str);

#endif
