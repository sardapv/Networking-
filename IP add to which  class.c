/*111408053_SARDA_PRANAV_VINOD_ASSIGN_1*/
#include<math.h>
#include<ctype.h>		//for  atoi()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>		//for checking ip address conditions

int isValidIpAddress(char *ipAddress);
int ConvertBinaryToDecimal(long long n);
int checkbinary (int binary);

int main () {
	int choice , i;
	char string_ip[35], dup_ip[35], a[8], b[8], c[8], d[8], new[35], *search = ".", *token;
	long p,q,r,s,val;
	system("clear");
	printf("\t\t ------ Choose one to input IP address ------\n\n\t\t1 . Binary 32 bit IP (eg. abc.abc.xyz.xyz) \n\n\t\t");
	printf("2. Decimal IP (eg.255.198.125.32)\n\n\t\t3.Exit\n\n\t\t Choice = ");			//menu to choose

	scanf("%d",&choice);
	switch (choice) {
		case 1:/*for Binary Input*/
			doagain:printf("\n\nEnter IP in Binary Format only = ");
			scanf("%s",dup_ip);
			strcpy(string_ip,dup_ip);

			token = strtok(dup_ip, search);
			strcpy(a,token);
			token = strtok(NULL, search);//taken input in string format with '.' now remove them and store each part of ip in a b c d 
			strcpy(b,token);
			token = strtok(NULL, search);
			strcpy(c,token);
			token = strtok(NULL, search);
			strcpy(d,token);

			p=ConvertBinaryToDecimal(atoi(a));
			q=ConvertBinaryToDecimal(atoi(b));
			r=ConvertBinaryToDecimal(atoi(c));// covert all strings into decimal numbers and store in  p q r s	
			s=ConvertBinaryToDecimal(atoi(d));
			//printf("%d.%d.%d.%d", p,q,r,s);

			sprintf(new, "%ld.%ld.%ld.%ld", p, q, r, s);//concatenate all long pqrs into a new string named 'new'
			
			if(isValidIpAddress(new) == 0) {//pass new to check if it is valid ip or not
				printf("\n\nIvalid IP address... Please Enter again \n\n");				
				goto doagain;
			}
			
			printf("\n\nYour IP  = ' %s ' = ' %s '",string_ip , new);
			val = p;	// copy 1st part of ip to val
			if (val >=0 && val <=127 )
				printf(" belongs to Class 'A'\n\n");
			if (val >=128 && val <=191) 
				printf(" belongs to Class 'B'\n\n");
			if (val >=192 && val <=223) 
				printf(" belongs to Class 'C'\n\n");//check conditions and print its class
			if (val >=224 && val <=239) 
				printf(" belongs to Class 'D'\n\n");
			if (val >=240 && val <=255) 
				printf(" belongs to Class 'E'\n\n");
			break;

		case 2:	/*for Decimal Input*/
			again:printf("\n\nEnter IP in Decimal Format = ");
			scanf("%s",string_ip);
			if(isValidIpAddress(string_ip) == 0) {
				printf("\n\nIvalid IP address... Please Enter again \n\n");//directly pass decimal string to check valid ip
				goto again;
			}
			char buffer[3];
			for (i = 0; i < 3 ; i++) {
				buffer[i] = string_ip[i];//put first part of ip into buffer string
			}					
			printf("\n\nYour IP  = ' %s '",string_ip);
			int val = atoi(buffer);//convert buffer into 
			if (val >=0 && val <=127 )
				printf(" belongs to Class 'A'\n\n");
			if (val >=128 && val <=191) 
				printf(" belongs to Class 'B'\n\n");
			if (val >=192 && val <=223) 
				printf(" belongs to Class 'C'\n\n");//check conditions and print class
			if (val >=224 && val <=239) 
				printf(" belongs to Class 'D'\n\n");
			if (val >=240 && val <=255) 
				printf(" belongs to Class 'E'\n\n");
			break;

		case 3: getchar();
			exit(1);//exit from program
		default:printf("Invalid Choice");
			break;
	}	
	return 0;
}
int isValidIpAddress(char *ipAddress) {
	struct sockaddr_in sa;
	int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr)); //inet_pton checks if it is valid ip or not returns 0 on failure
	return result;
}

int ConvertBinaryToDecimal(long long n) {
	int ret = checkbinary(n);
	if (ret == 0) {
		printf("Not Valid Binary Input...\n\n"); 
		getchar();
		exit(1);	
	}  
	else {  
		int decimalNumber = 0, i = 0, remainder;	//converts binary to decimal number
		while (n!=0)
		{
			remainder = n%10;
			n /= 10;
			decimalNumber += remainder * pow(2,i);
			++i;
		}
		return decimalNumber;
	}
}
int checkbinary (int binary) {
	int status,tmp;
	while(1){
		if(binary == 0){
			break;
		} else {
			tmp = binary%10;	//to check if binary input consists of num other than 1 and 0 if yes then invalid binary num
			if(tmp > 1){
				status = 0;
				break;
			}
			binary = binary/10;
		}
	}
	return status;
}

