#include<iostream>
#include<cstring>
using namespace std;

class STRING{
	char *p;
	int j;
	public:
	STRING(){
		p=0;
	}
	STRING(const char *t){//Parametrised constructor
		p=new char[strlen(t)+1];
		strcpy(p,t);
	}
	STRING(STRING &t){//deep copy
		p=new char [strlen(t.p)+1];
		strcpy(p,t.p);
	}
	//s1=s2; s1.operator =(s2)
	STRING operator =(STRING &t){//Assignment overload
		p=new char[strlen(t.p)+1];
		strcpy(p,t.p);
		//return *this;
	}
	char& operator [](int i){
		return p[i];
	}
	//s1<s2;//s1.operator(s2);
	bool operator <(STRING &t){
		if(my_strcmp(*this,t)>0)
		return false;
		else
		return true; 
	}
	//s1>s2;//s1.operator(s2);
	bool operator >(STRING &t){
		if(my_strcmp(*this,t)<0)
		return false;
		else
		return true; 
	}
	//s1>=s2//s1.operator(s2);
	bool operator >=(STRING &t){
		if(my_strcmp(*this,t)<=0)
		return false;
		else
		return true;
	}
	//s1<=s2//s1.operator(s2);
	bool operator <=(STRING &t){
		if(my_strcmp(*this,t)>=0)
		return false;
		else
		return true;
	}
	//s1==s2//s1.operator(s2);
	bool operator ==(STRING &t){
		if(my_strcmp(*this,t)==0)
		return true;
		else
		return false;
	}
	//s1!=s2//s1.operator(s2);
	bool operator !=(STRING &t){
		if(my_strcmp(*this,t)!=0)
		return true;
		else
		return false;
	}
	STRING& operator +(STRING &t){//= overload
		STRING temp;
		temp.p=new char [strlen(p)+strlen(t.p)+1];
		my_strcpy(temp,*this);
		strcat(temp.p,t.p);
		delete []p;	
		p=new char [strlen(temp.p)+1];
		my_strcpy(*this,temp);
		return temp;
	}
	void getData(){
		cout<<p<<endl;
	}
	void memory(){
		p=new char [10];
	}
	friend istream& operator >>(istream &,STRING &);
	friend ostream& operator <<(ostream &,STRING &);
	friend void my_strcpy(STRING &,STRING &);
	friend void my_strncpy(STRING &,STRING &,int);
	friend int my_strcmp(STRING &,STRING &);
	friend int my_strncmp(STRING &,STRING &,int);
	friend void my_strcat(STRING &,STRING &);
	friend void my_strncat(STRING &,STRING &,int);
	friend const char *my_strchr(STRING &,int);
	friend const char *my_strrchr(STRING &,int);
	friend const char *my_strstr(STRING &,const char*);
	friend int str_len(STRING &);
	friend void str_upp(STRING &);
	friend void str_low(STRING &);
	friend void str_rev(STRING &);
	~STRING(){
		delete []p;
	}
};


////////////////////////////////////////////
int main(){
	STRING s1("abcdef"),s2("ghijkl"),s3,s4,s5;
	s5=s2+s1;
	s5.getData();
}
////////////////////////////////////////////


int str_len(STRING & a){	
	int len=0;
	for(;a.p[len];len++);
	return len;	
}

void str_upp(STRING & a){
	for(int i=0;a.p[i];i++){
		if(a.p[i]>='a' && a.p[i]<='z')
		a.p[i]-=32;
	}
}

void str_low(STRING & a){
	for(int i=0;a.p[i];i++){
		if(a.p[i]>='A' && a.p[i]<='Z')
		a.p[i]+=32;
	}
}

void str_rev(STRING & a){
	char ch;
	int len=0;
	for(;a.p[len];len++);
	len--;
	
	for(int i=0;i<len;i++,len--){
		ch=a.p[i];
		a.p[i]=a.p[len];
		a.p[len]=ch;
	}
}


const char *my_strstr(STRING & a,const char* q){
	int i,j,start=0;
	for(i=0;a.p[i];i++){
		if(a.p[i]==q[0]){
			start=i;
			for(j=0;a.p[j];j++,start++){
				if(a.p[start]!=q[j])
				break;
			}
			
			if(q[j]=='\0')
			return &a.p[i];
		}
	}
	return 0;
}


const char *my_strchr(STRING & a,int ch){
	for(int i=0;a.p[i];i++){
		if(a.p[i]==ch)
		return &a.p[i];
	}
	return 0;
}

const char *my_strrchr(STRING & a,int ch){
	int len;
	for(len=0;a.p[len];len++);
	
	for(int i=len-1;i>=0;i--){
		if(a.p[i]==ch)
		return &a.p[i];
	}
	return 0;
}

void my_strcat(STRING & a,STRING & b){
	STRING temp;
	temp.p=new char [strlen(a.p)+strlen(b.p)+1];
	
	my_strcpy(temp,a);
	strcat(temp.p,b.p);
	delete []a.p;	
	a.p=new char [strlen(temp.p)+1];
	my_strcpy(a,temp);
}

void my_strncat(STRING & a,STRING & b,int n){
	STRING temp;
	temp.p=new char [strlen(a.p)+n+1];
	int len,i;
	for(len=0;a.p[len];len++);
	len--;
	
	my_strcpy(temp,a);
	for(i=0;i<n;i++){
		temp.p[len+i]=b.p[i];	
	}
	temp.p[len+i]='\0';
	delete []a.p;
	my_strcpy(a,temp);
}

istream& operator >>(istream &in,STRING &s){
	s.p=new char [30];
	in>>s.p;
	return in;
}
ostream& operator <<(ostream &out,STRING &s){
	out<<s.p;
	return out;
}

void my_strcpy(STRING &dest,STRING &src){
	dest.p=new char [strlen(src.p)+1];
	int i;
	for(i=0;src.p[i];i++){
		dest.p[i]=src.p[i];
	}
	dest.p[i]='\0';
}

void my_strncpy(STRING& dest,STRING& src,int n){
	dest.p=new char [strlen(src.p)+n+1];
	
	int i;
	for(i=0;i<n;i++){
		dest.p[i]=src.p[i];
	}
	dest.p[i]='\0';
}


int my_strcmp(STRING & a,STRING & b){
	int i;
	for(i=0;a.p[i] && b.p[i];i++){
		if(a.p[i]!=b.p[i])
		return a.p[i];
	}
	
	if(a.p[i] || b.p[i])
	return a.p[i]-b.p[i];

	return 0;
}

int my_strncmp(STRING & a,STRING & b,int n){
	for(int i=0;i<n;i++){
		if(a.p[i]!=b.p[i])
		return a.p[i]-b.p[i];
	}
	return 0;
}
