#include "code.h"

char devinette[255] = "JEDETESTELEC";


void majuscules(char * s) {
   int i = 0 ;
   while (s[i]!='\0'){
      if (s[i]>='a' && s[i]<= 'z'){
         s[i]-=32;
      }
      i++;
   }
}

void multitap1(char * d, char * s) {
   char tab[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   int inTab[26] = {2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999};

   FILE * file = fmemopen(d,50,"w");
   int i = 0 ;
   while (s[i]!='\0'){
      if (i!=0) { fprintf(file," "); }
      for (int j = 0; j<26;j++){      
         if (tab[j] == s[i]){
            fprintf(file,"%d",inTab[j]);
         }
         
      }
      i++;
   }
   fclose(file);
}

void multitap2(char * s) {
   char d[50] = "";
   multitap1(d,s);
   int occ =0, num =0 , rest = 0; 
   char *next , *current = d;
   FILE *file =  fmemopen(s,50,"w");

   while(*current != '\0'){
      next = current;
      while (*next != '\0' && *next != ' '){
         next++;
      }

      char temp = *next;
      *next = '\0';

      num = atoi(current);
      occ = 0 ;
      rest = num%10;

      while (num > 0){
         occ++;
         num /=10.0;
      }

      if(occ > 1){
         fprintf(file,"%d*",occ);
      }
      fprintf(file,"%d",rest);

      *next = temp;
      if( *next == ' '){
         current = next + 1;
      }else{
         current = next;
      }
   }
   fclose(file);
}

void antitap1(char *d, char * s) {
   char tab[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   char *inTab[26] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
   
   FILE * file = fmemopen(d,50,"w");

   char *next , *current = s;

   while(*current != '\0'){
      next = current;
      while (*next != '\0' && *next != ' '){
         next++;
      }

      char temp = *next;
      *next = '\0';

     for (int j = 0; j<26;j++){      
         if (0==strcmp(inTab[j],current)){
            fprintf(file,"%c",tab[j]);
         }
         
      }

      *next = temp;
      if( *next == ' '){
         current = next + 1;
      }else{
         current = next;
      }
   }
   fclose(file);
}

void antitap2(char * s) {
   char d[50] = "";
   
   int i =0 , num = 0, occ = 0;
   while (s[i]!='\0'){
      occ = s[i]-'0';
      if (s[i+1]!='\0' && s[i+1] == '*')
      {
         char car = s[i+2];
         for (int j =0; j < occ; j++){
            d[num++] = car;
         }
         i+=3;
         
      }
      else {
         d[num++]=s[i];
         i++;
      }
      if(s[i]!= '\0'){
          d[num++]=' ';
      }
   }
   antitap1(s,d);
}

char * sms(char * nom) {
   FILE *file = fopen(nom,"r");
   if(file == NULL) { return NULL; }
   char ligne[50] = "";
   char multitap_ligne[50] = "";
   char *sms = calloc(sizeof(char),1024);
   
   while(fgets(ligne,50,file) != NULL)
   {
      majuscules(ligne);
      multitap1(multitap_ligne,ligne);
      size_t l = strlen(multitap_ligne);
      multitap_ligne[l]='\n',
      strcat(sms,multitap_ligne);

   }
   size_t l = strlen(sms);
   sms[l-1]='\0';
   fclose(file);
   return sms;
}