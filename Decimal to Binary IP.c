/*111408053_SARDA_PRANAV_VINOD_ASSIGN_2*/
#include<ctype.h>		//for  atoi()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>		//for checking ip address conditions

int isValidIpAddress(char *ipAddress);
long long convertDecimalToBinary(int n);

int main () {
	char string_ip[64],dup_ip[64], a[8],b[8],c[8],d[8],new[128], *search = ".", *token;
	long long p,q,r,s;
	system("clear");
	again:printf("\n\nEnter IP in Decimal Format = ");
	scanf("%s",string_ip);
	if(isValidIpAddress(string_ip) == 0) {
		printf("\n\nIvalid IP address... Please Enter again \n\n");//directly pass decimal string to check valid ip
		goto again;
	}
	strcpy(dup_ip,string_ip);
			token = strtok(string_ip, search);
			strcpy(a,token);
			token = strtok(NULL, search);//took input in string format with '.' now remove them and store each part of ip in a b c d 
			strcpy(b,token);
			token = strtok(NULL, search);
			strcpy(c,token);
			token = strtok(NULL, search);
			strcpy(d,token);

			p=convertDecimalToBinary(atoi(a));
			q=convertDecimalToBinary(atoi(b));
			r=convertDecimalToBinary(atoi(c));// covert all strings into binary numbers and store in  p q r s	
			s=convertDecimalToBinary(atoi(d));

			sprintf(new, "%08lld.%08lld.%08lld.%08lld", p, q, r, s);//concatenate all long pqrs into a new string named 'new'
			printf("\n\nYour IP = '%s' = ' %s '\n\n",dup_ip, new);
	return 0;
}
int isValidIpAddress(char *ipAddress) {
	struct sockaddr_in sa;
	int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr)); //inet_pton checks if it is valid ip or not returns 0 on failure
	return result;
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1;

    while (n!=0)
    {
        remainder = n%2; //convert decimal to binary number
         n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}
