#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <string.h>
#pragma hdrstop

#pragma argsused
#define MaxDig 1000
#define n_Osn 4

typedef long TLong[MaxDig];

void input(long a[MaxDig])
{
  long Osn,i,ch;
  char c[1];
  Osn=pow(10.0,n_Osn);
  for(i=0;i<MaxDig;i++)
	a[i]=0;
  a[0]=1;
  while(isdigit(c[0]=getch()))
  {
	ch=atoi(c);
	printf("%c",c[0]);
	for(i=a[0];i>0;i--)
    {
	  a[i+1]=a[i+1]+a[i]*10/Osn;
      a[i]=a[i]*10%Osn;
    }
	a[1]+=ch;
	if(a[a[0]+1]>0) a[0]++;
  }
}

void output(long a[MaxDig])
{
  int i,j,NN,Osn,p;
  long N;
  Osn=pow(10.0,n_Osn);
  printf("%ld",a[a[0]]);
  for(i=a[0]-1;i>0;i--)
  {
	NN=1;
	N=a[i];
	if(N==0) NN=0;
	for(p=0;N>0;p++)
	{
	  N/=10;
	}
	while((n_Osn-p)!=0)
	{
	  printf("0");
	  p++;
	}
	if(NN==1) printf("%ld",a[i]);
  }
  printf("\n");
}

void Sum(long A[MaxDig], long B[MaxDig], long C[MaxDig])
{
	int i,k;
	long Osn=pow(10.0,n_Osn);
	for (i = 0; i < MaxDig; i++) C[i]=0;
	if (A[0]>B[0]) {
		k=A[0];
	}
	else k=B[0];
	for (i = 1; i <= k; i++) {
		C[i+1]=(C[i]+A[i]+B[i])/Osn;
		C[i]=(C[i]+A[i]+B[i])%Osn;

		//for (int j = 0; j<=i+1; j++) {
		//	cout<<C[j]<<' ';
		//}
		//cout<<"   ";


	}
	if (C[k+1]==0) {
		C[0]=k;
	}
	else C[0]=k+1;
}


bool Eq(long A[MaxDig], long B[MaxDig])
{
	int i;
	bool ok=false;
	if (A[0]==B[0]) {
		i=1;
		while ((i<A[0]) && (A[i]==B[i])) i++;
			ok=(i==A[0]+1);
	}
	return ok;
}


//Вернет 0, если A>B, 1, если A<B и 2 если A=B
int More(long A[MaxDig], long B[MaxDig], int sdvig)
{
	int i, ok;
	if (A[0]>(B[0]+sdvig)) ok=0;
	else if (A[0]<(B[0]+sdvig)) ok=1;
	else {
		i=A[0];
		while ((i>sdvig)&&(A[i]==B[i-sdvig])) i--;
		if (i==sdvig) {
			ok=0;
			for (i = 1; i <= sdvig; i++) {
				if (A[i]>0) break;
				ok=2;
			}
		}
		else ok=(A[i]<B[i-sdvig]);
	}
}

void Mul(long A[MaxDig], long K, long C[MaxDig])
{
	int i;
	long Osn=pow(10.0,n_Osn);
	for (i = 0; i < MaxDig; i++) C[i]=0;
	if (K==0) C[0]++;
	else {
		for (i = 1; i <= A[0]; i++) {
			C[i+1]=(A[i]*K+C[i])/Osn;
			C[i]=(A[i]*K+C[i])%Osn;
		}
		if (C[A[0]+1]>0) C[0]=A[0]+1;
		else C[0]=A[0];
    }
}

void MulLong(long A[MaxDig], long B[MaxDig], long C[MaxDig])
{
	int i,j;
	long dv;
    long Osn=pow(10.0,n_Osn);
	for (i = 0; i < MaxDig; i++) C[i]=0;
	for (i = 1; i <= A[0]; i++)
		for (j = 1; j <= B[0]; j++) {
			dv=A[i]*B[j]+C[i+j-1];
			C[i+j]+=dv/Osn;
			C[i+j-1]=dv%Osn;
		}
	C[0]=A[0]+B[0];
	while ((C[0]>1)&&(C[C[0]]==0)) C[0]--;
}

int main(int argc, char* argv[])
{
	TLong A, B, C;
	long K;
	input(A);
	cout<<endl;
	input(B);
	cout<<endl;
	Sum(A,B,C);
	output(C);
	//cout<<endl;
	input(A);
	cout<<endl;
	input(B);
	cout<<endl;
	MulLong(A,B,C);
	output(C);
	getch();

	return 0;
}
