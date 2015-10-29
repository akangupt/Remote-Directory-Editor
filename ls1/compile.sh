gcc rls.c dir_clnt.c dir_xdr.c -o client
gcc dir_svc.c dir_proc.c dir_xdr.c -o server
