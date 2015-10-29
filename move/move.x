const MAXNAMELEN = 255; /* max length of directory entry */

typedef string nametype<MAXNAMELEN>; /* director entry */

struct name{
	nametype old;
	nametype final;
};

program MOVE_PROG{
   version MOVE_VERS {
    char MOVE(name) = 1;
   } = 1;
} = 0x20000076;