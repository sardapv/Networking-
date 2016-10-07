import java.io.*;
import java.net.*;
public class TCPclient
{
	public static void main(String[] args) throws Exception
	{
		Socket sock = new Socket("127.0.0.1", 8000);
		BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
		OutputStream ostream = sock.getOutputStream(); 
		PrintWriter pwrite = new PrintWriter(ostream, true);
		InputStream istream = sock.getInputStream();
		BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));

		System.out.println("Start the chitchat ----\n");

		String receiveMessage, sendMessage;         
		Boolean exflag = false;      
		while(true)
		{
			System.out.print("\nTYPE HERE... : ");
			sendMessage = keyRead.readLine();  // keyboard reading
			pwrite.println(sendMessage);       // sending to server
			pwrite.flush();                    
			if((receiveMessage = receiveRead.readLine()) != null) //receive from server
			{
				if(receiveMessage.equals("end"))
				{
					System.out.println("\n    BYEEEEEEEEEE !!");
					exflag = true;
					break;
				}
				if (exflag == true) {
					System.exit(0);
				} 

				System.out.println();
				System.out.println("SERVER       : "+receiveMessage);
			}         
		}               
	}                    
}                        
