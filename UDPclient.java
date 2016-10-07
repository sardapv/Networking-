import java.io.*;
import java.net.*;
class UDPclient
{
	public static void main(String args[])
	{
		try
		{
			DatagramSocket Clientsock=new DatagramSocket();
			BufferedReader in=new BufferedReader(new InputStreamReader(System.in));

			String str1;
			while(true)
			{
				byte[] send_data=new byte[1024];
				byte[] recv_data=new byte[1024];
				System.out.println();
				System.out.printf("\nME: ");
				str1=in.readLine();
				send_data=str1.getBytes();
				InetAddress addr=InetAddress.getLocalHost();
				DatagramPacket send_pack=new DatagramPacket(send_data,send_data.length,addr,8000);
				Clientsock.send(send_pack);

				DatagramPacket recv_pack=new DatagramPacket(recv_data,recv_data.length);
				Clientsock.receive(recv_pack);
				String s1=new String(recv_pack.getData());
				System.out.println();
				System.out.print("received: "+s1.trim());

			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
