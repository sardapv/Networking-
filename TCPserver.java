import java.io.*;
import java.net.*;
public class TCPserver
{
	public static void main(String[] args) throws Exception
	{
		ServerSocket sersock = new ServerSocket(8000);
		System.out.println("Server  ready to chat\n");
		Socket sock = sersock.accept();                          
		BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
		OutputStream ostream = sock.getOutputStream(); 
		PrintWriter pwrite = new PrintWriter(ostream, true);
		InputStream istream = sock.getInputStream();
		BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));
		Boolean exflag = false;
		String receiveMessage, sendMessage;               
		while(true)
		{
			if((receiveMessage = receiveRead.readLine()) != null)  
			{
				if(receiveMessage.equals("end"))
				{
					System.out.println("\n    BYEEEEEEEEEE !!");
					exflag = true;
					sock.close();
					break;
				}	
				System.out.println(); 
				System.out.println("CLIENT       : " + receiveMessage); 

			}

			if (exflag == true) {
				System.exit(0);

			}
			System.out.print("\nTYPE HERE... : ");         
			sendMessage = keyRead.readLine(); 
			pwrite.println(sendMessage);             
			pwrite.flush();
		}               
	}                    
} 
