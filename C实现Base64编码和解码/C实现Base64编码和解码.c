

/********Base64编码和解码***********************************/

    #include "stdio.h"
    #include "string.h"
    #include "math.h"
    #include <ctype.h>
    #include <stdlib.h>
    static char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz"
                                 "0123456789+/";
    int base64_needed_encoded_length(int length_of_data)
    {
      int nb_base64_chars;
      nb_base64_chars= (length_of_data + 2) / 3 * 4;
      return nb_base64_chars + (nb_base64_chars - 1)/ 76 + 1;
    }
    int base64_needed_decoded_length(int length_of_encoded_data)
    {
      return (int) ceil(length_of_encoded_data * 3 / 4);
    }
    int base64_encode(const void *src, size_t src_len, char *dst)
    {
      const unsigned char *s= (const unsigned char*)src;
      size_t i= 0;
      size_t len= 0;
      for (; i < src_len; len += 4)
      {
        unsigned c;
        if (len == 76)
        {
          len= 0;
          *dst++= '\n';
        }
        c= s[i++];
        c <<= 8;
        if (i < src_len)
          c += s[i];
        c <<= 8;
        i++;
        if (i < src_len)
          c += s[i];
        i++;
        *dst++= base64_table[(c >> 18) & 0x3f];
        *dst++= base64_table[(c >> 12) & 0x3f];
        if (i > (src_len + 1))
          *dst++= '=';
        else
          *dst++= base64_table[(c >> 6) & 0x3f];
        if (i > src_len)
          *dst++= '=';
        else
          *dst++= base64_table[(c >> 0) & 0x3f];
      }
      *dst= '\0';
      return 0;
    }
    int pos(unsigned char c)
    {
      return (strchr(base64_table, c) - base64_table);
    }
    void SKIP_SPACE(const char *src, int i, int size)
    {
      while (i < size && isspace(*src))
      {
        i++;
        src++;
      }
      if (i == size)
      {
        i= size + 1;
      }
    }
    int base64_decode(const char *src, size_t size, void *dst)
    {
      char b[3];
      size_t i= 0;
      char *dst_base= (char *)dst;
      char *d= dst_base;
      size_t j;
      while (i < size)
      {
        unsigned c= 0;
        size_t mark= 0;
        SKIP_SPACE(src, i, size);
        c += pos(*src++);
        c <<= 6;
        i++;
        SKIP_SPACE(src, i, size);
        c += pos(*src++);
        c <<= 6;
        i++;
        SKIP_SPACE(src, i, size);
        if (* src != '=')
          c += pos(*src++);
        else
        {
          i= size;
          mark= 2;
          c <<= 6;
          goto end;
        }
        c <<= 6;
        i++;
        SKIP_SPACE(src, i, size);
        if (*src != '=')
          c += pos(*src++);
        else
        {
          i= size;
          mark= 1;
          goto end;
        }
        i++;
      end:
        b[0]= (c >> 16) & 0xff;
        b[1]= (c >>  8) & 0xff;
        b[2]= (c >>  0) & 0xff;
        for (j=0; j<3-mark; j++)
          *d++= b[j];
      }
      if (i != size)
      {
        return -1;
      }
      return (int) (d - dst_base);
    }
    int main(void)
    {
    	int k, l;
    	int needed_length,dst_len;
        char* src="abc";
        char* str;
        char* dst;
        int src_len=strlen(src);

        needed_length= base64_needed_encoded_length(src_len);
        str= (char *) malloc(needed_length);
        for (k= 0; k < needed_length; k++)
          str[k]= 0xff;
          base64_encode(src,src_len,str);
          printf("src :");
    for (l=0;l<src_len; l++)
    {
    	unsigned char c= src[l];
    	printf("%2x ",(unsigned)c);
    }
    
    printf("\nEncode dist:");
       for (l=0;l<needed_length-1;l++)
       {
       	unsigned char c= str[l];
       	printf("%2x ",(unsigned)c);
       }
        dst= (char *) malloc(base64_needed_decoded_length(strlen(str)));
        dst_len= base64_decode(str, strlen(str), dst);
        printf("\nDecode dist:");
       for (l=0;l<dst_len; l++)
       {
         unsigned char c= dst[l];
         printf("%2x ", (unsigned)c);
       }
       printf("\nTest succeeded.\n");
       return 0;
    }
