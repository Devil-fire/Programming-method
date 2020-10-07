#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
        char a[1000];
        struct string *next;
}h;
void del(char* s)
{
        char* p=s;
        while(*p != '\0')
                if(*p == '\\') *p++;
                else
                {
                *s = *p;
                *s++;
                *p++;
            }
        *s = '\0';
}
int main()
{  char s[10000],m[10000],n[10000],type,temp[10000];char c='/';
    int i,j=0,t=0,r=0,count=0,m1=0,n1=0,temp1=0,temp2=0,flag=0,cou=0;
    h *p,*q,*head;
    gets(s);
    p = head = (h *) malloc (sizeof(h));
    for(i=0;i<1000;i++)
      {gets(s);
        if(strcmp(s, "[/Text]")==0)
           break;
         q =(h *) malloc (sizeof(h));
         p->next=q;
         strcpy(q->a,s);
         q->next=NULL;
         p=q;
         count++;
      }/*读入数据的处理*/
	 while(scanf("%c ", &type)!=EOF) 
     {
 	   line:
        if(type=='i')
           {scanf("%d/%[^\n]",&m1,s);
           del(s);
               if(m1>count)
                  { for(p=head;p->next!=NULL;p=p->next)
                            ;
                    q=  (h *) malloc (sizeof(h));
                    strcpy(q->a,s);
                    p->next=q;
                    q->next=NULL;
                    count++;
                  }
               else
                { p=head;   i=1;
                   while(i<m1)
                    {  p=p->next;
                    i++;
                    }
                      q=(h *) malloc (sizeof(h));
                      strcpy(q->a,s);
                      q->next=p->next;
                      p->next=q;
                      count++;
                }
            }
         if(type=='d')
            { 
			   scanf("%d",&m1);
               p=head;  
			   i=1;
              while(i<m1)
                 {  
				 	p=p->next;
                    i++;
                  }
                p->next=p->next->next;
                //free(p->next);
                count--;
            }
         if(type=='f')
            {  
               int x;m1=0;n1=0;
            while(c=='/'){
            	c='0';
               scanf("%d %c",&x,&c);
               //printf("%d %c\n",x,c);
               //printf("%d\n",count);
               if(x<1||x-cou>count) continue; 
               //printf("Go\n");
			   if(m1==0) m1=x-cou;
			   else if(n1==0) n1=x-cou;
			   if(n1==0) continue;
			   
			  // printf("*%d %d\n",m1,n1); 
                p=head->next;
                q=head;
                i=1;
                while(i<m1)
                    { 
					  p=p->next; 
					  i++;
                    }
                 i=1;
                 while(i<n1)
                   { 
				     q=q->next;
                     i++;
                   }
                 strcat(p->a,q->next->a);
				 //printf("%s\n%s\n",p ->a,q->next->next->a);
                 q->next=q->next->next;
                 //free(q->next->next);
                 count--;cou++;
                 n1=0; 
			   }
			   if(c=='i'||c=='q'||c=='d'||c=='f') {type=c;goto line;}
            }
        if(type=='c')
         { 
		 scanf("%s", s);
         t=0;r=0;
         for(i=0;s[i]!='\0';i++)
          { if(s[i]!='\\'&&s[i+1]=='/')
                 s[i+1]='\0';
                 j=i+2;
                 }
            for(i=0;s[i]!='\0';i++)
               {  if(s[i]!='\\')
                    m[t++]=s[i];
                  else
                  { m[t++]=s[i+1];
                    i++;
                  }
               }
               m[t]='\0';
               //printf("%d\n",j);
            for(i=j;s[i]!='\0';i++)
              { if(s[i]=='\\'&&s[i+1]=='/')
              {
              	n[r++]=s[i+1];i++;
			  }
              	else n[r++]=s[i];
              }
              n[r]='\0';
              //puts(m);puts(n);
              temp1=strlen(m);temp2=strlen(n);
              t=0;r=0;
                  memset(temp,0,sizeof(temp));
          for(p=head->next,r=1;r<=count;p=p->next,r++)
            { t=0;
                    for(i=0;p->a[i]!='\0';i++)
                {     if(p->a[i]!=m[0])
                                { temp[t++]=p->a[i];
                                    temp[t]='\0';
                                }
                      else
                                    { for(j=0;j<temp1;j++)
                                             if(p->a[i+j]!=m[j])
                                                { flag=0;break;}
                                             if(j==temp1)
                                               flag=1;
                        if(flag==1)
                            { strcat(temp,n);
                                    i=i+temp1-1;
                                    t=t+temp2;
                            }
                         else
                            {temp[t++]=p->a[i];
                             temp[t]='\0';
                            }
                        }
                     }
                strcpy(p->a,temp);
                memset(temp,0,sizeof(temp));
            }
         }
        // printf("%d\n",type=='q');
		 if(type=='q')
		 {
		 	scanf("#%d/",&m1);
		 	scanf("%s",s);
		 	//printf("%s",s);
		 	del(s); 
		 	i=1;
		 	p=head->next;
		 	while(i<m1)
                 {  
				 	p=p->next;
                    i++;
                  }
            char k[5];
		 	if(strstr(p->a,s)!=NULL) strcpy(k,"Yes");
		 	else strcpy(k,"No");
		 	while(i<count)
                 {  
				 	p=p->next;
                    i++;
                  }	
                //printf("%s\n",p->a);
            q=  (h *) malloc (sizeof(h));
            strcpy(q->a,k);
            p->next=q;
            q->next=NULL;
            count++;
            c='0';
			 }	
	 }   
            for(p=head->next,r=1;r<=count;p=p->next,r++)
               printf("%s\n",p->a);
            memset(temp,0,sizeof(temp));
    return 0;
}
