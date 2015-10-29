/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rename.h"

bool_t
xdr_nametype (XDR *xdrs, nametype *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, MAXNAMELEN))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_name (XDR *xdrs, name *objp)
{
	register int32_t *buf;

	 if (!xdr_nametype (xdrs, &objp->old))
		 return FALSE;
	 if (!xdr_nametype (xdrs, &objp->final))
		 return FALSE;
	return TRUE;
}
