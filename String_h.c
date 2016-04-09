#define <stdio.h>

void *mem_chr(const void*, int, size_t);
int mem_cmp(const void*,const void*,int);
void *mem_cpy(const void*, const void*, int);
void *mem_set(void *,int, size_t);
char *str_cat(char*, const char*);
char *str_chr(char*, int);

void main()
{
    char cad[31];
    int carc;
    puts("\t\tIngrese cadena:\n\n\t\t");
    gets(cad);
    puts("\n\n\t\tIngrese caracter a buscar en cadena:\n\t\t\t");
    scanf("%d",&carc);
    printf("%s\n\n\t", mem_chr(cad,carc,sizeof(cad)));
}

void *mem_chr(const void *s, int c, size_t n)
{
    while((unsigned char)*s != (unsigned char)c && n != 0)
    {
        s++;
        n--;
    }
    return n ? s : NULL;

}

int mem_cmp(const void *s1,const void *s2,int n)
{
    while((unsigned char)*s1 == (unsigned char)*s2 && n != 0)
    {
        n--;
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2); //si sale xq n=0, al hacer la resta y como las dos cadenas son iguales va a retornar 0
}

void *mem_cpy(void *s1, const void *s2, int n)
{
    void *aux = s1;

    while(--n)
    {
        *s1 = *s2;//ver si lo podes hacer en la misma linea cuando funcione
        s1++;
        s2++;
    }
    return aux;
}
void *mem_set(void *s,int c, size_t n)
{
    void *aux = s;

    while(--n)

      *aux = (unsigned char) c; //no se si el casteo esta bien

    return s;
}
char *str_cat(char *s1, const char *s2) //fijate si esta bien puestos los operadores '++' y '--'
{
    char * aux = s1;

    while(aux ++)

    aux --;

    while(s2 ++)                       // fijate si hay que clavarle el caracter nulo
      *aux = *s2;

    return s1;
}
char *str_chr(char *s, int c)
{
    while(*s != (unsigned char)c && s)
      s++;

    return (*s == (unsigned char)c || (unsigned char)c == '\0') ? s : NULL;
}

