/* 
   PROGRAM FOR GETBLOCK ALGORITHM (ALL FIVE SCEANRIOS)
   PREFERABLE OS :: WINDOWS PLATFORM

*/



#include<stdio.h>
#include<stdlib.h>
#define PF printf
#define SF scanf
struct node
{
 int info;
 struct node *nxt;
}*start=NULL;
struct L1
{
 int info;
 struct L1 *nxt; 
}*start1=NULL;
struct L2
{
 int info;
 struct L2 *nxt; 
}*start2=NULL;
struct L3
{
 int info;
 struct L3 *nxt; 
}*start3=NULL;
struct L4
{
 int info;
 struct L4 *nxt; 
}*start4=NULL;
int search1(int);
int search2(int);
int search3(int);
int search4(int);
void add();
void addFreeList();
void searchFreeList();
void dis();
void del(int [],int);
void disList();
int no;
void add1(int no);
void add2(int no);
void add3(int no);
void add4(int no);
void del1(int);
void del2(int);
void del4(int);
void del3(int);

int main()
{
 int ch;

 while(1)
 {
 
    PF("\nPRESS 1:ADD\nPRESS 2:ADD FREE LIST\nPRESS 3:SEARCH ON FREE LIST\nPRESS 4:DISPLAY\nPRESS 5:DISPLAY FREE LIST\nPRESS 6:EXIT");
    PF("\nENTER YOUR CHOICE ::");
    SF("%d",&ch);
    switch(ch)
    {
      case 1:add();        		 break;
      case 2:addFreeList();              break;
      case 3:searchFreeList();           break;
      case 4:dis();                      break;
      case 5:disList();                  break;
      case 6:exit(0);                    break;
    }
 }
}

void add()
{
  PF("\nENTER NUMBER YOU WANT TO ENTER INTO HASHQ ::");
  SF("%d",&no);
  switch(no%4)
  {
   case 0:  add1(no);             break;
   case 1:  add2(no)	;	break;
   case 2:  add3(no);		break;
   case 3:  add4(no);		break;
  }
}
void add1(int no)
{
 //addition of node in 1st linked list..
 struct L1  *cur,*t1,*t2;
 cur=(struct L1* )malloc(sizeof(struct L1));
 cur->nxt=NULL;
 cur->info=no;

 if(start1==NULL)
 {
   start1=cur;
    PF("\n done");
    return;
 }
 t1=start1;
 while(t1->nxt!=NULL)
 {
   t1=t1->nxt;
 }
 t1->nxt=cur;
 PF("\n done");
}

void add2(int no)
{
  //addition of node in 2nd linked list..
 struct L2  *cur,*t1;
 cur=(struct L2* )malloc(sizeof(struct L2));
 cur->nxt=NULL;
 cur->info=no;

 if(start2==NULL)
 {
   start2=cur;
    PF("\n done");
    return;
 }
 t1=start2;
 while(t1->nxt!=NULL)
 {
   t1=t1->nxt;
 }
 t1->nxt=cur;
  PF("\n done");
}

