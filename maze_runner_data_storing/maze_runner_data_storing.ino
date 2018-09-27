/*#define lm1 3
#define lm2 5
#define rm1 6
#define rm2 9*/
#define s_0 A0
#define s_1 A1
#define s_2 A2
#define s_3 A3
#define s_4 A4
#define s_5 A5

int s1,s2,s3,s4,s5,s6,n,count=0,control=0,x=0;
char rout[30];
char dec[30];

void setup() {
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(s_0,INPUT);
pinMode(s_1,INPUT);
pinMode(s_2,INPUT);
pinMode(s_3,INPUT);
pinMode(s_4,INPUT);
pinMode(s_5,INPUT);
for(int i=0;i<30;i++)
{
rout[i]='o';
dec[i]='f';
}
n=-1;
Serial.begin(9600);
}

void sensorRead()
{
    s1=digitalRead(12);
    s2=digitalRead(s_1);
    s3=digitalRead(s_2);
    s4=digitalRead(s_3);
    s5=digitalRead(s_4);
    s6=digitalRead(s_5);
    /*Serial.print(s1);
    Serial.print(s2);
    Serial.print(s3);
    Serial.print(s4);
    Serial.print(s5);
    Serial.print(s6);
    Serial.println();*/
}


void store(char c, int i)
{
  if(dec[n]=='t' && c=='s')
  goto l1;
  if(c!=rout[n] || (c==rout[n]&&i==1) || (c==rout[n]&&dec[n]=='t'))
  {
    if(c=='u' && (rout[n]=='r' || rout[n]=='l') && i!=1)
    goto l1;
    if(c=='u' && i==0)
    {
      if(count>100)
      {
        n++;
        rout[n]=c;
        Serial.print(n);
        Serial.print(" : ");
        if(i==1) Serial.print(" * ");
        Serial.println(rout[n]);      
      }
    }
    else if(c=='u' && i==1)
    {
      count=0;
      n++;
      rout[n]=c;
      Serial.print(n);
      Serial.print(" : ");
      if(i==1) Serial.print(" * ");
      Serial.println(rout[n]);
    }
    else
    {
      count=0;
      n++;
      rout[n]=c;
      Serial.print(n);
      Serial.print(" : ");
      if(i==1) Serial.print(" * ");
      Serial.println(rout[n]);
    }
  }
    l1:
    if(n>1&&rout[n-2]=='l'&&rout[n-1]=='u'&&rout[n]=='l')
    {
        n=n-3;
        store('s',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f';          
    }
    else if(n>1&&rout[n-2]=='s'&&rout[n-1]=='u'&&rout[n]=='s')
    {
        n=n-3;
        store('u',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f';  
    }
    else if(n>1&&rout[n-2]=='r'&&rout[n-1]=='u'&&rout[n]=='l')
    {
        n=n-3;
        store('u',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f';   
    }
    else if(n>1&&rout[n-2]=='l'&&rout[n-1]=='u'&&rout[n]=='r')
    {
        n=n-3;
        store('u',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f';  
    }
    else if(n>1&&rout[n-2]=='r'&&rout[n-1]=='u'&&rout[n]=='r')
    {
        n=n-3;
        store('s',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f';
    }
    else if(n>1&&rout[n-2]=='s'&&rout[n-1]=='u'&&rout[n]=='r')
    {
        n=n-3;
        store('l',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f'; 
    }
    else if(n>1&&rout[n-2]=='l'&&rout[n-1]=='u'&&rout[n]=='s')
    {
        n=n-3;
        store('r',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f';  
    }
    else if(n>1&&rout[n-2]=='r'&&rout[n-1]=='u'&&rout[n]=='s')
    {
        n=n-3;
        store('l',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f'; 
    }
    else if(n>1&&rout[n-2]=='s'&&rout[n-1]=='u'&&rout[n]=='l')
    {
        n=n-3;
        store('r',1);
        rout[n+1]='o';
        rout[n+2]='o';
        dec[n]='t';
        dec[n+1]='f';
        dec[n+2]='f';   
    }  
}


void forward()
{
  analogWrite(3,150);
  analogWrite(5,0);
  analogWrite(6,150);
  analogWrite(9,0);
}

void left()
{
  forward();
  delay(200);
  analogWrite(3,0);
  analogWrite(5,150);
  analogWrite(6,150);
  analogWrite(9,0);
  delay(700);  
}

void right()
{
  analogWrite(3,150);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,150);  
}

void uturn()
{
  analogWrite(3,150);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,150);
  delay(1500);
}

void softleft()
{
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(6,150);
  analogWrite(9,0);
}

void softright()
{
  analogWrite(3,150);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
}

void pause()
{
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
}

int dryrun()
{
  if(s1==1&&
     s2==1&&
     s3==0&&
     s4==0&&
     s5==1&&
     s6==1)
     {
       forward();
       store('s',0);  
     }
  else if(s1==0&&
          s2==0&&
          s3==0&&
          s4==0&&
          s5==1&&
          s6==1)
          {
            left();
            store('l',0);  
          }
  else if(s1==1&&
          s2==1&&
          s3==0&&
          s4==0&&
          s5==0&&
          s6==0)
          {
            forward();
            delay(200);
            sensorRead();
            if(s1==1&&
               s2==1&&
               s3==1&&
               s4==1&&
               s5==1&&
               s6==1)
               {
                 store('r',0);
                 right();
                 delay(700);
               }
               else
               {
                 forward();
                 store('s',1); 
               }
          }
  else if(s1==0&&
          s2==0&&
          s3==0&&
          s4==0&&
          s5==0&&
          s6==0)
          {
            forward();
            delay(100);
            //pause();
            Serial.println("hi");
            //delay(2000);
            sensorRead();
            if(s1==0&&
               s2==0&&
               s3==0&&
               s4==0&&
               s5==0&&
               s6==0)
               {
                 pause();
                 store('p',1);
                 //delay(10000);
                 //control=1;
                 //Serial.println("hellow");
                 return(0);         
               }
            else
            {
                 store('l',0);
                 forward();
                 delay(100);
                 analogWrite(3,0);
                 analogWrite(5,150);
                 analogWrite(6,150);
                 analogWrite(9,0);
                 delay(700);
                 //left();
            }  
          }
  else if(s1==1&&
          s2==1&&
          s3==1&&
          s4==1&&
          s5==1&&
          s6==1)
          {
            count=count+1;
            store('u',0);
            right();  
          }
     else if(s1==1&&
             s2==0&&
             s3==0&&
             s4==0&&
             s5==1&&
             s6==1)
             {
                 softleft();
                 store('s',0); 
             }
     else if(s1==1&&
             s2==1&&
             s3==0&&
             s4==0&&
             s5==0&&
             s6==1)
             {
                 softright(); 
                 store('s',0); 
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==0&&
             s5==0&&
             s6==1)
             {
                 softright();
                 store('s',0);  
             }
     else if(s1==1&&
             s2==0&&
             s3==0&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 softleft();
                 store('s',0);  
             }
     else if(s1==1&&
             s2==1&&
             s3==0&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 forward();
                 store('s',0);  
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==0&&
             s5==1&&
             s6==1)
             {
                 forward();
                 store('s',0);  
             }
     else if(s1==0&&
             s2==0&&
             s3==0&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 softleft();  
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==0&&
             s5==0&&
             s6==0)
             {
                 softright();  
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==1&&
             s5==1&&
             s6==0)
             {
                 softright();  
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==1&&
             s5==0&&
             s6==0)
             {
                 softright();  
             }
     else if(s1==0&&
             s2==1&&
             s3==1&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 softleft();  
             }
     else if(s1==0&&
             s2==0&&
             s3==1&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 softleft();  
             }
}

void actualRun(int *z)
{   //Serial.print(" this one ");Serial.println(*z);
    if(s1==1&&
       s2==1&&
       s3==0&&
       s4==0&&
       s5==1&&
       s6==1&&
       rout[*z]=='s')
       {
           forward(); 
           Serial.println(*z);
       }
       else if(s1==0&&
               s2==0&&
               s3==0&&
               s4==0&&
               s5==1&&
               s6==1&&
               rout[*z+1]=='l')
               {
                   left();
                   *z=*z+2; 
               }
       else if(s1==0&&
               s2==0&&
               s3==0&&
               s4==0&&
               s5==1&&
               s6==1&&
               rout[*z+1]=='s')
               {
                   forward();
                   delay(400);
                   Serial.println("ls");
                   *z=*z+1; 
               }
       else if(s1==1&&
               s2==1&&
               s3==0&&
               s4==0&&
               s5==0&&
               s6==0&&
               rout[*z+1]=='r')
               {
                   forward();
                   delay(400);
                   right();
                   delay(700);
                   *z=*z+2; 
               }
       else if(s1==1&&
               s2==1&&
               s3==0&&
               s4==0&&
               s5==0&&
               s6==0&&
               rout[*z+1]=='s')
               {
                   forward();
                   delay(400);
                   *z=*z+1; 
               }
       else if(s1==0&&
               s2==0&&
               s3==0&&
               s4==0&&
               s5==0&&
               s6==0&&
               rout[*z+1]=='s')
               {
                   forward();
                   delay(400);
                   *z=*z+1; 
               }
       else if(s1==0&&
               s2==0&&
               s3==0&&
               s4==0&&
               s5==0&&
               s6==0&&
               rout[*z+1]=='r')
               {
                   forward();
                   delay(400);
                   right();
                   delay(700);
                   *z=*z+2; 
               }
       else if(s1==0&&
               s2==0&&
               s3==0&&
               s4==0&&
               s5==0&&
               s6==0&&
               rout[*z+1]=='l')
               {
                   left();
                   *z=*z+2; 
               }
       else if(s1==0&&
               s2==0&&
               s3==0&&
               s4==0&&
               s5==0&&
               s6==0&&
               rout[*z+1]=='p')
               {
                   pause();
                   //digitalWrite(led,HIGH);
                   //delay(5000);
                   //digitalWrite(led,LOW);
                   exit(0); 
               }               
     else if(s1==1&&
             s2==0&&
             s3==0&&
             s4==0&&
             s5==1&&
             s6==1)
             {
                 softleft(); 
             }
     else if(s1==1&&
             s2==1&&
             s3==0&&
             s4==0&&
             s5==0&&
             s6==1)
             {
                 softright();  
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==0&&
             s5==0&&
             s6==1)
             {
                 softright();  
             }
     else if(s1==1&&
             s2==0&&
             s3==0&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 softleft();  
             }
     else if(s1==0&&
             s2==0&&
             s3==0&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 softleft();  
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==0&&
             s5==0&&
             s6==0)
             {
                 softright();  
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==1&&
             s5==1&&
             s6==0)
             {
                 softright();  
             }
     else if(s1==1&&
             s2==1&&
             s3==1&&
             s4==1&&
             s5==0&&
             s6==0)
             {
                 softright();  
             }
     else if(s1==0&&
             s2==1&&
             s3==1&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 softleft();  
             }
     else if(s1==0&&
             s2==0&&
             s3==1&&
             s4==1&&
             s5==1&&
             s6==1)
             {
                 softleft();  
             }
}

void loop() {
sensorRead();
if(control==0)
{
x=dryrun();
}
if(control==1)
{
  actualRun(&x);
}
}
