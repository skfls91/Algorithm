#include<iostream>
#include<algorithm>
using namespace std;


//3X8 배열				 
int inputpeb[3][8];
int w[4][8];
int peb[4][8]; 

int pebble(int n)
{
	for(int p=0; p<4; p++){
		peb[p][0]=w[p][0];
	}
	for(int p=1; p<n; p++){
		for(int i=0; i<4; i++)
		{
			if(i==0)
				peb[i][p] = max(peb[1][p-1], peb[2][p-1]) + w[i][p];
			if(i==1)
				peb[i][p] = max(max(peb[0][p-1], peb[2][p-1]), peb[3][p-1] ) + w[i][p];
			if(i==2)
				peb[i][p] = max(peb[0][p-1], peb[1][p-1]) + w[i][p];
			if(i==3)
				peb[i][p] = peb[1][p-1] + w[i][p];
		}
	}
		
	 
}
int main(){
	//inputpeb 테이블, w 배열 생성 
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<8; j++)
		{
			cin >> inputpeb[i][j];
			w[i][j]=inputpeb[i][j];
			if(i==2)
				w[3][j]=w[0][j]+w[2][j];
		}
	}
	

	//확인 
	cout << "\n\n--w Array--\n\n";
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<8; j++)
		{
			cout << w[i][j] << "\t";
		}
		cout << endl;
	}
	
	pebble(8);
	
	cout << "\n\n###  The Answer is.. ";
	cout << max( max(peb[0][7], peb[1][7]), max(peb[2][7], peb[3][7]) ) << "  ###"; 
	
	cout << "\n\n\n(--peb Array--)\n\n";
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<8; j++)
		{
			cout << peb[i][j] << "\t";
		}
		cout << endl;
	}
	
	
	
	return 0;
}