void add3(int no)
{
  //addition of node in 1st linked list..
 struct L3  *cur,*t1;
 cur=(struct L3* )malloc(sizeof(struct L3));
 cur->nxt=NULL;
 cur->info=no;

 if(start3==NULL)
 {
   start3=cur;
    PF("\n done");
    return;
 }
 t1=start3;
 while(t1->nxt!=NULL)
 {
   t1=t1->nxt;
 }
 t1->nxt=cur;
  PF("\n done");
}
void add4(int no)
{
  //addition of node in 4th linked list..
 struct L4  *cur,*t1;
 cur=(struct L4* )malloc(sizeof(struct L4));
 cur->nxt=NULL;
 cur->info=no;

 if(start4==NULL)
 {
   start4=cur;
    PF("\n done");
    return;
 }
 t1=start4;
 while(t1->nxt!=NULL)
 {
   t1=t1->nxt;
 }
 t1->nxt=cur;
  PF("\n done");
}
void addFreeList()
{

  struct node *cur,*t1;
  int n;
  cur=(struct node *)malloc (sizeof(struct node));
  cur->nxt=NULL;
  PF("\nENTER THE BLOCK YOU WANT TO BE IN FREE LIST ::");
  SF("%d",&cur->info);
  if(start==NULL)
  {
    start=cur;
    return;
  }
  t1=start;
  while(t1->nxt!=NULL)
  {
    t1=t1->nxt;
  }
  t1->nxt=cur;

}
void searchFreeList()
{
  struct node *t1,*t2;
   int ch,i,a[10];
  int n,res,temp;
  if(start==NULL)
  {
    // 4th scenario is covered because free list of buffer is empty...
    PF("Sorry, First add free list...");
    return;
  }
///1st scenario..:::
  PF("\nENTER THE BLOCK YOU WANT TO SEARCH IN FREE LIST ::");
  SF("%d",&n);
  t1=t2=start;
  if(n==start->info)
  {
    start=start->nxt;
    PF("%d is deleted from free list.",t1->info);
    free(t1);
     return;
  }
  while(t1!=NULL)
  {
    if(n==t1->info)
    {
	/// if it finds 1st scenario is covered...
       PF("\nWE ARE IN 1st Scenario\n\n");
      PF("%d is deleted from free list...",t1->info);
      t2->nxt=t1->nxt;
      free(t1);
      return;

  /// we are returning to main if 1st scenario satisfies...
    }
    t2=t1;
    t1=t1->nxt;
  }

// now we have to check 1st 5th sceanario.
  //5th scenario : kernel finds block on hashQ , but buffer is busy...

 switch(n%4)
  {
     case 0 :
	     res=search1(n);
	     if(res==1)
		return;
	     break;
    case 1:    res=search2(n);
	     if(res==1)
		return;
	     break;
    case 2:    res=search3(n);
	     if(res==1)
		return;
	     break;
    case 3:
	      res=search4(n);
	     if(res==1)
		return;
	     break;

  }
  //if 1st scenario and 5th scenario doesnt occur 2nd scenario is here...
   //2nd Scenario :: if kernel cant find block on hashQ,so it allocates buffer from free list,
  //so the kernel removes first buffer from free list..


// Till now we have covered 1st,4th,5th scenarios.so lets start with 2nd and 3rd scenario..

// 3rd scenario :: if kernel cant find block on hashQ,so in attempting to  allocate a buffer from free list,
 //  finds  a buffer on free list i.e delayed write...


// Logic : one thing is common between 2nd and 3rd scenario is that we have to add required block on hashQ.
 PF("\nWe are in either 2nd or 3rd scenario\n\n");

 // irrespective of 2nd or 3rd scenario we have to add require block on
 // hashQ depends on hash function i.e no%4
     switch(n%4)
     {
      // through switch we are adding the required block on HashQ based on key=blockno%4;
       //addition of block on hashq is done for both scenarios..
       case 0  :  add1(n);         break;
       case 1  :  add2(n);         break;
       case 2  :  add3(n);         break;
       case 3  :  add4(n);         break;
     }

  PF("\nPress 1:if there are delayed write buffers(3rd Scenario)\nPress 2: if there are not delayed write buffers(2nd Scenario)\nEnter Choice ::");
  SF("%d",&ch);
  switch(ch)
  {
    //  case 1 :3rdscenario..
   case 1:   
           PF("\nFirst of all Enter How many delayed write buffers are there\n");
 	   SF("\n%d",&ch);
           for(i=0;i<ch;i++) 
           { 
             PF("\nEnter ::");
             SF("%d",&a[i]);
           }
	   // in this we must delete one of the free buffers from free list
	   del(a,ch);
           break;
   case 2: /// scenario is 2 is executed..
 // now its time to delete the first buffer from free list..
           t1=start;
           start=start->nxt;
           PF("%d is deleted from free list... i.e 1st buffer from free list",t1->info);
           free(t1);
           break;
  }
	// now its time to delete the first buffer from free list..
     
}

