#include <rpc/rpc.h>
#include <sys/dir.h>
#include "dir.h"
#include <stdlib.h>
extern int err;
extern char *strdup();
readdir_res *
//readdir_1_svc(dirname)
//nametype *dirname;
readdir_1_svc(nametype *dirname, struct svc_req *req)
{
DIR *dirp;
struct direct *d;
namelist nl;
namelist *nlp;
static readdir_res res; /*
must be static
!*/
/*
* Open directory
*/
dirp = opendir(*dirname);
if (dirp == NULL) {
res.err = err;
return (&res);
}
/*
* Free pre vious result
*/
xdr_free((xdrproc_t)xdr_readdir_res,(char *) &res);
/*
* Collect directory entries.
* Memory allocated here will be freed by xdr_free
* next time readdir_1 is called
*/
nlp = &res.readdir_res_u.list;
while (d = readdir(dirp)) {
nl = *nlp = (namenode *) malloc(sizeof(namenode));
nl->name = strdup(d->d_name);
nlp = &nl->next;
}
*nlp = NULL;
/*
* Return the result
*/
res.err = 0;
closedir(dirp);
return (&res);
}