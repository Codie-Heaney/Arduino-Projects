String k[8];
String past_k[8];
int i_1=-1;
int i_2=0;
int i_3=0;
int i_4=0;
int i_5=0;
int i_6=0;
int i_7=0;
int i_8=0;
int q=0;
String a[]={"0","1","2","3","4","5","6","7","8","9"};
String combination_[]={"1","1","1","1","0","0","0","0"};
bool combination[]={true,true,true,true,true,true,true,true};
int a_size=9;
int comb_len=0;
bool pp=bool(int(1));
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++){
      combination[i]=bool(int(combination_[i]));
      if(combination[i]){
          comb_len+=1;
      }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i_1<a_size and combination[0]){
      i_1+=1;
  }else if(i_2<a_size and combination[1]){
      i_1=0;
      i_2+=1;
  }else if(i_3<a_size and combination[2]){
      i_1=0;
      i_2=0;
      i_3+=1;
  }else if(i_4<a_size and combination[3]){
      i_1=0;
      i_2=0;
      i_3=0;
      i_4+=1;
  }else if(i_5<a_size and combination[4]){
      i_1=0;
      i_2=0;
      i_3=0;
      i_4=0;
      i_5+=1;
  }else if(i_6<a_size and combination[5]){
      i_1=0;
      i_2=0;
      i_3=0;
      i_4=0;
      i_5=0;
      i_6+=1;
  }else if(i_7<a_size and combination[6]){
      i_1=0;
      i_2=0;
      i_3=0;
      i_4=0;
      i_5=0;
      i_6=0;
      i_7+=1;
  }else if(i_8<a_size and combination[7]){
      i_1=0;
      i_2=0;
      i_3=0;
      i_4=0;
      i_5=0;
      i_6=0;
      i_7=0;
      i_8+=1;
  }k=a[i_1]+a[i_2]+a[i_3]+a[i_4]+a[i_5]+a[i_6]+a[i_7]+a[i_8];
  if(past_k==k){
      Serial.println("Done:"+String(q));
      file.close();
      break;
  }else{
      past_k=k
  }if(pp){Serial.println(k);}q+=1
}