void disList()
{
  struct node *l1;
 PF("\n FREE LIST ->");
 l1=start;
 while(l1!=NULL)
 {
  PF("\t%d->",l1->info);
  l1=l1->nxt;
 } 

}
void dis()
{
 struct L1 *l1;
 struct L2 *l2;
 struct L3 *l3;
 struct L4 *l4;
 
 PF("\nLIST 0 ->");
 l1=start1;
 while(l1!=NULL)
 {
  PF("\t%d->",l1->info);
  l1=l1->nxt;
 } 

 PF("\nLIST 1 ->");
 l2=start2;
 while(l2!=NULL)
 {
  PF("\t%d->",l2->info);
  l2=l2->nxt;
 } 

 PF("\nLIST 2 ->");
 l3=start3;
 while(l3!=NULL)
 {
  PF("\t%d->",l3->info);
  l3=l3->nxt;
 } 

 PF("\nLIST 3 ->");
 l4=start4;
 while(l4!=NULL)
 {
  PF("\t%d->",l4->info);
  l4=l4->nxt;
 } 
}
int search1(int n)
{
 struct L1 *t1; 
///1st scenario..:::
  t1=start1;
  while(t1!=NULL)
  {
    if(n==t1->info)
    { 
	// if it finds the block on hashQ it satisfies 5th scenario and it is busy     
       PF("\nWE ARE IN 5th Scenario\n\n");
      PF("%d is found in the  list... but it is busy",t1->info);
      return 1;  
  /// we are returning to main if 5th scenario satisfies...
    }
    t1=t1->nxt;
  }
  return 0;
}
int search2(int n)
{
  struct L2 *t1; 
///1st scenario..:::
  t1=start2;
  while(t1!=NULL)
  {
    if(n==t1->info)
    { 
	// if it finds the block on hashQ it satisfies 5th scenario and it is busy     
       PF("\nWE ARE IN 5th Scenario\n\n");
      PF("%d is found in the  list...it is busy",t1->info);
      return 1;  
  /// we are returning to main if 5th scenario satisfies...
    }
    t1=t1->nxt;
  }
  return 0;
}
int search3(int n)
{
  struct L3 *t1; 
///1st scenario..:::
  t1=start3;
  while(t1!=NULL)
  {
    if(n==t1->info)
    { 
	// if it finds the block on hashQ it satisfies 5th scenario and it is busy     
       PF("\nWE ARE IN 5th Scenario\n\n");
      PF("%d is found in the  list...it is busy",t1->info);
      return 1;  
  /// we are returning to main if 5th scenario satisfies...
    }
    t1=t1->nxt;
  }
  return 0;
}
int search4(int n)
{
  struct L4 *t1; 
///1st scenario..:::
  t1=start4;
  while(t1!=NULL)
  {
    if(n==t1->info)
    { 
	// if it finds the block on hashQ it satisfies 5th scenario and it is busy     
       PF("\nWE ARE IN 5th Scenario\n\n");
      PF("%d is found in the  list...it is busy",t1->info);
      return 1;  
  /// we are returning to main if 5th scenario satisfies...
    }
    t1=t1->nxt;
  }
  return 0;
}
void del(int a[],int n)
{
  struct node *t1,*t2;
  int i,ch;

  PF("\n%d\t%d\n\n",a[0],a[1]);
  for( i=0;i<n;i++)
  {
      t2=t1=start;
      if(a[i]==t1->info)
      {
        PF(" Delayed write buffer %d is deleted from free list\n\n",a[i]);
        start=start->nxt;
        free(t1);
        continue;    
      }
       t1=t1->nxt;
      while(t1!=NULL)
      {
         if(a[i]==t1->info)
         {
            /// if found 
            PF(" Delayed write buffer %d is deleted from free list\n\n",a[i]);
            t2->nxt=t1->nxt;
            free(t1); 
            break;
         }
         t2=t1;
         t1=t1->nxt;
      }

   PF("\nout of loop");
  }

// next available buffer is allocated i.e deleted from free list as well as from HashQ
/// deleting from free list
  t1=start;
  ch=start->info;

 // PF("starttttttttttt :%d",ch);
  start=start->nxt;
  free(t1);

// it is also necessary to delete from Hashq
// deleting from hashQ
   switch(ch%4)
   {
     case 0:del1(ch);          break;
     case 1:del2(ch);	       break;
     case 2:del3(ch);          break;
     case 3:del4(ch);          break;

   } 
}
void del1(int se)
{
  struct L1 *t1,*t2;
  t1=start1;  
  if(start1->info==se)
  {
   PF("  buffer %d is deleted from hashQ\n\n",se);
   start1=start1->nxt;
   free(t1);
   return;
  } 
   while(t1!=NULL)
      {
         if(se==t1->info)
         {
            /// if found 
             PF("  buffer %d is deleted from hashQ\n\n",se);
            t2->nxt=t1->nxt;
            free(t1); 
            t1=start1;
            break;
         }
         t2=t1;
         t1=t1->nxt;
      }
}

void del2(int se)
{
  struct L2 *t1,*t2;
  t1=start2;  
  if(start2->info==se)
  {
   PF("  buffer %d is deleted from hashQ\n\n",se);
   start2=start2->nxt;
   free(t1);
   return;
  } 
   while(t1!=NULL)
      {
         if(se==t1->info)
         {
            /// if found 
             PF("  buffer %d is deleted from hashQ\n\n",se);
            t2->nxt=t1->nxt;
            free(t1); 
            
            break;
         }
         t2=t1;
         t1=t1->nxt;
      }
}
void del3(int se)
{
  struct L3 *t1,*t2;
  t1=start3;  
  if(start3->info==se)
  {
   PF("  buffer %d is deleted from hashQ\n\n",se);
   start3=start3->nxt;
   free(t1);
   return;
  } 
   while(t1!=NULL)
      {
         if(se==t1->info)
         {
            /// if found 
             PF("  buffer %d is deleted from hashQ\n\n",se);
            t2->nxt=t1->nxt;
            free(t1); 
            t1=start3;
            break;
         }
         t2=t1;
         t1=t1->nxt;
      }
}
void del4(int se)
{
  struct L4 *t1,*t2;
  t1=start4;  
  if(start4->info==se)
  {
   PF("  buffer %d is deleted from hashQ\n\n",se);
   start4=start4->nxt;
   free(t1);
   return;
  } 
   while(t1!=NULL)
      {
         if(se==t1->info)
         {
            /// if found 
             PF("  buffer %d is deleted from hashQ\n\n",se);
            t2->nxt=t1->nxt;
            free(t1); 
            t1=start4;
            break;
         }
         t2=t1;
         t1=t1->nxt;
      }
}

