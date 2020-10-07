#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
        char a[100];
        struct string *next;
}hang;

void main()
{  char s[100],m[100],n[100],type,zancun[100];
    int i,j,t=0,r=0,count=0,m1,n1,temp1,temp2,l,flag=0;
    hang *p,*q,*head;
    gets(s);
    p = head = (hang *) malloc (sizeof(hang));
    for(i=0;i<1000;i++)
      {gets(s);
        if(strcmp(s, "[/Text]")==0)
           break;
         q =(hang *) malloc (sizeof(hang));
         p->next=q;
         strcpy(q->a,s);
         q->next=NULL;
         p=q;
         count++;
      }/*读入数据的处理*/
      while(scanf("%c ", &type) != EOF)
     {

        if(type=='i')
           {scanf("%d/%[^\n]",&m1,s);
               if(m1>count)
                  { for(p=head;p->next!=NULL;p=p->next)
                            ;
                    q=  (hang *) malloc (sizeof(hang));
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
                      q=(hang *) malloc (sizeof(hang));
                      strcpy(q->a,s);
                      q->next=p->next;
                      p->next=q;
                      count++;
                }
            }
         if(type=='d')
            { scanf("%d",&m1);
               p=head;  i=1;
              while(i<m1)
                 {  p=p->next;
                    i++;
                  }
                p->next=p->next->next;
                free(p->next);
                count--;
            }
         if(type=='f')
            {  scanf("%d/%d",&m1,&n1);
                p=head->next;
                q=head;
                i=1;
                while(i<m1)
                    { p=p->next; i++;
                    }
                 i=1;
                 while(i<n1)
                   { q=q->next;
                     i++;
                   }
                 strcat(p->a,q->next->a);
                 q->next=q->next->next;
                 free(q->next);
                 count--;
            }
        if(type=='c')
         { scanf("%[^\n]", s);
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
            for(i=j;s[i]!='\0';i++)
              { if(s[i]!='\\')
                   n[r++]=s[i];
                else
                  { n[r++]=s[i+1];
                    i++;
                  }
              }
              n[r]='\0';
              temp1=strlen(m);temp2=strlen(n);
              t=0;r=0;
                  memset(zancun,0,sizeof(zancun));
          for(p=head->next,r=1;r<=count;p=p->next,r++)
            { t=0;
                    for(i=0;p->a[i]!='\0';i++)
                {     if(p->a[i]!=m[0])
                                { zancun[t++]=p->a[i];
                                    zancun[t]='\0';
                                }
                      else
                                    { for(j=0;j<temp1;j++)
                                             if(p->a[i+j]!=m[j])
                                                { flag=0;break;}
                                             if(j==temp1)
                                               flag=1;
                        if(flag==1)
                            { strcat(zancun,n);
                                    i=i+temp1-1;
                                    t=t+temp2;
                            }
                         else
                            {zancun[t++]=p->a[i];
                             zancun[t]='\0';
                            }


                        }
                     }
                strcpy(p->a,zancun);
                memset(zancun,0,sizeof(zancun));
            }
         }

     }
         getchar();
            for(p=head->next,r=1;r<=count;p=p->next,r++)
               printf("%s\n",p->a);

                memset(zancun,0,sizeof(zancun));
}
