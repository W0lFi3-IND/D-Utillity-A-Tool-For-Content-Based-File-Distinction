// User-Define Fucnction for Concatination
char* mystrcat(char *dest , char* src)
{ 
	while(*dest) dest++;
	while(*dest++ = *src++);
	return --dest;
}
size_t file_list(const char *path, char ***ls) {
    size_t count = 0;
    size_t length = 0;
    DIR *dp = NULL;
    struct dirent *ep = NULL;

    dp = opendir(path);
    if(NULL == dp) {
        fprintf(stderr, "no such directory: '%s'", path);
        return 0;
    }

    *ls = NULL;
    ep = readdir(dp);
    while(NULL != ep){
        count++;
        ep = readdir(dp);
    }

    rewinddir(dp);
    *ls = calloc(count, sizeof(char *));

    count = 0;
    ep = readdir(dp);
    while(NULL != ep){
        (*ls)[count++] = strdup(ep->d_name);
         
		  ep = readdir(dp);
    }
	

    closedir(dp);
    return count;
}
