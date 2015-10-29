
const MAXNAMELEN = 255; /* max length of directory entry */

typedef string nametype<MAXNAMELEN>; /* director entry */

program DEL_PROG{
   version DEL_VERS {
    char DEL(nametype) = 1;
   } = 1;
} = 0x20000076;
