const MAXNAMELEN = 255; /* max length of directory entry */

typedef string nametype<MAXNAMELEN>; /* director entry */

struct name{
	nametype old;
	nametype final;
};

program RENAME_PROG{
   version RENAME_VERS {
    char RENAME(name) = 1;
   } = 1;
} = 0x20000076;