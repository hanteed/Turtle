SRC =   src/main.c \
		src/my_unzip.c \
		src/content.c \
		src/date.c \
		src/links.c \
		src/my_string.c \
		src/name.c \
		src/ascii_art.c \
		src/check_reponse.c \
		src/find_malwares.c \
		src/get_api_key.c \
		src/get_file_id.c \
		src/get_report.c \
		src/menu.c \
		src/edit_police.c \
		src/pictures.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wextra

NAME = Turtle

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
	mkdir stock
	mkdir media
	mkdir Save

all:     $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf docProps
	rm -rf stock
	rm -rf media
	rm -rf _rels
	rm -rf word
	touch test.xml
	rm *.xml
	rm -rf Save

zip:
	zip -r editedfile.docx docProps/ media/ _rels/ word/ '[Content_Types].xml'

re:     fclean all
